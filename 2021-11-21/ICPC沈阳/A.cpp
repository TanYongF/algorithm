#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	int a = 10;
	set<int> st;
	st.insert(10);
	st.insert(20);
	auto it = st.find(20);
	it = st.upper_bound(20);
	cout << distance(st.begin(), it);
	


    return 0;
}