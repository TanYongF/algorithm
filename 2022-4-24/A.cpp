#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
vector<int> v;
vector<int> split(string &s){
	int i = 0, j = 0, len = s.size();
	while(j < len){
		while(i < len and s[i] == ',') i++;
		j = i;
		while(j < len and s[j] != ',' ) j++;
		if(i < len) v.push_back(stoi(s.substr(i, j - i)));
		i = j;
	}
}
int main(int argc, char * argv[]){
	string s;
	int target;
	cin >> s >> target;
	int i;
	int len = s.size();
	s = s.substr(1, len - 3);
	split(s);
	for(auto it : v){
		if(it == target){
			cout << "true";
			return 0;
		}
	}
	cout << "false" << endl;
	return 0;
	// int l = 0, r = v.size()-1, ret = false;
	// while(l <= r){
	// 	int mid = (l + r) >> 1;
	// 	if(nums[mid] == target){
	// 		ret = false;
	// 		break;
	// 	}
	// }




    return 0;
}