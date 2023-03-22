#include<bits/stdc++.h>
using namespace std;
const int MAXM = 21;
int nums[MAXM];

int main(){
	int m, n;
	cin >> m >> n;
	int ans = INT_MAX;
	for(int i = 0; i < n; i++) cin >> nums[i];	
	for(int state = 0; state < (1 << n); state++){
		int idx = 0, sum = 0, use = 0;
		int curState = state;
		while(curState){
			if(curState & 1){
				use++;
				sum += nums[idx];
			}
			idx++;
			curState >>= 1;
		}
		if(sum == m) ans = min(ans, use);
	}
	ans == INT_MAX ? 0 : ans;
	cout << ans;
	return 0;
}