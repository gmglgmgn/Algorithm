#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 스택 생성.
    deque<int> deq;
    
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
        
        // 명령이 front인 경우.
        if(instruction == "front"){
            if(deq.empty()){ // 비어있으면
                cout << "-1" << '\n';
            }
            else{
                cout << deq.front() << '\n';
            }
        }    // 명령이 pop_back 인 경우.
        else if(instruction == "pop_back"){
            if(deq.empty()){ // 비어있으면
                cout << "-1" << '\n';
            }
            else{
                cout << deq.back() << '\n';
                deq.pop_back();                
            }
        }    // 명령이 pop_front 인 경우.
        else if(instruction == "pop_front"){
            if(deq.empty()){ // 비어있으면
                cout << "-1" << '\n';
            }
            else{
                cout << deq.front() << '\n';
                deq.pop_front();                
            }
        }  // 명령이 back 인 경우
        else if(instruction == "back"){
            if(deq.empty()){ // 비어있으면
                cout << "-1" << '\n';
            }
            else{
                cout << deq.back() << '\n';
            }
        }    // 명령이 empty인 경우
        else if(instruction == "empty"){
            cout << deq.empty() << '\n';
        }    // 명령이 size 인 경우
        else if(instruction == "size"){
            cout << deq.size() << '\n';
        }    // 명령이 push_front인 경우
        else if(instruction == "push_front"){
            // 입력 버퍼에 남이있는 숫자 x에 입력 받기.
            cin >> x;
            deq.push_front(x);
        }    // 명령이 push_back인 경우
        else if(instruction == "push_back"){
            // 입력 버퍼에 남이있는 숫자 x에 입력 받기.
            cin >> x;
            deq.push_back(x);
        }
    }
}