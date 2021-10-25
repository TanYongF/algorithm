#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 0;i < n;i++){
        a[i] = i+1;
    }
    do{
        for (int i = 0;i < n;i++){
        	printf("%d",a[i] );
            // cout << a[i];
            if (i + 1 != n){
                printf(" ");
            }
        }
        printf("\n");
    }while (next_permutation(a,a+n));
}