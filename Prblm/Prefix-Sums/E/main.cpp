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

int digitSums(int n){
    int ans = 0;
    while(n > 0){
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, k;
    cin >> n >> q >> k;

    vll p(n+1, 0);
    for (int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        p[i] = p[i - 1] + ((digitSums(x) == k) ? 1 : 0);
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << p[r] - p[l - 1] << nl;
    }

    return 0;
}