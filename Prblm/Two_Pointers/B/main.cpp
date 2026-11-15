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

/*
8
abcabcbb



find longest substr without duplicate char.

[a] -> 1
[a b] -> 2
[a b c] -> 3

so on..

*/

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;

    unordered_map<char, int> mp;

    int l = 0;

    for (int r = 0; r < n; r++){

        mp[s[r]]++;

        while (mp[s[r]] > 1)
        {
            mp[s[l]]--;
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