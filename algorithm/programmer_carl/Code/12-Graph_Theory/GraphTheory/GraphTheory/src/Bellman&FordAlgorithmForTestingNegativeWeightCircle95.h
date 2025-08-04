#pragma once

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>


// queue improved edition
//struct Edge
//{
//	int end, weight;
//
//	Edge(int end, int weight)
//		: end(end), weight(weight) {
//	}
//};
//
//
//int main()
//{
//	int n, m;
//	std::cin >> n >> m;
//
//	std::vector<std::list<Edge>> graph(n + 1);
//	int s, t, v;
//	for (int i = 0; i < m; i++)
//	{
//		std::cin >> s >> t >> v;
//
//		graph[s].push_back({ t, v });
//	}
//
//	std::vector<int> minDist(n + 1, INT_MAX);
//	std::queue<int> queue;
//	std::vector<bool> isInQueue(n + 1, false);
//	std::vector<int> pushedCounts(n + 1, 0);
//	minDist[1] = 0;
//	queue.push(1);
//	isInQueue[1] = true;
//
//	while (!queue.empty())
//	{
//		int curNode = queue.front();
//		queue.pop();
//		isInQueue[curNode] = false;
//
//		for (Edge edge : graph[curNode])
//		{
//			if (minDist[edge.end] > minDist[curNode] + edge.weight)
//			{
//				minDist[edge.end] = minDist[curNode] + edge.weight;
//
//				if (isInQueue[edge.end] == false)
//				{
//					isInQueue[edge.end] = true;
//
//					queue.push(edge.end);
//
//					// test negative weight circle
//					if (pushedCounts[edge.end] == n - 1)
//					{
//						std::cout << "circle" << std::endl;
//						return 0;
//					}
//					pushedCounts[edge.end] += 1;
//				}
//			}
//		}
//	}
//
//	if (minDist[n] == INT_MAX)
//		std::cout << "unconnected" << std::endl;
//	else
//		std::cout << minDist[n] << std::endl;
//}


// naive eidtion
//struct Edge
//{
//	int s, t, v;
//
//	Edge(int s, int t, int v)
//		: s(s), t(t), v(v) {
//	}
//};
//
//
//int main()
//{
//	int n, m;
//	std::cin >> n >> m;
//
//	std::vector<Edge> edges;
//	edges.reserve(m);
//	int s, t, v;
//	for (int i = 0; i < m; i++)
//	{
//		std::cin >> s >> t >> v;
//		edges.push_back({ s, t, v });
//	}
//
//	std::vector<int> minDist(n + 1, INT_MAX);
//	minDist[1] = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (Edge& edge : edges)
//		{
//			if (minDist[edge.s] == INT_MAX)
//				continue;
//
//			if (minDist[edge.t] > minDist[edge.s] + edge.v)
//			{
//				// test negative weight circle
//				if (i == n - 1)
//				{
//					std::cout << "circle" << std::endl;
//					return 0;
//				}
//
//				minDist[edge.t] = minDist[edge.s] + edge.v;
//			}
//		}
//	}
//
//	if (minDist[n] == INT_MAX)
//		std::cout << "unconnected" << std::endl;
//	else
//		std::cout << minDist[n] << std::endl;
//}

