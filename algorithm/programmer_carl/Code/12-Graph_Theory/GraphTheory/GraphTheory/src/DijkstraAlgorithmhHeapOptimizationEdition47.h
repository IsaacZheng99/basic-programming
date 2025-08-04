#pragma once

#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <list>
#include <queue>


// Dijkstra (heap optimization edition) print paths
//struct Edge
//{
//	Edge(int end, int value)
//		: End(end), Value(value) {
//	}
//
//	int End, Value;
//};
//
//
//class MyComparison
//{
//public:
//	bool operator() (const std::pair<int, int>& lhs,
//		const std::pair<int, int>& rhs)
//	{
//		return lhs.second > rhs.second;
//	}
//};
//
//
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<std::list<Edge>> graph(N + 1);
//	int S, E, V;
//	for (int i = 0; i < M; i++)
//	{
//		std::cin >> S >> E >> V;
//		graph[S].push_back({ E, V });
//	}
//
//	std::vector<bool> visited(N + 1, false);
//	std::vector<int> minDist(N + 1, INT_MAX);
//	std::priority_queue<std::pair<int, int>,
//		std::vector<std::pair<int, int>>, MyComparison> priorityQueue;
//
//	std::vector<int> parents(N + 1, -1);  // for path print
//
//	visited[1] = true;
//	minDist[1] = 0;
//	priorityQueue.push({ 1, 0 });
//	while (!priorityQueue.empty())
//	{
//		std::pair<int, int> minDistPair = priorityQueue.top();
//		priorityQueue.pop();
//
//		for (Edge edge : graph[minDistPair.first])
//		{
//			if (visited[edge.End] == false &&
//				minDistPair.second + edge.Value < minDist[edge.End])
//			{
//				minDist[edge.End] = minDistPair.second + edge.Value;
//				priorityQueue.push({ edge.End, minDist[edge.End] });
//
//				parents[edge.End] = minDistPair.first;  // for path print
//			}
//
//		}
//	}
//
//	if (minDist[N] == INT_MAX)
//		std::cout << -1 << std::endl;
//	else
//		std::cout << minDist[N] << std::endl;
//
//	for (int i = 1; i <= N; i++)
//		std::cout << parents[i] << " -> " << i << std::endl;
//}


// Dijkstra (heap optimization edition)
//struct Edge
//{
//	Edge(int end, int value)
//		: End(end), Value(value) {
//	}
//
//	int End, Value;
//};
//
//
//class MyComparison
//{
//public:
//	bool operator() (const std::pair<int, int>& lhs,
//		const std::pair<int, int>& rhs)
//	{
//		return lhs.second > rhs.second;
//	}
//};
//
//
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<std::list<Edge>> graph(N + 1);
//	int S, E, V;
//	for (int i = 0; i < M; i++)
//	{
//		std::cin >> S >> E >> V;
//		graph[S].push_back({ E, V });
//	}
//
//	std::vector<bool> visited(N + 1, false);
//	std::vector<int> minDist(N + 1, INT_MAX);
//	std::priority_queue<std::pair<int, int>,
//		std::vector<std::pair<int, int>>, MyComparison> priorityQueue;
//
//	visited[1] = true;
//	minDist[1] = 0;
//	priorityQueue.push({ 1, 0 });
//	while (!priorityQueue.empty())
//	{
//		std::pair<int, int> minDistPair = priorityQueue.top();
//		priorityQueue.pop();
//
//		for (Edge edge : graph[minDistPair.first])
//		{
//			if (visited[edge.End] == false &&
//				minDistPair.second + edge.Value < minDist[edge.End])
//			{
//				minDist[edge.End] = minDistPair.second + edge.Value;
//				priorityQueue.push({ edge.End, minDist[edge.End] });
//			}
//
//		}
//	}
//
//	if (minDist[N] == INT_MAX)
//		std::cout << -1 << std::endl;
//	else
//		std::cout << minDist[N] << std::endl;
//}
