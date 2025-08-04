#pragma once

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>


// Dijkstra (native edition) print paths
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<int> minDist(N + 1, INT_MAX);
//	minDist[1] = 0;
//
//	int S, E, V;
//	std::vector<std::vector<int>> graph(N + 1, std::vector<int>(N + 1, INT_MAX));
//	for (int i = 0; i < M; i++)
//	{
//		std::cin >> S >> E >> V;
//		graph[S][E] = V;
//	}
//
//	std::vector<int> parents(N + 1, -1);  // for print paths
//	std::vector<bool> visited(N + 1, false);
//	int curNode = -1;
//	while (curNode != N)
//	{
//		int nextNode = -1;
//		int curMinDist = INT_MAX;
//		for (int i = 1; i <= N; i++)
//		{
//			if (visited[i] == true)
//				continue;
//
//			if (minDist[i] < curMinDist)
//			{
//				curMinDist = minDist[i];
//				nextNode = i;
//			}
//		}
//
//		if (nextNode == -1)
//		{
//			std::cout << -1 << std::endl;
//			return 0;
//		}
//
//		visited[nextNode] = true;
//
//		for (int i = 1; i <= N; i++)
//		{
//			if (visited[i] == true || graph[nextNode][i] == INT_MAX)
//				continue;
//
//			// for print paths
//			if (curMinDist + graph[nextNode][i] < minDist[i])
//				parents[i] = nextNode;
//
//			minDist[i] = std::min(minDist[i], curMinDist + graph[nextNode][i]);
//		}
//
//
//		curNode = nextNode;
//	}
//
//	std::cout << minDist[N] << std::endl;
//
//	for (int i = 1; i <= N; i++)
//		std::cout << parents[i] << " -> " << i << std::endl;
//}


// Dijkstra (native edition)
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<int> minDist(N + 1, INT_MAX);
//	minDist[1] = 0;
//
//	int S, E, V;
//	std::vector<std::vector<int>> graph(N + 1, std::vector<int>(N + 1, INT_MAX));
//	for (int i = 0; i < M; i++)
//	{
//		std::cin >> S >> E >> V;
//		graph[S][E] = V;
//	}
//
//	std::vector<bool> visited(N + 1, false);
//	int curNode = -1;
//	while (curNode != N)
//	{
//		int nextNode = -1;
//		int curMinDist = INT_MAX;
//		for (int i = 1; i <= N; i++)
//		{
//			if (visited[i] == true)
//				continue;
//
//			if (minDist[i] < curMinDist)
//			{
//				curMinDist = minDist[i];
//				nextNode = i;
//			}
//		}
//
//		if (nextNode == -1)
//		{
//			std::cout << -1 << std::endl;
//			return 0;
//		}
//
//		visited[nextNode] = true;
//
//		for (int i = 1; i <= N; i++)
//		{
//			if (visited[i] == true || graph[nextNode][i] == INT_MAX)
//				continue;
//
//			minDist[i] = std::min(minDist[i], curMinDist + graph[nextNode][i]);
//		}
//
//		curNode = nextNode;
//	}
//
//	std::cout << minDist[N] << std::endl;
//}
