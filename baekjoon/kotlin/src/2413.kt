package p2413

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    with(BufferedReader(InputStreamReader(System.`in`))) {
        val n = readLine()!!.toInt()
        val used = BooleanArray(n + 1) { false }
        val answers = mutableListOf<Int>()
        readLine()!!.split(" ").map { it.toInt() }.forEach { num ->
            // num에 num-1을 매칭하는 것이 최선. 이 경우 num-1에는 num을 매칭
            // num에 num-1을 매칭할 수 없다면 num을 매칭한다.
            if (used[num]) {
                answers.add(num + 1)
            } else if ((num - 1) in (1..n) && !used[num - 1]) {
                answers.add(num - 1)
                used[num - 1] = true
                used[num] = true
            } else {
                answers.add(num)
                used[num] = true
            }
        }
        println(answers.joinToString(" "))
    }
}