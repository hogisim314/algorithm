#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

ll init(vector<ll> &arr, vector<ll> &tree, ll node, ll start, ll end) {
  if (start==end) return tree[node]=arr[start];

  ll mid=(start+end)/2;
  //구간 합을 구하는 경우
  return tree[node]=init(arr, tree, node*2, start, mid)+init(arr, tree, node*2+1, mid+1, end);
}

ll sum(vector<ll> &tree, ll node, ll start, ll end, ll left, ll right) {
  //case 1: 교집합이 공집합
  if (right<start||left>end) return 0;

  //case 2: [start, end]가 [left, right]에 포함
  if (left<=start&&end<=right) return tree[node];

  //case 3, 4: 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색 시작
  ll mid=(start+end)/2;
  return sum(tree, node*2, start, mid, left, right)+sum(tree, node*2+1, mid+1, end, left, right);
}

void update(vector<ll> &tree, ll node, ll start, ll end, ll index, ll diff) {
  if (index<start||index>end) return;
  tree[node]=tree[node]+diff;

  if (start!=end) {
    ll mid=(start+end)/2;
    update(tree,node*2, start, mid, index,diff);
    update(tree,node*2+1, mid+1,end, index, diff);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll N, M, K;
  cin>>N>>M>>K;
  vector<long long> arr(N);
  int h= (int)ceil(log2(N));
  int tree_size=(1<<(h+1));
  vector<long long> tree(tree_size);
  for (int i=0; i<N; ++i) {
    cin>>arr[i];
  }
  init(arr, tree, 1, 0, N-1);
  for (int i=0; i<M+K; ++i) {
    ll a, b, c;
    cin>>a>>b>>c;
    if (a==1) {
      b--;
      long long diff=c-arr[b];
      arr[b]=c;
      update(tree, 1, 0, N-1, b, diff);
    }
    else if (a==2) {
      cout<<sum(tree, 1, 0,N-1, b-1, c-1)<<'\n';
    }
  }
}