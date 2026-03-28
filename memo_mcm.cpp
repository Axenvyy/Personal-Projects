#include <iostream>
#include <vector>
#include <random>
#include <climits>

using namespace std;

int lookup(const vector<int> & p, int i, int j,vector<vector<int>>& m){
    if(m[i][j]<INT_MAX){return m[i][j];}
    if(i==j){return 0;}
    else for(int k=i;k<j;k++){
        int q= lookup(p,i,k,m)+lookup(p,k+1,j,m)+p[i-1]*p[k]*p[j];
        if (q<m[i][j]){m[i][j]=q;}
    }
    return m[i][j];
}
int mcm(vector<vector<int>>& m, const vector<int>& p){
    int n=p.size();
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
        m[i][j]=INT_MAX;
    };}
    return lookup(p,1,n,m);
}

int main(){
    int n;
    cin>>n;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(2,100);

    vector<int> p(n+1,0);
    for (int& x:p){x=dist(gen);}

    vector<vector<int>> m(n+1,vector<int>(n+1,0));

    for(int i=0;i<n+1;i++){m[i][i]=0;}
    cout<<mcm(m,p);

}