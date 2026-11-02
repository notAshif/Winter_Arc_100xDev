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

struct Flights
{
    int flightNumber;
    int departureTime;
    string destination;
};

bool cmp(Flights a, Flights b)
{
    if(a.departureTime != b.departureTime){
        return a.departureTime < b.departureTime;
    }
    return a.flightNumber < b.flightNumber;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Flights a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].flightNumber >> a[i].departureTime >> a[i].destination;
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
    {
        cout << a[i].flightNumber << " " << a[i].departureTime << " " << a[i].destination << nl;
    }
    return 0;
}