#include <iostream>
#include <cstring>
using namespace std;
int T , N, K;
const int MAXN = 1000001;
int nums[MAXN];
int preAdd[MAXN+1];
int res_left = 1000002, res_right = 1000002;
int cur_len = 1000003;
int main(){
	cin >> T;
	while(T--){
		cin >> N >> K;
		int num;
		preAdd[0] = 0;
		res_left = 1000002;
		res_right = 1000002;
		cur_len = 1000003;

		for (int i = 0; i < N; ++i){
			cin >> num;
			preAdd[i+1] = preAdd[i]^num; 
			for(int j = i; j >= 0 ; j--){
				if((preAdd[i+1] ^ preAdd[j])>= K){
					if((i-j) < cur_len || ( ((i-j) == cur_len) && j + 1 < res_left)){
						res_left = j+1;
						res_right= i+1;
						cur_len = (i-j);
						break;
					}
				}
			}
		}
		if(res_left == 1000002) cout << -1 << endl;
		else cout << res_left << " " << res_right << endl;
	}
	return 0;

}
int main)({