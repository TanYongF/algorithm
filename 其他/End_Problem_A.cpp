#include <iostream>
using namespace std;
int t;
int n, m;
int nums[1000][1000];
void solve(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			scanf("%d", &nums[i][j]);
		}
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			int value =  4 - (i == 0) - (j == 0) - (j == m-1) - (i == n-1);
			if(nums[i][j] > value){
				cout << "NO" << endl;
				return;
			}
			nums[i][j] = value;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(j < m-1) printf("%d ", nums[i][j]);
			else printf("%d\n", nums[i][j]);
		}

	}
	return 0;

}
int main(){
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
	
}