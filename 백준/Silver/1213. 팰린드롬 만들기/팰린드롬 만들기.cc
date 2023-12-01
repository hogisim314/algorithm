#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
string palin;
int alpha[26]; // 알파벳 갯수
int odd=0;
int oddIdx = 0;
int main() {
    cin>>s;
    for (int i=0; i<s.size(); i++) {
        alpha[(int)s[i]-65]++;
    }

    if (s.size()%2==0) { // 
        for (int i=0; i<26; i++) {
            if (alpha[i]%2==1) {
                cout<<"I'm Sorry Hansoo"<<'\n';
                return 0;
            }
        }
        //이거 통과하면 모두 짝수라서 팰린드롬 생성가능. 
        for (int i=0; i<26; i++) {
            if (alpha[i]) {
                for (int j=0; j<alpha[i]/2; j++) {
                    palin.push_back((char)(i+65));
                }
            }
        }
        int sz = palin.size();
        for (int i=sz-1; i>=0; i--) {
            palin.push_back(palin[i]);
        }
    }
    else {
        for (int i=0; i<26; i++) {
            if (alpha[i]%2==1) {
                odd++;
                oddIdx=i;
            }
        }
        if (odd!=1) {
            cout<<"I'm Sorry Hansoo"<<'\n';
            return 0;
        }

        for (int i=0; i<26; i++) {
            if (alpha[i]) {
                for (int j=0; j<alpha[i]/2; j++) {
                    palin.push_back((char)(i+65));
                }
            }
        }

        palin.push_back((char)(oddIdx+65));
        int sz = palin.size();
        for (int i=sz-2; i>=0; i--) {
            palin.push_back(palin[i]);
        }
    }

    cout<<palin;
}