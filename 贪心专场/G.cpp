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

int m;
vector<int> v;
vector<int> v2;
set<int> st;
bool cmp(int a ,int b){
	return a >= b;
}
int main(int argc, char * argv[]){
	cin >>m ;
	int he;
	for(unsigned i = 0; i < m; ++i) {
		scanf("%d",&he);
		// if(st.find(he)==st.end()) {
		// 	st.insert(he);
		// 	v.push_back(he);
		// }else{
		// 	v2.push_back(he);
		// }
		v.push_back(he);
	}
	sort(v.begin(), v.end());
	// sort(v2.begin(), v2.end(), cmp);
	// for(auto it : v){
	// 	cout << it << " ";
	// }
	// for(auto it: v2){
	// 	cout << it << " ";
	// }


	for(int i = 0; i < v.size(); i+=2){
		cout << v[i] << " ";
		v[i] = -1;
	}
// cout << v.size() << endl;
	for(int i = v.size()-1 ; i >= 0; i--) {
		// cout << endl;
		if(v[i] != -1){
			cout << v[i] << " ";
		}
	}
	/* code */


    return 0;
}