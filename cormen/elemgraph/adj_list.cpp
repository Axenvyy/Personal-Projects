#include <vector>
#include <iostream>
#include <random>

using namespace std;

//erdos - renyi model

vector<vector<int>> randomgraph(int v){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> r(0,1);

    double p= r(gen);

    cout<<"generating graph with "<<v<<" vertices with p = "<<1.00-p<<"\n";

    vector<vector<int>> g(v);

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
        double p_e=r(gen);
        if (p_e>p){g[i].push_back(j);}
        

    }

} cout<<"graph generated\n";
return g;}

void printg(const vector<vector<int>>& g){
    cout<<"printing graph g with "<<g.size()<<" vertices\n";
    for(vector<int> v:g){for (int e:v){cout<<e<<" ";}cout<<"\n";}
}

int main(){

    auto g= randomgraph(50);
    printg(g);

    

}