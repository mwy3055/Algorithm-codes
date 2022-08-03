package p18436

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.log2
import kotlin.system.exitProcess

fun main() {
    val tree = getInput()
    solve(tree)
}

fun getInput(): SegmentTree<Int> {
    val n = readLine()!!.toInt()
    // 홀수?
    val isOdd = readLine()!!.split(" ").map { it.toInt() % 2 }
    return SegmentTree(values = isOdd, identity = 0, operation = { value1, value2 -> value1 + value2 })
}

fun solve(tree: SegmentTree<Int>) {
    val answers = mutableListOf<Int>()
    with(BufferedReader(InputStreamReader(System.`in`))) {
        val m = readLine()!!.toInt()
        repeat(m) {
            val (i, l, r) = readIntLine()
            when (i) {
                1 -> {
                    tree.update(l - 1, r % 2)
                }

                2 -> {
                    answers.add((r - l + 1) - tree.get(l - 1, r - 1))
                }

                3 -> {
                    answers.add(tree.get(l - 1, r - 1))
                }

                else -> exitProcess(-1)
            }
        }
    }

    with(BufferedWriter(OutputStreamWriter(System.out))) {
        write(answers.joinToString("\n"))
        flush()
    }
}

fun BufferedReader.readIntLine() = readLine()!!.split(" ").map { it.toInt() }

data class Segment<T>(
    val left: Int,
    val right: Int,
    val value: T,
)

class SegmentTree<T>(
    /**
     * number of values <= `2^(maxDepth - 1)
     */
    values: List<T>, private val identity: T, private val operation: (T, T) -> T
) {
    private val maxDepth: Int = (log2(values.size.toDouble()) + 2).toInt()
    private val treeSize = (1 shl maxDepth) - 1
    private val offset: Int = (1 shl (maxDepth - 1)) - 1
    private val tree: Array<Segment<T>> = Array(treeSize) { Segment(0, 0, identity) }

    init {
        init(0, values)
    }

    private fun init(index: Int, values: List<T>): Segment<T> {
        tree[index] = if (index >= offset) {
            val listIndex = index - offset
            Segment(
                left = listIndex,
                right = listIndex,
                value = if (listIndex < values.size) values[listIndex] else identity
            )
        } else {
            val leftTree = init(index.leftIndex, values)
            val rightTree = init(index.rightIndex, values)
            Segment(
                left = leftTree.left, right = rightTree.right, value = operation(leftTree.value, rightTree.value)
            )
        }
        return tree[index]
    }

    fun get(left: Int, right: Int): T {
        return get(0, left, right)
    }

    private fun get(curIndex: Int, left: Int, right: Int): T {
        return with(tree[curIndex]) {
            if (right < this.left || this.right < left) identity
            else if (left <= this.left && this.right <= right) value
            else operation(get(curIndex.leftIndex, left, right), get(curIndex.rightIndex, left, right))
        }
    }

    fun update(targetIndex: Int, targetValue: T) {
        update(0, targetIndex, targetValue)
    }

    private fun update(curIndex: Int, targetIndex: Int, targetValue: T): T {
        val newValue = with(tree[curIndex]) {
            if (this.left == targetIndex && this.right == targetIndex) targetValue
            else if (this.left == this.right || targetIndex < this.left || this.right < targetIndex) this.value
            else operation(
                update(curIndex.leftIndex, targetIndex, targetValue),
                update(curIndex.rightIndex, targetIndex, targetValue)
            )
        }
        tree[curIndex] = tree[curIndex].copy(value = newValue)
        return newValue
    }

    private val Int.leftIndex: Int
        get() = 2 * this + 1

    private val Int.rightIndex: Int
        get() = 2 * this + 2
}