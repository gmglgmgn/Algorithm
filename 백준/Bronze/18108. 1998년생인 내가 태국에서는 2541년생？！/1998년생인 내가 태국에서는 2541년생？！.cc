#include <iostream>
using namespace std;
// 서기와 불기의 차이는 543년
#define GAP_BETWEEN_BUD_YEAR_AND_AC 543

int main(){

    int BuddhistYear, AC;

    // 불기 입력 받고
    cin >> BuddhistYear;
    // 서기 = 불기 - 543
    AC = BuddhistYear - GAP_BETWEEN_BUD_YEAR_AND_AC;

    // 서기 출력
    cout << AC;
}