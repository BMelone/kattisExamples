
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

	std::string line;

	std::cin >> line;
	int len = line.length()+1;
	int * rain = new int[len];

	for (int i = 0; i < len; i++) {
		rain[i] = 0;
	}

	rain[1] = (line[0] == 'B' ? 1 : -1);
	for (int i = 1; i < len-1; i++) {
		rain[i+1] = rain[i] + (line[i] == 'B' ? 1 : -1);
	}

	int prevBot = 0, prevTop = 0, currBot = 0, currTop = 0;
	int ibBot = 0, ibTop = 0, iBot = 0, iTop = 0;
	for (int i = 0; i < len; i++) {
		if (rain[i] <= currBot) {
			currBot = rain[i];
			iBot = i;
			currTop = rain[i];
			iTop = i;
		}
		if (rain[i] > currTop) {
			currTop = rain[i];
			iTop = i;
			if (currTop - currBot > currTop - prevBot) {
				prevTop = currTop;
				prevBot = currBot;
				ibBot = iBot;
				ibTop = iTop;
			} else if (currTop - prevBot > prevTop - prevBot) {
				prevTop = currTop;
				ibTop = iTop;
			}
		}
	}

	int blues = ibBot - ibTop;

	for (int i = 0; i < len; i++) {
		rain[i] = rain[i] * -1;
	}

	prevBot = 0; prevTop = 0; currBot = 0; currTop = 0;
	int irBot = 0, irTop = 0; iBot = 0; iTop = 0;
	for (int i = 0; i < len; i++) {
		if (rain[i] <= currBot) { // new base
			currBot = rain[i];
			iBot = i;
			currTop = rain[i];
			iTop = i;
		}
		if (rain[i] > currTop) {
			currTop = rain[i];
			iTop = i;
			if (currTop - currBot > currTop - prevBot) {
				prevTop = currTop;
				prevBot = currBot;
				irBot = iBot;
				irTop = iTop;
			} else if (currTop - prevBot > prevTop - prevBot) {
				prevTop = currTop;
				irTop = iTop;
			}
		}
	}

	int reds = irBot - irTop;

	if (abs(reds) == abs(blues)) {
		if (irBot < ibBot) {
			std::cout << irBot+1 << " " << irTop << "\n";
		} else {
			std::cout << ibBot+1 << " " << ibTop << "\n";
		}
	} else if (abs(reds) > abs(blues)) {
		std::cout << irBot+1 << " " << irTop << "\n";
	} else {
		std::cout << ibBot+1 << " " << ibTop << "\n";
	}
	
	delete [] rain;
	return 0;
}

