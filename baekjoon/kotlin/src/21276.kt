package p21276

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

var n = 0
val people = mutableListOf<Person>()
val nameIndex = mutableMapOf<String, Int>()

fun main() {
    getInput()
    solve()
}

fun getInput() {
    with(BufferedReader(InputStreamReader(System.`in`))) {
        n = readIntLine()
        readLine()!!.split(" ").forEachIndexed { index, name ->
            people.add(Person(index, name))
            nameIndex[name] = index
        }
        val m = readIntLine()
        repeat(m) {
            val (child, ancestor) = readLine()!!.split(" ").map { nameIndex[it]!! }
            people[ancestor].edges.add(child)
            people[child].enter++
        }
    }
}

fun solve() {
    val origins = people.filter { it.enter == 0 }
    origins.forEach { origin -> makeTree(origin.index) }

    // print origins
    with(origins.sortedBy { it.name }) {
        println(size)
        println(joinToString(" ") { it.name })
    }
    // print parent-child relationships
    people.sortedBy { it.name }.forEach { person ->
        println(person.answer())
    }
}

fun makeTree(i: Int) {
    val q: Queue<Int> = LinkedList()
    q.add(i)

    // topological sort
    while (q.isNotEmpty()) {
        val top = q.remove()
        people[top].edges.forEach { childIndex ->
            if (--people[childIndex].enter == 0) {
                q.add(childIndex)
                people[top].addChild(childIndex)
            }
        }
    }
}

private fun BufferedReader.readIntLine() = readLine()!!.toInt()

data class Person(val index: Int, val name: String) {
    val edges = mutableListOf<Int>()
    private val children = mutableListOf<Int>()
    var enter = 0

    fun addChild(child: Int) = children.add(child)

    fun answer(): String {
        val childrenNames = children.map { people[it].name }.sorted().joinToString(" ")
        return "$name ${children.size} $childrenNames"
    }
}