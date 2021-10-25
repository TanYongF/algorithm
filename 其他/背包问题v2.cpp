#include <iostream>
using namespace std;
const int maxv=50001;
const int maxn = 20001;
int w[maxn],v[maxn],num[maxn];
int dp[maxv];
int main()
{
	int n,W,w1,v1,num1,cnt=0;
	cin>>n>>W;
	for(int i=0; i < n; i++)
	{
		scanf("%d %d %d",&w1, &v1, &num1);
		for(int k=1; k <= num1; k <<= 1)
		{
			//分解
			w[cnt] = k * w1;
			v[cnt++] = k * v1;
			num1 -= k;
		}
		if(num1 > 0)
		{
			w[cnt]=num1*w1;
			v[cnt++]=num1*v1;
		}
	}
	for(int i = 0;i < cnt;i++)	
	{
		for(int j=W;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	}
	cout << dp[W];
	return 0;
} 
