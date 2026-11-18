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

void PrintPath2(int x, int y, vector<char> &curr, vector<vector<char>> &ans, vector<vector<int>> &grid, int n, int m)
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
    if (y + 1 < m && grid[x][y + 1] == 0)
    {
        curr.push_back('R');
        PrintPath2(x, y + 1, curr, ans, grid, n, m);
        curr.pop_back();
    }

    // move down
    if (x + 1 < n && grid[x + 1][y] == 0)
    {
        curr.push_back('D');
        PrintPath2(x + 1, y, curr, ans, grid, n, m);
        curr.pop_back();
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<char> curr;
    vector<vector<char>> ans;

    PrintPath2(0, 0, curr, ans, matrix, n, m);

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