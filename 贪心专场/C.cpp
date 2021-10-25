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

int T;
ll px,py;
ll maxx = 0, maxy =0 ;
ll minx =0 , miny= 0;
ll x = 0,y=0;
string str;
char pos;
bool flag = false;
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		string st;
		 maxx =0;
		 maxy =0 ;
		 minx =0 ;
		 miny= 0;
		 x= 0;
		 y = 0;
		 flag = false;
		cin >> px >>py >>str;
		for(unsigned i = 0; i < str.size(); ++i) {
			pos = str[i];
			if(pos == 'R'){
				maxx++;
			}else if(pos == 'L'){
				minx--;
			}else if(pos == 'U'){
				maxy++;
			}else if(pos == 'D'){
				miny--;
			}
			maxx = max(maxx, x);
			maxy = max(maxy, y);
			minx = min(minx, x);
			miny = min(miny, y);
			if(px <= maxx && px >= minx && py <= maxy && py >= miny){
				cout << "YES" << endl;
				flag = true;
				break;
			}
		}
		if(!flag)
		cout << "NO" << endl;
	}


    return 0;
}