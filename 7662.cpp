#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, k, n;
	char c;
	bool valid[1000001] = { 0 };
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k;
		int idx = 1;
		priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_asc;
		priority_queue<pair<int,int>> pq_des;
		for (int j = 0; j < k; j++) {
			cin >> c >> n;
			if (c == 'I') {
				pq_asc.push(make_pair(n, idx));
				pq_des.push(make_pair(n, idx));
				valid[idx] = true;
				idx += 1;
			}
			else if (c == 'D') {
				if (n == 1) {
					while (!pq_des.empty() && !valid[pq_des.top().second])
						pq_des.pop();
					if (!pq_des.empty()) {
						valid[pq_des.top().second] = false;
						pq_des.pop();
					}
				}
				else {
					while (!pq_asc.empty() && !valid[pq_asc.top().second])
						pq_asc.pop();
					if (!pq_asc.empty()) {
						valid[pq_asc.top().second] = false;
						pq_asc.pop();
					}
				}
				
			}
		}
		while (!pq_des.empty() && !valid[pq_des.top().second])
			pq_des.pop();
		while (!pq_asc.empty() && !valid[pq_asc.top().second])
			pq_asc.pop();

		if (pq_des.empty())
			cout << "EMPTY" << endl;
		else
			cout << pq_des.top().first << ' ' << pq_asc.top().first << endl;
	}
	return 0;
}
