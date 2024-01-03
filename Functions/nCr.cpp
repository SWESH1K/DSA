#include <bits/stdc++.h>
using namespace std;

int fact(long long int n) {
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}

long long int nCr(long long int n,long long int r) {
    int ans = (fact(n-r)*fact(r));
    return fact(n)/ans;
}

int main()
{
    long long int n,r;
    cin>>n>>r;
    cout<<nCr(n,r);

    // cout<<fact(n)/(fact(n-r)*fact(r))<<endl;
}