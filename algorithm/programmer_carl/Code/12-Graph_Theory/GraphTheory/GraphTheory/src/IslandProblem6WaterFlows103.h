#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>


// BFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void BFS(int x, int y, std::vector<std::vector<int>>& grid,
//	std::vector<std::vector<std::vector<bool>>>& visited, int groupNum)
//{
//	std::queue<std::pair<int, int>> queue;
//	queue.push({ x, y });
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
//				|| visited[nextX][nextY][groupNum - 1] == true
//				|| grid[x][y] > grid[nextX][nextY])
//				continue;
//
//			visited[nextX][nextY][groupNum - 1] = true;
//			BFS(nextX, nextY, grid, visited, groupNum);
//		}
//	}
//
//
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
//	std::vector<std::vector<std::vector<bool>>> visited(
//		N, std::vector<std::vector<bool>>(
//			M, std::vector<bool>(2, false)));
//	for (int i = 0; i < N; i++)
//	{
//		if (visited[i][0][0] == false)
//		{
//			visited[i][0][0] = true;
//			BFS(i, 0, grid, visited, 1);
//		}
//
//		if (visited[i][M - 1][1] == false)
//		{
//			visited[i][M - 1][1] = true;
//			BFS(i, M - 1, grid, visited, 2);
//		}
//	}
//
//	for (int j = 0; j < M; j++)
//	{
//		if (visited[0][j][0] == false)
//		{
//			visited[0][j][0] = true;
//			BFS(0, j, grid, visited, 1);
//		}
//
//		if (visited[N - 1][j][1] == false)
//		{
//			visited[N - 1][j][1] = true;
//			BFS(N - 1, j, grid, visited, 2);
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//		{
//			if (visited[i][j][0] == true && visited[i][j][1] == true)
//				std::cout << i << " " << j << std::endl;
//		}
//}


// DFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void DFS(int x, int y, std::vector<std::vector<int>>& grid,
//	std::vector<std::vector<std::vector<bool>>>& visited, int groupNum)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int nextX = x + dir[i][0];
//		int nextY = y + dir[i][1];
//
//		if (nextX < 0 || nextX > grid.size() - 1 || nextY < 0 || nextY > grid[0].size() - 1
//			|| visited[nextX][nextY][groupNum - 1] == true
//			|| grid[x][y] > grid[nextX][nextY])
//			continue;
//
//		visited[nextX][nextY][groupNum - 1] = true;
//		DFS(nextX, nextY, grid, visited, groupNum);
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
//	std::vector<std::vector<std::vector<bool>>> visited(
//		N, std::vector<std::vector<bool>>(
//			M, std::vector<bool>(2, false)));
//	for (int i = 0; i < N; i++)
//	{
//		if (visited[i][0][0] == false)
//		{
//			visited[i][0][0] = true;
//			DFS(i, 0, grid, visited, 1);
//		}
//
//		if (visited[i][M - 1][1] == false)
//		{
//			visited[i][M - 1][1] = true;
//			DFS(i, M - 1, grid, visited, 2);
//		}
//	}
//
//	for (int j = 0; j < M; j++)
//	{
//		if (visited[0][j][0] == false)
//		{
//			visited[0][j][0] = true;
//			DFS(0, j, grid, visited, 1);
//		}
//
//		if (visited[N - 1][j][1] == false)
//		{
//			visited[N - 1][j][1] = true;
//			DFS(N - 1, j, grid, visited, 2);
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//		{
//			if (visited[i][j][0] == true && visited[i][j][1] == true)
//				std::cout << i << " " << j << std::endl;
//		}
//}
