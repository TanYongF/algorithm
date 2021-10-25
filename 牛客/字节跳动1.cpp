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
string str;
string slove(string s){
	string ans;
	int len = s.length();
	int preLen = 0, preChar = '.', curLen = 0, curChar =  '.';
	for(int i = 0, j = 0; i < len; i++){
		if(s[i] == curChar){
			if(curLen >= 2 || (curLen == 1 && preLen == 2)) continue;
			else{
				curLen++;
				ans += curChar;
			}
		}else{
			preChar = curChar;
			preLen = curLen;
			ans += s[i];
			curChar = s[i];
			curLen = 1;
		}
	}
	// for(int i = 0; i< )
	return ans;

}
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> str;
		cout << slove(str) << endl;
		/* code */
	}
    return 0;
}