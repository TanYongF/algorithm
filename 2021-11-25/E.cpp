#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long LL;
const int maxn= 1e5+100;
int dp1[maxn];//升序
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		int i,a;
		cin>>n;
		int ans=INF;
		memset(dp1,0,sizeof dp1);
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			dp1[a]=max(dp1[a],dp1[a-1]+1);
			ans=min(ans,n-dp1[a]);
		}
		cout<<ans<<endl;
	}
	return 0;
}