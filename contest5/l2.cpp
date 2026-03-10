#include <iostream>
#include <vector> 
#include <map>
#include <string>

long long func(long long num,long long power,long long mod) {
	if (power == 0) return 1;
	long long result = func(num, power / 2, mod);
	result = (result * result) % mod;
	if (power % 2 == 1) result = (result * num) % mod;
	return result;
}

int main () {
	long long mod = 1000000007;
	std::string str;
	std::cin >> str;
	std::map <char, int> mp;
	int size = str.size();
	for (int i = 0; i < size;i++) mp[str[i]]++;
	std::vector <long long> fc(size + 1), rev(size + 1);
	fc[0] = 1; rev[0] = 1;
	for (int i = 1;i <= size;i++) {
		fc[i] = fc[i - 1] * i % mod;
	}
	for (int i = 0;i <= size;i++) {
		rev[i] = func(fc[i], mod - 2, mod);
	}
	long long answer = fc[size];
	for (auto x : mp) {
		answer = 1LL * answer * rev[x.second] % mod;
	}
	std::cout << answer;
	return 0;
}
