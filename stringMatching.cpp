
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

	std::string pat, text;
	std::size_t place, next;
	// read field
	while (std::getline(std::cin, pat)) {
		std::getline(std::cin, text);

		place = text.find(pat);
		while (place != std::string::npos) {
			next = text.find(pat, place+1);
			bool test = next && next < text.length();
			std::cout << place << (test ? " " : "");
			place = next;
		}

		std::cout << "\n";
	}
	
	
	return 0;
}

