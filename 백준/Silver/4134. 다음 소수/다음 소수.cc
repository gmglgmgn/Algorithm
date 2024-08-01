#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
    일단 모든 수에 대해 수행해보자.
    단 수 N의 소수 여부를 판정할 때에는 sqrt(N) 이하의 수 까지만 검사를 하면 된다.
    sqrt(N)이 정수 값으로 떨어지는 경우 무조건 N의 약수라고 생각할 수 있으니까..
    N이 20인 경우를 생각해보자. sqrt(N)은 4 초과 5 미만의 실수 값을 가진다.

    4 * 10^9 까지 숫자가 나올 수 있다고 했으니 자료형은 int 보다 크게 사용하는게 좋겠다.

*/

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long num;
    cin >> num;

    vector<long long> numbers;

    for(int i = 0; i < num; i++){
        // 정수 N 입력 받기.
        long long N;
        cin >> N;
        
        numbers.push_back(N);
    }

    for(int k = 0; k < num; k++){

        long long nextPrime = 0;
        bool isPrime = false;

        if( numbers[k] > 3){
            for(long long j = numbers[k]; isPrime == false ; j++){
                
                isPrime = true;
                long long sqrtJ = sqrt(j);

                for(long long i = 2; i <= sqrtJ ; i++ ){
                    if( (j % i) == 0 ){
                        isPrime = false;
                        break;
                    }
                }

                if( isPrime == true ){
                    nextPrime = j;
                    break;
                }

            }
        }
        else if( numbers[k] <= 2) {
            nextPrime = 2;
        }
        else{
            nextPrime = 3;
        }

        cout << nextPrime << '\n';
    }

}