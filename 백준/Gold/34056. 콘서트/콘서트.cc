// 34056 콘서트 https://www.acmicpc.net/problem/34056
#include <iostream>
#include <vector>
using namespace std;

void calc_Q1(vector<long long>* D, int c, int x);             // 쿼리 타입 1을 요청받아 D를 업데이트 하는 함수
void calc_left(vector<long long> * D, int left, int x);       // 왼쪽으로 소음 x의 진행을 계산하고 D를 업데이트하는 함수
void calc_right(vector<long long> * D, int right, int x);     // 오른쪽으로 ...;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N = 0;          // 벽 c의 수
    vector<long long> D;      // 각 c의 차음 성능을 나타내는 배열
    int NofQ = 0;          // 쿼리의 수
    
    cin >> N;   // 벽의 수 입력 받기.

    for ( int i = 0; i < N; i++ ) {     //  D 배열 입력 받기
        int temp;
        cin >> temp;
        D.push_back(temp);
    }
    
    cin >> NofQ;    // 쿼리의 수 입력 받을 변수

    for ( int j = 0; j < NofQ; j++ ) {
        // 쿼리를 한줄 씩 입력 받아 처리

        int temp;
        cin >> temp;    // 쿼리의 구분을 입력받는 temp 변수
        int c, x;       // 쿼리의 상세 내용 (칸막이 번호 c, 소음 x)

        if (temp == 1) {
            // 1번 쿼리는 D를 업데이트 해야 함. c와 x 두가지 변수가 주어짐.               
            cin >> c >> x;
            calc_Q1(&D, c-1, x);    // c는 1 베이스로 주는데 배열은 0 베이스이므로 1 빼서 맞춰주기.
        }
        else {
            // 2번 쿼리는 단순히 c번째 방음벽의 현재 성능을 출력.
            cin >> c;
            cout << D[c-1] << "\n";
        }
    }

}

void calc_Q1(vector<long long>* D, int c, int x){
    // 쿼리 1에 따라 D를 업데이트하는 함수.

    calc_left(D, c, x);
    calc_right(D, c+1, x);

}

void calc_left(vector<long long> * D, int left, int x){
    // 왼쪽으로 한칸씩 진행하며 x를 방음벽 성능만큼 감소시키고 방음벽 보강
    if ( x <= 0 ){
        return;
    }
    
    if ( left < 0 ) {
        // x가 아직 다 줄어들지 않았는데 왼쪽 벽 다 뚫린 경우
        return;
    }
    
    if ( x <= (*D)[left] ) {
        // 소음이 D[c] 와 같거나 작은 경우
        (*D)[left] += x;
        return;
    }

    x -= (*D)[left];    // 소음 감소.
    (*D)[left] *= 2;    // 벽 뚤렸으니 D만큼 보강

    calc_left(D, left - 1, x);  // 재귀 호출

}

void calc_right(vector<long long> * D, int right, int x){
    // 오른쪽으로 한칸씩 진행하며 x를 방음벽 성능만큼 감소시키고 방음벽 보강
    if ( x <= 0 ){
        return;
    }

    if ( right >= (*D).size() ) {
        // x가 아직 다 줄어들지 않았는데 오른쪽 벽 다 뚫린 경우
        return;
    }
    
    if ( x <= (*D)[right] ) {
        // 소음이 D[c+1] 와 같거나 작은 경우
        (*D)[right] += x;
        return;
    }

    x -= (*D)[right];    // 소음 감소.
    (*D)[right] *= 2;    // 벽 뚤렸으니 D만큼 보강

    calc_right(D, right + 1, x);  // 재귀 호출

}
