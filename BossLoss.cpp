#include <iostream>
#include <math.h>

using namespace std;
typedef long long LL;

inline void solve()
{
	LL n,m;
	cin >> n >> m;
	LL d2 = 8*m + 1;
	LL d = sqrt(d2);
	while (d*d < d2)
		d++;

	LL x = d / 2; //  0.5 * (d - 1)
	if (x <= n) cout << x << endl;
	else cout << -1 << endl;
}

int main() {

	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++)
		solve();

	return 0;
}
