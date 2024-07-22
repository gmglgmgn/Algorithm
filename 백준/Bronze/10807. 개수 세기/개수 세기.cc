#include <bits/stdc++.h>
using namespace std;
//int arr[100];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[100];
    int N, V;
    int CNT = 0;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cin >> V;
    for(int i = 0; i < N; i++){
        if(arr[i] == V){
            CNT++;
        }
    }
    cout << CNT << '\n';
}