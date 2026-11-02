#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
#define nl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << nl
#else
#define dbg(x)
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vi a(n + 1, 0);
    vll p(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        int m = (i > 1 && a[i] == a[i - 1] ? 1 : 0);
        p[i] = p[i - 1] + m;
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << (p[r] - p[l])<< nl;
    }

    return 0;
}