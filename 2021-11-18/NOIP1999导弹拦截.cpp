#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 1e5+10; 
int nums[MAXN];
int deep[MAXN], up[MAXN];
bool cmp(int a, int b) {return a > b;}
int main(){
	memset(nums,0, sizeof(nums));
	memset(deep,0, sizeof(deep));
	memset(up,0, sizeof(up));
	int n = 0, len = 0, need = 0;
	while(cin >> nums[n]){n++;}
	// cout << n << endl;
	// n = 8;
	deep[0] = nums[0]; up[0] = nums[0];
	for(int i = 1; i < n; i++){
		if(nums[i] <= deep[len]) deep[++len] = nums[i];
		else deep[upper_bound(deep, deep + len + 1, nums[i], cmp) - deep] = nums[i];
		if(nums[i] > up[need]) up[++need] = nums[i];
		else up[lower_bound(up, up + need + 1, nums[i]) - up] = nums[i];	
	}
	// for(int i = 0; i <= len; i++) cout << deep[i] << " ";
	// 	cout << endl;
	// for(int i =0; i<= need; i++) cout << up[i] << " ";
	// 	cout << endl;
	cout << len + 1<< " " << need + 1;	
	return 0;



	// cout << 1;

}
