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
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    while(q--){
        int type, x;
        cin >> type >> x;


        if(type == 1){
            cout << upper_bound(a.begin(), a.end(), x) - lower_bound(a.begin(), a.end(), x) << nl;
        }

        if(type == 2){
            cout << lower_bound(a.begin(), a.end(), x) - a.begin() << nl;
        }

        if(type == 3){
            cout << a.end() - upper_bound(a.begin(), a.end(), x) << nl;
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}