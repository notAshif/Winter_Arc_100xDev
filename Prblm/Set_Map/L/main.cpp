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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;

    map<int, int> mp;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    cin >> m;
    vector<int> b(m);

    vector<int> ans;

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        if (mp[b[i]] > 0)
        {
            ans.push_back(b[i]);
            mp[b[i]]--;
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}