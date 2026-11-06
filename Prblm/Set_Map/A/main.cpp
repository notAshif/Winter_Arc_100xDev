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

    int q;
    cin >> q;

    unordered_map<int, int> mp;

    while(q--){
        int type, x;
        cin >> type >> x;

        // if (type == 1)
        // {
        //     mp[x]++;
        // }
        // else if (type == 2)
        // {
        //     if(mp[x] > 0){
        //         mp[x]--;
        //     }
        // }
        // else
        // {
        //     cout << mp[x] << nl;
        // }


        if(type == 1){
            if(mp.find(x) == mp.end()){
                mp.insert({x, 1});
            } else{
                mp[x]++;
            }
        } else if(type == 2){
            if (mp.find(x) != mp.end()){

                mp[x]--;

                if (mp[x] == 0)
                {
                    mp.erase(x);
                }
            }
        } else {
            cout << (mp.find(x) != mp.end() ? mp[x] : 0) << nl;
        }

    }
    return 0;
}