#include <iostream>
using namespace std;

const int N = 1e7 ;
int prime[N] = {0}, cnt = 0;	//分别存储素数和下标
bool isPrime[N];	//分别存储每一个数字是否为素数，如果为1那么就是素数

//线性筛模板
void pre(){
	//初始化,isPrime数组为1
	for (int i = 2; i < N; ++i){
		isPrime[i] = true;
	}
	//线性筛
	for (int i = 2; i < N; ++i){
		if(isPrime[i] == 1){
			prime[cnt++] = i;
		}
		//分别对每个素数遍历，进行筛选
		for (int j = 0; j < cnt; ++j){
			if (i * prime[j] >= N) break;	//如果大于数组上限直接跳出
			isPrime[i * prime[j]] = 0;		//满足条件就是非素数
			//重点，当 i 是 pri [j] 的倍数时，i = k*pri [j]，
			//如果继续运算 j+1，i * pri [j+1] = pri [j] * k*pri [j+1]，这里 pri [j] 是最小的素因子，当 i = k * pri [j+1] 时会重复，所以才跳出循环。
			if (i % prime[j] == 0){
				break;
			}
		}
	}
}
int main(){
	pre();
	for (int i = 0; i < 1000; ++i)
	{
		// cout << isPrime[i] << ",";
		cout << prime[i] << ",";
	}


}