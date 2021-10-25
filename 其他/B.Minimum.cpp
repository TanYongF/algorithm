#include <iostream>
using namespace std;
typedef long long LL;
LL Res = 0;
LL MAXN = 10000002;
int pa[MAXN] ;

int Find(int x) {
    return x == pa[x] ? x : pa[x] = Find(pa[x]);
}

void Uion(int x, int y) {
    int px = Find(x), py = Find(y);
    if (px != py) {
        pa[px] = py;
    }
}
void init(int num){
	for(int i = 2; i <= MAXN; i++){
		if(pa[i] == i) continue;
		for(int j = 2 *i; j <= num; j+=i){
			pa[j] = i;
			Res += i;
		}
	}
}

int main(){
	int case_size;
	int num;
	cin >> case_size;
	while(case_size--){
		init();
		int res;
		cin >> num;
		for (int i = 2; i <= num; ++i)
		{
			
		}

	}
	return 0;

}