
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string line;
	std::vector<std::vector<char>> field(10, std::vector<char>(10, '@'));

	// read field
	for (int i  = 1; i < 9; i++) {
		std::cin >> line;
		for (int j = 1; j < 9; j++) {
			field[i][j] = line[j-1];
		}
	}

	int Ki,Kj,ki,kj,Ri,Rj;
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (field[i][j] == 'K') {
				Ki = i;
				Kj = j;
			} else if (field[i][j] == 'R') {
				Ri = i;
				Rj = j;
			} else if (field[i][j] == 'k') {
				ki = i;
				kj = j;
			}
		}
	}

	field[Ki-1][Kj-1] = '@';
	field[Ki-1][Kj]   = '@';
	field[Ki-1][Kj+1] = '@';
	field[Ki][Kj-1]   = '@';
	field[Ki][Kj+1]   = '@';
	field[Ki+1][Kj-1] = '@';
	field[Ki+1][Kj]   = '@';
	field[Ki+1][Kj+1] = '@';

	//test move R to ki
	if (Rj > kj) { //right
		if (Rj != kj + 1)
		for (int j = Rj; j >= 0; j--) {
			if (field[ki][j] == 'K') {
				break;
			} else if (field[ki][j] == '@') {
				
			} else {
				field[ki][j] = 'I';
			}
		}
	} else if (Rj < kj) { //left
		if (Rj != kj - 1)
		for (int j = Rj; j < 10; j++) {
			if (field[ki][j] == 'K') {
				break;
			} else if (field[ki][j] == '@') {
				
			} else {
				field[ki][j] = 'I';
			}
		}
	}

	if (field[ki][kj] == 'I'
		&& (field[ki-1][kj-1] == '@' || field[ki-1][kj-1] == 'I')
		&& (field[ki-1][kj]   == '@' || field[ki-1][kj]   == 'I')
		&& (field[ki-1][kj+1] == '@' || field[ki-1][kj+1] == 'I')
		&& (field[ki][kj-1]   == '@' || field[ki][kj-1]   == 'I')
		&& (field[ki][kj+1]   == '@' || field[ki][kj+1]   == 'I')
		&& (field[ki+1][kj-1] == '@' || field[ki+1][kj-1] == 'I')
		&& (field[ki+1][kj]   == '@' || field[ki+1][kj]   == 'I')
		&& (field[ki+1][kj+1] == '@' || field[ki+1][kj+1] == 'I')) 
	{
		std::cout << "Yes\n";
		return 0;
	}

	//test move R to kj
	if (Ri > ki) { //below
		if (Ri != ki + 1)
		for (int i = Ri; i >= 0; i--) {
			if (field[i][kj] == 'K') {
				break;
			} else if (field[i][kj] == '@') {
				
			} else {
				field[i][kj] = 'J';
			}
			
		}
	} else if (Ri < ki) { //above
		if (Ri != ki - 1)
		for (int i = Ri; i < 10; i++) {
			if (field[i][kj] == 'K') {
				break;
			} else if (field[i][kj] == '@') {
				
			} else {
				field[i][kj] = 'J';
			}
		}
	}
	
	if (field[ki][kj] == 'J'
		&& (field[ki-1][kj-1] == '@' || field[ki-1][kj-1] == 'J')
		&& (field[ki-1][kj]   == '@' || field[ki-1][kj]   == 'J')
		&& (field[ki-1][kj+1] == '@' || field[ki-1][kj+1] == 'J')
		&& (field[ki][kj-1]   == '@' || field[ki][kj-1]   == 'J')
		&& (field[ki][kj+1]   == '@' || field[ki][kj+1]   == 'J')
		&& (field[ki+1][kj-1] == '@' || field[ki+1][kj-1] == 'J')
		&& (field[ki+1][kj]   == '@' || field[ki+1][kj]   == 'J')
		&& (field[ki+1][kj+1] == '@' || field[ki+1][kj+1] == 'J')) 
	{
		std::cout << "Yes\n";
		return 0;
	}

	// debug output
	/*std::cout << '\n';
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << field[i][j];
		}
		std::cout << "\n";
	}*/

	std::cout << "No\n";
	return 0;
}

