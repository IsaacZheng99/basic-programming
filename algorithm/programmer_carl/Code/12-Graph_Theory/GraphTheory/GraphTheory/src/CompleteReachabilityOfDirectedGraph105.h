#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>
#include <queue>


// BFS
//void BFS(int startIdx,
//	std::vector<std::list<int>>& graph,
//	std::vector<bool>& visited)
//{
//	std::queue<int> queue;
//	queue.push(startIdx);
//
//	while (!queue.empty())
//	{
//		int curIdx = queue.front();
//		queue.pop();
//
//		for (int nextIdx : graph[curIdx])
//		{
//			if (visited[nextIdx] == true)
//				continue;
//
//			visited[nextIdx] = true;
//			queue.push(nextIdx);
//		}
//	}
//}
//
//int main()
//{
//	int N, K;
//	std::cin >> N >> K;
//
//	std::vector<std::list<int>> graph(N + 1);
//	int s, t;
//	for (int i = 0; i < K; i++)
//	{
//		std::cin >> s >> t;
//		graph[s].push_back(t);
//	}
//
//	std::vector<bool> visited(N + 1, false);
//	visited[1] = true;
//
//	BFS(1, graph, visited);
//
//	for (int i = 1; i <= N; i++)
//	{
//		if (visited[i] == false)
//		{
//			std::cout << -1 << std::endl;
//			return 0;
//		}
//	}
//
//	std::cout << 1 << std::endl;
//}


// DFS
//void DFS(int curNodeIdx,
//	std::vector<std::vector<int>>& graph,
//	std::vector<bool>& visited)
//{
//	for (int i = 1; i < graph.size(); i++)
//	{
//		if (visited[i] == true || graph[curNodeIdx][i] == -1)
//			continue;
//
//		visited[i] = true;
//		DFS(i, graph, visited);
//	}
//}
//
//int main()
//{
//	int N, K;
//	std::cin >> N >> K;
//
//	std::vector<std::vector<int>> graph(N + 1, std::vector<int>(N + 1, -1));
//	int s, t;
//	for (int i = 0; i < K; i++)
//	{
//		std::cin >> s >> t;
//		graph[s][t] = 0;
//	}
//
//	std::vector<bool> visited(N + 1, false);
//	visited[1] = true;
//
//	DFS(1, graph, visited);
//
//	for (int i = 1; i <= N; i++)
//	{
//		if (visited[i] == false)
//		{
//			std::cout << -1 << std::endl;
//			return 0;
//		}
//	}
//
//	std::cout << 1 << std::endl;
//}


// DFS
//bool DFS(int curNodeIdx,
//	std::vector<std::vector<int>>& graph,
//	std::unordered_set<int>& visited)
//{
//	if (visited.empty())
//		return true;
//
//	for (int i = 1; i < graph.size(); i++)
//	{
//		if (visited.find(i) == visited.end() || graph[curNodeIdx][i] == -1)
//			continue;
//
//		visited.erase(i);
//		if (DFS(i, graph, visited))
//			return true;
//	}
//
//	return false;
//}
//
//int main()
//{
//	int N, K;
//	std::cin >> N >> K;
//
//	std::vector<std::vector<int>> graph(N + 1, std::vector<int>(N + 1, -1));
//	int s, t;
//	for (int i = 0; i < K; i++)
//	{
//		std::cin >> s >> t;
//		graph[s][t] = 0;
//	}
//
//	std::unordered_set<int> visited;
//	for (int i = 2; i <= N; i++)
//		visited.insert(i);
//
//	if (DFS(1, graph, visited))
//		std::cout << 1 << std::endl;
//	else
//		std::cout << -1 << std::endl;
//}
