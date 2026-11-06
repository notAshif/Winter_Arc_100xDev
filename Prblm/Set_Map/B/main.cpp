#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << nl
#else
#define dbg(x)
#endif

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    unordered_map<int, int> mp;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]] = i + 1;
    }

    while(q--){
        int x;
        cin >> x;

        if(mp.find(x) != mp.end()){
            cout << mp[x] << nl;
        } else {
            cout << -1 << nl;
        }
    }

    return 0;
}