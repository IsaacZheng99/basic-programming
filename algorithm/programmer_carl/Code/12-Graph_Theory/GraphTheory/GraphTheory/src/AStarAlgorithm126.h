#pragma once

#include <iostream>
#include <climits>
#include <cstring>
#include <queue>


//int moves[1001][1001];
//int dir[8][2] = { -2, -1, -2, 1, 2, -1, 2, 1, -1, -2, -1, 2, 1, -2, 1, 2 };
//
//
//struct Knight
//{
//	int x, y;
//	int g, h, f;
//
//	bool operator< (const Knight& other) const
//	{
//		return other.f < f;
//	}
//};
//
//
//int HeuristicFunction(int x1, int y1, int x2, int y2)
//{
//	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
//}
//
//
//void AStar(int a1, int a2, int b1, int b2)
//{
//	std::priority_queue<Knight> prQueue;
//	prQueue.push({ a1, a2, 0,
//		HeuristicFunction(a1, a2, b1, b2),
//		HeuristicFunction(a1, a2, b1, b2) });
//
//	while (!prQueue.empty())
//	{
//		Knight cur = prQueue.top();
//		prQueue.pop();
//
//		if (cur.x == b1 && cur.y == b2)
//			break;
//
//		for (int i = 0; i < 8; i++)
//		{
//			int nextX = cur.x + dir[i][0];
//			int nextY = cur.y + dir[i][1];
//
//			if (nextX < 1 || nextX > 1000 || nextY < 1 || nextY > 1000)
//				continue;
//
//			if (!moves[nextX][nextY])
//			{
//				int g = cur.g + 5;  // this is not Euclidean distance
//				int h = HeuristicFunction(nextX, nextY, b1, b2);
//				int f = g + h;
//
//				moves[nextX][nextY] = moves[cur.x][cur.y] + 1;
//
//				prQueue.push({ nextX, nextY, g, h, f });
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	int n;
//	std::cin >> n;
//
//	int a1, a2, b1, b2;
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> a1 >> a2 >> b1 >> b2;
//
//		memset(moves, 0, sizeof(moves));
//
//		AStar(a1, a2, b1, b2);
//
//		std::cout << moves[b1][b2] << std::endl;
//	}
//}
