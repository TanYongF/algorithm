// 64 位输出请用 printf("%lld")
#include<bits/stdc++.h>
using namespace std;

vector<int> temp;
int main() {
    int  a= 10;
    string s = 
    int n; cin >> n;
    temp = vector<int>(n, 0);
    auto nums = vector<int>(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    // cout << mergeSort(nums, 0, n - 1);
    return 0;
}

int merge(vector<int>& nums, int left,  int mid,  int right){
    int ans  = 0; 
    int ls = left, rs = mid + 1, idx = 0;
    
    while(ls <= mid or rs <= right){
        if(ls <= mid and rs <= right){
            if(nums[ls] <= nums[rs]) ans += (right - rs + 1) * nums[ls] , temp[idx++] = nums[ls++];
            else temp[idx++] = nums[rs++]; 
        }else if(ls <= mid){
            temp[idx++] = nums[ls++];
        }else{
            temp[idx++] = nums[rs++];
        }
    }
    for(int i = left, j = 0; i <= right; i++, j++) nums[i] = temp[j];
    return ans;
}
int mergeSort(vector<int> &nums, int l, int r){
    if(l >= r) return 0;
    int mid = (l + r) >> 1;
    int L = mergeSort(nums, l, mid);
    int R = mergeSort(nums, mid + 1, r);
    int C = merge(nums, l, mid, r);

    return L + R + C;
}


