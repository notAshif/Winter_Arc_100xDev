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
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    unordered_map<int, int> mp;

    int l = 0, cnt = 0;
    for (int i = 0; i < n; i++){
        mp[a[i]]++;
        while(mp.size() > k){
            mp[a[l]]--;
            if(mp[a[l]] == 0){
                mp.erase(a[l]);
            }
            l++;
        }

        cnt += (i - l + 1);
    }
    cout << cnt << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}