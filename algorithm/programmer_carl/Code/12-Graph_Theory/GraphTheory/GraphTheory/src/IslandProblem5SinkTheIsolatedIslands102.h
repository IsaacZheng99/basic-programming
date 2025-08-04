#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>


// BFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void BFS(int x, int y, std::vector<std::vector<int>>& grid)
//{
//	std::queue<std::pair<int, int>> queue;
//	queue.push({ x, y });
//
//	grid[x][y] = 2;
//
//	while (!queue.empty())
//	{
//		std::pair<int, int> curPos = queue.front();
//		queue.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nextX = curPos.first + dir[i][0];
//			int nextY = curPos.second + dir[i][1];
//
//			if (nextX < 0 || nextX > grid.size() - 1 || nextY < 0 || nextY > grid[0].size() - 1
//				|| grid[nextX][nextY] == 0 || grid[nextX][nextY] == 2)
//				continue;
//
//			grid[nextX][nextY] = 2;
//			queue.push({ nextX, nextY });
//		}
//	}
//}
//
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<std::vector<int>> grid(N, std::vector<int>(M, 0));
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			std::cin >> grid[i][j];
//
//	for (int i = 0; i < N; i++)
//	{
//		if (grid[i][0] == 1)
//			BFS(i, 0, grid);
//
//		if (grid[i][M - 1] == 1)
//			BFS(i, M - 1, grid);
//	}
//
//	for (int j = 0; j < M; j++)
//	{
//		if (grid[0][j] == 1)
//			BFS(0, j, grid);
//
//		if (grid[N - 1][j] == 1)
//			BFS(N - 1, j, grid);
//	}
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//		{
//			if (grid[i][j] == 2)
//				grid[i][j] = 1;
//			else if (grid[i][j] == 1)
//				grid[i][j] = 0;
//		}
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M - 1; j++)
//			std::cout << grid[i][j] << " ";
//
//		std::cout << grid[i][M - 1] << std::endl;
//	}
//}


// DFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void DFS(int x, int y, std::vector<std::vector<int>>& grid)
//{
//	grid[x][y] = 2;
//
//	for (int i = 0; i < 4; i++)
//	{
//		int nextX = x + dir[i][0];
//		int nextY = y + dir[i][1];
//
//		if (nextX < 0 || nextX > grid.size() - 1 || nextY < 0 || nextY > grid[0].size() - 1
//			|| grid[nextX][nextY] == 0 || grid[nextX][nextY] == 2)
//			continue;
//
//		grid[nextX][nextY] = 2;
//		DFS(nextX, nextY, grid);
//	}
//}
//
//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<std::vector<int>> grid(N, std::vector<int>(M, 0));
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			std::cin >> grid[i][j];
//
//	for (int i = 0; i < N; i++)
//	{
//		if (grid[i][0] == 1)
//			DFS(i, 0, grid);
//
//		if (grid[i][M - 1] == 1)
//			DFS(i, M - 1, grid);
//	}
//
//	for (int j = 0; j < M; j++)
//	{
//		if (grid[0][j] == 1)
//			DFS(0, j, grid);
//
//		if (grid[N - 1][j] == 1)
//			DFS(N - 1, j, grid);
//	}
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//		{
//			if (grid[i][j] == 2)
//				grid[i][j] = 1;
//			else if (grid[i][j] == 1)
//				grid[i][j] = 0;
//		}
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M - 1; j++)
//			std::cout << grid[i][j] << " ";
//
//		std::cout << grid[i][M - 1] << std::endl;
//	}
//}
