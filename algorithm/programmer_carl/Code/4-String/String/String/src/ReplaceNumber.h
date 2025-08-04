#pragma once

#include <iostream>
#include <string>

//int main()
//{
//	std::string s;
//	std::cin >> s;
//
//	int numberCount = 0;
//	for (char c : s)
//		if (c >= '0' && c <= '9')
//			numberCount++;
//
//	int oldSize = s.size();
//	s.resize(s.size() - numberCount + numberCount * 6);
//	int left = oldSize - 1;
//	int right = s.size() - 1;
//	while (left >= 0)
//	{
//		if (s[left] >= '0' && s[left] <= '9')
//		{
//			s[right--] = 'r';
//			s[right--] = 'e';
//			s[right--] = 'b';
//			s[right--] = 'm';
//			s[right--] = 'u';
//			s[right--] = 'n';
//		}
//		else
//			s[right--] = s[left];
//		left--;
//	}
//
//	std::cout << s << std::endl;
//}