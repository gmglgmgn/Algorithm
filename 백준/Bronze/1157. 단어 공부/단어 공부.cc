#include <iostream>
using namespace std;

int main(){
    int arr[26] = {0};
    
    string str;
    cin >> str;
    
    // 무조건 알파벳 대소문자로 이루어진 문자열만 들어온다고 가정.
    for(int i = 0; i < str.length(); i++){
        if(str[i] > 'Z'){ // 알파벳 소문자면 대문자로 만들기. ASCII 코드값 32 차이.
            str[i] -= 32;        
        }
        arr[str[i] - 'A']++;    // 해당 알파벳 카운트 증가.
    }
    
    int Max = 0;    // 가장 높은 알파벳 번호
    bool notHighest = false;    // 빈도수가 가장 높은 알파벳이 하나 이상이면 true
    for(int i = 1; i < 26; i++){
        if(arr[Max] < arr[i]){ 
            Max = i;
            notHighest = false;
        }
        // else if((arr[Max] == arr[i]) && arr[Max] != 0){ 
        // 이건 Max 교체되는 경우에 false로 플래그를 교체하면 논리 AND 대체 가능
        else if(arr[Max] == arr[i]){
            notHighest = true;
        }
    }
    
    if(notHighest == true){
        cout << '?' << '\n';
    }
    else{
        cout << (char)('A' + Max) << '\n';
    }
    
    return 0;
}