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

void TOH(int n, char src, char aux, char dest){

    if(n==0) return;

    TOH(n - 1, src, dest, aux);
    cout << "Move " << src << " to " << dest << nl;
    TOH(n - 1, aux, src, dest);
}

void solve() {
    int n;
    cin >> n;

    TOH(n, 'A', 'B', 'C');
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}