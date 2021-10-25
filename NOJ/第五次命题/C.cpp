#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
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
typedef pair<int,int> P;
int T, m ,n;
vector<P> edge;
bool accessZero = false;
int main(int argc, char * argv[]){
	cin >> m >> n;

	while(n--){
		int from, to;
		cin >> from << to;
		if(from > to && to != 0) edge.push_back(P(to,from));
		else if(from < to && to == 0) edge.push_back();
		else if(from < to) edge.push_back(from, to);
		else                                                                             

	}
	


    return 0;
}