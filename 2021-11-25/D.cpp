#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
char f, l;
int T;
int main(int argc, char * argv[]){
	cin >> T;
	string s;
	while(T--){
		bool ok = false;
		cin >> s;
		int len = s.size();
		if(s.size() <= 1){
			cout << -1 << endl;
			continue;
		}
		// f = s[0], l = s[len - 1];
		f = s[0] == 'r' ? 'b' : 'r';
		l = s[len-1] == 'r' ? 'b' : 'r'; 
		if(f != l){
			cout << 1 << endl;
			continue;
		}

 		for(int i = 1; i < len - 2; i++){
 			if(s[i] == l and s[i+1] == f){
 				cout << 2  << endl;
 				ok = true;
 				break;
 			}

 		}
 		if(not ok)cout << -1 << endl;
	}

	


    return 0;
}