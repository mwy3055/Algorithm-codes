package p2637

fun Array<Int>.addEachElement(other: Array<Int>) {
    other.forEachIndexed { index, i -> this[index] += i }
}

data class SubPart(val partNumber: Int, val count: Int)

var n = 0
val graph = Array<MutableList<SubPart>>(101) { mutableListOf() }
val isBasicPart = BooleanArray(101) { false }
val dp = Array<Array<Int>>(101) { arrayOf() }
val calculated = BooleanArray(101) { false }

private fun main() {
    getInput()
    solve()
}

private fun getInput() {
    n = readLine()!!.toInt()
    val m = readLine()!!.toInt()
    repeat(m) {
        val line = readLine()!!.split(" ").map { it.toInt() }
        val x = line[0]
        val y = line[1]
        val k = line[2]
        graph[x].add(SubPart(y, k))
    }

    (1..n).forEach { part ->
        isBasicPart[part] = graph[part].size == 0
    }
}

// 재귀 DP
private fun calculate(part: Int): Array<Int> {
    if (calculated[part]) return dp[part]
    if (isBasicPart[part]) {
        dp[part] = Array(n + 1) { if (it == part) 1 else 0 }
        calculated[part] = true
        return dp[part]
    }

    val array = Array(n + 1) { 0 }
    graph[part].forEach { (childPart, count) ->
        val basicArray = calculate(childPart).map { it * count }.toTypedArray()
        array.addEachElement(basicArray)
    }
    dp[part] = array
    calculated[part] = true
    return array
}


private fun solve() {
    val result = calculate(n)
    result.forEachIndexed { index, count ->
        if (count != 0) println("$index $count")
    }
}