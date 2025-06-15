#include <iostream>
#include <vector>
#include <string>
using namespace std;

int req(vector<int> v, vector<int> arr, int n, vector<int> ori){
	if (n == 6){
		for (int i = 0; i < arr.size(); i++){
			cout << arr[i];
			if (i != arr.size()-1) cout << ' ';
			else cout << '\n';
		}
	return 0;
	}

	for (auto i = v.begin(); i < v.end(); i++){
		if (!arr.empty() && arr.back() > *i) continue;
		if (ori[ori.size()-6+n] < *i) break;
		arr.push_back(*i);
		v.erase(i);
		req(v, arr, n+1, ori);
		v.insert(i, arr.back());
		arr.pop_back();
	}
	return 0;
}



int main() {
	int n, in;
	
	cin >> n;
	while (n != 0){
		vector<int> v, arr;
		for (int i = 0; i < n; i++){
			cin >> in;
			v.push_back(in);
		}
		vector<int> ori(v);
		req(v, arr, 0, ori);
		cin >> n;
		if (n != 0) cout << endl;
	}
	
	
    return 0;
}
