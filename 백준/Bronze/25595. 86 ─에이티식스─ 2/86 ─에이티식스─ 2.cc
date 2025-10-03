#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool canClear = true;      // 전체 처치 가능한지 나타내는 변수.

    int N;      // N * N 판 크기.
    cin >> N;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // getline(stream, string) 쓰기전에 버퍼에 쓸데 없는 문자 빼기.

    // 인덱스의 합이 홀수면 흑 칸으로, 짝수면 백 칸으로 간주. 흑은 true, 백은 false로 간주.
    pair<int, int> shin;
    vector<pair<int, int>> enemies;

    for (int i = 0; i < N; i++ ){   // N 줄 반복
        
        string currentLine;
        getline(cin, currentLine);  // 1줄 씩 읽어오기

        for (int j = 0; j < currentLine.length(); j++){
            char tile = currentLine.at(j);

            if ( tile == ' ' || tile == '0' ) {  // 빈칸 무시
                continue;
            }

            if ( tile == '2' ){     // 주인공 타일 체크해서 기록
                shin = pair(i, j/2);
                continue;
            }

            if ( tile == '1' ) {    // 적 타일 체크해서 기록
                enemies.push_back(pair(i, j/2));

                continue;
            }
        }
    }

    int shinTile = (shin.first + shin.second) % 2;  // 주인공 흑백 구하기
    
    for(pair<int, int> e : enemies){    // 적들의 위치를 순회하며 계산. 적이 0명이면 안 돌겠지
        int enemyTile = (e.first + e.second) % 2;   // 적 흑백 구하기
        if (enemyTile == shinTile){     // 주인공이랑 같은 종류 타일을 밟고 있는 적이 있으면 못 잡음.
            canClear = false;
            break;
        }
    }
    
    if (canClear) {
        cout << "Lena";
    }
    else {
        cout << "Kiriya";
    }
}