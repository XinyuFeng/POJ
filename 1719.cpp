#include <iostream>

using namespace std;
int m, n;
int map[1001][1001];
int cnk[1001];
int match[1001];

int result;

int dfs(int p){
    for(int i=0; i<n; ++i){
        if(cnk[i]==0 && map[p][i]==1){
            cnk[i]=1;
            int t=match[i];
            match[i]=p;
            if(t==-1 || dfs(t)){
                return 1;
            }
            match[i]=t;
            
        }
    }
    return 0;
}

int check(){
    int ans=0;
    memset(match, -1, sizeof(match));
    for(int i=0; i<m; ++i){
        memset(cnk, 0, sizeof(cnk));
        if(dfs(i)==1) ans++;
    }
    return ans;
    
}

int main(){
    int c;
    cin>>c;
    while(c--){
        cin>>m>>n;
        memset(map, 0, sizeof(map));
        
        for(int i=0; i<n; ++i){
            int a, b;
            cin>>a>>b;
            map[a-1][i]=1;
            map[b-1][i]=1;
        }
        result=check();
        
        if(result==m){
            for(int i=0; i<n-1; ++i){
                if(match[i]!=-1)
                    cout<<match[i]+1<<' ';
                else{
                    for(int j=0; j<m; ++j){
                        if(map[j][i]==1){
                            cout<<j+1<<' ';
                            break;
                        }
                        
                        
                    }
                }
            }
            if(match[n-1]==-1){
                for(int j=0; j<m; ++j){
                    if(map[j][n-1]==1){
                        cout<<j+1<<endl;
                        break;
                    }
                        
                }
            }
            else
                cout<<match[n-1]+1<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
