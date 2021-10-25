//https://vjudge.net/contest/454533#problem/G
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
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

int T;
string s;
int n;
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >>n;
		char c;
		int size= 0 ;
		while(n--){
			cin >>c;
			if(c == '0') size++;
		}
		if(size == 1 || size % 2 == 0) cout << "BOB" << endl;
		else cout << "ALICE" << endl;
	}
    return 0;
}