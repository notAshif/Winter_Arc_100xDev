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

bool isVowels(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        if (isVowels(s[i]))
        {
            cnt++;
        }
    }

    cout << cnt << " ";

    // second window
    for (int i = k; i < n; i++)
    {
        if (isVowels(s[i]))
        {
            cnt++;
        }
        if (isVowels(s[i - k]))
        {
            cnt--;
        }
        cout << cnt << " ";
    }

    cout << nl;

    return 0;
}