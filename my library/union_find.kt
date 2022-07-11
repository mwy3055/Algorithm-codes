class Union(val n: Int) {
    // 1-indexed
    private val parents = IntArray(n + 1) { it }

    fun get(node: Int): Int {
        if (parents[node] != node) {
            parents[node] = get(parents[node])
        }
        return parents[node]
    }

    fun union(p1: Int, p2: Int) {
        val (child, parent) = listOf(get(p1), get(p2)).sorted()
        parents[parent] = child
    }

    fun isConnected(p1: Int, p2: Int) = (get(p1) == get(p2))
}