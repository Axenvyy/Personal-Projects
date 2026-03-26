#include <iostream>
#include <vector>
#include <random>
#include <climits>

using namespace std;

int main(){

    int n;
    cin>>n;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> r(2,100);

    vector<int> p(n+1,0);
    for(int& x:p){x=r(gen);}

    vector<vector<int>> c(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++){c[i][i]=0;}
    for(int k=0;k<n;k++){
        for(int j=0;;j++){
            if(j+k>=n){break;}
            for(int q=0;q<k;q++){
                int s= c[j][j+q]+c[j+q+1][j+k]+p[j]*p[j+q+1]*p[j+k+1];
                if(c[j][j+k]>s){c[j][k+j]=s;}

        }
    }
    }

    cout<<c[0][n-2];

}
