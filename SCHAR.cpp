#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;
typedef vector<int> vi;

const int MaxN = 100 * 1000;
const int inf = 1000000000;

inline void solve()
{
    string s;
    cin >> s;
    vi cost('z'-'a'+1, inf);

    cost[s[0]-'a'] = 0;
    int price = 0;
    int l = s.length();
    for (int i = 1; i < l; i++)
    {
        price = min(price + abs(s[i-1] - s[i]), cost[s[i]-'a']);
        cost[s[i]-'a'] = price;
    }

    cout << cost[s[l-1]-'a'] << endl;
}

int main() {

	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++)
		solve();

	return 0;
}
