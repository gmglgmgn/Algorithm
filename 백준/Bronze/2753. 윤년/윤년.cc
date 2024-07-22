#include <iostream>
using namespace std;

int main(){
    int year;
    cin >> year;
    
    // 400의 배수거나, 4의 배수이면서 100의 배수가 아닌 경우 1 아니면 0 출력.
    cout << (((year % 400) == 0) || (((year % 4) == 0) && ((year % 100) != 0)));

    return 0;
}