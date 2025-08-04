#pragma once

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <array>


//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<std::vector<std::vector<int>>> grid(N + 1,
//		std::vector<std::vector<int>>(N + 1, std::vector<int>(N + 1, INT_MAX)));
//	int from, to, weight;
//	for (int i = 0; i < M; i++)
//	{
//		std::cin >> from >> to >> weight;
//		grid[from][to][0] = weight;
//		grid[to][from][0] = weight;
//	}
//
//	//for (int i = 1; i <= N; i++)
//	//	for (int j = 0; j <= N; j++)
//	//		grid[i][i][j] = 0;
//
//	int Q;
//	std::cin >> Q;
//
//	std::vector<std::array<int, 2>> startEndPairs(Q);
//	int start, end;
//	for (int i = 0; i < Q; i++)
//	{
//		std::cin >> start >> end;
//		startEndPairs[i] = { start, end };
//	}
//
//	// dynamic programming
//	for (int k = 1; k <= N; k++)
//	{
//		for (int i = 1; i <= N; i++)
//		{
//			for (int j = 1; j <= N; j++)
//			{
//				if (grid[i][k][k - 1] == INT_MAX || grid[k][j][k - 1] == INT_MAX)
//					grid[i][j][k] = grid[i][j][k - 1];
//				else
//					grid[i][j][k] =
//					std::min(grid[i][k][k - 1] + grid[k][j][k - 1], grid[i][j][k - 1]);
//			}
//		}
//	}
//
//	for (std::array<int, 2>&startEnd : startEndPairs)
//	{
//		if (grid[startEnd[0]][startEnd[1]][N] == INT_MAX)
//			std::cout << -1 << std::endl;
//		else
//			std::cout << grid[startEnd[0]][startEnd[1]][N] << std::endl;
//	}
//}
