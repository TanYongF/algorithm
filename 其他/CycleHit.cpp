#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
set<string> st;
string pattern = "chokudai";
int len;
ll res = 0;
int mod = 1e9+7;
string s;
void breakTrace(int cur_index, int str_index){
	if(cur_index == len){
		res = (res + 1) % mod;
		return;
	}else if(str_index == s.size()){
		return;
	}	
	for(int i = str_index; i < s.size(); i++){
		if(s[i] == pattern[cur_index]){
			breakTrace(cur_index+1, i + 1);
		}
	}

}
int main(int argc, char * argv[]){
	len = pattern.size();
	// string s;
	cin >> s;
	// cout << s.size();
	breakTrace(0,0);
	cout << res;


    return 0;
}
