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
ll T,num;


const int N = 1e9+10;	//分别存储每一个数字是否为素数，如果为1那么就是素数


bool isPrime( ll num )
{
    
    if(num ==2|| num==3 )   //两个较小数另外处理
        return 1 ;
    if(num %6!= 1&&num %6!= 5)   //不在6的倍数两侧的一定不是质数
        return 0 ;
    int tmp =sqrt(num);
    for(int i= 5; i <=tmp; i+=6 )   //在6的倍数两侧的也可能不是质数
        if(num %i== 0||num %(i+ 2)==0)  //排除所有，剩余的是质数
            return 0 ;
    return 1 ;
}
bool judge(ll year){
	 if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            // // 这里如果被 400 整除是闰年
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> num;
		if(isPrime(num) && judge(num)){
			cout << "yes" << endl;
		}else{
			cout << "no"<<endl;
		}
	}
	/* code */
    return 0;
}