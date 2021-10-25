
#include <iostream>

#include <algorithm>
using namespace std;
int a[9];
int main(){
	int size ;
	cin >> size;
	for (int i = 1; i <= size; ++i)
	{
		a[i] = i;
	}
	bool flag = false;//是否为结尾
	do{
		if(flag){
			cout << endl;
		}else{
			flag = true;
		}
		for(int i = 1; i <= size; i++){
			cout << "    " << a[i];

		}
	}while(next_permutation(a+1,a+size+1));
	return 0;
}