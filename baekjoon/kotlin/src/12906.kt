package p12906

import java.util.*

var a = ""
var b = ""
var c = ""

fun main() {
    getInput()
    println(solve())
}

fun getInput() {
    a = readStick()
    b = readStick()
    c = readStick()
}

fun readStick(): String {
    val line = readLine()!!.split(" ")
    return if (line.size == 1) "" else line[1]
}

fun solve(): Int {
    val aCount = count('A')
    val bCount = count('B')
    val cCount = count('C')
    val targetState = makeState("A".repeat(aCount), "B".repeat(bCount), "C".repeat(cCount))

    val set = hashSetOf<String>()
    val queue: Queue<String> = LinkedList()
    var ans = 0

    val insertState = { a: String, b: String, c: String ->
        val newState = makeState(a, b, c)
        if (!set.contains(newState)) {
            set.add(newState)
            queue.add(newState)
        }
    }

    // 막대가 많아봐야 10개이기 때문에 BFS로 해도 된다.
    insertState(a, b, c)
    while (queue.isNotEmpty()) {
        val size = queue.size
        for (i in 0 until size) {
            val state = queue.poll()
            if (state == targetState) return ans

            val (sa, sb, sc) = state.split(".")
            // a -> b
            val (a1, b1, c1) = movedStates(sa, sb, sc)
            insertState(a1, b1, c1)
            // a -> c
            val (a2, c2, b2) = movedStates(sa, sc, sb)
            insertState(a2, b2, c2)
            // b -> a
            val (b3, a3, c3) = movedStates(sb, sa, sc)
            insertState(a3, b3, c3)
            // b -> c
            val (b4, c4, a4) = movedStates(sb, sc, sa)
            insertState(a4, b4, c4)
            // c -> a
            val (c5, a5, b5) = movedStates(sc, sa, sb)
            insertState(a5, b5, c5)
            // c -> b
            val (c6, b6, a6) = movedStates(sc, sb, sa)
            insertState(a6, b6, c6)
        }
        ans++
    }
    return -1
}

fun count(target: Char) = a.count { it == target } + b.count { it == target } + c.count { it == target }

fun makeState(vararg sticks: String) = sticks.joinToString(".")

fun movedStates(from: String, to: String, same: String): List<String> {
    val (newFrom, newTo) = if (from.isNotEmpty()) {
        listOf(from.dropLast(1), to.plus(from.last()))
    } else {
        listOf(from, to)
    }
    return listOf(newFrom, newTo, same)
}