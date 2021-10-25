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
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
int a[105];
int b[105];
int resfrom[8];
int resto[8];
int T ;
int main(int argc, char * argv[]){

	cin >> T;
	char bit;
	for(unsigned k = 1; k <= T; ++k) {
		ms(a);
		int firstOneIndex = INT_MAX;
		for(int i = 0; i < 30; ++i) {
			getchar();
			for(int j = 0; j < 100; ++j) {
				scanf("%c",&bit);
				if(bit == '#'){
					firstOneIndex = min(firstOneIndex, j);
					a[j] = 1;
				}
			}
		}

		cout << "Case "<< "#" << k <<":"<<endl;
		int i,j = 99;
		int size = 7;
		for(i = 99, j = 99; i > 0 && size > 0 ; --i) {
			if(a[i] ==0) continue;
			if(a[i] == 1){
				j = i;
				while(a[j] != 0){
					j--;
				}
				resto[size] = i;
				if(size == 1) resfrom[size] = firstOneIndex;
				else resfrom[size] = j+1;
				size--;
			}
			i = j;
		}
		for(unsigned z = 1; z <= 7; ++z) {
			cout << resfrom[z]+1 << " " << resto[z]+1 << endl;
		}

	}
    return 0;
}