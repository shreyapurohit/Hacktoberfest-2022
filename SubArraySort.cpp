#include <bits/stdc++.h>
using namespace std;

// input:
// 11
// 1 2 3 4 5 8 6 7 9 10 11

// output:
// 5 7

bool outofOrder(vector<int> arr, int i) {

	int n = arr.size();
	if (i == 0) {
		return arr[0] > arr[1];
	}
	if (i == n - 1) {
		return arr[n - 2] > arr[n - 1];
	}

	return arr[i] > arr[i + 1] || arr[i] < arr[i - 1];

}

pair<int, int> subarraySort(vector<int> arr, int n) {
	int small = INT_MAX, large = INT_MIN;

	for (int i = 0; i < n; i++) {
		if (outofOrder(arr, i)) {
			small = min(small, arr[i]);
			large = max(large, arr[i]);
		}
	}

	if (small == INT_MAX) {
		return make_pair(-1, -1);
	}

	int l = 0;
	while (small >= arr[l]) {
		l++;
	}

	int r = n - 1;
	while (large <= arr[r]) {
		r--;
	}

	return make_pair(l, r);
}

int main()
{
	int n;
	cin >> n;
	int x;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}

	auto res = subarraySort(arr, n);

	cout << res.first << " " << res.second;

	return 0;
}
