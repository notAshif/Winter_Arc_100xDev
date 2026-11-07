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

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        if (a[i] == 1)
        {
            cnt++;
        }
    }

    ans = min(k, cnt + 1);

    for (int i = k; i < n; i++)
    {
        if (a[i] == 1)
        {
            cnt++;
        }

        if (a[i - k] == 1)
        {
            cnt--;
        }
        ans = max(ans, min(k, cnt + 1));
    }
    cout << ans << nl;

    return 0;
}