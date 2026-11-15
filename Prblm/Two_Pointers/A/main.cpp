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

/*

longest so -> its would in right we need (increasing order (my word for understanding))
k=8
sum < k

2 1 5 1 3

[2] = 1 => 1 < 8 true => not max len
[2 1] = 2 -> 2 < 8 true => not max len
[2 1 5] = 3 -> 8 < 8 false => max len

same above take 1, 2 len of sub with remove l ele
[1 5 1] = 3 -> 7 < 8 true max len

[5 1 3] = 3 -> 8 < 8 false max len
so on..

search in right and include in sum sum+=a[r];
search till condition is become true(sum < k);
we need ans is longest len so maximum of r - l + 1, what if only r;

*/

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int l = 0;
    int sum = 0;

    int ans = 0;
    for (int r = 0; r < n; r++){
        sum += a[r];

        while(sum >= k){
            sum -= a[l];
            l++;
        }

       ans = max(ans, r-l+1);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}