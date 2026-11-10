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

int first_occurrence(vector<int> &a, int x)
{
    int l = 0;
    int r = a.size() - 1;

    int ans = a.size();

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] >= x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int last_occurrence(vector<int> &a, int y)
{
    int l = 0;
    int r = a.size() - 1;

    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] <= y)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

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
        int x, y;
        cin >> x >> y;

        if(x > y){
            cout << 0 << nl;
            continue;
        }

        int first = first_occurrence(a, x);
        int last = last_occurrence(a, y);
        cout << last - first + 1<< nl;
    }

    return 0;
}
