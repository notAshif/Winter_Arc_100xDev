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

bool isPossible(vector<int> &p, int hour, int speed)
{
    int takeHours = 0;
    for (int pile:p){
        if (pile % speed == 0)
        {
            takeHours += pile / speed;
        }
        else
        {
            takeHours += (pile / speed) + 1;
        }
    }
    return takeHours <= hour;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int l = 1;
    int r = *max_element(a.begin(), a.end());

    int ans = -1;

    while(l <= r){
        int mid = l + (r - l) / 2;

        if(isPossible(a, h, mid)){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << nl;

    return 0;
}