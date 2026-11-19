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

string mapping[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void KeyPad(string s, size_t idx, string &curr, vector<string> &ans){
    if(idx == s.size()){
        ans.push_back(curr);
        return;
    }

    int digits = s[idx]-'0';

    string chose = mapping[digits];

    for(char ch: chose){
        curr.push_back(ch);
        KeyPad(s, idx + 1, curr, ans);
        curr.pop_back();
    }
}

void solve() {
    string s;
    cin >> s;

    string curr;
    vector<string> ans;

    KeyPad(s, 0, curr, ans);

    cout << ans.size() << nl;
    for(auto s: ans){
        cout << s << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}