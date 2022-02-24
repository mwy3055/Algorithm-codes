package p18808

var n = 0
var m = 0
var k = 0
val stickers = mutableListOf<Sticker>()
lateinit var notebook: Array<Array<Boolean>>

fun getIntLine(): List<Int> = readLine()!!.split(" ").map { it.toInt() }

fun getInput() {
    var line = getIntLine()
    n = line[0]
    m = line[1]
    k = line[2]
    repeat(k) {
        line = getIntLine()
        val r = line[0]
        val c = line[1]
        val contents = (0 until r).map {
            getIntLine().map { it == 1 }.toTypedArray()
        }.toTypedArray()
        stickers.add(Sticker(r, c, contents))
    }
    notebook = Array(n) { Array(m) { false } }
}

/**
 * (r, c) 위치에 스티커를 붙일 수 있다면 붙이고 true를 반환한다.
 * 그렇지 않다면 false를 반환한다.
 */
fun attach(sticker: Sticker, r: Int, c: Int): Boolean {
    // 붙일 수 있는지 검사
    sticker.content.forEachIndexed { rowIndex, row ->
        row.forEachIndexed { colIndex, col ->
            val alreadyFilled = notebook[r + rowIndex][c + colIndex] and col
            if (alreadyFilled) return false
        }
    }
    // 실제로 붙인다.
    sticker.content.forEachIndexed { rowIndex, row ->
        row.forEachIndexed { colIndex, col ->
            notebook[r + rowIndex][c + colIndex] = notebook[r + rowIndex][c + colIndex] or col
        }
    }
    return true
}

/**
 * 스티커를 붙일 수 있는 위치가 있는지 탐색한다.
 */
fun attach(sticker: Sticker) {
    var newSticker = sticker
    repeat(4) {
        val rowScope = 0..(n - newSticker.r)
        val colScope = 0..(m - newSticker.c)
        rowScope.forEach { row ->
            colScope.forEach { col ->
                if (attach(newSticker, row, col)) return
            }
        }
        newSticker = newSticker.rotate()
    }
}

fun printTemporaryAnswer() {
    println("=".repeat(20))
    notebook.print()
    println("=".repeat(20))
}

fun solve() {
    stickers.forEach { sticker ->
        attach(sticker)
//        printTemporaryAnswer()
    }
}

fun printAnswer() {
    val sum = notebook.fold(0) { total, elements ->
        total + elements.filter { it }.size
    }
    println(sum)
}

fun main() {
    getInput()
    solve()
    printAnswer()
}

data class Sticker(
    val r: Int,
    val c: Int,
    val content: Array<Array<Boolean>> = Array(r) { Array(c) { false } }
) {
    fun rotate(): Sticker {
        val newContent = Array(c) { Array(r) { false } }
        (0 until r).forEach { row ->
            (0 until c).forEach { col ->
                newContent[col][r - 1 - row] = content[row][col]
            }
        }
        return Sticker(c, r, newContent)
    }

    fun print() {
        println("Height: $r, Width: $c")
        content.print()
    }
}

fun Array<Array<Boolean>>.print() {
    this.forEach { row ->
        println(row.joinToString(separator = " ") { if (it) "1" else "0" })
    }
}