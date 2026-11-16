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

    string s;
    cin >> s;

    unordered_map<char, int> mp;

    int l = 0;
    int ans = 0;

    for (int r = 0; r < n; r++){
        mp[s[r]]++;
        
        while(mp.size() > k)
        {
            mp[s[l]]--;
            if(mp[s[l]] == 0){
                mp.erase(s[l]);
            }
            l++;
        }

        ans = max(ans, r - l + 1);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}