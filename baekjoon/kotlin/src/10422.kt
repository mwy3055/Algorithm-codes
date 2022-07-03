package source

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val dp = LongArray(5001) { 0 }

fun main() {
    calculate()
    solve()
}

private fun solve() {
    with(BufferedReader(InputStreamReader(System.`in`))) {
        val writer = BufferedWriter(OutputStreamWriter(System.out))
        val n = readLine()!!.toInt()
        repeat(n) {
            val l = readLine()!!.toInt()
            writer.write(dp[l].toString())
            writer.newLine()
        }
        writer.close()
    }
}

private fun calculate() {
    dp[0] = 1
    (2..5000 step 2).forEach { i ->
        (2..i step 2).forEach { j ->
            dp[i] = dp[i] modSum (dp[j - 2] modTimes dp[i - j])
        }
    }
}

private const val MOD = 1_000_000_007

infix fun Long.modSum(other: Long) = ((this % MOD) + (other % MOD)) % MOD

infix fun Long.modTimes(other: Long) = (this * other) % MOD