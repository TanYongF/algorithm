#include <iostream>
using namespace std;
long long f[9][1 << 9][82];
int N, K;
//计算状态现有个数
int count(int num){
	int size = 0;
	for (int i = 0; i < N; ++i)
	{
		size += (num >> i) & 1;
	}
	return size;
}
//判断单行是否符合
bool check1(int num1){
	for (int i = 1; i < N; ++i)
	{
		if(((num1 >> i) & 1)== 1){
			if( ((num1 >> (i-1)) & 1) == 1){
				return false;
			}
		}
	}
	return true;
}
//检查相邻两行是否符合
bool check2(int s1, int s2){
	for (int i = 0; i < N; ++i)
	{
		if(( (s1 >> i ) & 1) == 1){
			if(((s2 >> i) & 1) == 1){
				return false;
			}else if( ((s2 >> (i+1)) & 1) == 1){
				return false;
			}else if( ((s2 >> (i-1)) & 1) == 1){
				return false;
			}
		} 
	}
	return true;

}
int main(){
	cin >> N >> K;
	long long  result = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < (1 << N); ++j)
		{
			if(!check1(j)){
				continue;
			}
			if(i == 0){
				
				f[i][j][count(j)] = 1;
				continue;
			}
			for (int k = count(j); k <= K; ++k)
			{
				for (int j2 = 0; j2 < (1 << N); ++j2)
				{
					if(!check1(j2) || !check2(j2, j)){
						continue;
					}else{
						f[i][j][k] += f[i-1][j2][k - count(j)];
					}
				}
				
			}
		}
	}
	for (int i = 0; i < (1 << N); ++i)
	{
		result += f[N-1][i][K];
	}
	cout << result;
	return 0;
}