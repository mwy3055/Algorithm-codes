package p21609

import java.util.*

fun main() {
    val (n, _) = readLine()!!.split(" ").map { it.toInt() }
    val grid = Grid(n)

    println(solve(grid))
}

fun solve(grid: Grid): Int {
    var answer = 0
    while (true) {
        val groups = findBlockGroups(grid)

        val largestGroup = groups.firstOrNull() ?: break
        answer += largestGroup.score

        grid.remove(largestGroup)
        grid.applyGravity()
        grid.rotate()
        grid.applyGravity()
    }
    return answer
}

fun findBlockGroups(grid: Grid): List<BlockGroup> {
    val groups = mutableListOf<BlockGroup>()
    val visit = Array(grid.size) { Array(grid.size) { false } }

    // find groups
    grid.forEachRow { row ->
        row.forEach { block ->
            if (block is Normal && !visit[block.coord]) {
                val group = findBlockGroup(
                    block.coord,
                    grid,
                    { c -> visit[c] = true },
                    { c -> visit[c.r][c.c] }
                )
                if (group.size > 1) {
                    groups.add(group)
                }
            }
        }
    }

    // sort before return
    return groups.sortedWith(
        compareBy({ it.size }, { it.rainbowCount }, { it.firstBlock.coord.r }, { it.firstBlock.coord.c })
    ).reversed()
}

private operator fun Array<Array<Boolean>>.set(coord: Coord, value: Boolean) {
    this[coord.r][coord.c] = value
}

private operator fun Array<Array<Boolean>>.get(coord: Coord): Boolean = this[coord.r][coord.c]

val diff = listOf(
    Coord(-1, 0),
    Coord(0, 1),
    Coord(1, 0),
    Coord(0, -1)
)

/**
 * @param start 탐색을 시작할 일반 블럭의 좌표
 */
fun findBlockGroup(start: Coord, grid: Grid, setVisit: (Coord) -> Unit, getVisit: (Coord) -> Boolean): BlockGroup {
    val startNumber = grid[start].number
    val rainbowSet = mutableSetOf<Coord>()
    val group = BlockGroup()
    val q: Queue<Coord> = LinkedList()
    val insertQueue: (Coord) -> Unit = { coord ->
        q.add(coord)
        setVisit(coord)
        rainbowSet.add(coord)
    }

    group.add(grid[start])
    insertQueue(start)
    while (q.isNotEmpty()) {
        val top = q.poll()

        diff.forEach { d ->
            val next = top + d
            if (!grid.isIn(next)) return@forEach
            val nextBlock = grid[next]
            if ((nextBlock is Rainbow && next !in rainbowSet) ||
                (nextBlock is Normal && nextBlock.number == startNumber && !getVisit(next))
            ) {
                group.add(nextBlock)
                insertQueue(next)
            }
        }
    }
    group.blocks.sortWith(compareBy({ it !is Normal }, { it.coord.r }, { it.coord.c }))
    return group
}

data class Coord(val r: Int, val c: Int) {
    operator fun plus(other: Coord) = Coord(this.r + other.r, this.c + other.c)

    override fun toString(): String = "($r, $c)"
}

sealed class Block {
    abstract var coord: Coord
    abstract val number: Int

    override fun toString() = "$coord, $number"
}

class Black(override var coord: Coord, override val number: Int) : Block()
class Rainbow(override var coord: Coord, override val number: Int) : Block()
class Normal(override var coord: Coord, override val number: Int) : Block()
class Empty(override var coord: Coord, override val number: Int = 0) : Block()

class Grid(val size: Int) {
    private val blocks =
        List(size) { row ->
            readLine()!!
                .split(" ")
                .map { it.toInt() }
                .mapIndexed { col, value ->
                    val c = Coord(row, col)
                    when (value) {
                        -1 -> Black(c, value)
                        0 -> Rainbow(c, value)
                        else -> Normal(c, value)
                    }
                }
                .toMutableList()
        }

    fun forEachRow(action: (row: List<Block>) -> Unit) {
        blocks.forEach(action)
    }

    fun isIn(coord: Coord): Boolean {
        val range = 0 until size
        return coord.r in range && coord.c in range
    }

    operator fun get(coord: Coord): Block = blocks[coord.r][coord.c]

    fun remove(group: BlockGroup) {
        group.blocks.forEach { block ->
            val c = block.coord
            blocks[c.r][c.c] = Empty(c)
        }
    }

    fun applyGravity() {
        (size - 2 downTo 0).forEach { row ->
            (0 until size).forEach inner@{ col ->
                if (blocks[row][col] is Black) return@inner
                var nextRow = row
                while (isIn(Coord(nextRow + 1, col)) && blocks[nextRow + 1][col] is Empty) {
                    nextRow++
                }
                if (nextRow != row) {
                    blocks[nextRow][col] = blocks[row][col].apply { coord = Coord(nextRow, col) }
                    blocks[row][col] = Empty(Coord(row, col))
                }
            }
        }
    }

    // https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
    fun rotate() {
        blocks.forEach { row ->
            row.reverse()
        }
        (0 until size).forEach { row ->
            (row until size).forEach { col ->
                blocks[row][col] = blocks[col][row].also { blocks[col][row] = blocks[row][col] }
                blocks[row][col].coord = Coord(row, col)
                blocks[col][row].coord = Coord(col, row)
            }
        }
    }
}

class BlockGroup {
    val blocks = mutableListOf<Block>()

    val size: Int
        get() = blocks.size

    val score: Int
        get() = size * size

    val rainbowCount: Int
        get() = blocks.count { it is Rainbow }

    val firstBlock: Block
        get() = blocks[0]

    fun add(block: Block) = blocks.add(block)

    override fun toString(): String = "Size: $size, first: $firstBlock"
}