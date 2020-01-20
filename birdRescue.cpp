
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, q, px, py;
	int x1, y1, x2, y2;
	int t1, t2, t3, t4;
	int temp;
	int d1,d2,d3,d4;
	int farthestCorner, closestCorner, closestPoint;

	std::cin >> n >> q >> px >> py;
	int * dists = new int[2000001];

	// read field
	for (int i  = 0; i < n; i++) {
		std::cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) {
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
		if (y1 > y2) {
			temp = y1;
			y1 = y2;
			y2 = temp;
		}

		t1 = abs(x1 - px);
		t2 = abs(x2 - px);
		t3 = abs(y1 - py);
		t4 = abs(y2 - py);
		//find farthest corner
		d1 = t1 + t3;
		d2 = t1 + t4;
		d3 = t2 + t3;
		d4 = t2 + t4;
		farthestCorner = std::max(d4, std::max(d3, std::max(d1, d2)));
		closestCorner = std::min(d4, std::min(d3, std::min(d1, d2)));

		//find closest point
		if (x1 <= px && x2 >= px && y1 <= py && y2 >= py) {
			closestPoint = 0;
		} else if (x1 < px && px < x2) {
			closestPoint = py > y2 ? t4 : t3;
		} else if (y1 < py && py < y2) {
			closestPoint = px > x2 ? t2 : t1;
		} else {
			closestPoint = closestCorner;
		}


		//std::cout << closestPoint << " -> " << farthestCorner << "\n";
		dists[closestPoint]++;
		dists[farthestCorner+1]--;
	}
	
	int runningSum = 0;
	for (int i = 0; i < 2000001; i++) {
		runningSum += dists[i];
		dists[i] = runningSum;
	}

	int t;
	// read queries and test
	for (int i = 0; i < q; i++) {
		std::cin >> t;
		//std::cout << "\n";
		std::cout << dists[t] << '\n';
	}
	delete [] dists;
	return 0;
}

