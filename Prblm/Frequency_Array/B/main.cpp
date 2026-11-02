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

    string s;
    cin >> s;
 
    int freq[10] = {};

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - '0']++;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << freq[i];

        if (i < 9)
            cout << ' ';
    }
    cout << nl;

    return 0;
}