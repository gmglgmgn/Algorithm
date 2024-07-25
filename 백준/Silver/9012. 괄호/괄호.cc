#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 스트링 개수 입력받기.
    int T;
    cin >> T;
    
    // 스트링 저장할 변수
    string pstr;
    
    // ( 개수 셀 cnt 변수.
    int cnt;
    
    // 스트링 개수 만큼 반복.
    for(int i = 0; i < T; i++){
        // 입력 받기.
        cin >> pstr;
        // 각 문자열 시작 마다 0으로 설정.
        cnt = 0;
        // 잘못된 괄호 문자열인지 판단하는 NOflag. true면 잘못된 문자열.
        bool NOflag = false;
        for(int j = 0; j < pstr.length(); j++){    // 문자열의 문자 수 만큼 순회.
            if(pstr[j] == '('){    // ( 들어오면 카운트 증가.
                cnt++;
            }
            else if(pstr[j] == ')'){    // ) 들어왔을 때 2가지 시나리오.
                if(cnt > 0){    // cnt가 0보다 크면 cnt 감소
                    cnt--;
                }
                else{    // cnt가 <= 0 이면 잘못된 문자열. + 더 이상 순회 필요 없음.
                    NOflag = true;
                    break;
                }
            }
        }
        
        // 문자열 순회를 다 돌고나서 cnt가 0보다 크거나 == ( 가 남았거나
        // NOflag가 참이면 == 중간에 잘못된 괄호 문자열임을 알아냈다면 NO출력
        if(cnt > 0 || NOflag == true){ 
            cout << "NO\n"; 
        }
        else{
            cout << "YES\n";
        }
    }
}