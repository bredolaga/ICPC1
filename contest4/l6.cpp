#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main () {
	std::string wall;
	std::cout << std::fixed << std::setprecision(4);
	while (std::cin >> wall) {
		const double INF = 1e100;
		std::vector <double> gp(wall.size(), INF);
		if (wall[0] == '.') gp[0] = 0;
		else gp[0] = 1;
		for (int i = 1;i < int(wall.size());i++) {
			if (wall[i] == '.') {
				gp[i] = gp[i - 1];
				continue;
			}	
			else {
				gp[i] = gp[i - 1] + 1.0;
				gp[i] = std::min(gp[i], sqrt((double)(i + 1)));
				for (int q = 1;q < i;q ++){
					double cost = std::sqrt((double)(i - q + 1));
					gp[i] = std::min(gp[i], gp[q - 1] + cost);
				}
			}
		}
		std::cout << gp[int(wall.size()) - 1] << std::endl;
	}
	return 0;
}

