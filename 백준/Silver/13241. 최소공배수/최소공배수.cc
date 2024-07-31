#include <iostream>
#include <vector>
using namespace std;
/*
    A와 B의 최소 공배수는 어떻게 구할 수 있을까?
    
    A와 B의 최소 공배수(LCM) 은
    ( A * B ) / GCD( A, B ) 라고 할 수 있다.

    GCD(A, B) 는 A = B*q + R (q는 몫, R은 나머지) 일 때,
    GCD(B, R) 과 동일하다.
    GCD(A, 0) 혹은 GCD(0, A) 의 결과는 A다.

    1. GCD는 재귀 함수로 간단히 구하자.
    2. A와 B에 랜덤하게 큰 수가 들어가므로 둘 모두 long long int 로 입력 받아야 할 필요가 있다.
    3. 함수에 작은 값을 인자를 전달할 때에는 int 로 처리해도 무방하다. 작은 값은 10^3 이하이므로.
    4. 함수의 리턴 값도 역시 1000 이하의 수가 될 것이므로 int로 처리해도 무방하다. GCD(A, B) <= min(A, B) 이므로.
    
*/

int getGCD(long long int A, int B){

    // 작은 수가 0이면 큰 수가 최대 공약수
    if(B == 0){
        return A;
    }

    // 아니면, 작은 수와  큰수 % 작은수의 최대 공약수를 계산.
    return getGCD(B, A % B);

}

int main(){
    
    // 두 수 A, B 입력 받기.
    long long int A, B;
    cin >> A >> B;

    int GCD = ( A > B ) ? getGCD(A, B) : getGCD(B, A);

    cout << (A * B) / GCD << '\n';
    
}