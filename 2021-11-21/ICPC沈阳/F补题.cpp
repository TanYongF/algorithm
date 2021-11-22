#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
int n;
string str;
int T;

string fs(string old){
	char cur = 'a' - 1;
	string ret = old;
	unordered_map<char, char> mp;
	for(int i = old.length() - 1; i >= 0; i--){
		if(mp.find(old[i]) == mp.end()){
			cur++;
			mp[old[i]] = cur;
		}
		ret[i] = mp[old[i]];
	}
	return ret;
}

int main(int argc, char * argv[]){
	cin >> n >> str;
	vector<string> vs;
	int len = str.length();
	for(int i = 1; i <= len; i++){
		vs.push_back(fs(str.substr(0,i)));
	}
	sort(vs.begin(), vs.end(), greater<>());
	cout<<vs[0];
    return 0;
}