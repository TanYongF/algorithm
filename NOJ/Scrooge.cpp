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

ll T;
string str;
int main(int argc, char * argv[]){
	cin >> str;
	int onceY, onceX;
	int n = 0,s = 0,e= 0,w= 0;
	for(auto ch : str){
		if(ch == 'N') n++;
		else if(ch == 'S') s++;
		else if(ch == 'E') e++;
		else if(ch == 'W') w++;
	}
	onceX = e - w;
	onceY = n - s;
	cin >> T;
	ll times = T / (str.length());
	ll values = T % (str.length());
	ll ansX = 0, ansY = 0;
	ansX = (ansX + (ll)times * onceX);
	ansY = (ansY + (ll)times * onceY);
	for(int i = 0; i < values; i++){
		char ch = str[i];
		if(ch == 'N') ansY++;
		else if(ch == 'S') ansY--;
		else if(ch == 'E') ansX++;
		else if(ch == 'W') ansX--;
	}
	cout << ansX << " " << ansY; 
    return 0;
}