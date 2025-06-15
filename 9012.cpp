#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie();
	cout.tie();
	ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++){
		string ans = "YES";
		stack<char> st;
		string in;
		cin >> in;
		for (auto input : in){
			if (input == '(') st.push(input);
			else if (!st.empty()) st.pop();
			else {
				ans = "NO";
				break;
			}
		}
		if (!st.empty()) ans = "NO";
		cout << ans << endl;
	}
	return 0;
}
