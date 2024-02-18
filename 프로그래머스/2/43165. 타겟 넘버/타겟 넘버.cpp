#include <string>
#include <vector>

using namespace std;

vector<int> v;
int ans;

void solve(int depth, int sum, int target) {
    if (depth==v.size()) {
        if (sum==target) {
            ans++;
        }
        return;
    }
    
    sum+=v[depth];
    solve(depth+1, sum, target);
    sum-=v[depth];
    
    sum-=v[depth];
    solve(depth+1, sum, target);
    sum+=v[depth];
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    for (int i=0; i<numbers.size(); i++) {
        v.push_back(numbers[i]);
    }
    solve(0,0,target);
    
    return ans;
}