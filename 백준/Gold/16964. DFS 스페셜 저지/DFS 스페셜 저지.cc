#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

bool check[100100];
vector<int> v[100100];
int N;
int v1, v2;
int order[100100];
stack<int> s;
bool flag=true;
int sindextoInsert;

void dfs(int x) {
    if (sindextoInsert>=N) {
        return;
    }
    int cand = order[sindextoInsert++];
    bool isIn = binary_search(v[x].begin(), v[x].end(),cand);
    if (isIn) {
        s.push(cand);
        dfs(s.top());
    }
    else {//없으면 s.pop()하면서
        while(!s.empty()&&!binary_search(v[s.top()].begin(), v[s.top()].end(), cand)) {
            s.pop();
        }
        if (s.empty()){
            flag= false;
            return;
        }
        s.push(cand);
        dfs(s.top());
    }

}

int main() {
    cin>>N;
    for (int i=0; i<N-1; i++) {
        cin>>v1>>v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
     
    for (int i=0; i<=N; i++) {
        sort(v[i].begin(), v[i].end());
    }
    
    for (int i=0; i<N; i++) {
        cin>>order[i];
    }
    if (order[0]!=1) {
        cout<<0;
        return 0;
    }
    s.push(order[sindextoInsert++]);
    dfs(1);
    cout<< (flag ? 1 : 0);
}
