#include <iostream>
#include <climits>
#include <deque>
using namespace std;
int a[1000001];
int b[1000001];
int c[1000001];
int N;
int K;
deque<int> qMax, qMin;
int main(){
    int index = 0;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < N; ++i)
    {
        while(!qMax.empty() && a[i] >= a[qMax.back()]) {
            qMax.pop_back();
        }
        qMax.push_back(i);
        while(!qMin.empty() && a[i] <= a[qMin.back()]){
            qMin.pop_back();
        }
        qMin.push_back(i);
        if(i >= K - 1){
            while(!qMax.empty() && qMax.front() <= i - K) {
                qMax.pop_front();
            }
            b[index] = a[qMax.front()];
            while(!qMin.empty() && qMin.front() <= i - K){
                qMin.pop_front();
            }
            c[index] = a[qMin.front()];
            index++; 
        }
    }
    for (int i = 0; i < index; ++i) 
    {
        if (i == 0) 
        {
            printf("%d",c[i]);
        }else{
            printf(" %d",c[i]);
        }

    }
    cout <<  endl;
    for (int i = 0; i < index; ++i) 
    {
        if (i == 0) 
        {
            printf("%d",b[i]);
        }else{
            printf(" %d",b[i]);
        }

    }
    return 0;


}