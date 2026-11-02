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

//A
// string classify(int n)
// {
//     int sum = 0;
//     for (int i = 1; i*i <= n; i++){
//         if(n%i==0){
//            if(i < n){
//                sum += i;
//            }

//            int m = n / i;
//            if(m!=i && m < n){
//                sum += m;
//            }
//         }
//     }
    
//     if(sum == n){
//         return "Perfect";
//     }
//     else if (sum > n)
//     {
//         return "Abundant";
//     } else {
//         return "Deficient";
//     }
// }

//B
// long long countPrettyPieces(vector<int> &colours)
// {
//     int ans = 0;
//     int n = colours.size();
//     for (int l = 0; l < n; l++){
//         for (int r = l; r < n; r++){
//             if(colours[l] == colours[r]){
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }

//C
// vector<bool> balancedQueries(string &s, vector<vector<int>> &queries)
// {
//     int n = s.size();

//     vector<int> pre(n + 1, 0);
//     for (int i = 0; i < n; i++){
//         if(s[i] == '1'){
//             pre[i + 1] = pre[i] + 1;
//         } else {
//             pre[i + 1] = pre[i] - 1;
//         }
//     }

//     vector<bool> ans;
//     for(auto &q: queries){
//         int l = q[0];
//         int r = q[1];

//         ans.push_back(pre[r] - pre[l - 1] == 0);
//     }
//     return ans;
// }

//D
// int countDarkSpots(vector<int> &power)
// {
//     int n = power.size();
//     vector<int> diff(n+1, 0);
//     for (int i = 0; i < n; i++){
//         if(power[i] == 0){
//             continue;
//         }
        
//         int l = max(0, i - power[i]);
//         int r = min(n - 1, i + power[i]);

//         diff[l]++;
//         diff[r + 1]--;
//     }
    
//     int c = 0;
//     int a = 0;
//     for (int i = 0; i < n; i++){
//         a += diff[i];

//         if(a == 0)
//             c++;
//     }
//     return c;
// }


//E
// vector<int> countCriticalPoints(vector<int> &a, vector<vector<int>> &queries)
// {
//     int n = a.size();
//     vector<int> pre(n, 0);
//     for (int i = 1; i < n - 1; i++)
//     {
//         int m = (a[i] > a[i - 1] && a[i] > a[i + 1]) ||
//                 (a[i] < a[i - 1] && a[i] < a[i + 1]);
//         pre[i] = pre[i - 1] + m;
//     }

//     vector<int> ans;
//     for (auto &q : queries)
//     {
//         int l = q[0];
//         int r = q[1];
//         if(r-l <= 1){
//             ans.push_back(0);
//             continue;
//         }
//         ans.push_back(pre[r - 2] - pre[l - 1]);
//     }
//     return ans;
// }

//F
long long countPrettyPieces(vector<int> &colours)
{
    int n = colours.size();
    unordered_map<int, long long> f;
    
    long long ans = 0;
    for (int i = 0; i < n; i++){
        ans += f[colours[i]] + 1;
        f[colours[i]]++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> colours(n);
    for (int i = 0; i < n; i++)
        cin >> colours[i];

    cout << countPrettyPieces(colours) << '\n';

    return 0;
}