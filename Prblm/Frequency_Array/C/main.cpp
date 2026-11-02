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

    string s, t;
    cin >> s >> t;

    int k = 26;
    int freq[k] = {};

    for(char ch : s){
        freq[ch - 'a']++;
    }

    for (char ch : t)
    {
        freq[ch - 'a']--;
    }

    for (int i = 0; i < k;i++){
        if(freq[i] != 0){
            cout << "NO" << nl;
            return 0;
        }
    }
    cout << "YES" << nl;

    return 0;
}