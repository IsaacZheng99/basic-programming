#pragma once

#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <queue>


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
//	std::vector<bool> visited(n + 1, false);
//	minDist[1] = 0;
//	queue.push(1);
//	visited[1] = true;
//
//	while (!queue.empty())
//	{
//		int curNode = queue.front();
//		queue.pop();
//		visited[curNode] = false;
//
//		for (Edge edge : graph[curNode])
//		{
//			if (minDist[edge.end] > minDist[curNode] + edge.weight)
//			{
//				minDist[edge.end] = minDist[curNode] + edge.weight;
//
//				if (visited[edge.end] == false)
//				{
//					queue.push(edge.end);
//					visited[edge.end] = true;
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
