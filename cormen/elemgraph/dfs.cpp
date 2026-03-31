#include <iostream>
#include <vector>
#include <climits>
#include <random>

using namespace std;

int time=0;


void visit(int i, const vector<vector<int>>& g, vector<int>& p,
    vector<int>& color, vector<pair<int,int>>& timest){
        color[i]=1;
        time++;
        timest[i].first=time;

     for(int v=0;v<g[i].size();v++){if (color[v]==0){
        
        p[v]=i;
        visit(v,g,p,color,timest);
        
     }}
}

void dfs(const vector<vector<int>>& g){
    int v= g.size();

    vector<int> color(v,0);
    vector<int> p(v,-1);

    vector<pair<int,int>>timest(v,{-1,-1});
    for(int i=0;i<v;i++){if (color[i]==0){visit(i,g,p,color,timest);}

    color[i]=2; time++;
    timest[i].second=time;}


}

//dfs done in two steps for all v with color= white visit (v)
//define visit as { color =gray;set visit time; for all u of v,
// if color=white visit u, set predecessor}
//then color= black 
//set finish time