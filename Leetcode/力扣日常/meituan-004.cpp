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
typedef tuple<int,int,int> T;

int n,queryNum, nums[20005],flag, x, y, k, ind;
vector<tuple<int,int,int>> queries;
int getans(int id){
	for(vector<T>::reverse_iterator it = queries.rbegin(); it != queries.rend(); ++it){
		if(get<0>(*it) + get<2>(*it) > id && id >= get<2>(*it)){
			return nums[get<1>(*it) + id - get<2>(*it)];
		}
	}
	return -1;

}
int main(int argc, char * argv[]){
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> nums[i]; 
	cin >> queryNum;
	for(int i = 1; i <= queryNum; i++){
		cin >> flag;
		if(flag == 1){
			cin >> k >> x >> y;
			queries.push_back({k,x,y});
		}else{
			cin >> ind;
			cout << getans(ind) << endl;
		}
	}
    return 0;
}