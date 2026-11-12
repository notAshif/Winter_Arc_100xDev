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

bool isPossible(vector<int> words, int width, int l)
{
    int lineUsed = 1, spaceUsed = words[0];

    for (int i = 1; i < words.size(); i++)
    {
        if (spaceUsed + 1 + words[i] <= width)
        {
            spaceUsed += (1 + words[i]);
        }
        else
        {
            lineUsed++;
            spaceUsed = words[i];
        }
    }

    return lineUsed <= l;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = *max_element(a.begin(), a.end());
    int r = accumulate(a.begin(), a.end(), 0LL) + n-1;

    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (isPossible(a, mid, m))
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;

    // while (t--) {
    //     solve();
    // }

    solve();

    return 0;
}