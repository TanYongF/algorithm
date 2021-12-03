#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    long long ans = 1;
    const int mod = 1e9+7;
    cin >> n;
    ll oABA = 6, oABC = 6, nABA, nABC;
    for(int i = 2; i <= n; i++){
        nABC = (2 * oABC % mod + 2 * oABC % mod) % mod;
        nABA = (3 * oABA % mod + 2 * oABC % mod) % mod;
        oABC = nABC;
        oABA = nABA;
    }
    cout << (oABC + oABA) % mod << endl;
    return 0;
}