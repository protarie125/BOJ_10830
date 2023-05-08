#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

constexpr auto mod = int{ 1000 };

int n;
ll b;
vvl a;

vvl mmul(const vvl& x, const vvl& y) {
	auto ret = vvl(n, vl(n, 0));

	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			for (auto k = 0; k < n; ++k) {
				ret[i][j] += x[i][k] * y[k][j];
				ret[i][j] %= mod;
			}
		}
	}

	return ret;
}

vvl solve(const vvl& a, const ll& b) {
	if (1 == b) {
		return a;
	}

	if (0 == b % 2) {
		const auto& q = solve(a, b / 2);
		return mmul(q, q);
	}

	const auto& q = solve(a, b - 1);
	return mmul(q, a);
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> b;

	a = vvl(n, vl(n));
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			cin >> a[i][j];
			a[i][j] %= mod;
		}
	}

	const auto& ans = solve(a, b);
	for (const auto& r : ans) {
		for (const auto& x : r) {
			cout << x << ' ';
		}
		cout << '\n';
	}

	return 0;
}