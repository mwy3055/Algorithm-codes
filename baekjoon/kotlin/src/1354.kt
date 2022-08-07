package p1354

var n = 0L
var p = 0L
var q = 0L
var x = 0L
var y = 0L

const val MAX = 2000000
val dp = LongArray(MAX + 1) { -1 }

fun main() {
    getInput()
    println(solve())
}

fun getInput() {
    val line = readLine()!!.split(" ").map { it.toLong() }
    n = line[0]
    p = line[1]
    q = line[2]
    x = line[3]
    y = line[4]
}

fun solve(): Long {
    return dp(n)
}

fun dp(i: Long): Long {
    if (i <= 0) return 1
    if (i <= MAX) {
        val iInt = i.toInt()
        if (dp[iInt] == -1L) dp[iInt] = dp(i / p - x) + dp(i / q - y)
        return dp[i.toInt()]
    }
    return dp(i / p - x) + dp(i / q - y)
}