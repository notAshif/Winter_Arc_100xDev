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

const int FIRST_OCC = 1;
const int LAST_OCC = 2;

// using or boolean.
int getOcc(int a[], int n, int x, int config)
{
    int l = 0, r = n - 1;
    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] == x)
        {
            ans = mid;
            if (config == FIRST_OCC)
            {
                r = mid - 1;
            }
            else if (config == LAST_OCC)
            {
                l = mid + 1;
            }
        }
        else if (a[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

// // With two separate function.
// int getFirstOcc(int a[], int n, int x){
//     int l = 0;
//     int r= n - 1;
//     int ans = -1;

//     while(l<=r){
//         int mid = l + (r - l) / 2;

//         if(a[mid] == x){
//             ans = mid;
//             r = mid - 1;
//         }
//         else if(a[mid] < x){
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }
//     return ans;
// }

// int getLastOcc(int a[], int n, int x)
// {
//     int l = 0;
//     int r = n - 1;
//     int ans = -1;

//     while (l <= r)
//     {
//         int mid = l + (r - l) / 2;

//         if (a[mid] == x)
//         {
//             ans = mid;
//             l = mid + 1;
//         }
//         else if (a[mid] < x)
//         {
//             l = mid + 1;
//         }
//         else
//         {
//             r = mid - 1;
//         }
//     }
//     return ans;
// }

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while (q--)
    {
        int x;
        cin >> x;

        int first = getOcc(a.data(), n, x, 1);
        if (first == -1)
        {
            cout << -1 << nl;
            continue;
        }
        int last = getOcc(a.data(), n, x, 2);
        cout << first + 1 << " " << last + 1 << nl;
    }

    return 0;
}