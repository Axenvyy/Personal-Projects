#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <utility>

using namespace std;

int main(){

 vector<int> denom{1,2,5,10,20,25,50};
 random_device rd;
 mt19937 gen(rd());
 uniform_int_distribution<> binary(0,1);
 uniform_int_distribution<> value_dist(100,200);


 vector<int> seed(denom.size(),false);
 for(auto& x: seed){x=binary(gen);}
 seed[0]=1;

 vector<int> availdenom;

 for(int i=0;i<denom.size();i++){
    if(seed[i]==1){availdenom.push_back(denom[i]);}
 }

 int value= value_dist(gen);


 vector<vector<int>> c(availdenom.size()+1,vector<int>(value+1,0));
 vector<int> &avd=availdenom;
 for(int i=0;i<=value;i++){c[0][i]=0;};
 for(int i=0;i<=availdenom.size()+1;i++){c[i][0]=0;};

 for(int i=1;i<=availdenom.size();i++){
    for(int j=1;j<=value;j++){if(avd[i]<value){c[i][j]=min(c[i-1][j],1+c[i-1][j-avd[i]]);}}
 }




}
