#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<vector<int>> gt(const vector<vector<int>>& g){
    int v=g.size();

    vector<vector<int>> gt(v);
    for(int i=0;i<v;i++){
        for(int j=0;j<g[i].size();j++){int t= g[i][j];gt[t].push_back(i);}
    }
 return gt;
}

vector<vector<int>> g2 (const vector<vector<int>>& g){
    int v= g.size();
    vector<vector<int>> g2(v);

    for (int i=0;i<v;i++){
        for (int x:g[i]){for(int y: g[g[i][x]]){g2[i].push_back(y);}}
    }
}

int sink(const vector<vector<int>>& p){//this algo is for adj matrix and is linear in v not usual v2
    int v= p.size();
    vector<bool> can (v,true);

    int i=0; int j=0;
    int n=v;
    while(n){if(i==v||j==v){break;
    if(p[i][j]==1){can[i]=0;i++;n--;}
    else{can[j]=0;j++;n--;}}
}

for(int i=0;i<v;i++){if (can[i]){return i;}}//in improvement check all elements of p[i], p[i][j]=1, p[i][i]=0;
return -1;
}
    
    
int main(){}