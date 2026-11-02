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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vi ans(n,1);

    int l = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = l;
        l *= a[i];
    }

    int r = 1;
    for (int i = n-1; i >= 0; i--)
    {
        ans[i] *= r;
        r *= a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ((i == n - 1) ? nl : ' ');
    }

    return 0;
}