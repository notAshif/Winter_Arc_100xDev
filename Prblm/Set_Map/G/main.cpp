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

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++){
        int sum = x - a[i];

        if (mp.find(sum) != mp.end())
        {
            cout << mp[sum] + 1 << " " << i+1 << nl;
            return 0;
        }
        mp[a[i]]=i;
    }
    cout << -1 << nl;
    return 0;
}