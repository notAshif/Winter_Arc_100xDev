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

    int n, m;
    cin >> n;

    set<int> st;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        st.insert(b[i]);
    }

    cout << st.size() << nl;

    for(int x : st){
        cout << x << " ";
    }
    return 0;
}