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

int sg[100];
int getSG(int x){
	if(sg[x] != -1) return sg[x];
	unordered_set<int> st;
	for(int i = 1; i <=3 && x >= i; i++) st.insert(getSG(x-i));
	for(int i = 0; ; i++) if(!st.count(i)) return sg[x] = i; 
}

int main(int argc, char * argv[]){
	memset(sg, -1,sizeof(sg));
	for(int i = 0; i < 100; i++) cout << getSG(i) << " ";
    return 0;
}