#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DSU
{
	vector <int> rnk;


	int find(int v)
	{
		int t = v;
		int root = v;
		while (rnk[v] != v)
		{
			v = rnk[v];
			root = rnk[v];
		}
		while (t != root)
		{
			int tt = rnk[t];
			rnk[t] = root;
			t = tt;
		}

		return v;
	}

	void unions(int v1, int v2) {
		int rn1 = find(v1);
		int rn2 = find(v2);
		rnk[rn1] = rn2;
	}
};

struct Edge
{
	int a;
	int b;
	int W;
};

bool cmp(Edge a, Edge b)
{
	return a.W < b.W;
}

int main()
{
	int n, m;
	cin >> n >> m;
	DSU st;
	vector<Edge>rebr(m);
	for (int i = 0; i < m; i++) {
		cin >> rebr[i].a >> rebr[i].b >> rebr[i].W;
		rebr[i].a--; rebr[i].b--;
	}
	for (int i = 0; i < n; i++) {
		st.point.push_back(i);
		st.rnk.push_back(i);
	}

	sort(rebr.begin(), rebr.end(), cmp);

	int t = 1, ves = 0;
	for (int i = 0; i < m; i++) {
		if (st.find(rebr[i].a) != st.find(rebr[i].b)) {
			st.unions(st.find(rebr[i].a), st.find(rebr[i].b));
			t++;
			ves += rebr[i].W;
			if (t >= n) break;
		}
	}

	cout << ves;

	return 0;
}
