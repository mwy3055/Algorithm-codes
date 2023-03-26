package source

import java.util.*

fun main() {
    val string = readln()
    val stack = Stack<Char>()

    string.forEach { c ->
        if (stack.isNotEmpty() && stack.peek() == '(' && c == ')') {
            stack.pop()
        } else {
            stack.push(c)
        }
    }
    println(stack.size)
}