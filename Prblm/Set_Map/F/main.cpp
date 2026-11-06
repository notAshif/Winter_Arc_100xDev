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

    int n, x;
    cin >> n >> x;

    
    vector<int> a(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // int sum = 0;
    // for (int i = 0; i < n; i++){
    //     for (int j = i + 1; j < n; j++){
    //         sum = a[i] + a[j];
    //         if(sum == x){
    //             cout << "TRUE" << nl;
    //             return 0;
    //         }
    //     }
    // }
    for (int i = 1; i < n; i++){
        int sum = x - a[i];
        if(mp.find(sum) != mp.end()){
            cout << "TRUE" << nl;
            return 0;
        }
        mp[a[i]]++;
    }
    cout << "FALSE" << nl;

    return 0;
}