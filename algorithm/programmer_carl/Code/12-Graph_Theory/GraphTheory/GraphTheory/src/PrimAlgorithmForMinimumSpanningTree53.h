#pragma once

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>


// Prim MST print
//int main()
//{
//	int V, E;
//	std::cin >> V >> E;
//
//	int v1, v2, val;
//	std::vector<std::vector<int>> graph(V + 1, std::vector<int>(V + 1, INT_MAX));
//	for (int i = 0; i < E; i++)
//	{
//		std::cin >> v1 >> v2 >> val;
//		graph[v1][v2] = val;
//		graph[v2][v1] = val;
//	}
//
//	std::vector<int> parent(V + 1, -1);  // MST print
//	std::vector<bool> isInTree(V + 1, false);
//	std::vector<int> minDist(V + 1, INT_MAX);
//	minDist[1] = 0;
//
//	int preNode = -1;
//	for (int i = 1; i < V; i++)
//	{
//		int curNode = -1;
//		int curMinDist = INT_MAX;
//
//		for (int j = 1; j <= V; j++)
//		{
//			if (isInTree[j] == false && minDist[j] < curMinDist)
//			{
//				curMinDist = minDist[j];
//				curNode = j;
//			}
//		}
//
//		isInTree[curNode] = true;
//
//		for (int j = 1; j <= V; j++)
//		{
//			if (isInTree[j] == false && minDist[j] > graph[curNode][j])
//			{
//				minDist[j] = graph[curNode][j];
//				parent[j] = curNode;
//
//			}
//		}
//	}
//
//	int result = 0;
//	for (int i = 1; i <= V; i++)
//		result += minDist[i];
//
//	std::cout << result << std::endl;
//
//	// MST print
//	for (int i = 1; i <= V; i++)
//		std::cout << i << " -> " << parent[i] << std::endl;
//}


// Prim MST
//int main()
//{
//	int V, E;
//	std::cin >> V >> E;
//
//	int v1, v2, val;
//	std::vector<std::vector<int>> graph(V + 1, std::vector<int>(V + 1, INT_MAX));
//	for (int i = 0; i < E; i++)
//	{
//		std::cin >> v1 >> v2 >> val;
//		graph[v1][v2] = val;
//		graph[v2][v1] = val;
//	}
//
//	std::vector<bool> isInTree(V + 1, false);
//	std::vector<int> minDist(V + 1, INT_MAX);
//	minDist[1] = 0;
//
//	for (int i = 1; i < V; i++)
//	{
//		int curNode = -1;
//		int curMinDist = INT_MAX;
//
//		for (int j = 1; j <= V; j++)
//		{
//			if (isInTree[j] == false && minDist[j] < curMinDist)
//			{
//				curMinDist = minDist[j];
//				curNode = j;
//			}
//		}
//
//		isInTree[curNode] = true;
//
//		for (int j = 1; j <= V; j++)
//		{
//			if (isInTree[j] == true)
//				continue;
//
//			minDist[j] = std::min(minDist[j], graph[curNode][j]);
//		}
//	}
//
//	int result = 0;
//	for (int i = 1; i <= V; i++)
//		result += minDist[i];
//
//	std::cout << result << std::endl;
//}
