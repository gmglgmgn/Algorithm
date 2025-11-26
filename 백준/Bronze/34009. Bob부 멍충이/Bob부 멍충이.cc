#include <iostream>
#include <vector>
#include <algorithm>
/*
    N이    홀수면 어차피 Bob이 가장 먼저 점수를 얻어 Alice의 승리 조건이 무조건 깨지고
    반대로 짝수면 항상 Alice가 이길 수 있게 재배치 할 수 있으므로

    홀짝만 확인하면 된다.
*/

using namespace std;

int main(){

    int N;
    vector<int> A;

    cin >> N;

    int sum = 0;
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        A.push_back(a);
        sum += a;
    }

    if(N%2){
        cout << "Bob";
    }
    else{
        cout << "Alice";
    }
}