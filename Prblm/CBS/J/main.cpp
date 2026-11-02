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

/*
\[
d=\sqrt{(x-r_x)^2+(y-r_y)^2}
\]
*/

//Create a function. of distance formula for best practices

struct Points
{
    int x, y;
};

int rx, ry;

bool cmp(Points a, Points b)
{
    long long d1 = 1LL * (a.x - rx) * (a.x - rx) + 1LL * (a.y - ry) * (a.y - ry);
    long long d2 = 1LL * (b.x - rx) * (b.x - rx) + 1LL * (b.y - ry) * (b.y - ry);

    if(d1 != d2){
        return d1 < d2;
    }

    if(a.x != b.x){
        return a.x < b.x;
    }

    return a.y < b.y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> rx >> ry;

    Points a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
    {
        cout << a[i].x << " " << a[i].y << nl;
    }

    return 0;
}