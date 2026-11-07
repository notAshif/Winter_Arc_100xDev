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

    // first window for sum of subarr
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }

    int mx = sum;
    // second window for find the max of size k
    for (int i = k; i < n; i++)
    {
        sum += a[i];
        sum -= a[i - k];
        mx = max(mx, sum);
    }
    cout << mx << nl;

    return 0;
}