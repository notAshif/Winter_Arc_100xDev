#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
#define nl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << nl
#else
#define dbg(x)
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vi a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int leftEvenSum = 0;
    int leftOddSum = 0;

    int rightEvenSum = 0;
    int rightOddSum = 0;

    ll c = 0;

    for (int i = 0; i < n; i++){
        if(i % 2 == 0){
            rightEvenSum += a[i];
        } else {
            rightOddSum += a[i];
        }
    }

    for (int i = 0; i < n; i++){
        if(i % 2==0){
            rightEvenSum -= a[i];
        } else {
            rightOddSum -= a[i];
        }

        int sumOdd = leftEvenSum + rightOddSum;
        int sumEven = leftOddSum + rightEvenSum;

        if(sumOdd == sumEven){
            c++;
        }

        if(i % 2 == 0){
            leftEvenSum += a[i];
        } else {
            leftOddSum += a[i];
        }
    }
    cout << c << nl;
    return 0;
}
