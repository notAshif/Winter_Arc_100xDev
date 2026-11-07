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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        st.insert(b[i]);
    }

    int cnt = 0;

    for (int i = 0; i < k; i++)
    {
        if (st.count(a[i]))
        {
            cnt++;
        }
    }

    cout << cnt << " ";

    for (int i = k; i < n; i++)
    {
        if (st.count(a[i]))
        {
            cnt++;
        }

        if (st.count(a[i - k]))
        {
            cnt--;
        }

        cout << cnt << " ";
    }

    cout << nl;

    return 0;
}