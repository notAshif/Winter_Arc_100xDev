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

bool isPrime(int n)
{

    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cnt = 0;

    // first window
    for (int i = 0; i < k; i++)
    {
        if (isPrime(a[i]))
        {
            cnt++;
        }
    }

    int mx = cnt;
    int ans = 0;

    // second window
    for (int i = k; i < n; i++)
    {
        if (isPrime(a[i]))
        {
            cnt++;
        }

        if (isPrime(a[i - k]))
        {
            cnt--;
        }

        if (cnt > mx)
        {
            mx = cnt;
            ans = i - k + 1;
        }
    }

    for (int i = ans; i < ans + k; i++)
    {
        cout << a[i] << " ";
    }

    cout << '\n';

    return 0;
}