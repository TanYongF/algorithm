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
int main(int argc, char * argv[]){
	map<int, string> mp; 
	cin >> T;
	int size;
	int idx;
	string segment;
	int maxLen = INT_MIN;
	while(T--){
		cin >> segment >> size;
		for(int i= 0; i < size; i++){
			cin >> idx;
			if(mp.find(idx) == mp.end() or mp[idx].size() < segment.size()) mp[idx] = segment;
			maxLen = max(maxLen,(int)segment.size() + idx - 1);
		}
	}
	string ans(maxLen + 1, 'a');
	int cur = 1, start, aboStart;
	for(auto &it : mp){
		start = it.first;
		aboStart = cur - start;
		if(aboStart < 0){
			aboStart = 0;
			cur = start;
		} 
		for(int i =  aboStart; i < (int)it.second.length(); i++){
			ans[cur] = it.second[i];
			cur++;
		}
		
		cur--;
	}
	cout <<  ans.substr(1, (int)ans.length());
    return 0;
}