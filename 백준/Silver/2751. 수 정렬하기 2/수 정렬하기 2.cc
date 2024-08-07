#include <iostream>
using namespace std;

/*
    수가 중복되지 않는다고 했으니... 입력 받은 정수 number에 대해서
    flag 배열의 number-1 번 인덱스를 각 number가 존재하는지 기록하는 flag로 대응시키고
    입력이 끝나면 0번 인덱스 부터 존재하는 경우에만 출력 시키기.

    1초에 1억번 이하 연산을 필요로 하는데 이렇게 수행할 경우
    숫자의 개수 N이 1,000,000 (1백만), 숫자의 범위 K 또한 1,000,000 (1백만) 이므로 
    flag 배열을 false로 초기화 하는데 100만번(K의 범위) - 고정
    flag 배열에 number가 존재하는지 기록하는데 N번(최대 100만)
    flag 배열을 순회하며 존재하면 출력하는데 100만(K의 범위) - 고정

    최대 300만번 정도의 연산이 필요하므로 시간 복잡도를 충족할 수 있지 않을까?

    아 문제에 절댓값이 나왔구나.. 그럼 크기를 200만으로 늘리고 -에 해당하는 것 부터 시작해야겠다.
    그럼 최대 시간 복잡도는 약 500만번 정도가 되겠다.
*/

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    bool *arr = new bool[2000001];

    for(int i = 0; i <= 2000000; i++){
        arr[i] = false;
    }

    int number;    
    for(int i = 0; i < N; i++){
        cin >> number;
        arr[number + 1000000] = true;
    }

    for(int i = 0; i <= 2000000; i++){
        if(arr[i] != false ){
            cout << i - 1000000 << '\n';
        }
    }

}