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

unordered_map<int, int> mp;

bool insert_x(int x)
{
    mp[x]++;

    return mp[x] == 1;
}

bool remove_x(int x)
{
    mp[x]--;

    if (mp[x] == 0)
    {
        mp.erase(x);
        return true;
    }
    return false;
}
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

    int cnt = 0;

    for (int i = 0; i < k; i++)
    {
        if (insert_x(a[i]))
        {
            cnt++;
        }
    }

    cout << cnt << " ";

    for (int i = k; i < n; i++)
    {
        if (insert_x(a[i]))
        {
            cnt++;
        }

        if (remove_x(a[i - k]))
        {
            cnt--;
        }

        cout << cnt << " ";
    }

    cout << nl;

    return 0;
}