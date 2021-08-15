package p1941

import java.util.*

val map = mutableListOf<String>()

fun <T> Iterable<T>.combinations(length: Int): Sequence<List<T>> = sequence {
    val pool = this@combinations as? List<T> ?: toList()
    val n = pool.size
    if (length > n) return@sequence
    val indices = IntArray(length) { it }
    while (true) {
        yield(indices.map { pool[it] })
        var i = length
        do {
            i--
            if (i == -1) return@sequence
        } while (indices[i] == i + n - length)
        indices[i]++
        for (j in i + 1 until length) indices[j] = indices[j - 1] + 1
    }
}

fun getInput() {
    (0 until 5).forEach { _ ->
        val input = readLine()!!
        map.add(input)
    }
}

fun solve(): Int {
    val coordsList = mutableListOf<Coord>()
    (0..4).forEach { r ->
        (0..4).forEach { c ->
            coordsList.add(Coord(r, c))
        }
    }

    var ans = 0
    coordsList.combinations(7).forEach { coords ->
        if (coords.isConnected() &&
            coords.filter { map[it.r][it.c] == 'S' }.size >= 4
        ) {
            println(coordsList)
            ans++
        }
    }
    return ans
}

fun main() {
    getInput()
    println(solve())
}

fun List<Coord>.isConnected(): Boolean {
    val queue: Queue<Coord> = LinkedList()
    val available = Array(5) { Array(5) { false } }
    val visit = available.map { it.copyOf() }

    this.forEach { coord ->
        available[coord.r][coord.c] = true
    }

    val start = this[0]

    var count = 1
    queue.add(start)
    visit[start.r][start.c] = true

    while (queue.isNotEmpty()) {
        val top = queue.poll()
        diffList.forEach { diff ->
            val new = top + diff
            try {
                if (available[new.r][new.c] and !visit[new.r][new.c]) {
                    count++
                    queue.add(new)
                    visit[new.r][new.c] = true
                }
            } catch (e: ArrayIndexOutOfBoundsException) {

            }
        }
    }
    return count == 7
}

val diffList = listOf(
    Coord(0, 1),
    Coord(1, 0),
    Coord(0, -1),
    Coord(-1, 0)
)

data class Coord(val r: Int, val c: Int) {
    operator fun plus(coord: Coord): Coord {
        return Coord(this.r + coord.r, this.c + coord.c)
    }
}
