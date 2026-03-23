#include <iostream>
#include <vector>
#include <random>
#define Init(msg) vector<int> msg##i(n); for (int& x:msg##i){x=r(gen); cout<<x<<" ";}

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
    Init(s);

}