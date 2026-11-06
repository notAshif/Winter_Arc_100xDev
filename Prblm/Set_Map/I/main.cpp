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

    unordered_map<char, int> mp;
    int pairs = 0;
    // int countO = 0;

    for(char ch: s){
        if(ch == 'O'){
            mp[ch]++;
            // countO++;
        } else if(ch == 'G'){
            pairs+=mp['O'];
            // pairs+=countO;
        }
    }
    cout << pairs << nl;

    return 0;
}