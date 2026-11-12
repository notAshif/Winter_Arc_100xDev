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

bool isPossible(vector<int> &a, int h, int w){
    int waterReq = 0;
    int n = a.size();
    for (int i = 0; i < n; i++){
        if(a[i] <= h){
            waterReq += h - a[i];
        }
    }
    return waterReq <= w;
}

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int l = *min_element(a.begin(), a.end());
    int r = *max_element(a.begin(), a.end())+x;

    int ans = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;

        if(isPossible(a, mid, x)){
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}