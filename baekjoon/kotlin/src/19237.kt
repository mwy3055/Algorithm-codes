package p19237

var n = 0
var m = 0
var k = 0
val map = Array(20) { row -> Array(20) { col -> Grid(Coord(row, col)) } }

fun <T> Array<Array<T>>.forEachValue(action: (T) -> Unit) {
    this.forEach { row ->
        row.forEach { elem ->
            action(elem)
        }
    }
}

operator fun <T> Array<Array<T>>.get(c: Coord): T = this[c.r][c.c]

fun getInput() {
    var line = readLine()!!
    val split = line.split(" ").map { it.toInt() }
    n = split[0]
    m = split[1]
    k = split[2]

    val sharks: MutableMap<Int, Coord> = mutableMapOf()
    repeat(n) { r ->
        line = readLine()!!
        line.split(" ").map { it.toInt() }.forEachIndexed { c, s ->
            if (s != 0) {
                map[r][c].sharks.add(Shark(s, Coord(r, c)))
                sharks[s] = Coord(r, c)
            }
        }
    }

    val dirs = readLine()!!.split(" ").map { it.toInt() - 1 }
    sharks.forEach { (num, coord) ->
        map[coord].sharks[0].dir = dirs[num - 1]
    }

    sharks.keys.sorted().forEach { num ->
        val coord = sharks[num]!!
        val order: Array<IntArray> = (0..3).map {
            line = readLine()!!
            line.split(" ").map { it.toInt() - 1 }.toIntArray()
        }.toTypedArray()
        map[coord].sharks[0].rotateOrder = order
    }
}

fun printInput() {
    map.forEach { row ->
        row.forEach { grid ->
            if (grid.sharks.isNotEmpty()) {
                println(grid.sharks[0])
            }
        }
    }
}

fun finished(): Boolean {
    return map.flatten().map { it.sharks }.flatten().size == 1
}

// 냄새를 뿌림
fun scatter() {
    map.forEachValue { grid ->
        if (grid.isNotEmpty()) {
            val shark = grid.sharks[0]
            grid.smell = Smell(shark.num, k)
        }
    }
}

// 상어를 쫓아냄
fun kick() {
    map.forEachValue { grid ->
        if (grid.sharks.size > 1) {
            with(grid.sharks) {
                val top = minByOrNull { it.num }!!
                clear()
                add(top)
            }
        }
    }
}

// 냄새의 유효기간 갱신
fun spoilSmell() {
    map.forEachValue { grid->
        val spoiled = grid.smell?.let { smell ->
            smell.oneSecondElapsed()
            smell.time == 0
        } ?: false
        if (spoiled) {
            grid.smell = null
        }
    }
}

fun move(shark: Shark) {
    // 방향 결정
    val currentDir = shark.dir
    val current = shark.coord
    var moveDir = -1
    // 먼저 아무 냄새가 없는 칸을 찾는다.
    for (candidateDir in shark.rotateOrder[currentDir]) {
        if (current.canMove(candidateDir)) {
            val next = current.move(candidateDir)
            if (map[next].smell == null) {
                moveDir = candidateDir
                break
            }
        }
    }
    // 아무 냄새가 없는 칸이 없으면
    if (moveDir == -1) {
        // 자신의 냄새가 있는 칸의 방향으로 결정
        for (candidateDir in shark.rotateOrder[currentDir]) {
            if (current.canMove(candidateDir)) {
                val next = current.move(candidateDir)
                if (map[next].smell?.num == shark.num) {
                    moveDir = candidateDir
                    break
                }
            }
        }
    }

    // 움직여!
    val next = current.move(moveDir)
    map[current].sharks.clear()
    val sharkMoved = shark.copy(coord = next, dir = moveDir)
    map[next].sharks.add(sharkMoved)
}

// 움직임
fun move() {
    val sharks = map.flatten().map { it.sharks }.flatten()
    sharks.forEach { shark ->
        move(shark)
    }
}

fun solve(): Int {
    if (finished()) {
        return 0
    }

    var ans = -1

    scatter()

    for (time in 1..1000) {
        // move map
        move()
        kick()
        if (finished()) {
            ans = time
            break
        }
        spoilSmell()
        scatter()
    }
    return ans
}

fun main() {
    getInput()

//    printInput()
    println(solve())
}

data class Coord(val r: Int, val c: Int) {
    infix operator fun plus(c: Coord): Coord = Coord(this.r + c.r, this.c + c.c)

    fun canMove(dir: Int): Boolean {
        val next = this + diffList[dir]
        return (next.r in (0 until n)) and (next.c in (0 until n))
    }

    fun move(dir: Int): Coord {
        val diff = diffList[dir]
        return Coord(this.r + diff.r, this.c + diff.c)
    }
}

val diffList = listOf(
    Coord(-1, 0),
    Coord(1, 0),
    Coord(0, -1),
    Coord(0, 1)
)

data class Shark(
    val num: Int,
    var coord: Coord,
    var dir: Int = 0,
    var rotateOrder: Array<IntArray> = arrayOf()
) {
    fun move(dir: Int) {
        coord = coord.move(dir)
    }
}

data class Grid(
    val coord: Coord,
    val sharks: MutableList<Shark> = mutableListOf(),
    var smell: Smell? = null
) {
    fun isEmpty(): Boolean = sharks.isEmpty()
    fun isNotEmpty(): Boolean = !isEmpty()
}

data class Smell(
    val num: Int,
    var time: Int
) {
    fun oneSecondElapsed() {
        time--
    }
}