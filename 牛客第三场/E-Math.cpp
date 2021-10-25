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


int main(int argc, char * argv[]){
	int t = 0;
	int res = 0;
	while(t != 100000){
		res = 0;
		for(unsigned i = 1; i <= t; ++i) {
			for(unsigned j = i; j <= t; ++j) {
				if((i*i +j * j) % (i * j + 1) == 0){
					// cout << i << "----" << j << endl;
					res++;
				}
			}
		}
		cout << t << ": " << res << endl;
		cout << "------------------------------" << endl;
		t++;
		
	}

	/* code */


    return 0;
}