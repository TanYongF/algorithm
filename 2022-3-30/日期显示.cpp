#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

long long times;
int main(int argc, char * argv[]){
	cin >> times;
	long long hour, min, sec;
	times /= 1000;
	long long day_long = 60 * 60 * 24;
	times %= day_long;
	hour = (times/(60*60));
	min  = ((times%(60*60))/60);
	sec  = (times%(60));
	printf("%-2lld:%-2lld:%-2lld", hour, min, sec);
    return 0;
}