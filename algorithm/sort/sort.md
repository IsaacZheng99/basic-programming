# 排序算法

## 1. 冒泡排序

### 1.1 原始实现

- 基本思路：以正序排序为例，循环比较相邻的两个元素，如果前一个元素比后一个元素大，就交换它们的位置，每次循环完毕会一次让最大的数，第二大的数......移动到最后的位置。

- 代码实现：

  ```python
  def bubble_sort(lNums: List):
      for i in range(1, len(lNums)):  # 循环len(lNums) - 1次
          for j in range(len(lNums) - i):  # 每次循环不需要比较最后已经排列好的元素
              if lNums[j] > lNums[j + 1]:
                  iTemp: int = lNums[j]
                  lNums[j] = lNums[j + 1]
                  lNums[j + 1] = iTemp
  ```

- 复杂度分析：最好和最坏的情况下都是`O(n^2)`。

### 1.2 优化实现1

- 基本思路：如果在某次循环中没有元素位置发生改变，则说明当前已排序完成。

- 代码实现：

  ```python
  def bubble_sort(lNums: List):
      for i in range(1, len(lNums)):
          bFlag: bool = False
          for j in range(len(lNums) - i):
              if lNums[j] > lNums[j + 1]:
                  bFlag = True
                  iTemp: int = lNums[j]
                  lNums[j] = lNums[j + 1]
                  lNums[j + 1] = iTemp
          if not bFlag:
              return
  ```

- 复杂度分析：最坏的情况下都是`O(n^2)`，最好的情况下是`O(n)`。

### 1.3 优化实现2

- 基本思路：记录每次循环中最后一次交换的索引，在下次循环中之需要比较到该位置。

- 代码实现：

  ```python
  def bubble_sort(lNums):
      iLastIndex: int = len(lNums) - 1
      for i in range(1, len(lNums)):
          iLastChange: int = 0
          for j in range(iLastIndex):
              if lNums[j] > lNums[j + 1]:
                  iTemp: int = lNums[j]
                  lNums[j] = lNums[j + 1]
                  lNums[j + 1] = iTemp
                  iLastChange = j
          iLastIndex = iLastChange
  ```

- 复杂度分析：最坏的情况下都是`O(n^2)`，最好的情况下是`O(n)`。

### 1.4 其他性质

- 原地排序算法，不需要额外的空间进行排序。
- 稳定排序算法，元素的相对位置不发生变化。

### 1.5 应用

- 小规模的数据排序。
- 数据基本有序的排序，因为冒泡排序不会对已排序好的部分进行交换。