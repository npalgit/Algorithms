#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
#pragma comment(linker, "/STACK:1024000000,1024000000") 
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
double a[87] = {0.0, 1312.0, 2372.3, 520.2, 932, 800.6, 1086.5, 1402.3, 1313.9, 1681.0, 2080.7, 495.8, 737.7, 577.5, 786.5, 1011.8, 999.6, 1251.2, 1520.6, 418.8, 589.8, 633.1, 658.8, 650.9, 652.9, 717.3, 762.5, 760.4, 737.1, 745.5, 906.4, 578.8, 762, 947.0, 941.0, 1139.9, 1350.8, 403.0, 549.5, 600, 640.1, 652.1, 684.3, 702, 710.2, 719.7, 804.4, 731.0, 867.8, 558.3, 708.6, 834 , 869.3, 1008.4, 1170.4, 375.7, 502.9, 538.1, 534.4, 527, 533.1, 540, 544.5, 547.1, 593.4, 565.8, 573.0, 581.0, 589.3, 596.7, 603.4, 523.5, 658.5, 761, 770, 760, 840, 880, 870, 890.1, 1007.1, 589.4, 715.6, 703, 812.1, 890, 1037};
int main() {
	int x, y;
	while (scanf("%d%d", &x, &y) != EOF) {
		if (a[x] > a[y])	puts("FIRST BIGGER");
		else puts("SECOND BIGGER");
	}
	return 0;
}
