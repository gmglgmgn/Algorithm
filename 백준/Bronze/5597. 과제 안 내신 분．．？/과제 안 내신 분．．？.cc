#include <iostream>
using namespace std;

int main(){

    bool student[30] = {0};
    int id;
    for(int i = 0; i < 28; i++){
        cin >> id;
        student[id-1] = true;
    }

    for(int i = 0; i < 30; i++){
        if(student[i] == false){
            cout << i+1 << '\n';
        }
    }

    return 0;
}