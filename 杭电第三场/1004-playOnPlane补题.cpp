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
int counts[1000005];
typedef pair<int, int> P;
pair<int, int> ks[1000005];

int xa, xb, ya, yb, num, dy, dx;
int gcd(int x, int y){
	if(y == 0){
		return x;
	}
	return gcd(y, x % y);
}
int main(int argc, char * argv[]){
	cin >> T;
	// int cou
	while(T--){
		ms(counts);
		cin >> num;
		for(unsigned i = 1; i < num+1; ++i) {
			scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
			dx = xa - xb;
			dy = ya - yb;
			if(xa == xb) dy = 1;
			else if(ya == yb) dx = 1;
			else{
				if(dx < 0) dx = -dx, dy = -dy;
				int n = gcd(abs(dx), abs(dy));
				dx = dx / n;
				dy = dy / n;
			}
			ks[i] = P(dx,dy); 
		}
		sort(ks+1, ks + num+1);
		int maxnum =0;
		// ms(counts);
		int j;
		for(int i = 1; i <= num; i = j) {
			//找到相同元素的下标
			for( j = i; j <= num && ks[i] == ks[j]; ++j);
			//统计第一层元素、第二层元素....
			for(int k = 1; k <= (j-i) ; ++k) counts[k]++;

			maxnum = max(maxnum, (j-i));
		}
		int sum =0 , i = 1;
		for(unsigned j = 1; j <= maxnum; ++j) {
			sum += counts[j];
			while(i <= sum){
				printf("%d\n",i-j);
				i++;
			}
			/* code */
		}
	}
	return 0;
}