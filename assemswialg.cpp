#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#define li[j](msg1,msg2) l#msg1##[msg2]
using namespace std;

int main(){
    int n;
    cin>>n;

    random_device rd;

    mt19937 gen(rd());
    uniform_int_distribution<> r(1,100);

    vector<int> a1(n);
    vector<int> a2(n);
    vector<int> t1(n);
    vector<int> t2(n);

    vector<int> l1(n);
    vector<int> l2(n);
    int l; int f;

    int e1,e2;
    int x1,x2;

    for(int& x: a1){x=r(gen);}
    for(int& x: a2){x=r(gen);}
    for(int& x: t1){x=r(gen);}
    for(int& x: t2){x=r(gen);}
    
    vector<int> f1(n);
    vector<int> f2(n);

    f1.at(1)=e1+a1[1];
    f2.at(1)=e2+a2[1];

    for(int j=2;j<=n;j++){
        if( f1[j-1]+a1[j]<=f2[j-1]+t2[j-1]+a1[j]){f1[j]=f1[j-1]+a1[j];l1[j]=1;}
        else {f1[j]=f2[j-1]+t2[j-1]+a1[j];l1[j]=2;}
        if( f2[j-1]+a2[j]<=f1[j-1]+t1[j-1]+a2[j]){f2[j]=f2[j-1]+a2[j];l2[j]=1;}
        else {f2[j]=f1[j-1]+t1[j-1]+a2[j];l2[j]=2;}
    }

    if (f1[n]+x1<=f2[n]+x2){f=f1[n]+x1;l=1;}
    else{f=f2[n]+x2;l=2;}

    int i=l;
    cout<<"line "<< i<<" station "<< n<<"\n";
    for (int j=2; j<=n;j++){cout<<"line "<< li[j](l,j)<<" station "<<j-1}
}