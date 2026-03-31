#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <climits>

using namespace std;

//bfs takes a graph adjacency list and a source
//distacne from s for each reachable vertex
//it produces a bfs tree
//d[u] color[u] predecessor[u]

void bfs(const vector<vector<int>>& p, int s){

    int v=p.size();

    vector<int> color(v,0);
    vector<int> d(v,INT_MAX);
    vector<int> pre(v,-1);


    color.at(s)=2;
    d.at(s)=0;

    queue<int> q;

    //coloring is like
    //0 undiscovered
    //1 discovered n qed;
    //2 processed and dqed
    // q only if white
    //thus color =1 after qing, happens only once

    q.push(s);
    while(!q.empty()){
        int u= q.front(); q.pop();
        for(int x:p[u]){if(color[x]==0){
            color[x]=1;
            d[x]=d[u]+1;
            pre[x]=u;
            q.push(x);
        }
    }
    color[u]=2;
    }

}