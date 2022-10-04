#include <bits/stdc++.h>
using namespace std;

// input:
// 7
// 10 11 5 4 3 2 1

// output:
// 4

int minSwaps(vector<int> arr, int n) {
	vector<pair<int, int>> a;
	int res = 0;

	for (int i = 0; i < n; i++) {
		a[i].first = arr[i];
		a[i].second = i;
	}

	sort(a, a + n);

	vector<bool> vis(n, false);

	for (int i = 0; i < n; i++)
	{
		int old_index = a[i].second;
		if (vis[i] || old_index == i) {
			continue;
		}

		int node = i;
		int c = 0;
		while (!vis[node]) {
			vis[node] = true;
			int new_node = a[node].second;
			node = new_node;
			c++;
		}
		res += c - 1;

	}

	return res;
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

	int res = minSwaps(arr, n);

	cout << res;

	return 0;
}
