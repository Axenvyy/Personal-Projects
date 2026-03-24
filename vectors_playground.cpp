#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;


int main(){

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution r(1,100);


    int N= r(gen);

    vector<vector<int>> v;

for(int i=0;i<N;i++){

    int n= r(gen);

    vector<int> temp(n);
    for (int j=0;j<n;j++){
        temp.push_back(r(gen));
    }

    v.push_back(temp);


}

for (int i=0;i< v.size();i++){
    for(int x: v[i]){cout<<x<<" ";}
    cout<<"/n";
}
 
}