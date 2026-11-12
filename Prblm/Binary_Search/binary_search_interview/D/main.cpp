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

bool isPossible(vector<int> &board, int k, int time)
{
    int reqUnitTime = 1;
    int totalLen = board[0];

    for (int i = 1; i < board.size(); i++)
    {
        if (totalLen + board[i] <= time)
        {
            totalLen += board[i];
        }
        else
        {
            reqUnitTime++;
            totalLen = board[i];
        }
    }
    return reqUnitTime <= k;
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

    return 0;
}