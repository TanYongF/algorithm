#include <iostream>
using namespace std;
int main(){
	int size ;
	cin >> size;
	while(size--){
		int length;
		cin >> length;
		int result = 0;
		for (int i = 0; i < length; ++i)
		{
			int temp;
			cin >> temp;
			if (temp == 1 || temp == 3)
			{
				result++;
			}
		}
		cout << result << endl;		
	}
	return 0;
}