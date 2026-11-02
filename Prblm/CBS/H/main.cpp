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

struct Stocks
{
    string stockName;
    int price;
    int marketCap;
};

bool cmp(Stocks a, Stocks b)
{
    if(a.price != b.price){
        return a.price < b.price;
    }

    if (a.marketCap != b.marketCap)
    {
        return a.marketCap > b.marketCap;
    }
    return a.stockName < b.stockName;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Stocks a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].stockName >> a[i].price >> a[i].marketCap;
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
    {
        cout << a[i].stockName << " " << a[i].price << " " << a[i].marketCap << nl;
    }
    return 0;
}