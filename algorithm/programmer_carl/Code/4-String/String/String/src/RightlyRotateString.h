#pragma once

#include <iostream>
#include <string>

void reverse(std::string& s, int begin, int end)
{
	while (begin < end)
	{
		std::swap(s[begin], s[end]);
		begin++;
		end--;
	}
}


int main()
{
	int k;
	std::string s;
	std::cin >> k;
	std::cin >> s;
	int size = s.size();

	if (k >= s.size())
		k = size;

	reverse(s, 0, size - 1);
	reverse(s, 0, k - 1);
	reverse(s, k, size - 1);

	std::cout << s << std::endl;
}

//int main()
//{
//	int k;
//	std::string s;
//	std::cin >> k;
//	std::cin >> s;
//	int size = s.size();
//
//	if (k >= s.size())
//		k = size;
//
//	int interval = 1;
//	while (size - (interval + 1) * k >= 0)
//	{
//		for (int i = 1; i <= k; i++)
//			std::swap(s[size - (interval - 1) * k - i], s[size - interval * k - i]);
//		interval++;
//	}
//
//	if (s.size() - interval * k > 0)
//	{
//		int left = 0;
//		int right = s.size() - interval * k;
//		while (left < k)
//		{
//			std::swap(s[left], s[right]);
//			left++;
//			right++;
//		}
//		char rightChar = s[right - 1];
//		char temp = s[left];
//		while (left < right - 1)
//		{
//			s[left + 1] = temp;
//			temp = s[left + 1];
//			left++;
//		}
//		s[k] = rightChar;
//	}
//
//	std::cout << s << std::endl;
//}