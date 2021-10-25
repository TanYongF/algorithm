#include <queue>
#include <iostream>
using namespace std;
int N;
priority_queue<int, std::vector<int>, greater<int>> q;
int main(){
	cin >> N;
	int num ;
	for (int i = 0; i < N; ++i){
		scanf("%d", &num);
		q.push(num);
	}
	if(N == 1){
		cout << num;
		return 0;
	}
	long long  res =0 ;
	while(q.size() > 1){

		int o1 = q.top();
		q.pop();
		int o2 = q.top();
		q.pop();
		int toAdd = o1 + o2;
		res += toAdd;
		q.push(toAdd);
	}
	cout << res;
	return res;

}