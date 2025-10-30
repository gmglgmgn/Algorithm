#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int N, M;

    cin >> N >> M;

    vector<int> A;

    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }

    reverse(A.begin(), A.end());

    for (int i = 1; i < N; i++){
        A[i] = A[i] + A[i-1];
    }

    int whenToStart = -1;

    for(int i = 0; i < N; i++){
        if ( A[i] >= M ){
            whenToStart = N - i;
            break;
        }
    }

    cout << whenToStart;
}