#include <iostream>
#include <cstdio>
#include <cctype>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

void prepare(std::string &s, std::set <char> &skip) {
	char *cstr = strdupa(s.c_str());
	while(skip.find(cstr[0]) != skip.end())
		++cstr;
	char *end = cstr + strlen(cstr);
	while(end > cstr && (skip.find(*(end - 1)) != skip.end()))
		--end;
	*(end) = '\0';
	for(char *c = cstr; c < end; ++c) {
		*c = tolower(*c);
	}
	s = std::string(cstr);
}

int main() {
	std::set <char> skip;
	std::string sk =  " (){}[]/\\.,<>!`~?@#'\"\n\t :-;\r";
	sk.push_back(0xc2);
	sk.push_back(0xa0);
	for(char c : sk) {
		skip.insert(c);
	}
	freopen("Hamlet.txt", "r", stdin);
	std::string s;
	std::map<std::string, int> count;
	while(true) {
		std::cin >> s;
		if(std::cin.eof())
			break;
		prepare(s, skip);
		if(count.find(s) == count.end())
			count[s] = 0;
		count[s]++;
	}
	std::vector < std::pair<int, std::string> > vec;
	for (std::pair<std::string,int> pair : count)
		vec.push_back(make_pair(pair.second, pair.first));
	std::sort(vec.begin(), vec.end());
	std::reverse(vec.begin(), vec.end());
	for(int i = 0; i < 5; ++i) {
		std::cout << vec[i].second << std::endl;
	}
	return 0;
}
