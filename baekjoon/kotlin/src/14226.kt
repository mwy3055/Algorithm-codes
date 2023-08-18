package source

import java.util.*

fun main() {
    val s = readLine()!!.toInt()
    println(solve(s))
}

private fun solve(s: Int): Int {
    val visit = hashSetOf<Pair>()
    val queue: Queue<Pair> = LinkedList()

    val add = { pair: Pair ->
        if (!visit.contains(pair)) {
            visit.add(pair)
            queue.add(pair)
        }
    }

    var time = 0
    queue.add(Pair(0, 1))
    while (queue.isNotEmpty()) {
        val size = queue.size
        repeat(size) {
            val (clip, count) = queue.poll()
            if (count == s) return time
            // 1
            add(Pair(count, count))
            // 2
            add(Pair(clip, count + clip))
            // 3
            add(Pair(clip, count - 1))
        }
        time++
    }
    return -1
}

data class Pair(val clipboard: Int, val count: Int)