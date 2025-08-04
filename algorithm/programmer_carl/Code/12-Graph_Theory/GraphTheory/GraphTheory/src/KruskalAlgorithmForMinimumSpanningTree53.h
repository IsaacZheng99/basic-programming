#pragma once

#include <iostream>
#include <algorithm>
#include <vector>


// Kruskal MST
//int V, E;
//std::vector<int> father;
//
//void Init()
//{
//	father.resize(V + 1);
//	for (int i = 0; i <= V; i++)
//		father[i] = i;
//}
//
//int Find(int u)
//{
//	return u == father[u] ? father[u] : father[u] = Find(father[u]);
//}
//
//bool IsSame(int u, int v)
//{
//	u = Find(u);
//	v = Find(v);
//
//	return u == v;
//}
//
//void Join(int u, int v)
//{
//	u = Find(u);
//	v = Find(v);
//
//	if (u == v)
//		return;
//
//	father[v] = u;
//}
//
//struct Edge
//{
//	int v1, v2, val;
//};
//
//int main()
//{
//	std::cin >> V >> E;
//
//	std::vector<Edge> edges;
//	edges.reserve(E);
//	int v1, v2, val;
//	for (int i = 0; i < E; i++)
//	{
//		std::cin >> v1 >> v2 >> val;
//		edges.push_back({ v1, v2, val });
//	}
//
//	std::sort(edges.begin(), edges.end(),
//		[](const Edge& a, const Edge& b) {return a.val < b.val; });
//
//	Init();
//
//	int result = 0;
//	for (int i = 0; i < E; i++)
//	{
//		if (IsSame(edges[i].v1, edges[i].v2))
//			continue;
//
//		std::cout << edges[i].v1 << " -> " << edges[i].v2 << std::endl;  // MST print
// 
//		result += edges[i].val;
//		Join(edges[i].v1, edges[i].v2);
//	}
//
//	std::cout << result << std::endl;
//}
