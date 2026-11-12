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

bool isPossible(vector<int> stalls, int cows, int distance){
    int prev = stalls[0], cowPlaced = 1;

    for (int i = 1; i < stalls.size(); i++){
        if(stalls[i]-prev >= distance){
            prev = stalls[i];
            cowPlaced++;
        }
    }
    return cowPlaced >= cows;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int l = 0;
    int r = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());

    int ans = -1;

    while(l<=r){
        int mid = l + (r - l) / 2;

        if(isPossible(a, k, mid)){
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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