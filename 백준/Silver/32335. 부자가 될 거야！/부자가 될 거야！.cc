#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N, M;       // N : 자물쇠의 수. M : 다이얼을 돌릴 수 있는 총 횟수
    vector<char> combination;  // 자물쇠 숫자 현 상태 저장 및 업데이트용 벡터
    string str;     // 자물쇠 입력 받기 위한 변수.
    
    cin >> N >> M;  
    cin >> str;

    // 현재 상태 벡터에 저장.
    for( int i = 0; i < N; i++){
        combination.push_back(str[i]);
    }


    // 최적 계산 하기
    for ( int i = 0; i < N; i++){
        
        // 한글자 씩 빼와서 문자를 숫자로 변경. ASCII 로 '0' 는 48
        char c = combination[i];
        int num = (int)c - 48;

        // 마지막 자리까지 진행했고 M이 남아있는 경우?
        if ( i == N-1 && M > 0 ){
            // 앞의 모든 자리 수가 0이었을 수 있으니, 마지막 자리까지 와도 M이 10보다 클 가능성이 있음. 다 돌리고 난 뒤 한 자리로 바꿔야 함.
            int last = (M + num) % 10;
            str[i] = (char) (last + 48);    // 다시 ASCII로 변환하기.
            continue;
        }

        // 현재 자리가 마지막 자리가 아니면서 0이면 안 돌리고 낮은 자리로 넘어가는 것이 이득.
        if (num == 0 ){
            continue;
        }

        // 현재 자리수 + 돌리기 횟수가 10이 넘을 수 있다면, 현재 자리를 0으로 만들 수 있다는 말.
        if ( M + num >= 10){
            int toTurn = 10 - num;  // 0으로 만들기 위해 필요한 수
            M -= toTurn;
            str[i] = '0';           // 현재 자리는 0으로 바뀌었음.
            continue;
        }


    }

    cout << str;    // 결과 출력

}