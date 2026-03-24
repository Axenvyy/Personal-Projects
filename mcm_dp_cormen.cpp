#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <climits>

using namespace std;

void mcm(const vector<int>& p, vector<vector<int>>& s, vector<vector<int>>& m);
    void print(const vector<vector<int>>& s,int i, int j);


int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> r(2,100);

    int k;
    cin>> k;

    vector<vector<int>> m(k,vector<int>(k,0));
    vector<vector<int>> s(k,vector<int>(k,0));
    
   
    vector<int> p(k);
    for( int& x: p){x=r(gen);}

    
    mcm(p,s,m);
    print(s,0,k-2);

}

    void mcm(const vector<int>& p,vector<vector<int>>& s,vector<vector<int>>& m){int n= p.size()-1;
    for (int i=0;i<n;i++){m[i][i]=0;}
    for (int l=1;l<n;l++){
        for (int i = 0; i < n - l; i++){
            int j=i+l;
            m[i][j]=INT_MAX;
            for (int l=i;l<j;l++){
                int q= m[i][l]+m[l+1][j]+p[i]*p[l+1]*p[j+1];
                if(q<m[i][j]){m[i][j]=q;s[i][j]=l;}
            }
        }
    }
}

void print(const vector<vector<int>>& s,int i, int j){
    if(i==j){cout<<"A"<<i<<" ";}
    else {cout<<"(";print(s,i,s[i][j]);print(s,s[i][j]+1,j);cout<<")";}
}
    
    