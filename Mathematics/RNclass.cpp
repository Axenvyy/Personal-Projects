#include <numeric>
#include <utility>
#include <iostream>
using std::gcd,std::swap,std::cout,std::cin;

void reduce(int& a, int& b){int n= gcd(a,b);
while (n!=1){a/=n;b/=n;n=gcd(a,b);};}


class RN{

    

    public:

    int n,d;

    void autosetRN(int a, int b){reduce(a,b);n=a;d=b;}
    void setRN(){int a,b; cout<<"enter numerator\n";
    cin>>a; cout <<"enter denom\n"; cin>>b;reduce(a,b);
    n=a;d=b;}
    RN(int a=0, int b=1){reduce(a,b);
    n=a;d=b;};

    RN(const RN& x){ n=x.n; d=x.d;}
    RN(const RN&& x){ n=x.n; d=x.d;}

    friend void reduce(int& a, int& b);
    friend RN reciprocal(RN const x);

    RN& operator=(const RN& x) {
    if (this != &x) {
        n = x.n;
        d = x.d;
    }
    return *this;
    }

    RN operator +(RN const x)const{
        int h= gcd(this->d,x.d);
        int rn=((this->n)*(x.d/h))+((x.n)*((this->d)/h));
        int rd=((this->d)/h)*x.d;
        reduce(rn,rd);
        return RN(rn,rd);
    }

    RN operator *(RN const x)const{
        int xn,yn,xd,yd;
        xn=this->n;yn=x.n;xd=this->d;yd=x.d;
        reduce(xn,yd);reduce(yn,xd);
        return RN(xn*yn,xd*yd);
    }

    float return_float() const {float x= (static_cast<float>(n))/d; return x;}
};


RN reciprocal(RN const x){int a,b;
    a=x.n;b=x.d;
    return RN(b,a);
}