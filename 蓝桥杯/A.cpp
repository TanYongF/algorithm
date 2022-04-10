#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAXN = 1e18;
int main(){
	long long a, b, c, ans = 0, day = 1;
	cin >> a >> b >> c;
	while(ans < c){
		if(day % 6 == 0 or day % 7 == 0){
			if(ans < c - b) ans += b;
			else{
				break;
			}
		}
		else{
			if(ans < c - a) ans += a;
			else{
				break;
			}
		}
		day++;
	}
	cout << day;
	return 0;
}