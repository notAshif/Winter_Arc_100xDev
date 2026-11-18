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

void Subsequences(int n, vector<int> &a, vector<int> &curr, vector<vector<int>> &ans, int idx){

    if(idx == n){
        ans.push_back(curr);
        return;
    }

    if(idx > n){
        return;
    }
    curr.push_back(a[idx]);
    Subsequences(n, a, curr, ans, idx + 1);
    curr.pop_back();

    Subsequences(n, a, curr, ans, idx + 1);
}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<int> curr;
    vector<vector<int>> ans;

    Subsequences(n, a, curr, ans, 0);

    for(auto &path: ans){
        for(auto &subS: path){
            cout << subS << " ";
        }
        cout << nl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}