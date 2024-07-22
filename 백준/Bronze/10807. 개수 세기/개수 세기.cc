#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[201];
    fill(arr, arr+201, 0);
    int N, V;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> V;
        arr[V+100]++;
    }
    
    cin >> V;
    cout << arr[V+100] << '\n';
    
    return 0;
}