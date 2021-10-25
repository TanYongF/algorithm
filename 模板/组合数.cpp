const int maxn = 1000010;
ll mod = 1000000007;
//快速幂
ll qpow(ll a,ll x){
    ll ret=1;
    while (x){
        if (x&1)
            ret = ret*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return ret;
}
ll fac[maxn],inv[maxn];
 
ll init(){
    fac[0]=1;
    for (int i=1;i<maxn;i++)
        fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=qpow(fac[maxn-1],mod-2);
    for (int i=maxn-2;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
    return 0;
}
 //Cmn计算
ll c(ll n,ll m){
    if (n<m) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
//Amn计算
ll a(ll n, ll m){
    if(n<m) return 0;
    return fac[n]*inv[n-m]%mod;
}
//第二类斯特林数 i个不同元素划分成j个组合方法.
//https://oi-wiki.org/math/combinatorics/stirling/
ll Stirling[maxn][maxn];
void initS() {
    Stirling[0][0] = 0;
    Stirling[1][1] = 1;
    for(ll i = 2; i < maxn; i++) {
        for(ll j = 1; j <= i; j++) {
            Stirling[i][j] = (Stirling[i - 1][j - 1] + (j * Stirling[i - 1][j])%mod)%mod;
        }
    }
}