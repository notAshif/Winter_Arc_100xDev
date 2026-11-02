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

    vector<string> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    
    string x;
    cin >> x;

    int l = 0;
    int r = n - 1;
    bool found = false;
    while(l <=r){

        int mid = (l + r) / 2;
        if(s[mid] == x){
            found = true;
            break;
        } else if (s[mid] < x){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if(found){
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }

    return 0;
}