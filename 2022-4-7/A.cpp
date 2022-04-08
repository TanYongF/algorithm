#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	long long n = 4;
	set<long long> v;
	int ans = 0;
	for(long long i = 1; i <= sqrt(n); i++){
		if(n % i == 0){
			v.insert(i);
			v.insert(n / i);
		} 
	}
	ans = 0;
	for(auto it1 : v){
		for(auto it2 : v){
			for(auto it3 : v){
				if(it2 * it1 * it3 == n){
					cout << it1 << it2 << it3 << endl;
					ans++;
				}
			}
		}
	}
	cout << ans;



    return 0;
}