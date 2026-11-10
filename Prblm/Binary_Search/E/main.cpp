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

    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] == x)
        {
            ans = mid;
            r = mid - 1;
        }
        else if (a[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int last_occurrence(vector<int> &a, int x)
{
    int l = 0;
    int r = a.size() - 1;

    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] == x)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (a[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

signed main() {
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

        int l = first_occurrence(a, x);
        if (l == -1)
        {
            cout << 0 << '\n';
            continue;
        }
        int r = last_occurrence(a, x);

        cout << r - l + 1 << '\n';
    }

    return 0;
}