# 随机取样

- 随机取样在业务场景中是一个十分常见的需求。
- 这篇文章主要介绍了四种随机取样的情况，主要是以权重是否相等和是否需要放回进行区分的。

## 1. 四种随机取样的场景及代码实现

### 1.1 等概率放回

- 等概率情况下不需要考虑权重随机，直接使用python的random模块即可。

- 代码示例：

  ```python
  import random
  
  # 假设有1~100一共100个待选择元素，我们需要在其中随机选择若干个
  lNums: List = [iNum + 1 for iNum in range(100)]
  
  def GetRandomNum(lNums: List, iRandCount: int) -> List:
      iTotalCount: int = len(lNums)
      lResult: List = []
      for _ in range(iRandCount):
          lResult.append(lNums[random.randint(0, iTotalCount - 1)])  # 随机下标，找到对应的元素
      return lResult
  ```

### 1.2 带权放回

- 带权情况下随机需要考虑权重。

- 代码示例：

  ```python
  # 假设有1~10一共十个元素，它们的权重分别为1，2，...，9，10，从中随机选择若干个
  dNumWeight: Dict = {iNum: iNum for iNum in range(1, 11)}
  
  def GetRandomNum(dNumWeight: Dict, iRandCount: int) -> List:
      # 计算总权重
      iTotalWeight: int = sum(dNumWeight.values())
      lResult: List = []
      for _ in range(iRandCount):
          # 在总权重范围内随机一个值，找到这个随机值所在区间对应的元素
          fRand: float = random.uniform(0.0, iTotalWeight)
          iCurWeight: int = 0
          for iNum, iWeight in dNumWeight.items():
              iCurWeight += iWeight
              if fRand < iCurWeight:
                  lResult.append(iNum)
                  break
      return lResult
  ```

### 1.3 等概率不放回

- 方法1：依次对每个元素进行随机判断，代码示例如下：（印象中高中有讲过证明，这里的证明就略过了）

  ```python
  # 假设有1~10一共十个元素，从中随机选择若干个
  lNums: List = [iNum for iNum in range(1, 11)]
  
  def GetRandomNum(lNums: List, iRandCount: int) -> List:
      lResult: List = []
      iTotalCount: int = len(lNums)
      for iIdx in range(iTotalCount, 0, -1):
          iRandNum: int = random.randint(0, iIdx - 1)
          if iRandNum < iRandCount:
              iRandCount -= 1
              lResult.append(lNums[iIdx])
      return lResult
  ```

- 方法2：使用python提供的random.shuffle()接口打乱数据后，取前若干个元素，代码示例如下：

  ```python
  import random
  
  # 假设有1~10一共十个元素，从中随机选择若干个
  lNums: List = [iNum for iNum in range(1, 11)]
  
  def GetRandomNum(lNums: List, iRandCount: int) -> List:
      random.shuffle(lNums)
      return lNums[:iRandCount]
  ```

