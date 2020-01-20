
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, k, t;
	int r1,r2,c1,c2;
	int count0 = -1;
	int count1 = 2;

	std::string line;
	std::cin >> n >> k;

	std::vector<std::vector<int>> field(n, std::vector<int>(k));

	// read field
	for (int i  = 0; i < n; i++) {
		std::cin >> line;
		for (int j = 0; j < k; j++) {
			field[i][j] = line[j]-'0';
		}
	}

	// process field
	std::stack<int> iStack, jStack;
	int ii, jj;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (field[i][j] == 0) {

				iStack.push(i);
				jStack.push(j);
				while(!iStack.empty()) {
					ii = iStack.top();
					jj = jStack.top();
					field[ii][jj] = count0;
					if (ii > 0 && field[ii-1][jj] == 0) { //up
						iStack.push(ii-1);
						jStack.push(jj);
					}
					else if (jj < k-1 && field[ii][jj+1] == 0) { //right
						iStack.push(ii);
						jStack.push(jj+1);
					}
					else if (ii < n-1 && field[ii+1][jj] == 0) { //down
						iStack.push(ii+1);
						jStack.push(jj);
					}
					else if (jj > 0 && field[ii][jj-1] == 0) { //left
						iStack.push(ii);
						jStack.push(jj-1);
					}
					else {
						iStack.pop();
						jStack.pop();
					}
				}
				count0--;
			} else if (field[i][j] == 1) {
				iStack.push(i);
				jStack.push(j);
				while(!iStack.empty()) {
					ii = iStack.top();
					jj = jStack.top();
					field[ii][jj] = count1;
					if (ii > 0 && field[ii-1][jj] == 1) { //up
						iStack.push(ii-1);
						jStack.push(jj);
					}
					else if (jj < k-1 && field[ii][jj+1] == 1) { //right
						iStack.push(ii);
						jStack.push(jj+1);
					}
					else if (ii < n-1 && field[ii+1][jj] == 1) { //down
						iStack.push(ii+1);
						jStack.push(jj);
					}
					else if (jj > 0 && field[ii][jj-1] == 1) { //left
						iStack.push(ii);
						jStack.push(jj-1);
					}
					else {
						iStack.pop();
						jStack.pop();
					}
				}
				count1++;
			}
		}
	}


	// read queries and test
	std::string output;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> r1;
		std::cin >> c1;
		std::cin >> r2;
		std::cin >> c2;
		if (field[r1-1][c1-1] == field[r2-1][c2-1]) {
			output = (field[r1-1][c1-1] < 0 ? "binary" : "decimal");
		} else {
			output = "neither";
		}
		std::cout << output << '\n';
	}

	// debug output
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			std::cout << field[i][j];
			if (field[i][j] > 0) {
				std::cout << ' ';
			}
		}
		std::cout << "\n";
	}*/
	return 0;
}

