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

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    while (q--)
    {
        int x;
        cin >> x;

        int l = 0, r = n - 1;
        int ans = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (a[mid] <= x)
            {
                ans = a[mid];
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        cout << ans << nl;
    }

    return 0;
}
