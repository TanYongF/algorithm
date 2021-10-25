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
struct Trie{
	vector<Trie*> child;
	int curLen;
	Tire(){
		this->child = vector<Trie*>(26,nullptr);
		this->curLen = 0;
	}
};
int T,n;

int main(int argc, char * argv[]){
	cin >> T;

	while(T--){
		vector<int> a(105);
		vector<string> ret(105);
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i]; 
		// cout << 1;
		for(int i = 0; i < 55; i++) ret[0] += 'a';
		// cout << ret[0];
		for(int i = 1; i <= n; i++){
			int preLen = a[i-1];
			string preStr = ret[i-1];
			for(int i = 0; i < 26; i++){
				if(preStr[preLen] != 'a' + i) {
					preStr[preLen] = 'a' + i; 
					break;
				}

			}
			// preStr[preLen] = 'b';
			// ret[i][preLen] = 'b'; 
			ret[i] = preStr;
		}
		for(int i= 0 ; i <= n; i++) cout << ret[i] << endl;
		// for(auto it : ret){
		// 	cout << it << endl;
		// }

	}

	


    return 0;
}