#pragma once

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


//int main()
//{
//	int c, n;
//	std::cin >> c >> n;
//	std::vector<int> weights(n);
//	std::vector<int> values(n);
//	std::vector<int> counts(n);
//	for (int i = 0; i < n; i++)
//		std::cin >> weights[i];
//	for (int i = 0; i < n; i++)
//		std::cin >> values[i];
//	for (int i = 0; i < n; i++)
//		std::cin >> counts[i];
//
//	int allCount = std::accumulate(counts.begin(), counts.end(), 0);
//	std::vector<int> allWeights;
//	allWeights.reserve(allCount);
//	std::vector<int> allValues;
//	allValues.reserve(allCount);
//	/*for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < counts[i]; j++)
//		{
//			allWeights.push_back(weights[i]);
//			allValues.push_back(values[i]);
//		}
//	}*/
//	for (int i = 0; i < n; i++)
//	{
//		allWeights.insert(allWeights.end(), counts[i], weights[i]);
//		allValues.insert(allValues.end(), counts[i], values[i]);
//	}
//
//	std::vector<int> dp(c + 1, 0);
//	for (int i = 0; i < allCount; i++)
//		for (int j = c; j >= 0; j--)
//		{
//			if (j >= allWeights[i])
//				dp[j] = std::max(dp[j], dp[j - allWeights[i]] + allValues[i]);
//		}
//
//	std::cout << dp[c] << std::endl;
//}
