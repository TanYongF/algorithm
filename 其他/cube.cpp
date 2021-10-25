#include<iostream>
#define MX 1000000007
using namespace std;

int main()
{
    long long result;
    int T;
    cin>>T;
    for (int i=0;i<T;i++)
    {
        long long int n;
        cin>>n;
        n=n-1;
    result=(n%MX)*(n%MX);
    result%=MX;
    result=result*((n+1)%MX);
    result%=MX;
    result=result*((n+1)%MX);
    result%=MX;
    result=result*2;
        result%=MX;
        cout<<result<<endl;
    }
    return 0;
}