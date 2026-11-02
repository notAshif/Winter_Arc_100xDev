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

    int q;
    cin >> q;

    map<int, int> freq;

    int c = 0;
    int dc = 0;

    for (int i = 0; i < q; i++)
    {
        char op;
        cin >> op;

        if (op == '1')
        {
            int x;
            cin >> x;
            if (freq[x] % 2 == 0)
            {
                dc++;
            }
            else
            {
                dc--;
            }
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
                if (freq[x] % 2 == 0)
                {
                    dc++;
                } else {
                    dc--;
                }
                freq[x]--;
                if (freq[x] == 0)
                {
                    c--;
                }
            }
        }
        else if (op == '3')
        {
            // int a, b;
            // cin >> a >> b;
            // if (freq[a] == freq[b])
            // {
            //     cout << "YES" << nl;
            // }
            // else
            // {
            //     cout << "NO" << nl;
            // }
            cout << dc << nl;
        }
    }

    return 0;
}