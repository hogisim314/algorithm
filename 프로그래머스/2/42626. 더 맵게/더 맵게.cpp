#include <string>
#include <vector>
#include <queue>
using namespace std;

bool flag = false;
int score;

priority_queue<int> pq;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for (int i=0; i<scoville.size(); i++) {
        pq.push(-scoville[i]);
    }
    
    while(true) {
        //스코빌 지수 만드는 과정
        int first = -pq.top();
        if (first>=K) {
            break;
        }
        pq.pop();
        int second = -pq.top();
        pq.pop();
        score = first + (second*2);
        pq.push(-score);
        
        //섞었으니까 answer++
        answer++;
        
        if (pq.size()==1 && -pq.top()<K) {
            answer=-1;
            break;
        }
    }
    
    return answer;
}