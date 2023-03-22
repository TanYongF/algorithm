#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	// cin >> T;
	int n;
	int nums[10];
	cin >> n;
	for(int i = 0; i < n; i++) cin >> nums[i];
	int a = INT_MIN, b = INT_MIN, c = INT_MIN; //largest, larger, large
	for(int i = 0; i < n; i++){
		//if nums[i] is of (a, b, c), 不会对答案产生影响
		if(nums[i] == a or nums[i] == b or nums[i] == c) continue;
		// firstly, compare with the max value --- a
		if(nums[i] > a){
			// nums[i] > a > b > c
			// so (a, b, c) become (nums[i], a, b)
			c = b;
			b = a;
			a = nums[i];
		}else if(nums[i] > b){
			// a > nums[i] > b > c 
			// so  (a, b, c) become (a, nums[i], b)
			c = b;
			b = nums[i];

		}else if(nums[i] > c){	
			// a > b > nums[i] > c
			// so (a, b, c) become (a, b, nums[i])
			c = nums[i];
		}else{
			// a > b > c > nums[i];
			continue;
		}
	}
	cout << c << endl;
    return 0;
}