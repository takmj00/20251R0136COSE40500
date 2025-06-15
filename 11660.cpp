#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int** arr = new int* [1025];
	for (int i = 0; i < n + 1; i++)
		arr[i] = new int[1025];
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> arr[i][j];
			arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
		}
	}
	int x1, y1, x2, y2, ans;
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		ans = arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}

	return 0;
}
