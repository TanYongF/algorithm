#include <iostream>
using namespace std;
const int maxl = 100000;
#define int long long
long long maxn = 1e15;
int nums[maxl], k;
long n;
//查找如果n的最大切题数
int check(long long x){
	int result = 0;
	int sum    = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += nums[i];
		if(sum >= x){
			sum = 0;
			result++;
		}
		if(sum < 0){ 
			sum = 0;
		} 
	}
	return result;
}
//二分
signed main(){
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	int ans = -1;
	int l = 1;
	int r = maxn;
	int mid = 0;
	//最大
	while(l <= r){
		mid = (l + r) >> 1;
		if (check(mid) > k)
		{
			l = mid + 1;
		}else if(check(mid) < k){
			r = mid - 1;
		}else{
			ans = mid;
			r = mid - 1;
		}

	}
	if (ans != -1)
	{
		cout << ans << " ";
	}else{
		cout <<  -1 << endl;
		return 0;
	}
	l = 1;
	r = maxn;
	mid = (l + r) >> 1;;
	while(l <= r) {

		if (check(mid) > k)
		{
			l = mid + 1;
		}else if(check(mid) < k){
			r = mid - 1;
		}else{
			ans = mid;
			l = mid + 1;
		}
		mid = (l + r) >> 1;

	}
	cout << ans;
	return 0;
}