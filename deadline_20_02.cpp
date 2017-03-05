#include <iostream>
#include <cstdio>
#include <cctype>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <locale>
#include <vector>

const int REG_WORDS = 10;

struct Statistic {
	int count;
	std::string word;
};

bool comp(const Statistic &lhs, const Statistic &rhs) {
	return lhs.count > rhs.count;
}

void prepare(std::string &s) {
	std::locale loc;
	for (std::string::iterator it = s.begin(); it != s.end(); ++it)
		if (std::ispunct(*it, loc)) {
			s.erase(it);
			if(it != s.begin())
				it--;
		}
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}

int main() {
	Statistic stat;
	freopen("Hamlet.txt", "r", stdin);
	std::string s;
	std::map<std::string, int> count;
	std::map<std::string, int>::iterator it;
	while (true) {
		std::cin >> s;
		if (std::cin.eof())
			break;
		prepare(s);
		if (count.find(s) == count.end())
			count[s] = 0;
		count[s]++;
	}
	std::vector < Statistic > vec;
	int i = 0;
	for (it = count.begin(); it != count.end(); ++it) {
		vec.push_back(stat);
		vec.at(i).count = (*it).second;
		vec.at(i).word = (*it).first;
		i++;
	}
	std::sort(vec.begin(), vec.end(), comp);

	for (int i = 0; i < REG_WORDS; ++i) {
		std::cout << vec[i].word << std::endl;
	}
	return 0;
}
