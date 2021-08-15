import kotlin.math.min

private var n = 0
private var m = 0
private var c = 0
private val orders = mutableListOf<Order>()

private fun getInput() {
    val line = readLine()!!.split(" ").map { it.toInt() }
    n = line[0]
    c = line[1]
    m = readLine()!!.toInt()
    repeat(m) {
        val (from, to, amount) = readLine()!!.split(" ").map { it.toInt() }
        orders.add(Order(from, to, amount))
    }
}

private fun solve(): Int {
    val capacity = Array(n + 1) { 0 }
    var ans = 0

    val comp = compareBy<Order>({ it.to }, { it.from })
    orders.sortedWith(comp).forEach { order ->
        var load = order.amount
        order.range.forEach { load = min(load, c - capacity[it]) }
        order.range.forEach { capacity[it] += load }
        ans += load
    }
    return ans
}

private fun main() {
    getInput()
    println(solve())
}

private data class Order(
    val from: Int,
    val to: Int,
    val amount: Int
) {
    val range: IntRange
        get() = (from until to)
}