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
	int qsize;
int T, n,m,k,from, to;
int bits[1005];
int froms[1005], tos[1005]; 

void check2(){
	bool flag = true;
	qsize = 0;
	int ans1f, ans1t;
	int ans2f, ans2t;
	// int index = 1;
	int j =0;
	for(int i = 1; i <= n; ) {
		// if(qsize > 2){
		// 	flag = false;
		// 	break;
		// }
		if(bits[i] == 1){
			j = i;
			// cout << "j" << j << endl;
			while(j <= n && bits[j] == 1){
				j++;
			}
			qsize++;
			// cout << "----------" << i <<" " << j << " " << qsize <<  endl;
			// if(qsize == 1){
			// 	ans1f = i;
			// 	ans1t = j-1;
			// }else if(qsize == 2){
			// 	ans2f = i;
			// 	ans2t = j-1;
			// }
			froms[qsize] = i;
			tos[qsize] = j-1;
			i = j;
		}else i++;
	}
	// if(!flag){
	// 	cout << -1 << endl;
	// 	return;
	// }

	// if(qsize == 1) cout << qsize <<endl << ans1f << " "<< ans1t << endl;
	// else cout <<qsize <<endl << ans1f <<" "<< ans2t << endl << ans2f << " " << ans1t<<endl;
}
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		ms(bits, 0);
		ms(froms,0);
		ms(tos,0);
		cin >> n >> m;
		for(unsigned i = 0; i < m; ++i) {
			cin >> from >> to;
			if(to >= from) for(unsigned i = from; i <= to; ++i) bits[i] = 1;
			else {
				for(int i = 1; i <= to; ++i) bits[i] = 1;
				for(int i = from; i <= n; i++) 	bits[i] = 1;
			}
		}

		// for(unsigned i = 1; i <= n; ++i) {
		// 	cout<<bits[i] << " ";
		// }
		// cout << endl;
		check2();
		// cout << "------------" << endl;
		// for(unsigned i = 1; i <= qsize; ++i) {
		// 	cout << froms[i] << " " <<  tos[i] <<  endl;
		// }
		// cout << "---------------" << endl;
		cout << qsize << endl;
		for(unsigned i = 2; i <= qsize; ++i) {
			cout << froms[i] << " " << tos[i-1] << endl;
		}
		cout << froms[1] << " " << tos[qsize] << endl; 
	}
    return 0;
}