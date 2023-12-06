#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#define MID 'N'

using namespace std;

int l, r;

int get_min(int a, int b) {
    if (a<b) {
        return a;
    }
    else return b;
}

int calc_dist(char ch) {
    if (ch<='N') {
        return (int)(ch-'A');
    }
    else {
        return (int)('A'-ch)+26;
    }
}

int solution(string name) {
    int answer = 0;
    int n = name.size();
    int cursor=n-1;
    
    for (int i=0; i<n; i++) {
        if (name[i]!='A') {
            answer+=calc_dist(name[i]);
        }
        
        int next = i+1;
        while(next<n && name[next]=='A') next++;
        
        cursor = get_min(cursor, i+n-next+get_min(i,n-next));
    }
    answer+=cursor;
    return answer;
}