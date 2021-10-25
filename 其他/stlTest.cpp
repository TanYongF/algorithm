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

	std::vector<int> v;
	std::vector<int> :: iterator its;
	v.push_back(10);
	v.insert(v.begin(), 5);
	for(auto it : v) {
		cout << it << " ";
	}


    return 0;
}