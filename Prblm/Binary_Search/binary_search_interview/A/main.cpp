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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int l = 0;
    int r = n;

    int ans = -1;

    while(l <= r){
        int mid = l + (r - l) / 2;

        if(mid == 0 || mid <= n/mid){
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << nl;

    return 0;
}

/*
n=6
mid = 0 + (6-0)/2 => 0 + 6/2 => 0+3 mid = 3;
3*3 <= 6 => 9 <= 3 //overflow
ans = 3
r = 3-1 => 2
l=3+1 => 4

n=10
mid 0+(10-0)/2 => 0+5 mid = 5

5/2 <= 10 => 3 <= 10 // not good
ans = 5
l = 5+1 => 6

n=10
mid = 0+(10-0)/2 => 5;
5 <= 10/5 => 5 <= 2 // false
ans = 5
r=5-1-> 4

mid => 0+(4-0)/4 => 2
2<=10/2 => 2<=5
ans = 2
l = 2+1 => 3

*/