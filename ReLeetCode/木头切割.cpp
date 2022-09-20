#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int find_maxm(vector<int> data, int k) {
	int max_number = *std::max_element(data.begin(), data.end());
	int res = 0;
	for (int i = 1; i <= max_number; ++i) {
		int cnt = 0;
		for (auto x : data) {
			cnt += x / i;
		}
		if (cnt >= k) {
			res = max(i, res);
		}
	}
	return res;
}

bool check(vector<int> data, int k, int m) {
	int cnt = 0;
	for (auto x : data) {
		cnt += x / m;
	}
	return cnt >= k;
}


int binary_find_maxm(vector<int> data, int k) {
	int max_number = *std::max_element(data.begin(), data.end());
	int left = 1, right = max_number;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (check(data, k, mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left - 1;
}

int main()
{
	vector<int> input{ 10,20,30,12,23 };
	int res1 = find_maxm(input, 5);
	int res2 = binary_find_maxm(input, 5);
	if (res1 == res2) {
		cout << "OK" << endl;
	}
}