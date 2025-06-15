#include <iostream>
using namespace std;

int rec(int n){
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;

	return rec(n-1) + rec(n-2) + rec(n-3);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++){
		cin >> n;
		cout << rec(n) << endl;
	}
	
	return 0;
	
}
