package source

import kotlin.system.exitProcess

var n = 0
var costSum = 0
val edges = mutableListOf<Edge>()

private fun main() {
    getInput()
    println(solve())
}

private fun getInput() {
    n = readLine()!!.toInt()
    repeat(n) { row ->
        readLine()!!.forEachIndexed { col, c ->
            val length = parseLength(c)
            if (length != 0) {
                edges.add(Edge(length, row + 1, col + 1))
                costSum += length
            }
        }
    }
}

private fun parseLength(c: Char): Int = when (c) {
    in 'a'..'z' -> c.minus('a') + 1
    in 'A'..'Z' -> c.minus('A') + 27
    '0' -> 0
    else -> exitProcess(-1)
}

private fun solve(): Int {
    edges.sortBy { it.length }
    val union = Union(n)

    // kruskal
    var usedCost = 0
    var connected = 0
    for ((cost, p1, p2) in edges) {
        if (connected == n - 1) break
        if (!union.isConnected(p1, p2)) {
            union.union(p1, p2)
            usedCost += cost
            connected++
        }
    }

    return if (connected == n - 1) costSum - usedCost else -1
}

data class Edge(val length: Int, val p1: Int, val p2: Int)

class Union(val n: Int) {
    // 1-indexed
    private val parents = IntArray(n + 1) { it }

    fun get(node: Int): Int {
        if (parents[node] != node) {
            parents[node] = get(parents[node])
        }
        return parents[node]
    }

    fun union(p1: Int, p2: Int) {
        val (child, parent) = listOf(get(p1), get(p2)).sorted()
        parents[parent] = child
    }

    fun isConnected(p1: Int, p2: Int) = (get(p1) == get(p2))
}