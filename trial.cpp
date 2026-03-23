#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> r(1,100);

    vector<int> v(n);
    for(int& x:v){x=r(gen);cout<<x<<" ";}
    
}