#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef vector<P>V;
const int N=105;
//pool 维护所有的 <数量，单价> 的状态。
int Case,n,m,i,j,k,a[N][N],b[N][N];ll ans;V f[N][N];P pool[1000005];
inline void ext(const P&t){
  //应为merge操作中是小的先进，pool中最后一个元素一定小于待插入元素的第一维，如果其第二维也小于待插入元素，直接剔除就可。
  while(m&&pool[m].second<=t.second)m--;
  if(!m||pool[m].first<t.first)pool[++m]=t;
}
inline void merge(const V&A,const V&B,V&C){
  int ca=A.size(),cb=B.size(),i=0,j=0;
  m=0;
  //这里第一维小的先进，保证pool中的第一维是递增的
  while(i<ca&&j<cb)ext(A[i].first<B[j].first?A[i++]:B[j++]);
  while(i<ca)ext(A[i++]);
  while(j<cb)ext(B[j++]);
  C.resize(m);
  for(i=0;i<m;i++)C[i]=pool[i+1];
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&b[i][j]);
    //f[i][j]表示到达下标为(i,j)时候取得所有的 <数量，单价> 的全部状态。
    //这里的f[i][j][k].first为数量； second为单价
    f[1][1].resize(1);
    f[1][1][0]=P(a[1][1],b[1][1]);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++){
      if(i==1&&j==1)continue;
      if(i==1)f[i][j]=f[i][j-1];
      else if(j==1)f[i][j]=f[i-1][j];
      //这一步得到f[i][j]的初始状态,也就是f[i][j]的 <数量，单价> 全部状态。
      //在初始化f[i][j]的过程中，需要剔除 f[i][j][k1].first < f[i][j][k2].second && f[i][j][k2].first < f[i][j][k2].second , 也就是单价小，数量也小的可以剔除 
      else merge(f[i-1][j],f[i][j-1],f[i][j]);
      for(k=0;k<f[i][j].size();k++){
        f[i][j][k].first+=a[i][j];
        f[i][j][k].second+=b[i][j];
      }
    }
    ans=0;
    //最后对最后一个位置的所有状态求总价取最大就是答案。
    for(i=0;i<f[n][n].size();i++)ans=max(ans,1LL*f[n][n][i].first*f[n][n][i].second);
    printf("%lld\n",ans);
  }
}