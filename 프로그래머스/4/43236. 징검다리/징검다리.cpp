#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    int sz = rocks.size();
    int lo = 0;
    int hi = distance+1;
    
    while(lo+1<hi) {
        int mid = (lo+hi)/2;
        int st = 0;
        int ed = 1;
        int cutCnt=0;
        while(ed<=sz-1) {
            if (rocks[ed]-rocks[st]<mid) {
                ed++;
                cutCnt++;
            }
            else {
                ed = ed + 1;
                st = ed - 1;
            }
        }
        if (cutCnt>n) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    
    return lo;
}