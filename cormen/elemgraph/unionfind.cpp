  
#include <vector>

using namespace std;

class UnionFind{

    int size;
    vector<int> sz;
    vector<int> id;

    int numComponents;

    UnionFind(int n):size(n),sz(vector<int>(n,1)),id(vector<int>(n,0)){
        for(int i=0;i<n;i++){id[i]=i;}
    }

    int find(int p){
        int root=p;
        while(root != id[root]){int next=id[p];id[p]=root;p=next;}
        return root;

    }

    bool connected(int p, int q){return find(p)==find(q);}

    int componentSize(int p){return sz[find(p)];}

    int size(){return size;}

    int components(){return numComponents;}

    void unify(int p, int q){id[find(q)]=id[find(p)];sz[find(p)]+=sz[find(q)];numComponents--;}

};