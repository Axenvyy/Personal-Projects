#include <iostream>
#include <vector>
#include <random>
#include <climits>

#include <utility>
using namespace std;

void print(const vector<vector<int>>& c, vector<int> w, vector<int> v, int i, int W){
    if(i==0||W==0){return;}
    if( c[i-1][W]==c[i][W]){print(c,w,v,i-1,W);}
    else {print(c,w,v,i-1,W-w[i]);cout<<i<<" ";}
}
int main(){

    int n=10;
    int W=5;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> vd(1,10);
    uniform_int_distribution<> wd(1,10);

    vector<int> vl(n,0);
    vector<int> wl(n,0);

    for(int& x: vl){x=vd(gen)*10;}
    for(int& x: wl){x=wd(gen);}

    vector<vector<int>> c(n+1,vector<int> (W+1,0));

    for (int i=1;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(w<wl[i]){c[i][w]=c[i-1][w];}
            else {c[i][w]=max(vl[i]+c[i-1][w-wl[i]],c[i-1][w]);}
        }
    }

    cout<<c[n][W]<<"\n";

    print(c,wl,vl,n,W);
}