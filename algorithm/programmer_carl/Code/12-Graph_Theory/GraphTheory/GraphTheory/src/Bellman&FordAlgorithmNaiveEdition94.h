#pragma once

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>


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
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (Edge& edge : edges)
//		{
//			if (minDist[edge.s] == INT_MAX)
//				continue;
//
//			minDist[edge.t] = std::min(minDist[edge.t], minDist[edge.s] + edge.v);
//		}
//	}
//
//	if (minDist[n] == INT_MAX)
//		std::cout << "unconnected" << std::endl;
//	else
//		std::cout << minDist[n] << std::endl;
//}
