//https://leetcode-cn.com/problems/smallest-k-lcci/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
	vector<int> res;
    vector<int> smallestK(vector<int>& arr, int k) {
    	qsort(arr,k,0,arr.size()-1);
    	return res;

    }
    void qsort(vector<int>& arr, int k, int left, int right){
    	if(left > right) return;
    	int i = left, j = right;
    	while(i < j){
    		while(i < j && arr[j] >= arr[left]) j--;
    		while(i < j && arr[i] <= arr[left]) i++;
    		swap(arr[i], arr[j]);
    	}
    	swap(arr[i], arr[left]);
    	if(i == k-1) res.assign(arr.begin(), arr.begin()+k);
    	else if(i < k-1) qsort(arr, k, i+1, right);
    	else qsort(arr, k, left, i-1);
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> test = {1,2,2,2,5};
	s.smallestK(test, 5);
	/* code */


    return 0;
}