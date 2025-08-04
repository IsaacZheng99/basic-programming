#pragma once

#include <iostream>
#include <vector>


// Disjoint set union
//std::vector<int> father;
//
//int Find(int u)
//{
//	return u == father[u] ? father[u] : father[u] = Find(father[u]);
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
//bool isSame(int u, int v)
//{
//	u = Find(u);
//	v = Find(v);
//
//	return u == v;
//}
//
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	father.resize(N + 1);
//	for (int i = 0; i <= N; i++)
//	{
//		father[i] = i;
//	}
//
//	int s, t;
//	for (int i = 0; i < M; i++)
//	{
//		std::cin >> s >> t;
//		Join(s, t);
//	}
//
//	int source, destination;
//	std::cin >> source >> destination;
//
//	if (isSame(source, destination))
//		std::cout << 1 << std::endl;
//	else
//		std::cout << 0 << std::endl;
//}
