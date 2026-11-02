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

    string s;
    cin >> s;

    int k = 26;
    int freq[k] = {};

    for (int i = 0; i < s.size(); i++){
        freq[s[i] - 'a']++;
    }
    string res;
    for (int i = 0; i < k; i++){
        if (freq[i] > 1)
        {
            res += char(i + 'a');
        }
    }

    if(res.empty()){
        cout << -1 << nl;
    } else {
        cout << res << nl;
    }

    return 0;
}