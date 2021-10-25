#include <iostream>
using namespace std;
int N = 0;
int euler[40001];
int main(){
	cin >> N;
	if(N == 0) cout << 0 << endl;
	for(int i = 1; i <= N; i++){
		euler[i] = i;
	}
	N--;
	for(int i = 2; i <= N; i++){
		if(euler[i] == i){ // 判断质数
			for(int j = i ; j <=N; j+=i){
				euler[j] = euler[j] / i * (i-1);
			}
		} 
	}
	int ans = 1;
	for(int i = 1; i <= N; i++){
		ans += euler[i] * 2;
	}
	cout << ans << endl;


	return 0;
}