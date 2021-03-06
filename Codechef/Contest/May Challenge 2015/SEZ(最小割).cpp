#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F first 
#define S second
#define mp make_pair
#define pb push_back
const int N = 205, inf = 100000;
struct Maxflow {
	int tot, to[N * N], nxt[N * N], cap[N * N << 1], head[N << 1],  cur[N << 1], pre[N << 1], dis[N * N], sum[N << 1];
	void add(int u, int v, int w) {
		to[tot] = v, cap[tot] = w, nxt[tot] = head[u], head[u] = tot++;
		to[tot] = u, cap[tot] = 0, nxt[tot] = head[v], head[v] = tot++;
	}
	void init() {
		tot = 0;
		memset(pre, -1, sizeof(pre));
		memset(head, -1, sizeof(head));
		memset(cap, 0, sizeof(cap));
		memset(sum, 0, sizeof(sum));
		memset(dis, 0, sizeof(dis));
	}
	int isap(int st, int ed) {
		int n = ed + 1;
		sum[0] = n;
		for (int i = st; i <= ed; ++i)	cur[i] = head[i];
		int u = pre[st] = st;
		int flow = 0, aug = -1;
		bool ok;
		while (dis[st] < n) {
			ok = 0;
			for (int &i = cur[u]; ~i; i = nxt[i]) {
				int v = to[i];
				if (cap[i] && dis[u] == dis[v] + 1) {
					ok = 1;
					pre[v] = u;
					u = v;
					aug = (aug == -1) ? cap[i] : min(cap[i], aug);
					if (v == ed) {
						flow += aug;
						for (u = pre[v]; v != st; v = u, u = pre[u]) {
							cap[cur[u]] -= aug;
							cap[cur[u] ^ 1] += aug;
						}
						aug = -1;
					}
					break;
				}
			}
			if (ok)	continue;
			int Min = n;
			for (int i = head[u]; ~i; i = nxt[i]) {
				int v = to[i];
				if (cap[i] && dis[v] < Min) {
					cur[u] = i;
					Min = dis[v];
				}
			}
			if (--sum[dis[u]] == 0)	break;
			dis[u] = Min + 1;
			++sum[dis[u]];
			u = pre[u];
		}
		return flow;
	}
}P;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	P.init();
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		P.add(x, y + n, 1);
		P.add(y, x + n, 1);
	}
	for (int i = 1; i <= n; ++i)	P.add(0, i, 1), P.add(i + n, n + n + 1, 1);
	printf("%d\n", n - P.isap(0, n + n + 1));
	return 0;
}
