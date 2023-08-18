package p1339

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    with(BufferedReader(InputStreamReader(System.`in`))) {
        val n = readLine()!!.toInt()
        val letters = (0 until n).map { readLine()!! }
        print(solve(letters))
    }
}

val used = BooleanArray(10) { false }

fun solve(letters: List<String>): Int {
    val chars = letters.fold(mutableSetOf<Char>()) { set, letter ->
        set.apply { addAll(letter.toCharArray().toList()) }
    }
    val charList = chars.toList()
    return search(letters, charList, mutableMapOf(), 0)
}

fun search(letters: List<String>, chars: List<Char>, map: MutableMap<Char, Int>, index: Int): Int {
    if (index == chars.size) {
        return eval(letters, map)
    }
    var result = 0
    (0..9).forEach { digit ->
        if (!used[digit]) {
            used[digit] = true
            map[chars[index]] = digit
            result = max(result, search(letters, chars, map, index + 1))
            used[digit] = false
        }
    }
    return result
}

fun eval(letters: List<String>, map: Map<Char, Int>): Int {
    return letters.fold(0) { result, letter ->
        result + letter.toInt(map)
    }
}

fun String.toInt(map: Map<Char, Int>): Int {
    return this.fold(0) { value, char ->
        value * 10 + map[char]!!
    }
}