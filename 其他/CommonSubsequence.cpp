#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1000][1000];
char s1[1000];
char s2[1000];
int getmax(int a,int b)
{if(a>b)return a;else return b;}

int main(){
	while(scanf("%s%s", s1+1, s2+1) != EOF){
		s1[0] = s2[0]  = '1';
		int length1 = strlen(s1);
		int length2 = strlen(s2);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i < length1; ++i)
		{
			for (int j = 1; j < length2; ++j)
			{
				if(s1[i] == s2[j]){
					dp[i][j] = getmax(dp[i-1][j-1],dp[i-1][j-1] + 1);
				}else{
					dp[i][j] = getmax(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		printf("%d\n", dp[length1-1][length2-1]);
	}
	return 0;
}