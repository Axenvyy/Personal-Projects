#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <climits>
using namespace std;

int kadane(const vector<int>& arr, int& start, int& end ){


    int n=arr.size();
    int acc=0;
    int bestl;
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(acc<0){
            acc=0;
            start=i;
        }
        acc+=arr[i];
        

        if(acc>max){
            max=acc;bestl=start;end=i;

        }
       
         
    }
   
    return max;
}

int main(){

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> r(-20,10);

    vector<int> arr(500,0);
    cout<<"vector is ";
    int i=0;
    for(int& x:arr){x=r(gen);cout<<"("<<i<<")"<<x<<" ";i++;}
    cout<<"\n";
    int start=0;int endd=0;

    int* begin; int* end;
    int acc=0;
    begin=&arr[0];
    for(int i=0;i<500;i++){
        if(acc<0){acc=0;begin=&arr[i];start=i;}
        acc+=arr[i];
        

    }
     acc=0;

    end=&arr[499];
    for(int i=499;i<=0;i--){
        if(acc<0){acc=0;end=&arr[i];endd=i;}
        acc+=arr[i];
        

    }

    auto it = begin;
   
    int sum=0;
    while(it<=end){sum+=*it;it++;}

    cout<<"max subarray sum is "<<sum<<".\n"<<"with index "<<start<<" and "<<endd<<"\n\n";
    endd=0;start=0;
    int maxx=kadane(arr,start,endd);


    cout<<"max by kadane's algo is "<<maxx<<".\n with index "<<start<<" and "<<endd<<"\n";
    


    

}