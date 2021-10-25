#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
bool isTrue;
vector<int> dots(10,0);
void backTracing(int curNum, bool flag){
	if(curNum <= 0) {isTrue = true; return;}
	for(int i= 1 ; i < 10 and not isTrue; ++i){
		if(dots[i] == 0) continue;
		if(dots[i] >= 2 and !flag){
			dots[i] -= 2;
			backTracing(curNum - 2, true);
			dots[i] += 2;
		}
		if(dots[i] >= 3){
			dots[i] -= 3;
			backTracing(curNum-3, flag);
			dots[i] += 3;
		}
		if(i <= 7 && dots[i] >= 1 and dots[i+1] >=1 and dots[i+2] >= 1){
			dots[i] -= 1, dots[i+1] -=1, dots[i+2] -= 1;
			backTracing(curNum -3 , flag);
			dots[i] += 1, dots[i+1] += 1, dots[i+2] += 1;
		}
	}
}
int main(int argc, char * argv[]){
	vector<int> ans;
	for(int i = 0; i < 13; i++){
		int dot;
		cin >> dot;
		dots[dot]++;
	}
	for(int i = 1; i <= 10; i++){
		if(dots[i] <= 3){
			dots[i]++;
			isTrue = false;
			backTracing(14, false);
			if(isTrue) ans.push_back(i);
			dots[i]--;
		}
	}
	if(ans.size() == 0) cout << 0;
	else{
		cout << ans[0];
		for(int i = 1; i < ans.size(); i++){
			cout << " "<< ans[i];
		}
	}
    return 0;
}