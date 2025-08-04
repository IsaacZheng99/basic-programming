#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <queue>


//int main()
//{
//	int N, M;
//	std::cin >> N >> M;
//
//	std::vector<std::vector<int>> matrix(N, std::vector<int>(M, 0));
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			std::cin >> matrix[i][j];
//
//	int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
//	std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
//	std::queue<std::pair<int, int>> queue;
//	int result = 0;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (matrix[i][j] == 0 || visited[i][j] == true)
//				continue;
//			
//			result += 1;
//
//			visited[i][j] = true;
//			queue.push({ i, j });
//			while (!queue.empty())
//			{
//				std::pair<int, int> cur = queue.front();
//				queue.pop();
//
//				for (int i = 0; i < 4; i++)
//				{
//					int nextX = cur.first + dir[i][0];
//					int nextY = cur.second + dir[i][1];
//					if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M
//						|| matrix[nextX][nextY] == 0 || visited[nextX][nextY] == true)
//						continue;
//
//					queue.push({ nextX, nextY });
//					visited[nextX][nextY] = true;
//				}
//			}
//		}
//	}
//
//	std::cout << result << std::endl;
//}
