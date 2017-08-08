#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

typedef long long LL;
LL s[35];
LL INF = 10L * 1000L * 1000L * 1000L;
set<LL> sumOdd, sumEven;

void calckSums(int start, int n, set<LL> &sums)
{
	sums.clear();
	sums.insert(0);
	int k = (n - start + 2) / 2;
	for (int mask = (1<<k)-1; mask > 0; mask--)
	{
		LL sum = 0;
		for (int j = 0; j < k; j++)
			if ((int)(mask&(1<<j)) != 0)
				sum += s[start + 2*j];
		sums.insert(sum);
	}
}

void calckSums(int n)
{
	calckSums(1, n, sumOdd);
	calckSums(2, n, sumEven);	
}

void gen()
{
 	s[1] = 2;
	s[2] = 7;
	int n = 3;
	for (; s[n-1] <= INF; n++)
		if (n%2 == 1) s[n] = s[n-1] + 3 * s[n-2];
		else s[n] = s[n-1] + 7;

	calckSums(n-2);
}
 

void solve()
{
	LL n;
	cin >> n;
	
	for (LL s1 : sumOdd)
		if (sumEven.count(n-s1) > 0)
		{
			cout << "YES" << endl;
			return;
		}

	cout << "NO" << endl;
}

int main() {
	gen();
	
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++)
		solve();
	
	return 0;
}