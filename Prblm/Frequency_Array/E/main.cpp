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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> res;
    for (int i = 1; i < n; i++){
        if(a[i] == a[i-1]){
            if(i == 1 || a[i] != a[i-2]){
                res.push_back(a[i]);
            }
        }
    }

    if(res.empty()){
        cout << -1 << nl;
    } else {
        for (int i = 0; i < res.size(); i++){
            if(i > 0)
                cout << ' ';
            cout << res[i];
        }
        cout << nl;
    }

    return 0;
}