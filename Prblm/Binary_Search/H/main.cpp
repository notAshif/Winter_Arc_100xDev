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

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    while(q--){
        int x;
        cin >> x;

        int l = 0, r = n-1;
        int ans = -1;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(a[mid] >= x){
                ans = a[mid];
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << nl;
    }

    return 0;
}
/*
n=6 q=6
a=[1, 3, 5, 7, 7, 10]  5 1 7 7 3 10
x=2
1
2
6
7
11
-5

l=3 r=5;

mid=3+(5-3)/2 => 3+2/2 => 4; a[4]=7
if(7 >= 2){
    ans=4;
    r = 4-1;
    r=3
}


*/