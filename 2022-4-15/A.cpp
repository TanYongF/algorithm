#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	// cin >> T;
	string s;
	cin >> s;
	vector<string> mp = vector<string>({" ", " ", "ABC","DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"});
	bool flag = false;
	int wait = -1, c = 0;
	string ans = "";
	for(int i = 0; i < s.size(); i++){
		char ch = s[i];
		if(ch == '1'){
			if(wait != -1){
				ans.push_back(mp[wait][(c % mp[wait].size())]);
				wait = -1;
				c = 0;
			} 
		}else{
			if(i > 0 and s[i] == s[i-1]){
				c++;
			}else{
				if(wait != -1){
					ans.push_back(mp[wait][(c % mp[wait].size())]);
					wait = -1;
					c = 0;
				}
				wait = (ch - '0');
				c = 0;
			}
		}
	}
	cout << ans;
    return 0;
}