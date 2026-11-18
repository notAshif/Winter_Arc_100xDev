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
n == 0 return;

if(a[3] == 7){
    cout <<3 4
}

*/

void indicesOfX(vector<int> &a, int n, int x, bool &found)
{
    if(n ==0) return;

    indicesOfX(a, n - 1, x, found);

    if(a[n-1] == x){
        found = true;
        cout << n << " ";
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x: a) cin >> x;

    int x;
    cin >> x;

    bool isFound = false;

    indicesOfX(a, n, x, isFound);
    
    if(!isFound){
        cout << -1;
        return;
    }

    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}