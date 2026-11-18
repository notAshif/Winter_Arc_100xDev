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

void climb2(int n, int k, vector<int> &curr, vector<vector<int>> &ans, int pos){

    if(pos == n){
        ans.push_back(curr);
        return;
    }

    if(pos > n){
        return;
    }

    for (int i = 1; i <= k; i++){
        curr.push_back(i);
        climb2(n, k, curr, ans, pos + i);
        curr.pop_back();
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> curr;
    vector<vector<int>> ans;

    climb2(n, k, curr, ans, 0);

    for(auto &path: ans){
        for(auto &jump: path){
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