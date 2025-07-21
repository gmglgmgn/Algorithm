#include <iostream>
#include <array>
#include <vector>
// #include <functional>
#include <queue>
using namespace std;

const int INF = 1e9+7;
typedef array<int, 2> pii;  // int형 크기 2짜리 array type을 pii로 부르기.

// 정점 V 가 1 이상이므로 배열 0번 무시하고 1번부터 넣어볼 생각.

int main(){

    int n, m;   // 정점 수 = n 간선 수 = m
    int s;      // 시작 정점 = s
    
    // n, m 입력 받기
    cin >> n >> m;
    cin >> s;   // 시작 정점 입력 받기.

    // 간선들의 정보 입력 받기.
    vector<vector<pii>> adj(n+1);   // adj[v] == v의 인접 노드와 인접 노드까지 간선의 비용의 배열

    for (int i = 0; i < m; i++){

        int s, d, c;     // 시작, 목적지, 비용
        cin >> s >> d >> c;

        adj[s].push_back({d, c});   // 인접 리스트에 추가

    }

    vector<int> dist(n+1, INF);     // dist[i] == s부터 i 까지의 거리
    priority_queue<pii, vector<pii>, greater<>> pq;     // { 거리, 목적지 }가 원소
    pq.push({dist[s] = 0, s});  // { 0, 시작 정점 } 시작 정점에서 시작 정점까지의 거리는 0.
    
    while (!pq.empty()) {   // 큐가 비어있지 않으면
        auto [cdist, cur] = pq.top(); // 가장 작은 원소 빼오기
        pq.pop();

        if (dist[cur] != cdist) continue;   // 큐에 들어가 있는 값이 최신 값이 아닌 경우 다음으로
        
        for (auto [nxt, cost]: adj[cur]) {  // cur의 모든 인접 노드 순회

            if (dist[nxt] <= dist[cur] + cost)  // cur에서 nxt로 가는 비용이 현재 s에서 nxt로 가는 비용보다 작지 않은 경우 update X 
                continue;
            
            pq.push({dist[nxt] = dist[cur]+cost, nxt}); // 새로운 최소 비용 기록 후 큐에 넣기.
        }
    }


    // 구한 dist 결과 출력
    for (int i = 1; i < n + 1; i++ ){
        
        if (dist[i] == INF){
            cout << "INF\n";
            continue;
        }

        cout << dist[i] << '\n';        
    }
}