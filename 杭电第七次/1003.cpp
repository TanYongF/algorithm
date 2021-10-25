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
const int MAXN = 1e4 + 10;
double s[MAXN];
int nums[MAXN];
int T,k;
int x1, y11, x2, y2, x3, y3;
double t[MAXN];
double ans;
int main(int argc, char * argv[]){
    cin >>T;
    while(T--){
        // cin >> k;
        scanf("%d", &k);
        scanf("%d %d %d %d %d %d",&x1,&y11,&x2,&y2,&x3,&y3);
        // cin >> x1 >> y11 >> x2 >> y2 >> x3 >> y3 ;
        ms(s,0);
        ms(nums,0);
        nums[1] = 2;
        nums[2] = 5;
        int height = y11-y2;
        s[1] = abs(x3 - x2)*height/2;
        s[2] = s[1] / 2 * nums[2];
        int add=  s[2] - s[1];
        t[2] = add;
        ans = s[1] + s[2];
        for(int i = 3; i <= k-1; ++i) {
            t[i] = t[i-1] / 2 + add;
            ans +=  (s[1]+t[i]);
        }
        
        printf("%0.3lf\n",ans);
    }
    return 0;
}