#include <memory.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, K;
int A[15][15];
int grid[15][15];
int x, y, z;
int ans;

int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

class Tree {
   public:
    int r;
    int c;
    int age;
    bool alive;
    int deadYear;
    Tree() {}
    Tree(int r, int c, int age) {
        this->r = r;
        this->c = c;
        this->age = age;
        this->alive = true;
    }

    bool operator<(const Tree& tree) const { return age < tree.age; }
};

deque<Tree> treeList[15][15];

void oneyear(int year) {
    // 봄
    int tempyangboon[15][15];
    memset(tempyangboon, 0, sizeof(tempyangboon));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 0; k < treeList[i][j].size(); ++k) {
                Tree t = treeList[i][j][k];
                if (t.alive == false) break;
                int r = t.r;
                int c = t.c;
                if (grid[r][c] >= t.age) {
                    grid[r][c] -= t.age;
                    treeList[i][j][k].age++;
                } else {
                    treeList[i][j][k].alive = false;
                    tempyangboon[i][j] += t.age / 2;
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            grid[i][j] += tempyangboon[i][j];
        }
    }

    // 가을

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int sz = treeList[i][j].size();
            for (int k = 0; k < sz; ++k) {
                Tree t = treeList[i][j][k];
                if (t.alive == false) break;
                int r = t.r;
                int c = t.c;
                if (t.age % 5 != 0) continue;
                for (int d = 0; d < 8; ++d) {
                    int nr = r + di[d];
                    int nc = c + dj[d];
                    if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
                    Tree newT = Tree(nr, nc, 1);
                    treeList[nr][nc].push_front(newT);
                }
            }
        }
    }

    // 겨울
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            grid[i][j] += A[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> A[i][j];
            grid[i][j] = 5;
        }
    }
    for (int i = 1; i <= M; ++i) {
        cin >> x >> y >> z;
        Tree tree = Tree(x, y, z);
        treeList[x][y].push_front(tree);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            sort(treeList[i][j].begin(), treeList[i][j].end());
        }
    }
    for (int i = 1; i <= K; i++) {
        oneyear(i);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 0; k < treeList[i][j].size(); ++k) {
                if (treeList[i][j][k].alive) {
                    ans++;
                } else
                    break;
            }
        }
    }
    cout << ans << '\n';
}