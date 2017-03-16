//
//  main.cpp
//  POJ
//
//  Created by Feng Xinyu on 3/15/17.
//  Copyright © 2017 Feng Xinyu. All rights reserved.
//

#include <iostream>
using namespace std;

int d[103][103][103][2];

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    
    
    while(cin>>n>>m){
        d[0][0][0][0]=d[0][0][0][1]=0;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=i; ++j){
                int p=i-j;
                for(int u=0; u<=p; ++u){
                    int q=i-j-u;
                    int maxp=0;
                    for(int v=1; v<=m; ++v){
                        if(v>j) break;
                        else if(v==j){
                            if(i-d[i-u-v][i-u-v][0][1]>maxp)
                                maxp=i-d[i-u-v][i-u-v][0][1];
                        }
                        else{
                            if(i-d[i][j-v][u+v][1]>maxp)
                                maxp=i-d[i][j-v][u+v][1];
                        }
                    }
                    d[i][j][u][0]=maxp;
                    maxp=0;
                    for(int v=1; v<=m; ++v){
                        if(v>j) break;
                        else if(v==j){
                            if(i-d[i-v-q][i-v-q][0][0]>maxp)
                                maxp=i-d[i-q-v][i-q-v][0][0];
                        }
                        else{
                            if(i-d[i][j-v][u][0]>maxp)
                                maxp=i-d[i][j-v][u][0];
                        }
                    }
                    d[i][j][u][1]=maxp;
                }
            }
        }
        cout<<d[n][n][0][0]<<endl;
        
    }

    return 0;
}
