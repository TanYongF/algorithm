#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// 之差至少2 

const int maxn=1e5+10;
// const int mod=1e9;
ll a[maxn];
ll qmax[maxn];
ll qmin[maxn];
int m,n;
int main(){
    int n;
    ll b,c,k;
    // cin>>n>>k;
    cin >> n >> m ;
    // cin>>a[0]>>b>>c;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        // a[i]=(1ll*a[i-1]*b+c)%mod;
    }
    ll ans=0,l=1,h1=1,t1=0,h2=1,t2=0;
    while(m--){
        cin >> k;
        for(int i=1;i<=n;i++){
            while(h1<=t1&&a[i]>=a[qmax[t1]]) t1--;
            while(h2<=t2&&a[i]<=a[qmin[t2]]) t2--;
            qmax[++t1]=i;
            qmin[++t2]=i;
            while(h1<=t1&&h2<=t2&&a[qmax[h1]]-a[qmin[h2]]>k){
                ans+=n-i+1;//计算权值 
                l++;
                if(qmax[h1]<l) h1++;
                if(qmin[h2]<l) h2++;
            }
        }
        cout << ans<< endl;
    }

    // cout<<ans<<endl;
} 