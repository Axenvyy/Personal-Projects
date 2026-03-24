#include <iostream>
#include <vector>
#include <random>
#include <utility>

using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> r(2,100);

    int k;
    cin>> k;

    vector<vector<int>> m;
    m.reserve(k);
    for(auto& x:m){x.reserve(k);}
    vector<vector<int>> s;
    s.reserve(k);
    for(auto& x:s){x.reserve(k);}
   
    vector<int> p(k-1);
    for( int& x: p){x=r(gen);}

    void mcm(vector<int> p, vector<vector<int>>& s, vector<vector<int>>& m);
    void print(const vector<vector<int>>& s,int i, int j);

    mcm(p,s,m);
    print(s,1,k);

}

    void mcm(vector<int> p,vector<vector<int>>& s,vector<vector<int>>& m){int n= p.size()-1;
    for (int i=0;i<n;i++){m[i][i]=0;}
    for (int l=1;l<n;l++){
        for (int i=0;i<n-2+l;i++){
            int j=i+l-1;
            m[i][j]=INFINITY;
            for (int l=i;l<j;l++){
                int q= m[i][l]+m[l+1][j]+p[i-2]*p[l-1]*p[j-1];
                if(q<m[i][j]){m[i][j]=q;s[i][j]=l;}
            }
        }
    }
}

void print(const vector<vector<int>>& s,int i, int j){
    if(i==j){cout<<i<<" ";}
    else {cout<<"(";print(s,i,s[i][j]);print(s,s[i][j]+1,j);cout<<")";}
}
    
    