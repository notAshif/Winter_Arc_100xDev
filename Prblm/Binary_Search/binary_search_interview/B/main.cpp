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


bool isPossible(vector<int> &weight, int d, int capacity){
    int dayReq = 1;
    int currWt = weight[0];

    for (int i = 1; i < weight.size(); i++){
        if(currWt + weight[i] <= capacity){
            currWt += weight[i];
        } else {
            dayReq++;
            currWt = weight[i];
        }
    }
    return dayReq <= d;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = *max_element(a.begin(), a.end());
    int r = accumulate(a.begin(), a.end(), 0LL);

    int ans = -1;

    while(l <= r){
        int mid = l + (r - l) / 2;

        if(isPossible(a, d, mid)){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << nl;

    return 0;
}