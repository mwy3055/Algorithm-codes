package p13172

import java.io.BufferedReader
import java.io.InputStreamReader

const val mod: Long = 1_000_000_007

var m = 0
val dices = mutableListOf<Dice>()

fun main() {
    getInput()
    println(solve())
}

fun getInput() {
    with(BufferedReader(InputStreamReader(System.`in`))) {
        m = this.readLine()!!.toInt()
        repeat(m) {
            val (n, s) = readLine()!!.split(" ").map { it.toLong() }
            val gcd = gcd(n, s)
            dices.add(Dice(n / gcd, s / gcd))
        }
    }
}

fun solve(): Long {
    var ans = 0L
    dices.forEach { (b, a) ->
        val bInverse = multiple(b, mod - 2)
        val add = ((a % mod) * (bInverse % mod)) % mod
        ans = (ans + add) % mod
    }
    return ans
}

data class Dice(val n: Long, val s: Long)

fun gcd(n1: Long, n2: Long): Long {
    if (n2 == 0L) return n1
    return gcd(n2, n1 % n2)
}

// n^x
fun multiple(n: Long, x: Long): Long {
    return when (x) {
        0L -> 1L
        1L -> n
        else -> {
            val half = multiple(n, x / 2) % mod
            var combine = (half * half) % mod
            if (x % 2 == 1L) {
                combine = (combine * (n % mod)) % mod
            }
            combine
        }
    }
}