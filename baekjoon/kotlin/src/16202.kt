package p16202

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.system.exitProcess

var n = 0
var m = 0
var k = 0

val edges: Deque<Edge> = LinkedList()

fun main() {
    getInput()
    solve()
}

fun getInput() {
    with(BufferedReader(InputStreamReader(System.`in`))) {
        val line = readLineToInts()
        n = line[0]
        m = line[1]
        k = line[2]
        repeat(m) {
            val (n1, n2) = readLineToInts()
            edges.add(Edge(it + 1, n1, n2))
        }
    }
}

fun solve() {
    repeat(k) { turn ->
        // make MST
        val score = makeMST()
        // print score
        if (score == -1) {
            finish(k - turn)
        } else {
            print("$score ")
        }
        // remove edge
        edges.pollFirst()
    }
}

fun makeMST(): Int {
    val unionFind = Union(n)
    var sum = 0
    var count = 0
    for (edge in edges) {
        val (cost, n1, n2) = edge
        if (unionFind.isConnected(n1, n2)) continue
        unionFind.union(n1, n2)
        sum += cost
        if (++count == n - 1) break
    }
    return if (count == n - 1) sum else -1
}

fun finish(n: Int) {
    repeat(n) {
        print("0 ".repeat(n))
        exitProcess(0)
    }
}

fun BufferedReader.readLineToInts() = readLine().split(" ").map { it.toInt() }

data class Edge(val cost: Int, val n1: Int, val n2: Int) : Comparable<Edge> {
    override fun compareTo(other: Edge): Int {
        return cost.compareTo(other.cost)
    }
}

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