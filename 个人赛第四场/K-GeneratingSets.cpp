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
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;


priority_queue<int,vector<int>,less<int>> q;
set<int> st;
int len;

int main(int argc, char * argv[]){

	cin >> len;
	int num;
	for(unsigned i = 0; i < len; ++i) {
		cin >> num;
		q.push(num);
		st.insert(num);
	}
	int curnum, cur;
	while(true){
		cur = curnum = q.top();
		q.pop();
		curnum /= 2;
		while(curnum){
			// auto it = st.find(curnum);
			if(st.find(curnum) == st.end()){
				st.insert(curnum);
				q.push(curnum);
				auto is = st.find(cur);
				st.erase(is);
				break;
			}
			curnum /= 2;
		}
		if(curnum == 0){
			for(auto it : st){
				cout << it << " " ;
			}
			return 0;
		}		
	}

    return 0;
}