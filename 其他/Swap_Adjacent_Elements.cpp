#include <iostream>
#include <algorithm>
using namespace std;
int N;
bool flag ;
int preIndex, SortedIndex;
int main(){
	cin >> N;
	int nums[N];
	int sortedNums[N];
	int k[N+1] = {0};
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
		sortedNums[i] = nums[i];
	}
	cin.get();
	for (int i = 0; i < N-1; ++i)
	{
		char temp;
		temp = cin.get();
		if(temp == '1'){
			k[i + 1] = k[i] + 1;
		}else{
			k[i + 1] = k[i];
		}
	}

	sort(sortedNums, sortedNums + N);
	for (int i = 0; i < N; ++i)
	{
		preIndex = i;
		int preNum = nums[i]; 
		int l = 0;
		int r = N;
		int mid ;
		while(l <= r){
			mid = (l + r) >> 1;
			if(sortedNums[mid] > preNum){
				r = mid -1;
				continue;
			}else if(sortedNums[mid] < preNum){
				l = mid + 1;
				continue;
			}else{
				SortedIndex = mid;
				break;
			}
		}
		if(abs(k[SortedIndex] - k[preIndex]) != abs(SortedIndex - preIndex)){
			cout << "NO";
			return 0 ;
		}

	}
	cout << "YES";
	return 0;


}