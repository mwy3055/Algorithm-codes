package p14907

import java.io.BufferedReader
import java.io.InputStreamReader

val time = IntArray(26) { -1 }
val totalTime = IntArray(26) { -1 }
val graph = Array(26) { mutableListOf<Int>() }
val outer = IntArray(26) { 0 }

fun main() {
    getInput()
    println(solve())
}

fun getInput() {
    with(BufferedReader(InputStreamReader(System.`in`))) {
        readLines().forEach { line ->
            val split = line.split(" ")
            val task = split[0][0].toOrder()
            val t = split[1].toInt()
            time[task] = t
            if (split.size == 3) {
                split[2].map { it.toOrder() }.forEach { child ->
                    graph[task].add(child)
                    outer[child]++
                }
            }
        }
    }
}

fun solve(): Int {
    return ('A'..'Z')
        .map { it.toOrder() }
        .filter { time[it] != -1 && outer[it] == 0 } // find root of tree
        .maxOf { task -> search(task) }              // calculate time to finish this task
}

fun search(task: Int): Int {
    if (totalTime[task] == -1) {
        val childMaxTime = graph[task].maxOfOrNull { child -> search(child) } ?: 0
        totalTime[task] = childMaxTime + time[task]
    }
    return totalTime[task]
}

fun Char.toOrder(): Int = this - 'A'