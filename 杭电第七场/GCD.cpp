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
#define maxn 1000005
#define N 100000050
const int inf = INT_MAX;

int T;
using namespace std;
int notPrime[N] = { 0 }; //0表示素数，1为非素数
void Prime(int n)
{
    int i;
    int t;
    for (i = 2; i * i <= n; i++)
    {
        if (!notPrime[i])
        {
            for (t = 2 * i; t <= n; t += i)
            {
                notPrime[t] = 1;
            }
        }
    }
}


int main(int argc, char * argv[]){
	Prime(N);
	cin >> T;
	int num, nums;
	int primsize = 0;
	int ones = 0;
	while(T--){
		cin >> nums;
		int size = 0;
		primsize = 0;
		ones = 0;
		for(unsigned i = 0; i < nums; ++i) {
			scanf("%d", &num);
			if(num == 1){
				ones++;
			}else if(notPrime[num] == 0){
				primsize++;
			}
		}
		size = (nums - ones - primsize);
		if(size % 2 == 0 && primsize % 2 == 0) cout << "Bob" << endl;
		else cout << "Alice" << endl;
	}
    return 0;
}