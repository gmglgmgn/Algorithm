#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> numbers(N);
    
    for(int i = 0; i < numbers.size(); i++){
        cin >> numbers[i];
    }
    
    // n - 1 번 순회.
    for(int i = 1; i < numbers.size(); i++){
        // i번째 순회 수행 후 i 번째 가장 큰 원소가 제일 뒤에 간다고 했으니까 
        // n - i 번 비교하면 되겠다.
        for(int j = 0; j < numbers.size() - i; j++){
            if(numbers[j] > numbers[j+1]){
                int temp = numbers[j+1];
                numbers[j+1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    
    // 결과 출력. 한줄에 원소 하나.
    for(int i = 0; i < numbers.size(); i++){
        cout << numbers[i] << '\n';
    }
    
}