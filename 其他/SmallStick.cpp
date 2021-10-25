#include <iostream>
#include <algorithm>
using namespace std;
int nums[60];
int N;
int sum, len, n;
bool flag = false;
bool isVisited[61];

int cmd(int a,int b){
	return a>b;
}
//hasSuccess : 已经成功的数量 l : 目前的长度   index： 当前的下标
void dfs(int hasSuccess, int l, int index){
	if(hasSuccess == sum / len){
		flag = true;
		return ;
	}

	for (int i = index ; i < N; ++i)
	{
	//使用剪枝，如果不符合那么和这一个相同的也需要删除
		if (isVisited[i] || (!isVisited[i-1] && nums[i] == nums[i-1]))
		{
			continue;
		}
		if (l + nums[i] == len)
		{
			hasSuccess++;
			isVisited[i] = true;
			if(hasSuccess == sum / len){
				flag = true;
				return;
			}
			//寻找下一个节点，如果下一个节点不能构成直接跳出
			for(int k = 0; k < N; k++){
				if(!isVisited[k]){
					dfs(hasSuccess, 0, k);
					if(flag) return;
					//如果没有成功，证明nums[i]节点位置不对， 这时候需要进行回溯
					hasSuccess--;
					isVisited[i] = false;
					return;
				}
			}
		}
		if(l + nums[i] < len){
			isVisited[i] = true;
			dfs(hasSuccess, l + nums[i], i + 1);
			if(flag) return;
			//进行回溯
			isVisited[i] = false;
			//这里进行剪枝，如果当前长度为0也就是len长度的第一个木条不符合，没必要进行下面的木条测试了。那么这时可以直接返回
			if(l == 0) return;
		}	
	}
}
int main(){
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
		sum += nums[i];

	}
	//倒序排列
	sort(nums, nums+N, cmd);
	for(int i = nums[0]; i <= sum; i++){
		if(sum % i == 0){
			len = i;
			for (int j = 0; j < N; ++j)
			{
				isVisited[j] = false;
			}
			dfs(0, 0, 0);
			if(flag){
				cout << len << endl;
				return 0;
			}
		}
		
	}
	return 0;

}