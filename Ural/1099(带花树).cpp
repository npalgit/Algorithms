#include <bits/stdc++.h>
using namespace std;
const int N = 250;
int n, tot, g[N][N], nxt[N], l[N], belong[N], mark[N], vis[N];
vector <int> E[N];
queue <int> q;
int find(int x) {
	return belong[x] == x ? x : belong[x] = find(belong[x]);
}
void Union(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy)	belong[fx] = fy;
}
int lca(int x, int y) {
	++tot;
	while (1) {
		if (x != -1) {
			x = find(x);
			if (vis[x] == tot)	return x;
			vis[x] = tot;
			if (l[x] != -1)	x = nxt[l[x]];
			else x = -1;
		}
		swap(x, y);
	}
}
void group(int x, int p) {
	while(x != p) {
		int y = l[x], z = nxt[y];
		if (find(z) != p)	nxt[z] = y;
		if (mark[y] == 2) {
			mark[y] = 1;
			q.push(y);
		}
		if (mark[z] == 2)	{
			mark[z] = 1;
			q.push(z);
		}
		Union(x, y);
		Union(y, z);	
		x = z;
	}
}
void dfs(int st) {
	while(q.size())	q.pop();
	for (int i = 1; i <= n; ++i)	nxt[i] = vis[i] = -1, mark[i] = 0, belong[i] = i;
	q.push(st);
	mark[st] = 1;//S型点
	while(q.size() && l[st] == -1) {
		int x = q.front();
		q.pop();		
		for (int i = 0, y; i < (int)E[x].size(); ++i) {
			y = E[x][i];
			if (l[x] != y && find(x) != find(y) && mark[y] != 2) {
				if (mark[y] == 1) {		//奇环缩点
					int p = lca(x, y);
					if (find(x) != p)	nxt[x] = y;
					if (find(y) != p)	nxt[y] = x;
					group(x, p);
					group(y, p);
				}
				else if (l[y] == -1) {	//y可增广
					nxt[y] = x;
					for (int u = y; u != -1;) {
						int v = nxt[u];
						int t = l[v];
						l[v] = u;
						l[u] = v;
						u = t;
					}
					break;//succeed
				}
				else {
					nxt[y] = x;
					mark[l[y]] = 1;	//l[y]为S型
					mark[y] = 2;	//y为T型
					q.push(l[y]);
				}
			}
		}
	}
}	
int main() {
	int x, y, ans = 0;
	scanf("%d", &n);
	while (scanf("%d%d", &x, &y) != EOF) {
		if (x != y && !g[x][y]) {
			g[x][y] = g[y][x] = 1;
			E[x].push_back(y);
			E[y].push_back(x);
		}
	}
	for (int i = 1; i <= n; ++i)	l[i] = -1;
	for (int i = 1; i <= n; ++i)
		if (l[i] == -1)	dfs(i);
	for (int i = 1; i <= n; ++i)	
		if (l[i] != -1)	++ans;
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i)	
		if (l[i] != -1 && l[i] >= i)	printf("%d %d\n", i, l[i]);
	return 0;
}

