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

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }

    map<int, int> mp;

    mp[0] = -1;

    int sum = 0,
        mx = 0, bestL = -1, bestR = -1;

    for (int i = 0; i < n; i++){
        sum += a[i];

        if(mp.count(sum)){
            int len = i - mp[sum];

            if(len > mx){
                mx = len;
                bestL = mp[sum] + 1;
                bestR = i;
            }
        } else {
            mp[sum] = i;
        }

    }
    
    if (bestL == -1){
        cout << -1 << nl;
        return;
    }

    for (int i = bestL; i <= bestR; i++){
        cout << a[i] << " ";
    }

    cout << nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}