#include <iostream>
using namespace std;

int main (){

    int N, M;

    cin >> N >> M ;

    int cost, total = 0;
    for (int i = 0; i < N; i++ ){
        int j, k;
        cin >> j >> k;
    }

    for (int i = 0; i < M; i++ ){
        int t;
        cin >> t >> cost;
        total += cost;
    }

    double res = double(total) / double(N);

    cout.fixed;
    cout.precision(5);
    cout << res;

}