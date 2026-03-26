#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

vector<vector<int>> rrvector( mt19937 gen, uniform_int_distribution<> r){
    int N= r(gen);

    vector<vector<int>> v;

for(int i=0;i<N;i++){

    int n= r(gen);

    vector<int> temp;
    temp.reserve(n);
    for (int j=0;j<n;j++){
        temp.push_back(r(gen));
    }

    v.push_back(temp);

 
}
return v;
};

void print(vector<vector<int>>& a){for (int i=0;i< a.size();i++){
    for(int x: a[i]){cout<<x<<" ";}
    cout<<"\n";
}
}

int main(){

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> r(1,20);

    auto a1=rrvector(gen,r);
    print(a1);
    
    vector<vector<int>> a;

    //a=vector<vector<int>>(5,vector<int>(5,0));
    // now edit by index, kind of reserved space

    //indexes go as a(0,0) to a(4,4)
    for( int k=0;k<2;k++){
    for (int i=0;i<5;i++){
        //for n rows from 0 to n-1 we will pushback a vector with f(i) dimensions 
        //here f(i)=i+1
    a.push_back(vector<int>(i+1,0));}}

    vector<vector<int>> b;

    for(int i=0;i<11;i++){
        int k=25-((i-5)*(i-5)); if(k!=0){
        b.push_back(vector<int>(k,0));}
    }

    cout<<b.size();
    print(b);
    print(a);
}