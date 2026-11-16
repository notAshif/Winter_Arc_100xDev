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

void solve()
{
    int n, q;
    cin >> n >> q;

    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    vector<int> pref(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        int lastdigit = x % 10;

        pref[i] = pref[i - 1];

        if(lastdigit == 1 or lastdigit == 7){
            pref[i]++;
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << pref[r] - pref[l - 1] << nl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}