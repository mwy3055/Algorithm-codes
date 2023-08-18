import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline


def solve(left_in, right_in, left_post, right_post):  # [left, right)
    global inorder, postorder, inorder_index

    length, length2 = right_in-left_in, right_post-left_post
    if length <= 0 or length2 <= 0:
        return

    root = postorder[right_post-1]
    print('== ans == %d' % root)

    if right_in-left_in <= 1:
        return

    idx_in = inorder_index[root]
    solve(left_in, idx_in, left_post, left_post+(idx_in-left_in))
    solve(idx_in+1, right_in, left_post+(idx_in-left_in), right_post-1)


n = int(input())
inorder = list(map(int, input().split()))
inorder_index = [0 for _ in range(n+1)]
for i, node in enumerate(inorder):
    inorder_index[node] = i
postorder = list(map(int, input().split()))

solve(0, n, 0, n)
