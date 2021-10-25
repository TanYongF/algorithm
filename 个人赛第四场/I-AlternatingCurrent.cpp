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
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;

string str;
stack<char> st;
int main(int argc, char * argv[]){
	cin >> str;
	st.push('0');
	str = str + "1";
	// cout << str.size();
	// cout << str;
	for(unsigned i = 0; i < str.size(); ++i) {
		char curToInsert = str[i];
		// cout << st.size() << endl;
		if(st.top() == curToInsert){
			// if(str[i+1] == curToInsert) continue;
			st.pop();
			// else while(st.top() == curToInsert) st.pop();
		}else{
			st.push(str[i]);
		}
	}
	if(st.size()!=2){
		cout << "NO";
	}else {
		cout << "YES";
	}
	/* code */


    return 0;
}