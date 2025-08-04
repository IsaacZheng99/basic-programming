#pragma once

//#include <iostream>
//#include <string>


//int main()
//{
//	std::string s;
//	std::cin >> s;
//
//	int numCount = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] >= '0' && s[i] <= '9')
//			numCount++;
//	}
//
//	int oldSize = s.size();
//	s.resize(oldSize - numCount + numCount * 6);
//	int cur = s.size() - 1;
//	for (int i = oldSize - 1; i >= 0; i--)
//	{
//		if (s[i] >= '0' && s[i] <= '9')
//		{
//			s[cur--] = 'r';
//			s[cur--] = 'e';
//			s[cur--] = 'b';
//			s[cur--] = 'm';
//			s[cur--] = 'u';
//			s[cur--] = 'n';
//		}
//		else
//			s[cur--] = s[i];
//	}
//
//	std::cout << s << std::endl;
//}