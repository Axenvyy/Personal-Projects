#include <iostream>
#include <vector>
#include <random>
#include <utility>

//indexing solution needed

using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> r1(50,250);
    uniform_int_distribution<> r2(1,26);



    int m=r1(gen); int n=r1(gen);
    vector<int> y (n,0);vector<int> x (m,0);

    for(int& z:x){z=r2(gen);};
    for(int& z:y){z=r2(gen);};

    vector<vector<int>> c (m,vector<int>(n,0));

    for(int i=0;i<m;i++){c[i][0]=0;};
    for(int i=0;i<n;i++){c[0][i]=0;};

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(x[i]!=y[j]){c[i][j]=max(c[i-1][j],c[i][j-1]);}

            if(x[i]==y[j]){c[i][j]=c[i-1][j-1]+1;}

        };
    }

    cout<<x.size()<<" "<<y.size()<<" "<<c[m-1][n-1];
}