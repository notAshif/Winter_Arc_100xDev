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

struct Plane
{
    int p1;
    int p2;
    
};

bool cmp(Plane a, Plane b)
{
    if (a.p1 != b.p1)
    {
        return a.p1 < b.p1;
    }
    return a.p2 < b.p2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Plane a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].p1 >> a[i].p2;
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
    {
        cout << a[i].p1 << " " << a[i].p2 << nl;
    }
    return 0;
}