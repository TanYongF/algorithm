#include <iostream>
using namespace std;
int nums[400];

void printNums(int length, int lastIndex){
	cout << "(" ;
	for(int i = 0; i < length; i++){
		if(i <= lastIndex){
			if(i != lastIndex){
				cout << nums[i] ;
				cout << " " ;
			}
			if(i == lastIndex ) {
				if( lastIndex == length-1){
					cout << nums[lastIndex] << ")" ;
				}else{
					cout << nums[lastIndex] << ") " ;
				}

			}
		}else{
			if(i != length-1){
				cout << nums[i] << " " ;
			}else{
				cout << nums[i] ;
			}

		}

	}
	cout << endl;

}



int main(){
	int length ;
	cin >> length;
	for(int i = 0; i < length; i++){
		cin >> nums[i];
	}
	int flag = 0;
	cout << "Source:" << endl;
	printNums(length, length-1);
	cout << "Bubble Sort:" << endl;
	for(int i = 0 ; i < length -1; i++){
		flag = 0;
		for(int j = 1; j < length - i; j++){
			if(nums[j] < nums[j-1]){
				flag = 1;
				int temp = nums[j];
				nums[j] = nums[j-1];
				nums[j-1] = temp;
			}
		}
		if(flag == 1){
			printNums(length, length-i-2);
		}

	}
	cout << "Result" << endl;
	printNums(length,length-1);
	return 0;
}
