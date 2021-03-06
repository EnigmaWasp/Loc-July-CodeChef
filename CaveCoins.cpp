#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pii;
typedef vector<uLL> vL;
const int step = 30;

uLL to32(int from, int l, string &s)
{
	uLL res = 0;
	for (int i = min(from + step - 1, l); i >= from; i--)
	{
		res <<= 1;
		if (s[i]=='1') res |= 1;
	}

	return res;
}

vL toVector(string &s)
{
	vL v;
	int l = s.length();
	for (int i = 0; i < l; i+= step)
		v.push_back(to32(i, l, s));

	return v;
}

void createZeroString(int l, string &s)
{
	s="";
	for (int i = 0; i < l; i++)
		s += "0";
}

void fillOne(int a, int b, string &s)
{
	for (int i = a; i <= b; i++)
		s[i] = '1';
}

string to2(uLL n)
{
	string s;
	while (n > 0)
	{
		s += (char)((char)(n&1) + '0');
		n >>= 1;
	}
	reverse(s.begin(), s.end());

	return s;
}

uLL toInt(string s)
{
    uLL res = 0;
	for (int i = s.length()-1; i >= 0; i--)
	{
		res <<= 1L;
		if (s[i]=='1') res |= 1L;
	}

	return res;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<pii> tm(n, {0, 0});
	for (int i = 0; i < n; i++)
		cin >> tm[i].first >> tm[i].second;
	string k;
	cin >> k;

	string s;
	uLL ans = 0;
	reverse(k.begin(), k.end());
    uLL mult2 = toInt(k);
	if (m==1)
    {
        for (int i = 0; i < n; i++)
        {
            createZeroString(tm[i].second+1, s);
            fillOne(tm[i].first, tm[i].second, s);
            uLL mult1 = toInt(s);
            uLL res = mult1 * mult2;

            if (res > ans) ans = res;
        }
    }
    else
    {// m == 2
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                createZeroString(max(tm[i].second, tm[j].second)+1, s);

                fillOne(tm[i].first, tm[i].second, s);
                fillOne(tm[j].first, tm[j].second, s);

                uLL mult1 = toInt(s);
                uLL res = mult1 * mult2;

                if (res > ans) ans = res;
            }

    }


    cout << to2(ans) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++)
		solve();

	return 0;
}
