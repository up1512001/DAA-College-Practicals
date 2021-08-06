#include<bits/stdc++.h>
using namespace std;
#define v vector

class Practical3{
public:
    int n;
    int factorialIterative(int n){
        int ans=1;
        for(int i=1;i<=n;i++)
            ans*=i;
        return ans;
    }
    int factorialRecursive(int n){
        if(n==0 || n==1)
            return 1;
        return n*factorialRecursive(n-1);
    }
    void fibonacciIterative(int n){
        int t1=0,t2=1;
        for(int i=0;i<n;i++){
            cout<<t1<<" ";
            int t=t1;
            t1=t2;
            t2=t+t2;
        }
    }
    int fibonacciRecursive(int n){
        if(n==0 || n==1){
            //cout<<n<<" ";
            return n;
        }
        //cout<<fibonacciRecursive(n-1)+fibonacciRecursive(n-2)<<" ";
        return fibonacciRecursive(n-1)+fibonacciRecursive(n-2);

    }

};

int main(){

    Practical3 p;
    cout<<"1) Factorial Iterative\n2) Factorial Recursive\n3) Fibonacci Iterative\n4) Fibonacci Recursive\n";
    cout<<"Enter your Choice:->";
    int c;cin>>c;

    switch(c){
    case 1:
            cout<<"Enter Number:->";
            cin>>p.n;
            cout<<"Value of "<<p.n<<"! is :->"<<p.factorialIterative(p.n)<<"\n";
            break;
    case 2:
            cout<<"Enter Number:->";
            cin>>p.n;
            cout<<"Value of "<<p.n<<"! is :->"<<p.factorialRecursive(p.n)<<"\n";
            break;
    case 3:
            cout<<"Enter Number:->";
            cin>>p.n;
            p.fibonacciIterative(p.n);
            cout<<"\n";
            break;
    case 4:
            cout<<"Enter Number:->";
            cin>>p.n;
            for(int i=0;i<p.n;i++)
                cout<<p.fibonacciRecursive(i)<<" ";
            cout<<"\n";
            break;
    default:
        cout<<"Enter Valid Choice...\n";
        break;
    }


}
