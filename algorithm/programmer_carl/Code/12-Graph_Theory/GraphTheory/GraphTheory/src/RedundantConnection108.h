#pragma once

#include <iostream>
#include <vector>


//int N;
//std::vector<int> father;
//
//void Init()
//{
//	father.resize(N + 1);
//	for (int i = 0; i <= N; i++)
//	{
//		father[i] = i;
//	}
//}
//
//int Find(int u)
//{
//	return u == father[u] ? father[u] : father[u] = Find(father[u]);
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
//int main()
//{
//	std::cin >> N;
//	Init();
//
//	int s, t;
//	for (int i = 0; i < N; i++)
//	{
//		std::cin >> s >> t;
//
//		if (isSame(s, t))
//		{
//			std::cout << s << " " << t << std::endl;
//			return 0;
//		}
//
//		Join(s, t);
//	}
//}
