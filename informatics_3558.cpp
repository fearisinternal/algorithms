#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DSU
{
	vector <int> rnk;

	void build(int n) {
		rnk.resize(0);
		for (int i = 0; i < n; i++) {
			rnk.push_back(i);
		}
	}

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

	bool check(int v1, int v2) {
		return find(v1) == find(v2);
	}
};

int main()
{
	DSU st;
	string zapros;
	while (cin >> zapros) {
		int a, b;
		if (zapros == "RESET") {
			cin >> a;	
			st.build(a);
			cout << "RESET DONE" << endl;
		}
		if (zapros == "JOIN") {
			cin >> a >> b;
			if (st.check(a, b)) {
				cout << "ALREADY " << a << " " << b << endl;
			}
			else {
				st.unions(a, b);
			}
		}
		if (zapros == "CHECK") {
			cin >> a >> b;
			if (st.check(a, b)) {
				cout << "YES" << endl;
			}
			else cout << "NO" << endl;
		}
	}


	return 0;
}