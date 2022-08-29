package p13563

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.min

private val che = IntArray(500_0001) { it }
private val primes = mutableListOf<Int>()
private val answers = mutableListOf<String>()

fun main() {
    calculatePrimes()
    with(BufferedReader(InputStreamReader(System.`in`))) {
        readLine()
        readLine()!!.split(" ").map { it.toInt() }.forEach { k ->
            solve(k)
        }
    }
    with(BufferedWriter(OutputStreamWriter(System.out))) {
        answers.forEach { write("$it\n") }
        flush()
    }
}

private fun calculatePrimes() {
    che[0] = -1
    che[1] = -1
    (2..500_0000).forEach { num ->
        if (che[num] == num) {
            primes.add(num)
            val long = num.toLong()
            (long * long..500_0000 step long).forEach { notPrime ->
                che[notPrime.toInt()] = min(che[notPrime.toInt()], num)
            }
        }
    }
}

private fun solve(num: Int) {
    val answer = factorize(num).apply { sort() }
    answers.add(answer.joinToString(" "))
}

private fun factorize(num: Int): MutableList<Int> {
    // 가장 빠른 소인수분해: 자신을 나눌 수 있는 가장 작은 소수로 계속 나눈다.
    // 자신을 나눌 수 있는 가장 작은 소수는 에라토스테네스의 체로 구한다.
    val answer = mutableListOf<Int>()
    var cur = num
    while (cur != 1) {
        val prime = che[cur]
        answer.add(prime)
        cur /= prime
    }
    return answer
}