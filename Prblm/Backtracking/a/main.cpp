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

void ClimbStair(int n, vector<int> &curr, vector<vector<int>> &ans, int pos){

    if(pos == n){
        ans.push_back(curr);
        return;
    }

    if(pos > n){
        return;
    }

    for (int i = 1; i <= 2; i++){
        curr.push_back(i);
        ClimbStair(n, curr, ans, pos + i);
        curr.pop_back();
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> curr;
    vector<vector<int>> ans;

    ClimbStair(n, curr, ans, 0);

    for (auto &path : ans){
        for (auto &jump : path)
        {
            cout << jump << " ";
        }
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}