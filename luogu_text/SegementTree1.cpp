#include<bits/stdc++.h>
#define int long long
#define lc p*2
#define rc p*2+1
using namespace std;
int n,m,k,o,l,r;
int a[10000005];
struct node{
	int l;//左端点 
	int r;//右端点 
	int data;//区间和 
	int tag_max_1;//区间最大值 
	int tag_max_add_1;//区间最大值lazy_tag 
	int tag_max_2;//区间次大值 
	int tag_max_add_2;//区间非最大值lazy_tag 
	int tag_max_1_old;//区间历史最大值 
	int tag_max_add_1_old;//区间历史最大值lazy_tag 
	int tag_max_2_old;//区间历史次大值 
	int tag_max_add_2_old;//区间历史非最大值lazy_tag 
	int tag_max_cnt;//最大值的个数 
}tree[1000005*4];
int read(){
    char c=getchar();int s=0,f=1;
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())s=s*10+c-48;
    return s*f;
}//读入优化 


void push_up(int p){//合并区间 
	tree[p].tag_max_1=max(tree[lc].tag_max_1,tree[rc].tag_max_1);//更新区间最大值 
	tree[p].tag_max_1_old=max(tree[lc].tag_max_1_old,tree[rc].tag_max_1_old);//更新历史区间最大值 
	tree[p].data=tree[lc].data+tree[rc].data;//更新区间和 
	if(tree[lc].tag_max_1==tree[rc].tag_max_1){//如果整个区间最大值两边都有 
		tree[p].tag_max_2=max(tree[lc].tag_max_2,tree[rc].tag_max_2);//更新区间次大值为两边次大值中的最大值 
		tree[p].tag_max_cnt=tree[lc].tag_max_cnt+tree[rc].tag_max_cnt;//更新区间最大值个数为两边最大值个数之和 
	}
	if(tree[lc].tag_max_1>tree[rc].tag_max_1){//如果区间最大值位于左边 
		tree[p].tag_max_2=max(tree[lc].tag_max_2,tree[rc].tag_max_1);//更新区间次大值为左边次大值与右边最大值中的最大值 
		tree[p].tag_max_cnt=tree[lc].tag_max_cnt;//最大值个数为左边最大值的个数 
	}
	if(tree[lc].tag_max_1<tree[rc].tag_max_1){//如果区间最大值位于右边 
		tree[p].tag_max_2=max(tree[lc].tag_max_1,tree[rc].tag_max_2);//区间最大值为左边最大值与右边次大值中的最大值 
		tree[p].tag_max_cnt=tree[rc].tag_max_cnt;//区间最大值个数为右边最大值的个数 
	}
}
void update(int k1,int k2,int k3,int k4,int p){
	//k1表示区间最大值要加的数，k2表示历史最大值要加的数，k3表示非最大值要加的数，k4表示非历史最大值最大值要加的数 
	tree[p].data+=k1*tree[p].tag_max_cnt+k3*(tree[p].r-tree[p].l+1-tree[p].tag_max_cnt);//更新区间和 
	tree[p].tag_max_1_old=max(tree[p].tag_max_1_old,tree[p].tag_max_1+k2);
	tree[p].tag_max_add_1_old=max(tree[p].tag_max_add_1_old,tree[p].tag_max_add_1+k2);
	tree[p].tag_max_add_2_old=max(tree[p].tag_max_add_2_old,tree[p].tag_max_add_2+k4);
	//如果当前区间的最大值加上最大的历史最大值要加的数大于原来的最大的历史最大值，就将值更新。如果值更新了，说明最大的历史最大值变了，那么懒标记肯定也要变。最后还要更新普通的历史最大值的懒标记
	tree[p].tag_max_add_1+=k1;//更新区间最大值lazy_tag 
	tree[p].tag_max_1+=k1;//更新区间最大值 
	tree[p].tag_max_2+=k3;//更新非区间最大值 
	tree[p].tag_max_add_2+=k3;//更新非区间最大值lazy_tag 
	if(tree[p].tag_max_2!=-1e18)tree[p].tag_max_2_old+=k3;//如果当前区间有次大值，那么次大值加上普通lazy_tag 
}
void push_down(int p){//下传懒标记 
	int maxn=max(tree[lc].tag_max_1,tree[rc].tag_max_1);//取出区间最大值 
	if(tree[lc].tag_max_1==maxn){//如果区间最大值位于左区间 
		update(tree[p].tag_max_add_1,tree[p].tag_max_add_1_old,tree[p].tag_max_add_2,tree[p].tag_max_add_2_old,lc);
		//向右儿子传递最大值lazy_tag 
	}else{
		update(tree[p].tag_max_add_2,tree[p].tag_max_add_2_old,tree[p].tag_max_add_2,tree[p].tag_max_add_2_old,lc);
		//否则向右儿子传递非最大值lazy_tag 
	} 
	if(tree[rc].tag_max_1==maxn){//如果区间最大值位于右区间 
		update(tree[p].tag_max_add_1,tree[p].tag_max_add_1_old,tree[p].tag_max_add_2,tree[p].tag_max_add_2_old,rc);
		//向左儿子传递区间最大值lazy_tag 
	}else{
		update(tree[p].tag_max_add_2,tree[p].tag_max_add_2_old,tree[p].tag_max_add_2,tree[p].tag_max_add_2_old,rc);
		//否则向右儿子传递非最大值lazy_tag
	}
	tree[p].tag_max_add_1=tree[p].tag_max_add_1_old=tree[p].tag_max_add_2=tree[p].tag_max_add_2_old=0;
	//清除lazy_tag 
}
void build(int p,int l,int r){//建树 
	tree[p].l=l;//存储左端点 
	tree[p].r=r;//存储右端点 
	if(l==r){//若果访问到叶子节点 
		tree[p].data=a[l];//因为当前节点只有一个元素，所以区间和为它本身 
		tree[p].tag_max_1=a[l];//因为当前区间只有一个元素，所以最大值就是它本身 
		tree[p].tag_max_1_old=a[l];//历史最大值赋值为当前元素 
		tree[p].tag_max_2=-1e18;//因为当前区间只有一个元素，所以不存在次大值，赋值为无穷小 
		tree[p].tag_max_cnt=1;//最大值只有一个也就是它本身
		return;//返回 
	}
	int mid=(l+r)/2;
	build(lc,l,mid);//递归建造左区间 
	build(rc,mid+1,r);//递归建造右区间 
	push_up(p);//合并区间 
}
void change_1(int p){//区间加 
	if(tree[p].l>r||tree[p].r<l) return;//如果当前区间不在目标范围内，直接返回 
	if(l<=tree[p].l&&tree[p].r<=r){//如果当前区间在完全在目标范围内 
		update(k,k,k,k,p);//更新值和lazy_tag 
		return; //返回 
	}
	push_down(p);//下传lazy_tag 
	change_1(lc),change_1(rc);//分左右递归 
	push_up(p);//合并区间 
}
void change_2(int p){//区间min修改 
	if(tree[p].l>r||tree[p].r<l||k>=tree[p].tag_max_1)return;//如果当前节点不在目标范围内，或者是区间最大值都比min数小，就没有继续递归下去的必要了 
	if(l<=tree[p].l&&tree[p].r<=r&&k>tree[p].tag_max_2){//如果当前区间在范围内，且min数比次大值大 
	    update(k-tree[p].tag_max_1,k-tree[p].tag_max_1,0,0,p);//则下传lazy_tag 
		return;
	}
	push_down(p);//下传lazy_tag 
	change_2(lc),change_2(rc);//递归左右区间 
	push_up(p);//更新区间 
}
int ask_1(int p){//区间求和 
	if(tree[p].l>r||tree[p].r<l)return 0;//如果当前节点在目标范围之外，直接返回0，不影响区间求和 
	if(l<=tree[p].l&&tree[p].r<=r)return tree[p].data;//如果当前区间完全在范围之内，直接返回当前区间和 
	push_down(p);//如果有积压的工作，直接通过下传lazy_tag的方式做完 
	return ask_1(lc)+ask_1(rc);//返回左区间与右区间的和 
}
int ask_2(int p){//求区间最大值 
	if(tree[p].l>r||tree[p].r<l)return -1e18;//如果当前节点在目标范围之外，直接返回无穷小，不影响求区间最大值 
	if(l<=tree[p].l&&tree[p].r<=r)return tree[p].tag_max_1;//如果当前区间完全在范围之内，直接返回当前区间最大值 
	push_down(p);//如果有积压的工作，直接通过下传lazy_tag的方式做完  
	return max(ask_2(lc),ask_2(rc));//返回左区间与右区间的区间最大值的最大值 
}
int ask_3(int p){//求区间历史最大值 
	if(tree[p].l>r||tree[p].r<l)return -1e18;//如果当前节点在目标范围之外，直接返回无穷小，不影响求区间历史最大值
	if(l<=tree[p].l&&tree[p].r<=r)return tree[p].tag_max_1_old;//如果当前区间完全在范围之内，直接返回当前区间历史最大值 
	push_down(p);//如果有积压的工作，直接通过下传lazy_tag的方式做完
	return max(ask_3(lc),ask_3(rc));//返回左区间与右区间的区间历史最大值的最大值 
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		// a[i]=read();
        cin >> a[i];
	}
	//输入 
	build(1,1,n);//调用建树函数 
	for(int i=1;i<=m;i++){
		o=read(),l=read(),r=read();
		if(o==1)k=read(),change_1(1);
		if(o==2)k=read(),change_2(1);
		if(o==3)printf("%lld\n",ask_1(1));
		if(o==4)printf("%lld\n",ask_2(1));
		if(o==5)printf("%lld\n",ask_3(1));
	}
	return 0;
} 