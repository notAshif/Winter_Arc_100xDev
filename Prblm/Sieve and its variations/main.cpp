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
    int q;
    cin >> q;

    unordered_map<int, int> mp;

    int ans = 0;

    while(q--){
        string t;
        cin >> t;

        if(t == "vote"){
            int m;
            cin >> m;
            mp[m]++;
        } else if(t == "withdraw"){
            int m;
            cin >> m;

            auto it = mp.find(m);
            if(it != mp.end()){
                if(--it->second == 0) mp.erase(it); // mp[m]--;
            }

        } else if(t == "check"){
            int m;
            cin >> m;
            auto it = mp.find(m);
            cout << (it == mp.end() ? 0 : it->second) << nl;
        } else if(t == "active"){
            cout << mp.size() << nl;
        }
    }

    int x = 1;
    int cnt = 0;

    for(auto &[id, c]: mp){
        if(c > cnt || (c == cnt && id < x)){
            cnt = c;
            x = id;
        }
    }
    cout << "movie for tonight is " << x << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}