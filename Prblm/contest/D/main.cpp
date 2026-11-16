#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nl '\n'

const int MOD = 1e9 + 7;
const int INF = 4e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << nl
#else
#define dbg(x)
#endif

int N = 200000;

vector<bool> prime(N + 1, true);
vector<int> freq(1000001, 0);

void sieve()
{
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

void solve()
{
    int q;
    cin >> q;

    sieve();

    int ans = 0;

    while (q--)
    {
        int tp;
        cin >> tp;

        if(tp == 4){
            cout << ans << nl;
            continue;
        }

        int x;
        cin >> x;

        if (prime[freq[x]])
        {
            ans--;
        }

        if (tp == 1){
            freq[x]++;
        } else if(tp == 2){
            if(freq[x] > 0){
                freq[x]--;
            }
        } else if(tp == 3){
            freq[x] = 0;
        }

        if (prime[freq[x]])
        {
            ans++;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}