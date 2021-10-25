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

int T,ind,n;
int price[] = {7,27,41,49,63,78,108};
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> n;
		int sum =0 ;
		while(n--){
			cin >> ind;
			sum += price[ind-1];
		}
		if(sum >= 120) cout << sum - 50 << endl;
		else if(sum >= 89) cout << sum-30 << endl;
		else if(sum >= 69) cout << sum-15 << endl;
		else cout << sum << endl;
		/* code */
	}

	


    return 0;
}