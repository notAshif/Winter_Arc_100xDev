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

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    //Approach: 1
    // unordered_map<int, int> mp;

    // for(int x: a){
    //     mp[x]++;
    // }
    // cout << mp.size() << nl;

    // Approach: 2
    // set<int> st(a.begin(),a.end());
    // cout << st.size() << nl;

    //Approach: 3
    unordered_set<int> st(a.begin(), a.end());
    for(int x: a){
        st.insert(x);
    }
    cout << st.size() << nl;

    return 0;
}