#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << nl
#else
#define dbg(x)
#endif

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, t;
    cin >> n >> k >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // first window
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    if (sum >= k * t)
    {
        cnt++;
    }

    // second window
    for (int i = k; i < n; i++)
    {
        sum += a[i];
        sum -= a[i - k];
        if (sum >= k * t)
        {
            cnt++;
        }
    }
    cout << cnt << nl;

    return 0;
}