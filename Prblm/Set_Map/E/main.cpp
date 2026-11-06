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

    unordered_multiset<int> mst;
    int count = 0;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            if (mst.find(x) == mst.end())
            {
                count++;
            }
            mst.insert(x);
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            auto it = mst.find(x);
            if (it != mst.end())
            {
                mst.erase(it);
                if(mst.find(x) == mst.end()){
                    count--;
                }
            }
        }
        else if (type == 3)
        {
            cout << count << nl;
        }
        else if (type == 4)
        {
            int x;
            cin >> x;
            cout << (mst.find(x) != mst.end() ? "YES" : "NO") << nl;
        }
    }

    return 0;
}