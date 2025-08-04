#pragma once

#include <iostream>
#include <vector>
#include <list>


// adjacent list
//std::vector<std::vector<int>> result;
//std::vector<int> curPath;
//
//void DFS(int start, int end, std::vector<std::list<int>>& graph)
//{
//	if (start == end)
//	{
//		result.push_back(curPath);
//		return;
//	}
//
//	for (int next : graph[start])
//	{
//		curPath.push_back(next);
//		DFS(next, end, graph);
//		curPath.pop_back();
//	}
//
//	return;
//}
//
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<std::list<int>> graph(N + 1);
//	int start, end;
//	for (int i = 0; i < M; i++)
//	{
//		std::cin >> start >> end;
//		graph[start].push_back(end);
//	}
//
//	curPath.push_back(1);
//	DFS(1, N, graph);
//
//	if (result.size() == 0)
//		std::cout << -1 << std::endl;
//
//	for (int i = 0; i < result.size(); i++)
//	{
//		for (int j = 0; j < result[i].size() - 1; j++)
//		{
//			std::cout << result[i][j] << " ";
//		}
//		std::cout << result[i][result[i].size() - 1] << std::endl;
//	}
//}


// adjacent matrix
std::vector<std::vector<int>> result;
//std::vector<int> curPath;
//
//void DFS(int start, int end, std::vector<std::vector<int>>& graph)
//{
//
//	if (start == end)
//	{
//		result.push_back(curPath);
//		return;
//	}
//
//	for (int i = 0; i < graph.size(); i++)
//	{
//		if (graph[start - 1][i] == 0)
//			continue;
//		
//		curPath.push_back(i + 1);
//		DFS(i + 1, end, graph);
//		curPath.pop_back();
//	}
//
//	return;
//}
//
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<std::vector<int>> graph(N, std::vector<int>(N, 0));
//	int start, end;
//	for (int i = 0; i < M; i++)
//	{
//		std::cin >> start >> end;
//		graph[start - 1][end - 1] = 1;
//	}
//
//	curPath.push_back(1);
//	DFS(1, N, graph);
//
//	if (result.size() == 0)
//		std::cout << -1 << std::endl;
//
//	for (int i = 0; i < result.size(); i++)
//	{
//		for (int j = 0; j < result[i].size() - 1; j++)
//		{
//			std::cout << result[i][j] << " ";
//		}
//		std::cout << result[i][result[i].size() - 1] << std::endl;
//	}
//}


// adjacent list
//class Node
//{
//public:
//	Node(int index)
//		: index(index), val(-1), next(nullptr) {
//	}
//
//	Node(int index, int val, Node* next)
//		: index(index), val(val), next(next) {
//	}
//
//	void AddNode(Node* newNode)
//	{
//		Node* cur = this;
//		while (cur->next)
//			cur = cur->next;
//		cur->next = newNode;
//	}
//public:
//	int index;
//	int val;
//	Node* next;
//};
//
//std::vector<std::vector<int>> result;
//std::vector<int> curPath;
//
//void DFS(int startIndex, int endIndex, std::vector<Node*>& adjacentList)
//{
//	if (startIndex == endIndex)
//	{
//		result.push_back(curPath);
//		return;
//	}
//
//	Node* cur = adjacentList[startIndex - 1];
//	while (cur->next)
//	{
//		curPath.push_back(cur->next->index);
//		DFS(cur->next->index, endIndex, adjacentList);
//		curPath.pop_back();
//		cur = cur->next;
//	}
//
//	return;
//}
//
//
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<Node*> adjacentList(N);
//	for (int i = 0; i < N; i++)
//		adjacentList[i] = new Node(i + 1);
//
//	for (int i = 0; i < M; i++)
//	{
//		int start, end;
//		std::cin >> start >> end;
//		Node* newNode = new Node(end);
//		adjacentList[start - 1]->AddNode(newNode);
//	}
//
//	curPath.push_back(1);
//	DFS(1, N, adjacentList);
//
//	if (result.size() == 0)
//		std::cout << -1 << std::endl;
//
//	for (int i = 0; i < result.size(); i++)
//	{
//		for (int j = 0; j < result[i].size() - 1; j++)
//		{
//			std::cout << result[i][j] << " ";
//		}
//		std::cout << result[i][result[i].size() - 1] << std::endl;
//	}
//}
