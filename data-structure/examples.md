# 数据结构示例

## 1. 写在前面

- 数据结构是基础。
- 对数据结构的理解最好不要浮于表面，知道怎么用，更要知道怎么去实现，以及为什么要这么实现。
- 示例没有严格按照逻辑数据结构或物理数据结构的类型来进行分类，部分条目中的内容可能会有重叠，但最终的目的是希望能够通过具体的业务场景和实际使用的例子来理解数据结构的思想。
- 文本主要是记录了学习过程中遇到的数据结构的真实案例，帮助我们更好地理解其本质。
- 部分内容只是笔者的猜想，没有具体验证过，如果有误，欢迎指出。

## 2. 示例

### 2.1 栈 stack

- Linux中的`cd`命令：

  ```
  cd a/b/c/../../
  ```

  最后我们会进入到a目录。过程：`a -> b -> c -> /..，出栈c -> /..，出栈b`。

### 2.2 一种限量的容器

- 具体业务场景中，我们需要需要不断判断当前数据是否处理完成，一个可行的方法就是，确定了最后输出的“数据量”，例如最后会有5条数据，那么就将这个容器大小设置为5，当容器满时，表示处理完毕。

- 框架示例：

  ```python
  class CContainer:
      def __init__(self, iVolume: int):
          self.m_Elems: List = []  # 这里以list为例存储数据，具体可以根据业务需求进行调整
          self.m_Volume: int = iVolume  # 记录需要处理的数据个数
  
      def AddElem(self, oElem):
          self.m_Elems.append(oElem)
  
      def GetElems(self) -> List:
          return self.m_Elems
  
      def CheckFull(self) -> bool:
          return len(self.m_Elems) == self.m_Volume
  ```

  

