#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

//void BFS(std::string& beginStr, std::string& endStr,
//	std::vector<std::string>& strList,
//	std::vector<int>& visited, int& result)
//{
//	std::queue<std::string> queue;
//	queue.push(beginStr);
//
//	while (!queue.empty())
//	{
//		int curQueueSize = queue.size();
//		bool flag = false;
//
//		for (int k = 0; k < curQueueSize; k++)
//		{
//			std::string curStr = queue.front();
//			queue.pop();
//
//			for (int i = 0; i < curStr.size(); i++)
//			{
//				for (int j = 0; j < 26; j++)
//				{
//					if (curStr[i] == 'a' + j)
//						continue;
//
//					std::string nextStr = curStr;
//					nextStr[i] = 'a' + j;
//
//					if (nextStr == endStr)
//						return;
//
//					auto it = std::find(strList.begin(), strList.end(), nextStr);
//					int nextStrIndex = it - strList.begin();
//					if (it == strList.end() || visited[nextStrIndex] == true)
//						continue;
//
//					flag = true;
//					visited[nextStrIndex] = true;
//					queue.push(nextStr);
//				}
//			}
//		}
//
//		if (flag == true)
//			result += 1;
//	}
//
//	result = 0;
//}
//
//int main()
//{
//	int strListSize;
//	std::cin >> strListSize;
//
//	std::string beginStr, endStr;
//	std::cin >> beginStr >> endStr;
//	if (beginStr.size() != endStr.size())
//	{
//		std::cout << 0 << std::endl;
//		return 0;
//	}
//	if (beginStr == endStr)
//	{
//		std::cout << 2 << std::endl;
//		return 0;
//	}
//
//	std::vector<std::string> strList(strListSize);
//	for (int i = 0; i < strListSize; i++)
//	{
//		std::cin >> strList[i];
//		if (strList[i].size() != beginStr.size())
//		{
//			std::cout << 0 << std::endl;
//			return 0;
//		}
//	}
//
//	int result = 2;
//	std::vector<int> visited(strListSize, false);
//	BFS(beginStr, endStr, strList, visited, result);
//	std::cout << result << std::endl;
//}
