#include <iostream>
using namespace std;

void print_fibonacci(int num)
{
    int a=0,b=1,c;
    while(num--) {
        cout<<a<<" ";
        c=b;
        b=a;
        a=a+c;
    }
}

int main()
{
    int n;
    cin>>n;
    print_fibonacci(n);
}