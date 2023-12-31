#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int node, l, r;
int colcnt = 1;
int maxLevel;
int ansLevel, ansDiff;
int root;

typedef struct treeNode
{
    int num;
    int level;
    int col;
    treeNode *parent;
    treeNode *left;
    treeNode *right;
} treeNode;

typedef struct levelInfo
{
    int minn;
    int maxx;
} levelInfo;

vector<treeNode> tree;
vector<levelInfo> levels;

void inOrderTraverse(treeNode *t, int level)
{
    if (t == NULL)
        return;
    inOrderTraverse(t->left, level + 1);
    t->col = colcnt++;
    t->level = level;
    maxLevel = max(maxLevel, level);
    inOrderTraverse(t->right, level + 1);
}

void traverse(treeNode *t)
{
    if (t == NULL)
    {
        return;
    }
    levels[t->level].maxx = max(levels[t->level].maxx, t->col);
    levels[t->level].minn = min(levels[t->level].minn, t->col);
    traverse(t->left);
    traverse(t->right);
}

int main()
{
    cin >> n;

    treeNode tmp;
    tree.push_back(tmp);

    for (int i = 1; i <= n; i++)
    {
        treeNode t;
        t.num = i;
        t.level = 0;
        t.parent = NULL;
        t.left = NULL;
        t.right = NULL;
        tree.push_back(t);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> node >> l >> r;
        if (l != -1)
        {
            tree[node].left = &tree[l];
            tree[l].parent = &tree[node];
        }
        if (r != -1)
        {
            tree[node].right = &tree[r];
            tree[r].parent = &tree[node];
        }
    }
    int tmpNode = 1;
    // root찾기
    while (tree[tmpNode].parent != NULL)
    {
        tmpNode = tree[tmpNode].parent->num;
    }
    root = tmpNode;

    inOrderTraverse(&tree[root], 1);

    levelInfo tmpLevel;
    levels.push_back(tmpLevel);
    for (int i = 1; i <= maxLevel; i++) // 1 base
    {
        levelInfo level;
        level.maxx = -1;
        level.minn = 10001;
        levels.push_back(level);
    }

    traverse(&tree[root]);

    for (int i = 1; i <= maxLevel; i++)
    {
        int diff = levels[i].maxx - levels[i].minn + 1;
        if (diff > ansDiff)
        {
            ansDiff = diff;
            ansLevel = i;
        }
    }
    cout << ansLevel << ' ' << ansDiff;
}