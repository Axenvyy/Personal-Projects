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

 return v;
}

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

    auto a=rrvector(gen,r);
    print(a);
    


}