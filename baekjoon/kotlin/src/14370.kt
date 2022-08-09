package p14370

fun main() {
    val n = readLine()!!.toInt()
    repeat(n) {
        val input = readLine()!!
        println("Case #${it + 1}: ${solve(input)}")
    }
}

// 첫 글자가 다른 문자열에서 안 쓰이는 정수부터 찾는다. 0부터 9까지 순서대로 찾으면 안 된다!
val digitEngs = listOf("ZERO", "XSI", "UFOR", "WTO", "SEVEN", "VFIE", "ONE", "GEIHT", "INNE", "RTHEE")
val digits = listOf(0, 6, 4, 2, 7, 5, 1, 8, 9, 3)

fun solve(input: String): String {
    val numbers = mutableListOf<Int>()
    val alphabetCount = (0..25).map { 0 }.toMutableList()
    input.forEach { alphabetCount[it.toOrder()]++ }

    digitEngs.forEachIndexed { index, digitEng ->
        val count = alphabetCount[digitEng[0].toOrder()]
        if (count > 0) {
            repeat(count) { numbers.add(digits[index]) }
            digitEng.forEach { char -> alphabetCount[char.toOrder()] -= count }
        }
    }

    return numbers.sorted().joinToString("")
}

fun Char.toOrder() = this - 'A'