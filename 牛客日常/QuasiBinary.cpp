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

int n;
int num[10];
// int res[10];
std::vector<int> res;
int main(int argc, char * argv[]){
	ms(num,0);
	cin >> n;
	int i = 0;
	while(n!=0){
		num[i++] = n % 10;
		n /= 10;
		// cout << n<< endl;
	}
	// for(unsigned i = 0; i < 10; ++i) {
	// 	cout << num[i] << " ";
	// }
	
	// cout << pow(10,0) << endl;
	int size =0;
	while(true){
		int ans= 0;
		for(unsigned i = 0; i < 8; ++i) {
			if(num[i] > 0){
				ans += pow(10, i);
				num[i]--;
			}
		}
		if(ans == 0) break;
		else res.push_back(ans), size++;
	}
	cout << size << endl;
	for(auto it : res){
		cout << it << " " ;
	}
	



	/* code */


    return 0;
}