
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int a[100010];
	int n;
	int m;
	int x;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	while( m --){
		cin >> x;
		if (x < a[0]){
			cout << -1 << endl;
		}else if(x > a[n-1]){
			cout << a[n-1] << endl;
		}else{
			if(binary_search(a,a+n,x)){
				cout << x << endl;
			}else{
				int ans=-1;
				int left=0,right=n-1;
				while(left<=right){
					//右移一位，节约时间 
					int mid=(left+right)>>1;
					if(a[mid]<=x){
						ans=a[mid];
						left=mid+1;
					}else{
						right=mid-1;
					}
				}
				cout << ans << endl;
			}

		}
	}
	return 0;
}
