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
#define fro(sign, start, maxN)  for(int sign = start, sign < maxN, sign++);
const int inf = INT_MAX;

int boys[105], girls[105];
int b,g;
int ans= 0;
void swap1(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void slove(int * boys , int * girls){
	int j = 1;
	// cout << b << " " << g<<endl;
	// cout << endl;
	// for(unsigned i = 1; i <= b; ++i) {
	// 	cout << boys[i] << " ";
	// }
	// cout << endl;
	// cout << girls[1] << " " << girls[2] << endl;

	for(unsigned i = 1; i <= b && j <= g; ++i) {
		// cout << " boys :" << i << " girls :" << j << endl;
		while(boys[i]+1 >= girls[j] && j <= g){
			if(abs(boys[i]-girls[j]) <= 1){
				// 
				ans++;
				j++;
				break;
			}
			j++;
		}
	}
	cout << ans << endl;
}
int main(int argc, char * argv[]){
	cin >> b;
	for(unsigned i = 1; i <= b; ++i) {
		cin >> boys[i];
	}

	cin >> g;
	for(unsigned i = 1; i <= g; ++i) {
		cin >> girls[i];
	}
	sort(boys+1, boys + b+1);
	sort(girls+1, girls +g+1);
	if(g >= b) slove(boys, girls);
	else { swap1(b,g); slove(girls , boys);}
	
    return 0;
}