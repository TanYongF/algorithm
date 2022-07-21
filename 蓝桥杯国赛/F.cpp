#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1005;
int T;
int N, M, K;

vector<int> monthDays = {31, 28,  31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int check(int fm, int fd, int em, int ed){
	if(fm == em){
		return ed - fd >= K;
	}else{
		int day = monthDays[fm] - fd + ed;
		for(int i = fm + 1;  i <= em - 1; i++) day += monthDays[i];
		return day >= K;
	}
}
bool cmp(vector<int> &a, vector<int>& b){
	if(a[0] == b[0]) return a[1] < b[1];
	else return a[0] < b[0];
}
int main(int argc, char * argv[]){
	cin >> N >> M >> K;
	vector<vector<int>> pages(MAXN, vector<int>(3, 0));
	int dp[N][M+1];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < N; i++){
		int month, day, val;
		cin >> month >> day >> val;
		pages[i][0] = month;
		pages[i][1] = day;
		pages[i][2] = val;
	}
	sort(pages.begin(), pages.begin() + N, cmp);
	// for(int i = 0; i < N; i++) cout << pages[i][0] << pages[i][1] << pages[i][2] << endl;
	for(int i = 0; i < N; i++){
		for(int j = pages[i][2]; j <= M; j++){
			if(i == 0) dp[i][j] = pages[i][2];
			else{
				int k;
				for(k = i-1; k >= 0; k--) if(check(pages[k][0], pages[k][1], pages[i][0], pages[i][1])) break;
				dp[i][j]=  dp[i-1][j];
				if(k < 0) dp[i][j] = max(dp[i][j], pages[i][2]);
				else dp[i][j] = max(dp[k][j-pages[i][2]] + pages[i][2],  dp[i][j]);  
			}
		}
	}
	cout << dp[N-1][M];
    return 0;
}