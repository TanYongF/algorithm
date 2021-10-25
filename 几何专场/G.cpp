//https://vjudge.net/contest/454533#problem/B
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
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

int T;
ll ans = 1e20;
class Point{
public:
	int x,y;
	Point(int xx, int yy) {
		x = xx;
		y =yy;
	}
	Point(){}
};
bool cmp_x(const Point &a, const Point &b){
	return a.x < b.x || (a.x==b.x && a.y < b.y);
}
struct cmp_y {
  bool operator() (const Point& point1, const Point& point2) const{
  	return point1.y < point2.y;
  }
};
void updateAns(const Point & point1, const Point & point2){
	// cout << ps[i].x << " "<< ps[i].y << endl;
	ll cur = pow(point2.x-point1.x,2) + pow(point1.y - point2.y ,2);
	ans = min(ans, cur);
}
Point ps[100010];
int posy[100010];
multiset<Point,cmp_y> mt;
int main(int argc, char * argv[]){
	int n;
	cin >> n;
	ms(posy,0);
	for(int i = 1; i <= n; i++){
		cin >> posy[i];
		posy[i] += posy[i-1];
		ps[i].x = i;
		ps[i].y = posy[i];
	}
	// for(int i = 1; i <= n; i++){
	// 	if(posy[i] - posy[i-1] == 1) cout << "FIND TI!" << endl;
	// 	cout << posy[i] << " ";
	// }
	// cout << endl;
	// sort(ps+1, ps+1+n, cmp_x);
	// for(int i = 1; i <= n; i++){
	// 	cout << ps[i].x << " "<< ps[i].y << endl;
	// }
	for(int i = 1, l = 1; i <= n; i++){
		
		// cout << ans << endl;
		// cout << " i : " << i << endl;
		while(l < i && ps[i].x - ps[l].x >= ans) mt.erase(mt.find(ps[l++]));
		// cout << mt.size();
		// for(auto is : mt ) cout <<"" << is.x << " " << is.y << endl;
		for(auto it = mt.begin(); it != mt.end() && it->y - ps[i].y < ans; it++){
			// cout << (*it).x << endl;
			updateAns(*it ,ps[i]);
		}
		mt.insert(ps[i]);
	}
	cout << ans ;
    return 0;
}