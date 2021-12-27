#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);                         
	int tt;
	cin >> tt;
	while (tt--) {
		vector<int> c(3);
		for (int i = 0; i < 3; i++) {
			cin >> c[i];
		}
		vector<int> a(5);
		for (int i = 0; i < 5; i++) {
			cin >> a[i];
		}
		// check if all 3 containers can accommodate the wastes
		bool checker = true;
		for (int i = 0; i < 3; i++) {
			if (a[i] > c[i]) {
				checker = false;
				break;
			}
		}
		if (!checker) {
			cout << "NO" << '\n';
			continue;
		}
		// subtract the available storage in the container by putting the wastes 
		// paper, plastic, neither paper nor plastic
		for (int i = 0; i < 3; i++) {
			c[i] -= a[i];
		}
  	// partially paper/plastic
  	a[3] -= min(c[0], a[3]);
  	a[4] -= min(c[1], a[4]);
  	// check if the 3rd container can accommodate the remaining partially paper/plastic wastes (if there are)
  	string ans = "YES";
  	if (a[3] > 0 || a[4] > 0) {
  		ans = (c[2] >= (a[3] + a[4]) ? "YES" : "NO");
  	}
		cout << ans << '\n';
	}
	return 0;
}