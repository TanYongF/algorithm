#include <iostream>
#include <string.h>
typedef long long ll;
 
using namespace std;
 
const int N=2e5+5;
int Next[N];
int lena,lenb;
int a[N];
int b[N];
int ans;
 
void set_naxt()
{
    int i=0,j=-1;
    Next[0]=-1;
    while(i<lenb)
    {
        if(j==-1||b[i]==b[j])
        {
            i++; j++;
            Next[i]=j;
        }
        else
        j=Next[j];
    }
}
 
int kmp()
{
    int i=0,j=0;
    set_naxt();
    while(i<lena)
    {
        if(j==-1||a[i]==b[j])
        {
            i++;j++;
        }
        else
        j=Next[j];
        if(j==lenb)
        {
            ans++;
        }
    }
    return 0;
}
 
int main(void){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)   scanf("%d",&a[i]);
    for(int i=0;i<m;i++)   scanf("%d",&b[i]);
    for(int i=0;i<n-1;i++) a[i]=a[i]-a[i+1];
    for(int i=0;i<m-1;i++) b[i]=b[i]-b[i+1];
    lena=n-1,lenb=m-1;
    kmp();
    if(m==1) cout << n;
    else cout <<ans<<endl;
}
