#pragma once

#include <iostream>
#include <vector>
#include <array>


//int N;
//std::vector<int> father;
//std::vector<std::array<int, 2>> edges;
//std::vector<int> inDegrees;
//std::vector<int> edgeIndicesWithInDegree2Node;
//
//void Init()
//{
//	father.resize(N + 1);
//	for (int i = 0; i <= N; i++)
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
//	u = father[u];
//	v = father[v];
//
//	if (u == v)
//		return;
//
//	father[v] = u;
//}
//
//void GetEdgeIndicesWithInDegree2Node()
//{
//	for (int i = N - 1; i >= 0; i--)
//	{
//		if (inDegrees[edges[i][1]] == 2)
//			edgeIndicesWithInDegree2Node.push_back(i);
//	}
//}
//
//void RemoveEdgeWithInDegree2Node()
//{
//	Init();
//
//	int edgeIdx = edgeIndicesWithInDegree2Node[0];
//
//	for (int i = 0; i < N; i++)
//	{
//		if (i == edgeIdx)
//			continue;
//
//		if (IsSame(edges[i][0], edges[i][1]))
//		{
//			edgeIdx = edgeIndicesWithInDegree2Node[1];
//			break;
//		}
//
//		Join(edges[i][0], edges[i][1]);
//	}
//
//	std::cout << edges[edgeIdx][0] << " " << edges[edgeIdx][1] << std::endl;
//}
//
//void RemoveCircleEdge()
//{
//	Init();
//
//	for (int i = 0; i < N; i++)
//	{
//		if (IsSame(edges[i][0], edges[i][1]))
//		{
//			std::cout << edges[i][0] << " " << edges[i][1] << std::endl;
//			return;
//		}
//
//		Join(edges[i][0], edges[i][1]);
//	}
//}
//
//int main()
//{
//	std::cin >> N;
//
//	inDegrees.resize(N + 1, 0);
//	int s, t;
//	for (int i = 0; i < N; i++)
//	{
//		std::cin >> s >> t;
//
//		edges.push_back({ s, t });
//		inDegrees[t] += 1;
//	}
//
//	GetEdgeIndicesWithInDegree2Node();
//
//	if (edgeIndicesWithInDegree2Node.size() > 0)
//		RemoveEdgeWithInDegree2Node();
//	else
//		RemoveCircleEdge();
//}
