#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <algorithm>
#define Init(msg) vector<int> msg##i(n); for (int& x:msg##i){x=r(gen); cout<<x<<" ";} cout<<"\nthat was "<<#msg<<"\n";
#define iter(msg) 
using namespace std;

int main()
{

    int n;
    cin>>n;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> r(1,100);

    Init(x);
    Init(y);
    Init(sy);
    Init(sx);

    vector<int> delx(n);
    for(int i=0;i<n;i++){delx.at(i)=x.at(i)-y.at(i)-sy.at(i);}
    vector<int> dely(n);
    for(int i=0;i<n;i++){dely.at(i)=y.at(i)-x.at(i)-sx.at(i);}

    auto it= max_element(delx.begin(),delx.end());

    

}