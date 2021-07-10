package p1377

/**
 * @param value 주어진 값
 * @param order 주어진 순서
 */
data class Data(var value: Int, var order: Int)

fun main() {
    val n = readLine()?.toInt()!!
    val input =
            (0 until n).map { order ->
                val value = readLine()?.toInt()!!
                Data(value, order)
            }

    val sorted = input.sortedBy { it.value }

    var ans = 0
    sorted.forEachIndexed { index, data ->
        if (ans < data.order - index) {
            ans = data.order - index
        }
    }
    println(ans + 1)
}
