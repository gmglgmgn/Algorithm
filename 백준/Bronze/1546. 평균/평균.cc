#include <iostream>
using namespace std;

int main(){
    // 과목 수 최대 1000 개.
    int scores[1000] = {0};
    int nOfSubjects;
    
    // 입력 받기.
    cin >> nOfSubjects;
    for(int i = 0; i < nOfSubjects; i++){
        cin >> scores[i];
    }
    
    // 최대 값 구하면서 누적 구하기.
    int Max = scores[0];
    int sum = Max;
    for(int i = 1; i < nOfSubjects; i++){
        if(Max<scores[i]){
            Max = scores[i];
        }
        sum += scores[i];
    }
    
    // 새로운 점수 넣고, 그 합 구하기. 필요 없을 듯. 
    // 원래 평균 구한 뒤에 Max*100으로 나누면 되는 거 아닌가?
    /*
    int sum = 0;
    for(int i = 0; i < nOfSubjects; i++){
        scores[i] /= Max*100;
        sum += scores[i];
    }
    */
    
    // 소수점 출력 고정하기.
    cout << fixed;
    cout.precision(5);

    cout << (double)sum/nOfSubjects/Max*100 << '\n';
    
    return 0;
}