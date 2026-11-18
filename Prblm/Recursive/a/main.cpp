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

void PrintDecreasing(int n)
{
    if(n == 0)
        return;
    cout << n <<nl;
    PrintDecreasing(n - 1);
}

void solve()
{
    int n;
    cin >> n;

    PrintDecreasing(n);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}