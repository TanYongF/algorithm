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
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;

int T;
ll n,d;
pair<ll, ll>  people[100005];
bool cmp(pair<ll,ll> p1, pair<ll,ll> p2){
	if (p1.first == p2.first) return p1.second > p2.second;
	else return p1.first <= p2.first;

}

int main(int argc, char * argv[]){
	cin >> n >> d;
	for(unsigned i = 0; i < n; ++i) {
		scanf("%lld %lld", &people[i].first,&people[i].second);
		// cin >> people[i].first >> people[i].second ;
	}
	sort(people, people+n, cmp);

	// for(unsigned i = 0; i < n; ++i) {
	// 	cout << people[i].first << " " <<  people[i].second << endl ;
	// }
	ull ret = 0;
	// for(unsigned i = 0; i < n; ++i) {
		
	// 	int index = i;
	// 	ull friSum = 0;
	// 	while(index < n && (ll)people[index].first < (ll)(minMoney + d)){
	// 		friSum += (ll)people[index].second;
	// 		index++;
	// 	}
	// 	ret = (ret > friSum ? ret : friSum);
	// 	// ret = max(ret, friSum);
	// }
	ull friSum = 0;
	for(int i = 0,j=0;  j < n; j++) {
		// ll minMoney = people[i].first;
		
		if(people[j].first - people[i].first < d){
			friSum += (ull)people[j].second;
			// ret = max(ret, friSum);
		}else{
			while(people[j].first - people[i].first >= d){
				friSum -= people[i].second;			
				i++;
			}
			friSum += people[j].second;
		}
		ret = max(ret, friSum);
	}
	cout << ret << endl;
	/* code */


    return 0;
}