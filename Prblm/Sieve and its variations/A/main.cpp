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
    int n;
    cin >> n;

    vector<vector<int>> factors(n + 1);

    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j+=i){
            factors[j].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++){
        for (int k = 0; k < (int)factors[i].size(); k++){
            cout << factors[i][k] << " ";
        }
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}