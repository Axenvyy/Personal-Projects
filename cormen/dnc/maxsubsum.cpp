#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <climits>
using namespace std;

int kadane(const vector<int>& arr, int& begin, int& end ){

    int n=arr.size();
    int acc=0;
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(acc<0){
            acc=arr[i];
            begin=i;
        }
        int bestl,bestr;

        if(acc>max){
            max=acc;bestl=begin;bestr=i;

        }

         
    }
    return acc;
}

int main(){

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> r(-20,50);

    vector<int> arr(500,0);
    cout<<"vector is ";
    for(int& x:arr){x=r(gen);cout<<x<<" ";}
    cout<<"\n";
    int start,endd;

    /*int* begin; int* end;
    int acc=0;
    begin=&arr[0];
    for(int i=0;i<500;i++){
        if(acc<0){acc=0;begin=&arr[i];}
        acc+=arr[i];
        

    }
     acc=0;

    end=&arr[499];
    for(int i=499;i<=0;i--){
        if(acc<0){acc=0;end=&arr[i];}
        acc+=arr[i];
        

    }

    auto it = begin;
   
    int sum=0;
    while(it!=end){sum+=*it;it++;}

    cout<<"max subarray sum is "<<sum<<".\n";*/


    cout<<"max by kadane's algo is "<<kadane(arr,start,endd)<<"./n with index "<<start<<" and "<<endd<<"\n";
    


    

}