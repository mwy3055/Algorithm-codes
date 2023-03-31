from sys import stdin
input = stdin.readline


def solve(preorder: str, inorder: str) -> str:
    if len(preorder) <= 1:
        return preorder
    root = preorder[0]
    inorder_root_index = inorder.index(root)
    left = solve(preorder[1:inorder_root_index+1],
                 inorder[:inorder_root_index])
    right = solve(preorder[inorder_root_index+1:],
                  inorder[inorder_root_index+1:])
    return f'{left}{right}{root}'


while True:
    try:
        preorder, inorder = input().split()
        ans = solve(preorder, inorder)
        print(ans)
    except:
        break
