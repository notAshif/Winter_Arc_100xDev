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

    int n, x;
    cin >> n >> x;

    vector<int> A(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int need = x - A[i];
        if(mp.find(need) != mp.end()){
        
            count += mp[need];
        }
        mp[A[i]]++;
    }
    cout << count << nl;

    return 0;
}