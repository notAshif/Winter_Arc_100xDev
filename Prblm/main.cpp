#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += (long long)a[i]*(i+1)*(n-i);
    }
    cout << sum << " ";
    return 0;
}
