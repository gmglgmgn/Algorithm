#include <iostream>
using namespace std;

long long func(long long A, long long B){
    return (A+B)*(A-B);
}

int main(){
    long long A, B;
    cin >> A >> B;
    cout << func(A, B) << '\n';
    
    return 0;
}