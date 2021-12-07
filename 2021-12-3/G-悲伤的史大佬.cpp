#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;


//思路， 遍历整个字符串，如果 该位 为 'd' 那么遍历前面最少满足的sd的 s的所在 位置。然后相加。
//最坏时间复杂度  O(n * logn * logn);
//数据量：2e6;
vector<int> sv , av, dv;
int search(vector<int>& v, int val){
	int ret = -1, mid;
	int left = 0, right = v.size() - 1;
	while(left <= right){
		mid = (left + right) >> 1;
		if(v[mid] < val){
			ret = mid;
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	// cout << ret;
	return ret;
}
char cstr[2000001];
int ax, sx;
int main(int argc, char * argv[]){
    scanf("%s", cstr);
    string s(cstr);
	ll ans = 0, pre = 0;
	
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] == 's') sv.push_back(i);
		else if(s[i] == 'a') av.push_back(i);
	}
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] != 'd'){
			ans += (ll)pre;
			continue;
		};
		ax = search(av, i);
		if(ax == -1){
			ans += pre;
			continue;
		}
		sx = search(sv, av[ax]);
		if(sx == -1){
			ans += pre;
			continue;
		}
		pre = sv[sx] + 1;
		ans += (ll)pre;
	}
	cout << ans << endl;

    return 0;
}