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
#include <bitset>
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
#define MAXN 700
const int inf = INT_MAX;
const int M = MAXN * (MAXN-1) / 2 + 1;
bitset<M> dp[MAXN]; 
int T,n;
void initT(){
	for(int i = 0; i < MAXN; i++) dp[i].set(0);
	for(int i = 2; i < MAXN; i++)
		for(int j = 1; j < i; j++){
			dp[i] |= (dp[j] << ((i-j)*j));
		}
}
int main(int argc, char * argv[]){
	initT();
	int T ;
	cout << "ok" << endl;

	// cout << "switch()"
   ofstream outfile;
   outfile.open("D://test.txt");
   outfile << "switch(n){" << endl;
   for(int n = MAXN;n <= MAXN; n++){
	   	outfile << "case " << n << ":";
	   	outfile << "cout<<" << "\"";
	   	outfile << '0';
		for(int i = 1; i <= n*(n-1)/2;i++){
			if(dp[n][i]){
				outfile << ' ' << i;
			}
		}  
		outfile << "\"" << "<<endl;break;" << "\n"; 	
   }
   outfile << "}";
   cout << "right" << endl;
   outfile.close();
    return 0;
}