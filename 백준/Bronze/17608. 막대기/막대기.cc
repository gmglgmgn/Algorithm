// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
using namespace std;
/*
    n개의 막대기의 왼쪽에서 부터 차례차례 세운다고 가정 했을때, 우측에서 보이는 막대기의 개수를 세는 문제.
    1. 맨 오른쪽의 막대기는 항상 보이겠다.
    2. 최소한 맨 오른쪽의 막대기 보다는 커야 보일 가능성이 있겠다.
    3. 내 오른쪽에 나보다 큰 막대기가 있다면 난 맨 오른쪽 막대기보다 크더라도 안보이겠다.
    4. 맨 오른쪽 막대기의 높이 <= 나보다 오른쪽에 있는 모든 막대기 중 가장 높은 놈의 높이 < 내 높이 여야 보이겠구나.
    5. 막대기들의 높이를 차례로 스택에 넣은 뒤, 맨 마지막 막대기를 최초의 max 높이로 두고, 
        stack의 원소를 하나씩 pop하며 max 값이 최신화 될 때만 보이는 막대기라고 간주하면 되겠다.
*/

int main(){
    
    // 막대기들의 높이를 저장할 스택
    stack<int> stackOfPoles;
    // 각 막대기의 높이를 입력받아 임시로 저장할 height, 막대기의 수를 저장하는 numberOfPoles
    // 보이는 막대기 수를 나타내는 visibleCount 변수.
    int height, numberOfPoles, visibleCount;
    
    // 막대기 높이 입력, 저장 부
    cin >> numberOfPoles;
    for(int i = 0; i < numberOfPoles; i++){
        cin >> height;
        stackOfPoles.push(height);
    }
    
    // 우측에서 좌측으로 진행할 때 현재 가장 높은 막대기 나타내는 max.
    // 맨 우측의 막대기는 언제나 보이므로 max에 해당 높이를 넣고 visibleCount 는 1로 설정하기.
    int max = stackOfPoles.top();
    stackOfPoles.pop();
    visibleCount = 1;

    // stack에 원소가 남아있는 동안 수행.    
    while( stackOfPoles.empty() != true ){
        // max가 최신화 되는 경우, visibleCount 증가.
        if( stackOfPoles.top() > max ){
            visibleCount++;
            max = stackOfPoles.top();
        }
        stackOfPoles.pop();
    }

    // 결과 출력
    cout << visibleCount;
}