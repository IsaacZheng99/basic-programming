#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>


// Simulation
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
//	int result = 0;
//	int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (grid[i][j] == 0)
//				continue;
//
//			for (int k = 0; k < 4; k++)
//			{
//				int nextX = i + dir[k][0];
//				int nextY = j + dir[k][1];
//
//				if (nextX < 0 || nextX > grid.size() - 1 || nextY < 0 || nextY > grid[0].size() - 1
//					|| grid[nextX][nextY] == 0)
//					result += 1;
//			}
//		}
//	}
//
//	std::cout << result << std::endl;
//}


// BFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void BFS(int x, int y, std::vector<std::vector<int>>& grid,
//	std::vector<std::vector<bool>>& visited, int& result)
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
//				|| grid[nextX][nextY] == 0)
//			{
//				result += 1;
//				continue;
//			}
//			else if (visited[nextX][nextY] == true)
//				continue;
//
//			visited[nextX][nextY] = true;
//			queue.push({ nextX, nextY });
//		}
//	}
//
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
//	int result = 0;
//	std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (grid[i][j] == 0 || visited[i][j] == true)
//				continue;
//
//			visited[i][j] = true;
//			BFS(i, j, grid, visited, result);
//		}
//	}
//
//	std::cout << result << std::endl;
//}


// DFS
//int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//
//void DFS(int x, int y, std::vector<std::vector<int>>& grid,
//	std::vector<std::vector<bool>>& visited, int& result)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int nextX = x + dir[i][0];
//		int nextY = y + dir[i][1];
//
//		if (nextX < 0 || nextX > grid.size() - 1 || nextY < 0 || nextY > grid[0].size() - 1
//			|| grid[nextX][nextY] == 0)
//		{
//			result += 1;
//			continue;
//		}
//		else if (visited[nextX][nextY] == true)
//			continue;
//
//		visited[nextX][nextY] = true;
//		DFS(nextX, nextY, grid, visited, result);
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
//	int result = 0;
//	std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (grid[i][j] == 0 || visited[i][j] == true)
//				continue;
//
//			visited[i][j] = true;
//			DFS(i, j, grid, visited, result);
//		}
//	}
//
//	std::cout << result << std::endl;
//}
