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

    map<int, int> freq;

    int c = 0;

    for (int i = 0; i < q; i++)
    {
        char op;
        cin >> op;

        if (op == '1')
        {
            int x;
            cin >> x;
            if (freq[x] == 0)
            {
                c++;
            }
            freq[x]++;
        }
        else if (op == '2')
        {
            int x;
            cin >> x;
            if (freq[x] > 0)
            {
                freq[x]--;
                if (freq[x] == 0)
                {
                    c--;
                }
            }
        }
        else if (op == '3')
        {
            int x;
            cin >> x;
            cout << freq[x] << nl;
        }
    }

    return 0;
}