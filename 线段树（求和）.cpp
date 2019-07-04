#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
const int maxn = 2e5+300;
const int inf = 0x3f3f3f3f;
using namespace std;

int N,M,a[maxn],Sum[maxn<<2],pos[maxn];

//更新当前节点
void pushup(int rt){
    Sum[rt] = Sum[rt<<1] + Sum[rt<<1|1];
}


//l:当前节点的左端点 r：当前节点的右端点 rt:当前节点的编号
void build(int l,int r,int rt){
    if(l == r){
        pos[l] = rt;
        Sum[rt] = a[l];
        return;
    }
    int m = (l+r) >> 1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}

//l:当前节点的左端点 r：当前节点的右端点 rt:当前节点的编号 [L,R]查询的区间
int query(int L,int R,int l,int r,int rt){
    if(L <= l && R >= r) return Sum[rt];
    int m = (l+r) >> 1;
    int res = 0;
    if(L <= m) res += query(L,R,l,m,rt<<1);
    if(R > m) res += query(L,R,m+1,r,rt<<1|1);
    return res;
}

//l:当前节点的左端点 r：当前节点的右端点 rt:当前节点的编号 将L的值改为V
void update(int L,int V,int l,int r,int rt){
    if(l==r){Sum[rt]=V;return;}
    int m = (l+r) >> 1;
    if(L <= m) update(L,V,l,m,rt<<1);
    else update(L,V,m+1,r,rt<<1|1);
    pushup(rt);
}



int main(){

}
