#include <iostream>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	string str;
	cin >> n >> m;
	cin >> str;
	int lastch = -1;
	int secondA = -1;
	int firstA = -1;
	string AU = "AEIOU";
	for (int i = str.size() - 1; i > -1; i--) {
		if (lastch == -1) {
			bool mo = false;
			for (int j = 0; j < 5; j++) {
				if (str[i] == AU[j]) {
					mo = true;
					break;
				}
			}
			if (mo) continue;
			lastch = i;
		}
		else if (secondA == -1 && str[i] == 'A')
			secondA = i;
		else if (firstA == -1 && str[i] == 'A')
			firstA = i;
	}
	int gap = n - m;
	int havetoerase = str.size()-1-firstA-2;
	if (gap < havetoerase) {
		cout << "NO" << endl;
		return 0;
	}
	string front = str.substr(0, m - 3);
	cout << "YES" << endl;
	cout << front + "AA" + str[lastch] << endl;
	return 0;
}

