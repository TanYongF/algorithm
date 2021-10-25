#include <iostream>
using namespace std;
typedef long long ll;
int n, m, a;
int main(){
	int l_size,s_size = 0;
	long long res = 0; 
	cin >> n >> m >> a;
	l_size = (int)(n/a);
	s_size = (int)(m/a);
	res = l_size*s_size;
	int l = (n % a);
	int s = (m % a);
	if(l != 0){
		l_size += 1;
	}
	if(s != 0){
		s_size += 1;
	}
	res = (long long)l_size * s_size;
	cout << res;
	return 0;
}