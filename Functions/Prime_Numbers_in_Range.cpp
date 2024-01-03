#include<iostream>
using namespace std;

bool is_prime(int n) {
    for(int i=2;i<=n/2;i++) {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        if(is_prime(i))
            cout<<i<<" ";
    }
    return 0;
}