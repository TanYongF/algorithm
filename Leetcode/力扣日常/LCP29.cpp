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
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;


class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        xPos++;
        yPos++;

        int q1 = min( xPos, num  + 1- xPos);
        int q2 = min(yPos ,num  + 1- yPos);
        int q= min(q1, q2);
        cout << q << endl;
        q--;
        int first = (long long)4*q%9*(num-q)%9; 
        // cout << first << endl;
        long long len = num - q * 2;
        int cc = q + 1;


        int a = (first + 1)%9;
        int b = (a + len - 1) % 9;
        int c = (b + len - 1) % 9;
        int d = (c + len - 1) % 9;
        cout << a << " " << b << " " << c << " " << d << endl;
        int ans = a;
        if(xPos == cc && yPos != num - cc + 1) ans =  (a + yPos - cc) % 9;
        else if(xPos == num - cc + 1 && yPos != cc)ans = (c + num - cc + 1 - yPos) % 9;
        else if(yPos == cc && xPos != cc) ans =(num + 1 - cc - xPos + d) % 9;
        else if(yPos == num - cc + 1 &&xPos != num - cc + 1 ) ans = (b + xPos - cc) % 9;
        return ans == 0 ? 9 : ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.orchestraLayout(8876, 217,97);
	/* code */


    return 0;
}