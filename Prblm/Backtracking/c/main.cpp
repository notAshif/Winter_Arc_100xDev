#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'

const int MOD = 1e9 + 7;
const int INF = 4e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << nl
#else
#define dbg(x)
#endif

void PrintPath(int x, int y, vector<char> &curr, vector<vector<char>> &ans, int n, int m)
{

    if (x == n - 1 && y == m - 1)
    {
        ans.push_back(curr);
        return;
    }

    if (x >= n || y >= m)
    {
        return;
    }

    // move right
    curr.push_back('R');
    PrintPath(x, y + 1, curr, ans, n, m);
    curr.pop_back();

    // move down
    curr.push_back('D');
    PrintPath(x + 1, y, curr, ans, n, m);
    curr.pop_back();
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<char> curr;
    vector<vector<char>> ans;

    PrintPath(0, 0, curr, ans, n, m);

    for (auto &path : ans)
    {
        for (char move : path)
        {
            cout << move;
        }
        cout << nl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}