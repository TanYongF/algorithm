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


int main(int argc, char * argv[]){
	int m;
	while(true){
		cin >> m;
		for(int i = 2; i * i <= m; i++){
			while(m % i == 0){
				m /= i;
				cout << i << " ";
			}
		}
		if(m > 1) cout << m;
	}
	


    return 0;
}