#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 스택 생성.
    stack<int> stk;
    
    // 명령의 개수 저장할 변수 생성.
    int numberOfInstruction;
    cin >> numberOfInstruction;
    
    // 명령을 저장할 문자열.
    string instruction;
    
    // 값을 저장할 x.
    int x;
    
    for(int i = 0; i < numberOfInstruction; i++){
        // 명령 입력받기.
        cin >> instruction;
        
        // 명령이 top인 경우.
        if(instruction == "top"){
            if(stk.empty()){ // 비어있으면
                cout << "-1" << '\n';
            }
            else{
                cout << stk.top() << '\n';
            }
        }    // 명령이 pop 인 경우.
        else if(instruction == "pop"){
            if(stk.empty()){ // 비어있으면
                cout << "-1" << '\n';
            }
            else{
                cout << stk.top() << '\n';
                stk.pop();                
            }
        }    // 명령이 empty인 경우
        else if(instruction == "empty"){
            cout << stk.empty() << '\n';
        }    // 명령이 size 인 경우
        else if(instruction == "size"){
            cout << stk.size() << '\n';
        }    // 명령이 push인 경우
        else if(instruction == "push"){
            // 입력 버퍼에 남이있는 숫자 x에 입력 받기.
            cin >> x;
            stk.push(x);
        }
    }
}