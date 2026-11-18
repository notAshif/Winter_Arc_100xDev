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

int FirstOccurrence(vector<int> &a, int n, int x)
{
    if (n == 0)
        return -1;

    int ans = FirstOccurrence(a, n - 1, x);

    if (FirstOccurrence(a, n - 1, x) != -1)
    {
        return ans;
    }

    if (a[n - 1] == x)
    {
        return (n + 1)-1;
    }

    return -1;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int x;
    cin >> x;

    cout << FirstOccurrence(a, n, x);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}