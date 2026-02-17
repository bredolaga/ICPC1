#include <iostream>
#include <vector>

void result (std::vector <long long> vec, long long sub){
	while (vec.size() >= sub) {
		int a = vec.size();
		int q = a / sub,cutoff = q * sub, elements = 0;
		long long sum = 0;
		for (int i = 0; i <  cutoff;i++) {
			sum += vec[i];
			elements++;
	            if (elements == sub) {
	                	vec.push_back(sum);
                		sum = 0; elements = 0;
        			}
        		}
			for (int i = cutoff; i < a; i++) {
            		vec.push_back(vec[i]);
        		}
		vec.erase(vec.begin(), vec.begin() + a);
		}
	for (int i = 0; i < vec.size();i++) {
		std::cout << vec[i] << " "; 
	}
	std::cout << std::endl;
}

int main () {
	int a; std::cin >> a;
	while (a-- > 0){
		int b; long long c;
		std::cin >> b >> c;
		std::vector <long long> vec(b);
		for (int i = 0; i < b;i++){
			std::cin >> vec[i];
		}
		result(vec, c);
	}
	return 0;
}
