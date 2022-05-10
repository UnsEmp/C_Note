#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int t[4*100009];
int up[4*100009];
int n,m;
void build(int rt,int l,int r)
{
    if(l==r)
    {
        t[rt]=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    t[rt]=t[rt<<1]+t[rt<<1|1];
}
void push_down(int rt,int l,int r)
{
    if(up[rt])
    {
        int mid=(l+r)>>1;
        t[rt<<1]=up[rt]*(mid-l+1);
        t[rt<<1|1]=up[rt]*(r-mid);
        up[rt<<1]=up[rt];
        up[rt<<1|1]=up[rt];
        up[rt]=0;
    }
}
void update(int rt,int l,int r,int x,int y,int val)
{
   if(x<=l&&r<=y)
   {
       t[rt]=val*(r-l+1);
       up[rt]=val;
       return ;
   }
   if(up[rt])
   push_down(rt,l,r);
   int mid=(l+r)>>1;
   if(x<=mid)
    update(rt<<1,l,mid,x,y,val);
   if(y>mid)
    update(rt<<1|1,mid+1,r,x,y,val);
   t[rt]=t[rt<<1]+t[rt<<1|1];
}
int query(int rt,int l,int r,int x,int y)//本题中不需要使用这个函数
{
    if(x<=l&&r<=y)
        return t[rt];
    if(up[rt])
        push_down(rt,l,r);
    int mid=(l+r)>>1;
    int sum=0;
    if(x<=mid)
        sum+=query(rt<<1,l,mid,x,y);
    if(y>mid)
        sum+=query(rt<<1|1,mid+1,r,x,y);
    return sum;
}
void print() {
    for(int i = 1;i <= n;++i) cout << query(1, 1, n, i, i) << " ";
    cout << "\n";
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    n = 5;
    update(1, 1, n, 2, 4, 1);
    print();
    update(1, 1, n, 1, 3, 1);
    print();
    update(1, 1, n, 3, 5, 2);
    // cout << query(1, 1, n, 3, 4) << "\n";
    print();
    // build(1, 1, n);
    // int T;
    // cin>>T;
    // for(int i=1;i<=T;i++)
    // {
    //     cin>>n>>m;
    //     build(1,1,n);
    //     memset(up,0,sizeof(up));
    //     int x,y,z;
    //     while(m--)
    //     {
    //         cin>>x>>y>>z;
    //         update(1,1,n,x,y,z);
    //     }
    //     cout<<"Case "<<i<<": "<<"The total value of the hook is "<<t[1]<<"."<<'\n';
    // }
    // return 0;
}

// int main() {
// //   build(1, n, 1);
//     n = 5;
//     memset(b, 0, sizeof b);
//     memset(d, 0, sizeof d);
//     memset(a, 0, sizeof a);
//     update(2, 4, 1, 1, n, 1);
//     print();
//     update(1, 3, 1, 1, n, 1);
//     print();
//     update(3, 5, 0, 1, n, 1);
//     print();
//   return 0;
// }