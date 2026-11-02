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

int factor_count(int n)
{
    int ans = 0;
    for (int i = 1; i * i <= n; i++){
        int f1, f2;

        if(n%i==0){
            f1 = i;
            f2 = n / i;
            
            if(f1 == f2){
                ans += 1;
            } else {
                ans += 2;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, k;
    cin >> n >> q >> k;

    vll p(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        p[i] = p[i - 1] + ((factor_count(x) == k) ? 1 : 0);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << p[r] - p[l - 1] << nl;
    }

    return 0;
}