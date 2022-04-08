#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;

const int MAXN = 1e7 + 10;
double a, b, c, d;
double ans;
double f(double n){
	return a * (n * n * n) + b * (n * n) + c * n + d;
}
int main(int argc, char * argv[]){

	cin >> a >> b >> c >> d;
	int cnt = 0;
	for(int i = -100; i <= 100; i++){
		double left = i, right = i + 1;
		double fl = f(left), fr = f(right);
		if(fl == 0){
			printf("%.2lf ", left);
			cnt++;
			continue;
		}
		if(fl * fr < 0){
			while(left <= right){
				double mid = (left + right) / 2;
				if(f(mid) * fl <= 0) right = mid - 0.0001, ans = mid;
				else left = mid + 0.0001, ans = mid; 
			}
			printf("%0.2lf ", ans);
			cnt++;
		}
		if(cnt == 3) break;
	}
	return 0;
}