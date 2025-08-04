#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <queue>


//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<std::list<int>> graph(N);
//	std::vector<int> inDegrees(N, 0);
//
//	int S, T;
//	for (int i = 0; i < M; i++)
//	{
//		std::cin >> S >> T;
//		graph[S].push_back(T);
//		inDegrees[T] += 1;
//	}
//
//	std::queue<int> queue;
//	for (int i = 0; i < N; i++)
//	{
//		if (inDegrees[i] == 0)
//			queue.push(i);
//	}
//
//	std::vector<int> result;
//	result.reserve(N);
//	while (!queue.empty())
//	{
//		int curNode = queue.front();
//		queue.pop();
//		result.push_back(curNode);
//
//		for (int nextNode : graph[curNode])
//		{
//			inDegrees[nextNode] -= 1;
//			if (inDegrees[nextNode] == 0)
//				queue.push(nextNode);
//		}
//	}
//
//	if (result.size() != N)
//		std::cout << -1 << std::endl;
//	else
//	{
//		for (int i = 0; i < N - 1; i++)
//			std::cout << result[i] << " ";
//		std::cout << result[N - 1] << std::endl;
//	}
//}
