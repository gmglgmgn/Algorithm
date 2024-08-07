#include <iostream>
#include <vector>
using namespace std;

/*
    많은 수의 소수를 빠르게 구하기 위해 에라스토테네스의 체를 이용해 보려고 한다.
    체 역할을 하는, 소수의 배수인지 기록하는 sieve 배열을 만들자. 
    배열의 각 인덱스는 해당 정수에 대응한다.
    먼저 0과 1을 제외한 sieve의 모든 원소를 true로 만들자. - O(N) 소요. (100만)
    
    sieve의 초기화가 끝난 뒤, 순회를 시작한다. 순회는 
    sieve의 i번째 원소가 true라면 해당 원소를 소수로 간주하고,
    해당 수의 모든 배수를 false로 처리한다.

*/

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool *sieve = new bool[1000001];
    vector<int> primeNumbers;

    sieve[0] = false;
    sieve[1] = false;

    for (int i = 2; i < 1000001; i++){
        sieve[i] = true;
    }

    for(int i = 2; i < 1000000; i++){

        if(sieve[i] == true){
            primeNumbers.push_back(i);
            for(int j = 2; j * i < 1000000; j++){
                sieve[j*i] = false;
            }
        }
    }

    // for(int i = 0; i < primeNumbers.size(); i++){
    //     cout << primeNumbers[i] << '\n';
    // }

    int N, M;
    cin >> M >> N;

    for(int i = 0; i < primeNumbers.size(); i++){
        if(primeNumbers[i] >= M && primeNumbers[i] <= N){
            cout << primeNumbers[i] << '\n';
            if(primeNumbers[i] >= N){
                break;
            }
        }
    }

}