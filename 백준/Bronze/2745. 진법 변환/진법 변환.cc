#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    B 진법 수 N이 주어졌을 때, 이를 10진수로 처리하는 코드.
    10을 초과하는 수는 A to Z로 표현. B는 2 <= B <= 36의 범위로 제한 됨.
    
    방법 1
     1. B 진법 수 N을 string에 저장한 다음 가장 작은 수 부터 차례로 
        vector 또는 stack에 10진수에 해당하는 수로 변환해서 저장하자.
        string N의 i번째 자리수를 Ni라고 했을 때
        Ni > '9' 라면 Ni의 정수 변환 값  = 10 + Ni - 'A' 가 되겠다(아스키 대문자만 사용하니까.)
        Ni <= '9' 라면, Ni의 정수 변환 값 =  Ni - '0' 이 되겠다.
     2. vector N에 Ni들을 정수 값으로 변환해서 저장했다고 가정하면
        이제 자리수에 해당하는 가중치만 곱해서 누적 시켜주면 되겠다. 
        i의 초깃 값은 1, i *= B 로 i를 증감 시키고 j의 초깃값은 vector 의 size-1 을 하나씩 줄여가며
        매 루프마다 sum += i * N[j] 와 동일한 연산을 수행하면 처리되지 않을까?

*/ 

int main(){

    int B;
    string N;
    vector<int> intermediate;
    int decimalValue = 0;

    cin >> N >> B;

    // NULL 문자 제외하고 string 순회하며 vector에 저장.
    // ABCD가 string N에 저장되어 있다고 하면, vector에는 [ 10, 11, 12, 13 ]이 들어가게 됨.
    // 입력은 아스키 0 ~ 9, 아니면 A ~ Z 사이의 아스키코드만 들어온다고 가정.
    for(int i = 0; i < N.size(); i++){
        // cout << (int) N[i] << ' ';
        intermediate.push_back( (N[i] < 'A' ? (N[i] - '0') : 10 + N[i] - 'A') );
        // cout << (N[i] < 'A' ? (N[i] - '0') : 10 + N[i] - 'A') << '\t';
    }
    // cout << endl;

    // 자릿수 별 가중치를 곱해서 decimalValue에 누적시키기.
    // vector 의 순회는 역순으로 수행하자. 
    for(int i = 1, j = intermediate.size() - 1; j >= 0; i *= B, j-- ){
        // cout << intermediate[j] << ' ';
        decimalValue += intermediate[j] * i;
        // cout << i << "번째 자리 더한 후 십진수 값 : " << decimalValue << endl;
    }

    cout << decimalValue << endl;
    
}