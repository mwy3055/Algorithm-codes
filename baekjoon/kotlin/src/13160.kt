package p13160

import java.io.BufferedReader
import java.io.InputStreamReader

data class Segment(val index: Int, val s: Int, val e: Int)

var n = 0
val segments = mutableListOf<Segment>()

fun main() {
    getInput()
    solve()
}

fun getInput() {
    with(BufferedReader(InputStreamReader(System.`in`))) {
        n = readLine()!!.toInt()
        repeat(n) {
            val (s, e) = readLine()!!.split(" ").map { it.toInt() }
            segments.add(Segment(index = it + 1, s, e))
        }
    }
}

fun solve() {
    val compressed = compressSegments()
    val starts = Array(600001) { mutableListOf<Int>() }
    val ends = Array(600001) { mutableListOf<Int>() }
    compressed.forEach {
        starts[it.s].add(it.index)
        ends[it.e].add(it.index)
    }

    // find ans
    var answer = 0
    var answerPos = 0
    var count = 0
    (0..600000).forEach { pos ->
        count += starts[pos].size
        if (count > answer) {
            answer = count
            answerPos = pos
        }
        count -= ends[pos].size
    }

    val answers = compressed.filter { it.s <= answerPos && answerPos <= it.e }.map { it.index }
    println(answers.size)
    println(answers.joinToString(" "))
}

// 좌표압축
fun compressSegments(): List<Segment> {
    val numbers = mutableListOf<Int>()
    segments.forEach {
        numbers.add(it.s)
        numbers.add(it.e)
    }
    val order = mutableMapOf<Int, Int>()
    with(numbers) {
        sort()
        forEachIndexed { index, i -> order[i] = index }
    }
    return segments.map {
        Segment(index = it.index, s = order[it.s]!!, e = order[it.e]!!)
    }
}

