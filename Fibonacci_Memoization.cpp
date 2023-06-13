#include<iostream>
#include<map>

using namespace std;

map<int,int> m;

long f(long n){

    static long counter = 0; static long x =0;
    //cout << "Total number of calls : " << ++counter;

    //cout << " called with n = " << n << endl;

    if(n==1 || n==2) return 1;

    if(m.find(n) != m.end()) return m[n];

    else{

    x = (f(n-1) + f(n-2));
    m[n] = x;
    return x;

    }
    //cout << " AFTER CALL with n = " << n << endl;

}

int main(int argc, char** argv){

    cout << f(atoi(argv[1])) << endl;

}
