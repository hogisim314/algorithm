#include <string>
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;
int num[10];
int curIdx=0;
int kk;

int atoi(char c) {
    return (int)c - 48;
}

stack<char> s;

string solution(string number, int k) {
    string answer = "";
    for (int i=0; i<number.size(); i++) {
        if (s.empty()) {
            s.push(number[i]);
        }
        else {
            if (number[i] > s.top() && k>0) {
                while(!s.empty() && number[i]>s.top()) {
                    s.pop();
                    k--;
                    if (k==0) {
                        break;
                    }
                } 
            }
            s.push(number[i]);
        }
    }
    
    if (s.size()> number.size() - k) {
        while(s.size() >number.size() - k) {
            s.pop();
        }
    }
    
    while(!s.empty()) {
        answer = s.top()+answer;
        s.pop();
    }
    
    return answer;
}