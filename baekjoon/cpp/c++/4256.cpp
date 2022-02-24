#include <bits/stdc++.h>

using vi = std::vector<int>;

// pre_idx: index of pre
// left, right are all indices [left, right)
void search(vi &pre_idx, vi &in_idx,
            vi &pre, int pre_left, int pre_right,
            vi &in, int in_left, int in_right,
            vi &post, int post_left, int post_right)
{
    if (post_left >= post_right)
        return;

    auto cur = pre[pre_left];

    auto left_len = in_idx[cur] - in_left;
    search(pre_idx, in_idx,
           pre, pre_left + 1, pre_left + 1 + left_len,
           in, in_left, in_idx[cur],
           post, post_left, post_left + left_len);

    auto right_len = in_right - in_idx[cur] - 1;
    search(pre_idx, in_idx,
           pre, pre_left + 1 + left_len, pre_right,
           in, in_idx[cur] + 1, in_right,
           post, post_left + left_len, post_right - 1);
    post[post_right - 1] = cur;
}

void solve(int n, vi &pre, vi &in)
{
    vi post(n);
    vi pre_idx(n + 1), in_idx(n + 1);
    for (int i = 0; i < n; i++)
    {
        pre_idx[pre[i]] = i;
        in_idx[in[i]] = i;
    }

    search(pre_idx, in_idx,
           pre, 0, n,
           in, 0, n,
           post, 0, n);

    for (auto &p : post)
        std::cout << p << ' ';
    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        vi preorder(n), inorder(n);
        for (int i = 0; i < n; i++)
            std::cin >> preorder[i];
        for (int i = 0; i < n; i++)
            std::cin >> inorder[i];
        solve(n, preorder, inorder);
    }
}