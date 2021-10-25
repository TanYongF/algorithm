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
const int MAXN = 1e6+10;
int T, A, B, C, D, N;
vector<vector<int>> Gx(60); 
int inti(){
	for(int i = 0; i <= MAXN; i++){
		int g = 0, cur = i;明天
		while(cur != 0){
			g += cur%10;
			cur /= 10;
		}
		Gx[g].push_back(i);
	}

}
ll cal(int g, int x){
	return (ll)A*x*x*g+B*x*x+C*x*g*g+D*x*g;
}
int main(int argc, char * argv[]){
	inti();
	// for(auto it : Gx[1]) cout << it << " ";
	cin >> T;
	while(T--){
		cin >> A >> B >> C >> D >> N;
		for(int g = 1; g <= 54; g++){
			int AA = g*A+B, BB = D*(g+g*g);
			if(AA == 0){
				if(BB = 0) cout << 0 << endl; 
				else if(BB > 0) cout << cal(g,1) << endl;
				else cout << cal(g,N) << endl;
				break; 
			}
			//对称轴
			ll vv = (int)-1*BB/(2*AA);
			//开口向上
			if(AA>0){
				if(vv < 1) cout << cal(g,1);
				else if(vv > N) cout << cal(g,N);
				else{

				}
			//开口向上	
			}else{
				if(vv < 1) cout << cal(g, N);
				else if(vv > N) cout << cal(g,N);
				else{

				}
			}
		}

		/* code */

	}

	


    return 0;
}