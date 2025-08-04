#pragma once

#include <iostream>
#include <climits>
#include <vector>


//int main()
//{
//	int n, m;
//	std::cin >> n >> m;
//
//	std::vector<std::vector<int>> edges(m);
//	int s, t, v;
//	for (int i = 0; i < m; i++)
//	{
//		std::cin >> s >> t >> v;
//		edges[i] = { s ,t , v };
//	}
//
//	int src, dst, k;
//	std::cin >> src >> dst >> k;
//
//	std::vector<int> curMinDist(n + 1, INT_MAX);
//	curMinDist[src] = 0;
//	std::vector<int> oldMinDist(n + 1, INT_MAX);
//	oldMinDist[src] = 0;
//
//	for (int i = 0; i < k + 1; i++)
//	{
//		for (std::vector<int>& edge : edges)
//		{
//			if (oldMinDist[edge[0]] != INT_MAX
//				&& curMinDist[edge[1]] > oldMinDist[edge[0]] + edge[2])
//			{
//				curMinDist[edge[1]] = oldMinDist[edge[0]] + edge[2];
//			}
//		}
//
//		oldMinDist = curMinDist;
//	}
//
//	if (curMinDist[dst] == INT_MAX)
//		std::cout << "unreachable" << std::endl;
//	else
//		std::cout << curMinDist[dst] << std::endl;
//}
