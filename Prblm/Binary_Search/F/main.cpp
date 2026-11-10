#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'
#define el endl

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

    int l = 1;
    int r = n;

    int ans = n+1;

    while(l <= r){

        int mid = l + (r - l) / 2;

        cout << "? " << mid << nl << flush;

        char ch;
        cin >> ch;

        if(ch == 'T'){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << "! " << ans << el << flush;

    return 0;
}