#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
string s,t;
bool check(string &s){
	int len = s.size();
	if(len < 3 or len > 10) return false;
	string t1 = s, t2 = s;
	sort(t1.begin(), t1.end());
	t2 = t1;
	reverse(t1.begin(),t1.end());
	if(t1 == s or t2 == s){
		for(int i = 1; i < len; i++){
			// if(s[i] == s[i-1]) return false;
			if(abs(s[i] - s[i-1]) != 1) return false;
		}
	}else return false;
	return true;
}
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> s;
		t = "";
		int i = 0, j = 0;
		bool can = false;
		while(j < s.size()){
			while(i < s.size() and not (s[i] <= '9' and s[i] >= '0')) i++;
			j = i + 1;
			while(j < s.size() and s[j] >= '0' and s[j] <= '9') j++;
			if(i < s.size()) t = s.substr(i, j - i);
			// cout << t << endl;
			can |= check(t);
			i = j;
		}
		if(can) cout << "yes" << endl;
		else cout << "no" << endl;
	}
    return 0;
}