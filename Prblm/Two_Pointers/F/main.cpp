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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int &x: a) cin >> x;

    int l = 0;
    int sum = 0;

    int ans = INF;

    for (int r = 0; r < n; r++){
        sum += a[r];

        while(sum > k){
            ans = min(ans, r - l + 1);
            sum -= a[l];
            l++;
        }

    }
    if(ans == INF){
        cout << -1 << nl;
        return;
    } else {
        cout << ans << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}