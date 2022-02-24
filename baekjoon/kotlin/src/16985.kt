package p16985

import java.util.*
import kotlin.math.min

val original = mutableListOf<Plate>()

fun <T> permutation(el: List<T>, fin: List<T> = listOf(), sub: List<T> = el): List<List<T>> {
    return if (sub.isEmpty()) listOf(fin)
    else sub.flatMap { permutation(el, fin + it, sub - it) }
}

fun main() {
    getInput()
    preprocess()
    val ans = solve()
    println(if (ans == Int.MAX_VALUE) -1 else ans)
}

fun getInput() {
    repeat(5) {
        val plate = getPlateInput()
        original.add(plate)
    }
}

fun getPlateInput(): Plate {
    val list = (0..4).map { _ ->
        val line = readLine()!!
        line.split(" ").map { it == "1" }
    }
    return Plate(list)
}

fun preprocess() {
    original.forEachIndexed { index, plate ->
        rotateAvailable[index].add(0)
        (1..3).forEach { rotation ->
            val rotatedPlate = plate.rotate(rotation)
            if (plate != rotatedPlate) {
                rotateAvailable[index].add(rotation)
            }
        }
    }
}

/**
 * 모든 회전 상태, 모든 순서, 모든 출발-도착 쌍에 대해 이동 횟수의 최솟값을 구한다.
 */
fun solve(): Int {
    var answer = Int.MAX_VALUE
    (0 until 1024).forEach { bitmask ->
        val caseAns = solve(bitmask)
        answer = min(answer, caseAns)
    }
    return answer
}

val rotateAvailable = Array(5) { mutableSetOf<Int>() }

/**
 * 회전 상태가 [bitmask]로 주어질 때,
 * 모든 순서, 모든 출발-도착 쌍에 대해 이동 거리의 최솟값을 구한다.
 *
 * @param bitmask 10자리 비트마스크
 */
fun solve(bitmask: Int): Int {
    // 일단 돌린 판을 얻기
    val rotatedPlates = (0..4).map { index ->
        val numberRotate = numberFromBitmask(bitmask, index)
        if (!rotateAvailable[index].contains(numberRotate)) {
            return Int.MAX_VALUE
        }
        original[index].rotate(numberRotate)
    }
    // 판을 쌓는 모든 순서에 대해
    var answer = Int.MAX_VALUE
    permutation((0..4).toList()).forEach { order ->
        // 모든 출발-도착 쌍에 대해 답을 구하고
        // 가장 작은 값 반환
        val candidate = solve(rotatedPlates, order)
        answer = min(answer, candidate)
    }
    return answer
}

/**
 * 판 [plates]의 순서가 [order]일 때,
 * 모든 출발-도착 쌍에 대해 이동 거리의 최솟값을 반환한다.
 */
fun solve(plates: List<Plate>, order: List<Int>): Int {
    val cube = getCube(plates, order)

    var answer = Int.MAX_VALUE
    Coord.starts.forEach { start ->
        val candidate = solve(cube, start, start.dest())
        answer = min(answer, candidate)
    }
    return answer
}

val q: Queue<Coord> = LinkedList()
val visit = Array(5) { Array(5) { Array(5) { false } } }

/**
 * 3차원 미로와 출발점, 도착점이 주어졌을 때
 * 출발점에서 도착점까지 가장 빨리 이동할 때의 이동 횟수를 구한다.
 * 도착점으로 갈 수 없다면 [Int.MAX_VALUE]를 반환한다.
 */
fun solve(cube: Cube, start: Coord, dest: Coord): Int {
    if (!cube[start] or !cube[dest]) return Int.MAX_VALUE

    q.clear()
    visit.forEach { floor ->
        floor.forEach { row ->
            row.fill(false)
        }
    }
    var dist = 0

    visit.set(start, true)
    q.add(start)
    while (q.isNotEmpty()) {
        val size = q.size
        repeat(size) {
            val cur = q.poll()
            if (cur == dest) return dist
            Coord.deltas.forEach { delta ->
                val next = cur + delta
                if (next.isIn && cube[next] && !visit[next]) {
                    visit.set(next, true)
                    q.add(next)
                }
            }
        }
        dist++
    }
    return Int.MAX_VALUE
}

fun getCube(plates: List<Plate>, order: List<Int>): Cube {
    val cubePlates = order.map { plates[it] }
    return Cube(cubePlates)
}

/**
 * [bitmask]에서 [index]번째 값을 얻는다.
 * 값은 2개의 이진수로 구성되며, 따라서 [0, 4) 구간의 정수를 갖는다.
 *
 * @param bitmask 10자리 비트마스크
 * @param index 값을 얻을 인덱스
 * @return 0 이상 4 미만의 정수
 */
fun numberFromBitmask(bitmask: Int, index: Int): Int {
    val a = if (bitmask and (1 shl (index * 2)) == 0) 0 else 1
    val b = if (bitmask and (1 shl (index * 2 + 1)) == 0) 0 else 1
    return b * 2 + a
}

data class Cube(val plates: List<Plate>) {
    operator fun get(c: Coord): Boolean = plates[c.z].content[c.x][c.y]
}

data class Plate(val content: List<List<Boolean>>) {
    /**
     * 주어진 판을 [count]번 회전한다.
     */
    fun rotate(count: Int): Plate {
        var rotated = this.content
        repeat(count) {
            val new = (0..4).map { row ->
                (0..4).map { col ->
                    rotated[col][4 - row]
                }
            }
            rotated = new
        }
        return Plate(rotated)
    }
}

data class Coord(val x: Int, val y: Int, val z: Int) {
    val isIn: Boolean
        get() = x in 0..4 && y in 0..4 && z in 0..4

    fun dest(): Coord {
        val dx = if (x == 4) 0 else 4
        val dy = if (y == 4) 0 else 4
        val dz = if (z == 4) 0 else 4
        return Coord(dx, dy, dz)
    }

    operator fun plus(c: Coord) = Coord(x + c.x, y + c.y, z + c.z)

    companion object {
        val deltas = listOf(
            Coord(1, 0, 0),
            Coord(-1, 0, 0),
            Coord(0, 1, 0),
            Coord(0, -1, 0),
            Coord(0, 0, 1),
            Coord(0, 0, -1)
        )

        val starts = listOf(
            Coord(0, 0, 0),
            Coord(0, 4, 0),
            Coord(4, 0, 0),
            Coord(4, 4, 0)
        )
    }
}


operator fun <T> Array<Array<Array<T>>>.get(c: Coord): T = this[c.z][c.x][c.y]

fun <T> Array<Array<Array<T>>>.set(c: Coord, value: T) {
    this[c.z][c.x][c.y] = value
}
