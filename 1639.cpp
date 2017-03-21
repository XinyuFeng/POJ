#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn=25;
int m, n, k, g[maxn][maxn], dis[maxn], pre[maxn], ans;
bool vis[maxn], link[maxn][maxn];

struct node{
    int u, v, len;
    node(){}
    node(int u, int v, int len):u(u), v(v), len(len){}
}del[maxn];
int kk;
void prim(int st){
    vis[st]=1;
    memset(pre, -1, sizeof(pre));
    for(int i=1; i<n; ++i){
        dis[i]=g[st][i];
        pre[i]=st;
    }
    while(1){
        int tmp=inf, nt=st;
        for(int i=1; i<n; ++i){
            if(!vis[i] and dis[i]<tmp){
                nt=i;
                tmp=dis[i];
            }
        }
        if(st==nt) break;
        if(g[0][nt]<g[0][kk]) kk=nt;
        link[pre[nt]][nt]=link[nt][pre[nt]]=1;
        vis[nt]=1;
        ans+=dis[nt];
        for(int i=1; i<n; ++i){
            if(!vis[i] and dis[i]>g[nt][i]){
                pre[i]=nt;
                dis[i]=g[nt][i];
            }
        }
    }
}

void dfs(int cur, int cpre, int u, int v){
    for(int i=1; i<n; ++i){
        if(cpre!=i and link[cur][i]){
            if(cpre==-1 or g[cur][i]>=g[u][v]){
                del[i]=node(cur, i, g[cur][i]);
                dfs(i, cur, cur, i);
            }
            else{
                del[i]=node(u, v, g[u][v]);
                dfs(i, cur, u, v);
            }
        }
    }
    
}

void solve(){
    for(int i=1;i<n; ++i){
        if(vis[i]) continue;
        k--;
        kk=i;
        prim(i);
        ans+=g[0][kk];
        link[kk][0]=link[0][kk]=1;
        dfs(kk,-1,-1,-1);
    }
    while(k--){
        int c=0, nt=0;
        for(int j=1; j<n; ++j){
            if(link[0][j] or g[0][j]==inf) continue;
            if(c<del[j].len-g[0][j]){
                nt=j;
                c=del[j].len-g[0][j];
            }
        }
        if(c==0) break;
        ans-=c;
        link[del[nt].u][del[nt].v]=link[del[nt].v][del[nt].u]=false;
        link[0][nt]=link[nt][0]=1;
        dfs(nt, 0, -1, -1);
    }
    cout<<"Total miles driven: "<<ans<<endl;
}

void init(){
    char s1[20], s2[20];
    int w,u,v;
    n=0;
    map<string, int> name;
    map<string, int>::iterator it1, it2;
    name.clear();
    name["Park"]=n++;
    memset(g, 0x3f, sizeof(g));
    memset(vis, 0, sizeof(vis));
    memset(link, 0, sizeof(link));
    for(int i=0; i<m; ++i){
        cin>>s1>>s2>>w;
        it1=name.find(s1);
        it2=name.find(s2);
        if(it1 != name.end()) u=it1->second;
        else{
            name[s1]=n;
            u=n++;
        }
        if(it2!=name.end()) v=it2->second;
        else{
            name[s2]=n;
            v=n++;
        }
        if(g[u][v]>w){
            g[u][v]=g[v][u]=w;
        }
    }
    cin>>k;
    ans=0;
}

int main(){
    while(cin>>m){
        init();
        solve();
    }
    return 0;
}
