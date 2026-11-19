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

void generateParentheses(int n, int open, int close, string &curr, vector<string> &ans)
{

    if (open == n && close == n)
    {
        ans.push_back(curr);
        return;
    }

    if(open < n){
        curr.push_back('(');
        generateParentheses(n, open + 1, close, curr, ans);
        curr.pop_back();
    }

    if(open != close){
        curr.push_back(')');
        generateParentheses(n, open, close + 1, curr, ans);
        curr.pop_back();
    }
}

void solve() {
    int n;
    cin >> n;


    string curr;
    vector<string> ans;

    generateParentheses(n, 0, 0, curr, ans);
    cout << ans.size() << nl;
    for (auto seq : ans)
    {
        cout << seq << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}