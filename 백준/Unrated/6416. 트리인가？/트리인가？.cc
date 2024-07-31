#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int tc = 1;
int u, v;
int edgeCnt;
int main() {
	while (true) {
		bool finished = false;
		map<int, int> indegree;
		set<int> vertex;
		edgeCnt = 0;
		while (true) {
			cin >> u >> v;
			if (u == -1 && v == -1) {
				finished = true;
				break;
			}
			if (u == 0 && v == 0) {//입력종료
				break;
			}

			edgeCnt++;
			indegree[v]++;
			vertex.insert(u);
			vertex.insert(v);

		}
		if (finished) {
			break;
		}

		int rootCnt = 0;
		bool rightTree = true;
		int root = 0;
		for (auto itr = vertex.begin(); itr != vertex.end(); itr++) {
			if (indegree[*itr] == 0) {
				root = *itr;
				rootCnt++;
			}
			else if (indegree[*itr]>1) {
				rightTree = false;
			}
		}
		if (edgeCnt == 0) {
			cout << "Case " << tc << " is a tree." << '\n';
		}
		else if (rootCnt > 1 || !rightTree || edgeCnt+1!=vertex.size()) {
			cout << "Case " << tc << " is not a tree."<<'\n';
		}
		else {
			cout << "Case " << tc << " is a tree." << '\n';
		}
		tc++;
	}
}