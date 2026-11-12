#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'

const int MOD = 1e9 + 7;
const int INF = 4e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << nl
#else
#define dbg(x)
#endif

bool isPossible(vector<int> &pages, int s, int Book_limit)
{
    int studentReq = 1;
    int PageReq = pages[0];
    int n = pages.size();
    for (int i = 1; i < n; i++)
    {
        if (PageReq + pages[i] > Book_limit)
        {
            studentReq++;
            PageReq = pages[i];
        }
        else
        {
            PageReq += pages[i];
        }
    }
    return (studentReq <= s);
}

void solve()
{
    int n, k;
    cin >> n >> k;

    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    if (k > n){
        cout << -1 << nl;
        return;
    }

    int l = *max_element(a.begin(), a.end());
    int r = accumulate(a.begin(), a.end(), 0LL);

    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (isPossible(a, k, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;

    // while (t--)
    // {
    //     solve();
    // }
    solve();

    return 0;
}