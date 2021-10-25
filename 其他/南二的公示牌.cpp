#include <iostream>
#define MAX_N 1000000
using namespace std;
 
int h ; 		//高度
int w ;			//宽度
 
struct{
	
	int r;		//定义该节点范围的左值
	int l;		//定义该节点范围的右值
	int width;	//定义该节点的最大容纳量
}tree[MAX_N << 2];
 
 //构建线段树函数
void build(int i, int l, int r){
	tree[i].l = l;
	tree[i].r = r;
	tree[i].width = w;
	if(l==r){
		return;
	}
	int mid = (l+r) / 2;		//取得两者平均值
	build((i<<1)|1, l, mid);	//根据线段树定义，左节点的下标为2 * i +1 
	build((i+1)<<1, mid+1, r);	//根据线段树定义，右节点的下标为 2 * i + 2
}
 //插入数据函数
int insert(int i, int wi){
	//基线条件：如果第i行的宽度不可以容纳wi的公告
	if(tree[i].width < wi){
		return -1;
	}
	//基线条件：如果找到了根节点，那么我们将其减去wi即可
	if(tree[i].l==tree[i].r){
		tree[i].width -= wi;
		return tree[i].l;
	}
	//先尝试向左子树进行插入
	int result = insert((i<<1)|1, wi);
	//如果左子树不可以插入,我们向右子树插入	
	if(result == -1){
		result = insert((i+1)<<1,wi);
	}
	//插入成功，进行更新，使当前节点为子节点的最大值即可（最大容纳量）
	if(result != -1){
		tree[i].width = max(tree[(i<<1)|1].width, tree[(i+1)<<1].width);
	}
	return result;
}
 
int main(){
	int n,wi;
	scanf("%d%d%d",&h,&w,&n);
	build(0, 1, min(h,n));
	while(n--){
		scanf("%d",&wi);
		printf("%d\n",insert(0,wi));
	}
}