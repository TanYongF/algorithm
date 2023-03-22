#include<bits/stdc++.h>
using namespace std;


//分划
int parition(vector<int> nums, int l, int r){
	int randomIdx = l + rand() % (r - l + 1);
	swap(nums[randomIdx], nums[l]);
	int pivot = nums[l];
	while(l < r){
		while(l < r and nums[r] >= pivot) r--;
		nums[l] = nums[r];
		while(l < r and nums[l] <= pivot) l++;
		nums[r] = nums[l];
	} 
	nums[l] = pivot;
	return l;
}

int quickSort(vector<int> &nums, int l, int r, int k){
	int idx = parition(nums, l, r);
	if(idx == k){
		return nums[k]; 
	}else if(idx < k){
		return quickSort(nums, idx + 1, r, k);
	}else return quickSort(nums, l, idx - 1, k);
}

int topK(vector<int>& nums, int k){
	int n = nums.size();
	if(k > n) return -1;
	if(k <= 0) return -1;
	return quickSort(nums, 0, n-1, n - k);
}

int main(){
	//right
	vector<int> test1 = vector<int>({1,2,3,4,5});
	cout << topK(test1, 2) << endl;
	cout << topK(test1, 5) << endl;
	cout << topK(test1, 1) << endl;

	//demo2
	vector<int> test2 = vector<int>({1,1,1,1});
	cout << topK(test2, 2) << endl;

	//demo3 wrong k
	vector<int> test3 = vector<int>({1,1,1});
	cout << topK(test3, 4) << endl;

	//demo4 wrong k
	vector<int> test4 = vector<int>({1,1,1});
	cout << topK(test4, -1) << endl;



	return 0;
}



