#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
#define nl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << nl
#else
#define dbg(x)
#endif

struct Amazon
{
    int orderId;
    int timestamp;
    int priority;
};

bool cmp(Amazon a, Amazon b)
{
    if (a.priority != b.priority)
    {
        return a.priority > b.priority;
    }

    if (a.timestamp != b.timestamp)
    {
        return a.timestamp < b.timestamp;
    }
    return a.orderId < b.orderId;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Amazon a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].orderId >> a[i].timestamp >> a[i].priority;
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
    {
        cout << a[i].orderId << " " << a[i].timestamp << " " << a[i].priority << nl;
    }
    return 0;
}