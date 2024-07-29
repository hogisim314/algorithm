#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
int N;
int cnt;
int student_num;
vector<int> v;
int recommend_cnt[111];
int idx;
int min_recommend_cnt = 11111;
int insert_time[111];
int main() {
	cin >> N;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> student_num;
		if (v.size() < N) {
			bool found = false;
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == student_num) {
					recommend_cnt[student_num]++;
					found = true;
					break;
				}
			}
			if (found) continue;
			v.push_back(student_num);
			recommend_cnt[student_num]++;
			insert_time[student_num] = i;
		}
		else {
			bool found = false;
			for (int j = 0; j < N; j++) {
				if (v[j] == student_num) {
					recommend_cnt[v[j]] ++;
					found = true;
					break;
				}
			}
			if (found) continue;
			//evict
			min_recommend_cnt = 111111;
			for (int j = 0; j < N; j++) {
				if (min_recommend_cnt > recommend_cnt[v[j]])
				{
					min_recommend_cnt = recommend_cnt[v[j]];
					idx = j;
				}
			}
			for (int j = 0; j < N; j++) {
				if (min_recommend_cnt == recommend_cnt[v[j]]) {
					if (insert_time[v[idx]] > insert_time[v[j]]) {
						idx = j;
					}
				}
				else continue;
			}
			recommend_cnt[v[idx]] = 0;
			v[idx] = 0;
			//insert
			v[idx] = student_num;
			recommend_cnt[student_num]++;
			insert_time[student_num] = i;
		}
	}

	sort(v.begin(), v.begin() + v.size());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}

}