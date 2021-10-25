#include <iostream>
using namespace std;
int a,b;
int lcd(int a , int b){
	if(b == 0) return a;
	else return lcd(b, a % b);
}
int main(){
	while(~scanf("%d %d", &a, &b)){
		int r = lcd(a,b);
		cout << r << " " << (long long)a *b /r << endl;
	}
	return 0;
}
