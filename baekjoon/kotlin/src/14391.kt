import kotlin.math.max

private var n = 0
private var m = 0
private val map = Array(4) { IntArray(4) { 0 } }

fun main() {
    getInput()
    println(solve())
}

private fun getInput() {
    val nums = readLine()!!.split(" ").map { it.toInt() }
    n = nums[0]
    m = nums[1]
    repeat(n) { r ->
        val line = readLine()!!
        line.forEachIndexed { index, c ->
            map[r][index] = c.digitToInt()
        }
    }
}

private fun solve(): Int {
    var ans = 0
    val shift = n * m
    // 0: 가로로 자름
    // 1: 세로로 자름
    (0 until (1 shl shift)).forEach { bitmask ->
        var sum = 0
        // 가로방향 합 구하기
        (0 until n).forEach { r ->
            var tempSum = 0
            (0 until m).forEach { c ->
                val bit = r * m + c
                if (bitmask and (1 shl bit) == 0) {
                    tempSum = tempSum * 10 + map[r][c]
                } else {
                    sum += tempSum
                    tempSum = 0
                }
            }
            sum += tempSum
            tempSum = 0
        }
        // 세로방향 합 구하기
        (0 until m).forEach { c ->
            var tempSum = 0
            (0 until n).forEach { r ->
                val bit = r * m + c
                if (bitmask and (1 shl bit) != 0) {
                    tempSum = tempSum * 10 + map[r][c]
                } else {
                    sum += tempSum
                    tempSum = 0
                }
            }
            sum += tempSum
        }
        ans = max(ans, sum)
    }
    return ans
}

