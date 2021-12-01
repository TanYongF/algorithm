#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long ans = 1;
    const int mod = 1e9+7;
    cin >> n;
    for(int i = 1; i <= n;i++){
        ans = (ans * 12) % mod;
    }
    cout << ans;
    return 0;
}