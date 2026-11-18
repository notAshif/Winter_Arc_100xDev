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

int MinimumElement(vector<int> &a, int n){
    if(n==0) return INT_MAX;

    int mn = MinimumElement(a, n - 1);
    return min(mn, a[n - 1]);
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x: a) cin >> x;

    cout << MinimumElement(a, n);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}