#include <iostream>
using namespace std;
int a[2 * 100000 + 10];
int fb[2 * 100000 + 10];
int mod = 1e9 + 7;

//生成n！数组
void fbs(){
	fb[0] = fb[1] = 1;
	for(int i = 2; i < 2 * 100000 + 1; i++){
		fb[i] = (long long )fb[i-1] * i % mod;
	}
}
int main(){

	fbs();
	int length ;
	cin >> length;
	int nums;
	while(length --){
		cin >> nums;
		int cns = 0;
		int ans = 0xffffffff;
		for(int i = 0; i < nums; i++){
			cin >> a[i];
			ans &= a[i];
		}
		for(int i= 0; i< nums; i++){
			if(a[i] - ans == 0){
				cns++;
			}
		}
		cout << (long long)cns *  (cns - 1) % mod  * fb[nums - 2] % mod << endl;
	}
	return 0;
}