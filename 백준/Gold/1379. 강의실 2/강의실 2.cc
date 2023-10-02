#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n,num;
int si[200200];
int ti[200200];
priority_queue<pair<int, int> > pq; // 끝나는 시간, 강의실번호
vector<pair<pair<int, int> , int> > lecture; // 시작시간, 끝나는시간, 강의번호
vector<int> room(100100);
int room_num=1;
int main() {
    cin>>n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i=1; i<=n; i++) {
        cin>>num>>si[i]>>ti[i];
        lecture.push_back(make_pair(make_pair(si[i], ti[i]),num));
    }
    
    sort(lecture.begin(), lecture.end());

    for (int i=0; i<lecture.size(); i++) {
        int lecture_num = lecture[i].second;
        int si = lecture[i].first.first;
        int ti = lecture[i].first.second;
        if (pq.empty()) {
            pq.push(make_pair(-ti,room_num));
            room[lecture_num] = room_num++;
        }
        else {//끝나는 시간보다 시작시간이 더 뒤일 때에는 그 해당 강의실에 넣어주면 됨. 
            if (-pq.top().first<=si) {
                room[lecture_num] = pq.top().second;
                pq.pop();
                pq.push(make_pair(-ti,room[lecture_num]));
            }
            else { // 시작시간이 더 일찍일때는 새로운 강의실을 만들어서 넣어야함. 
                room[lecture_num] = room_num++;
                pq.push(make_pair(-ti,room[lecture_num]));
            }
        }
    }
    cout<<pq.size()<<'\n';
    for (int i=1; i<=n; i++) {
        cout<<room[i]<<'\n';
    }
}

