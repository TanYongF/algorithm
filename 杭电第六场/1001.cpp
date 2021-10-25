#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn (2 * 10000005)
#define mem memset
using namespace std;
int prime[maxn] = {0};
int visit[maxn] = {0};
void Prime() {
    for (int i = 2; i <= maxn; i++) {
        if (!visit[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= maxn; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
int main()
{
    int t;
    bool isfu = false;
    long long res= 1;
    scanf("%d", &t);
    Prime();
    while (t--)
    {
        int n;
    	int cur;
        res = 1;
        isfu = false;
        scanf("%d", &n);
        if (n == 0) {printf("3\n"); continue;}
        else if(n==1){printf("2\n"); continue;}
        else if(n < 0){
        	n = -n;
    		res = 2 * n + 1;
    		n = n+1;
    		isfu = true;
    		res++;
        }

        if(visit[n] == 0) {cout << res << endl; continue;}
        else if( !isfu && (visit[n+n+1] ==0 || visit[n+n-1] == 0)) {cout << 2 << endl; continue;}
        else if(isfu && visit[n+n+1] == 0) {cout << res + 1 << endl; continue;}
        else{
        	if(!isfu) res += 2 * n;
        	else  res += 1;
			cur = n + 1;
        	while(true){
        		if(visit[cur] == 0){
        			res += 1;
        			break;
        		}else if(visit[cur + cur + 1] == 0){
        			res += 2;
        			break;
        		}else{
        			res += 2;
        			cur = cur + 1;
        		}
        	}
        }
        cout << res << endl;
    }
    return 0;
}