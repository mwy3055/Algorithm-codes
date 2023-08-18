package source

fun main() {
    val n = readLine()!!.toLong()
    println(solve(n))
}

// 감동 실화: Fraction 안 써도 됨
fun solve(n: Long): Long {
    val mass = (n * n).toDouble()
    var ans = 0L
    var va = 0.0
    var vb = -1.0
    // A 입장에서는 B - 벽 - B - 벽 - ...
    while (va !in 0.0..vb) {
        when (ans % 2) {
            0L -> {
                val newA = (1 - mass) / (1 + mass) * va + 2 * mass / (1 + mass) * vb
                val newB = (mass - 1) / (mass + 1) * vb + 2 / (mass + 1) * va
                va = newA
                vb = newB
            }
            1L -> {
                va = -va
            }
        }
        ans++
    }
    return ans
}