- 方法3：蓄水池算法。蓄水池算法一般用于大数据的随机取样，并且我们不需要关心样本数量。代码示例如下：（可以使用数学归纳法证明，参考：[蓄水池算法的证明](https://zhuanlan.zhihu.com/p/44154029)）

  ```python
  import random
  
  # 假设有1~10000一共一万个元素，从中随机选择若干个
  lNums: List = [iNum for iNum in range(1, 10001)]
  
  def GetRandomNum(lNums: List, iRandCount: int) -> List:
      iTotalCount: int = len(lNums)
      # 先将待选择元素的前iRandCount个加入到池子中
      lResult: List = [lNums[iIdx] for iIdx in range(iRandCount)]
      # 对之后的第k个元素，有 iRandCount / (iRandCount + k) 的概率加入到池子中，并且从池子里随机选择一个替换
      for iIdx in range(iRandCount, iTotalCount):
          if random.randint(0, iIdx) < iRandCount:
              iReplaceIdx: int = random.randint(0, iRandCount - 1)
              lResult[iReplaceIdx] = lNums[iIdx]
      return lResult
  ```

### 1.4 带权不放回

- 方法1：WRS（Weighted Random Sampling）算法，代码示例如下：（证明过程详见：[加权随机采样（WRS）](https://zhuanlan.zhihu.com/p/94562225)）

  ```python
  # 假设有1~10一共十个元素，它们的权重分别为1，2，...，9，10，从中随机选择若干个
  dNumWeight: Dict = {iNum: iNum for iNum in range(1, 11)}
  
  def GetKey(iWeight: int) -> float:
      """
      为每一个元素计算特征值
      :param iWeight: 每个元素的权重
      :return: float 特征值
      """
      # 这里为了和公式保持一致，命名会特殊些
      R = random.random()  # 随机一个(0, 1)的数
      k = math.pow(R, 1 / iWeight)
      return k
  
  def GetRandomNum(dNumWeight: Dict, iRandCount: int) -> List:
      # 计算每个元素的特征值，取出前iRandCount个特征值最大的元素
      dR: Dict = {}
      for iNum, iWeight in dNumWeight.items():
          dR[iNum] = GetKey(iWeight)
      lR: List = sorted(dR.items(), key=lambda item:item[1])
      return [tNumR[0] for tNumR in lR[:iRandCount]]
  ```

- 方法2：A - Res（Algorithm A With a Reservoir）算法，该算法是蓄水池算法的带权重版本，本质上和算法1相同，都是取特征值最高的若干个元素，在该算法中，同样会计算每个元素对应的特征值k，代码示例如下：

  ```python
  # 假设有1~10一共十个元素，它们的权重分别为1，2，...，9，10，从中随机选择若干个
  dNumWeight: Dict = {iNum: iNum for iNum in range(1, 11)}
  
  def GetKey(iWeight: int) -> float:
      """
      为每一个元素计算特征值
      :param iWeight: 每个元素的权重
      :return: float 特征值
      """
      # 这里为了和公式保持一致，命名会特殊些
      R = random.random()  # 随机一个(0, 1)的数
      k = math.pow(R, 1 / iWeight)
      return k
  
  def GetRandomNum(dNumWeight: Dict, iRandCount: int) -> List:
      lHeap: List = []
      qResult: deque = deque()
      lNums: List = list(dNumWeight.keys())
      lWeughts: List = list(dNumWeight.values())
      # 先将待选择元素的前iRandCount个加入到池子中
      for iIdx in range(iRandCount):
          heapq.heappush(lHeap, GetKey(lWeughts[iIdx]))
          qResult.append(lNums[iIdx])
      # 计算剩余元素的特征值，如果大于当前池子里最小的特征值，则替换
      for iIdx in range(iRandCount, len(dNumWeight)):
          fCurK: float = GetKey(lWeughts[iIdx])
          if fCurK > lHeap[0]:
              heapq.heapreplace(lHeap, fCurK)
              qResult.popleft()
              qResult.append(lNums[iIdx])
      return list(qResult)
  ```

## 2. 思考总结及注意点

- 严格来说，WRS算法是统称，但是笔者没有找到第四种情况下的方法1的来源，所以暂时这样分类了。
- 等概率只是一种特殊情况，当所有元素的权重相同时，就变成了等概率。
- 文本主要实现算法逻辑，代码中可能忽略了一些细节判断。
- 结合网上的一些文档的讲解，总结了一下蓄水池算法的思想：
  - 直接依次读取样本数据，不需要预处理样本数据再遍历，理论上是减少了一次遍历，可能这也是为什么称其优点是适用于大量数据。但笔者个人认为这里减少了一次遍历，本质上优化较少，理由如下：
    - “不需要预处理样本数据再遍历”意味着需要在放入蓄水池的过程中进行数据的处理，所以本质上只是减少一次遍历，遍历中的逻辑处理还是需要的，可能当嵌套循环时，优化效果会好一些。
    - 不考虑嵌套的情况下，简单计算，可以说时间复杂度由O(2N)将为了O(N)，这样的优化在实际业务环境中的作用可能也比较小，同样地，如果存在嵌套循环，会有一定的优化作用。
  - 数据流处理，不需要一次读入，可以减轻内存压力。
  - 部分情况下，可能无法预先得知所有的样本数据，这时蓄水池算法就比较有优势了，因为它不需要提前关注所有数据。
- 数学的推理验证真的很奇妙。
