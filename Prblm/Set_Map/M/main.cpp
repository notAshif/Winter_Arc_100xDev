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

    int n;
    cin >> n;

    map<string, vector<string>> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    cout << mp.size() << '\n';
    for (auto &p : mp)
    {
        vector<string> &v = p.second;

        sort(v.begin(), v.end());

        cout << v.size() << " ";

        for (auto &g : v)
        {
            cout << g << " ";
        }
        cout << '\n';
    }

    return 0;
}