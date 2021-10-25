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

int T,n;
string s0, s1;

int main(int argc, char * argv[]){

	cin >> T;

	while(T--){
		int ret =0;
		cin >> n >> s0 >> s1;
		bool flag = false;
		for(int i = 0; i < n; i++){
		 	if(s1[i] < s0[i]) {
				flag = true;
				break;
			}
		}
		if(flag) { cout << -1 << endl; continue; }
		while(s0 != s1){
			char need = 'z';
			for(int i = 0; i < n; i++) if(s0[i] != s1[i] and s0[i] < need) need = s0[i];
			char minChar = 'z';
			for(int i = 0; i < n; i++) 
				if(s0[i] == need and s0[i] != s1[i] and minChar > s1[i]) 
					 minChar = s1[i]; 
			// cout << s0 << endl;
			// cout << need << " " << minChar << endl;
			for(int i = 0; i < n; i++){
				if(s0[i] == need and s0[i] < s1[i]) s0[i] = minChar;
			}
			ret++;
		}
		cout << ret << endl;

	}

	


    return 0;
}