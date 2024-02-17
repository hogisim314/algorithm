#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int parent[105];
priority_queue<pair<int, pair<int, int> > > pq;
int cost, land1, land2, dab;

void init(int n) {
    for (int i=0; i<n; i++) {
        parent[i] = i;
    }
}

int Find(int v) {
    if (v==parent[v]) {
        return v;
    }
    return parent[v] = Find(parent[v]);
}

void Union(int x, int y) {
    parent[Find(x)] = parent[y];
    
    return;
}

void insert_to_pq(vector<vector<int>> &costs) {
    for (int i=0; i<costs.size(); i++) {
        pq.push({-costs[i][2], {costs[i][0], costs[i][1]}});
    }
}

void do_MST() {
    while(!pq.empty()) {
        cost = -pq.top().first;
        land1 = pq.top().second.first;
        land2 = pq.top().second.second;
        pq.pop();
        if (Find(land1) != Find(land2)) {
            cout<<land1 <<"의 부모는 "<<Find(land1)<<" " << land2 <<"의 부모는 "<<Find(land2)<<'\n';
            Union(land1, land2);
            dab +=cost;
        }
        else {
            cout<<"부모 같음"<<" "<<land1<<" "<<land2<<'\n';
        }
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    init(n);
    insert_to_pq(costs);
    do_MST();
    
    answer = dab;
    return answer;
}