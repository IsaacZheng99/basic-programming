1. 

引用算法4里面的一段话：

- 火箭科学家需要大致知道一枚试射火箭的着陆点是在大海里还是在城市中；
- 医学研究者需要知道一次药物测试是会杀死还是会治愈实验对象；

所以**任何开发计算机程序员的软件工程师都应该能够估计这个程序的运行时间是一秒钟还是一年**。



2. 

**不要以为只有C/C++才会有内存对齐，只要可以跨平台的编程语言都需要做内存对齐，Java、Python都是一样的**。

而且这是面试中面试官非常喜欢问到的问题，就是：**为什么会有内存对齐？**

主要是两个原因

1. 平台原因：不是所有的硬件平台都能访问任意内存地址上的任意数据，某些硬件平台只能在某些地址处取某些特定类型的数据，否则抛出硬件异常。为了同一个程序可以在多平台运行，需要内存对齐。
2. 硬件原因：经过内存对齐后，CPU访问内存的速度大大提升。

**大家可能会发现内存对齐岂不是浪费的内存资源么？**

是这样的，但事实上，相对来说计算机内存资源一般都是充足的，我们更希望的是提高运行速度。

**编译器一般都会做内存对齐的优化操作，也就是说当考虑程序真正占用的内存大小的时候，也需要认识到内存对齐的影响**。



3. 

**这道题目的前提是数组为有序数组**，同时题目还强调**数组中无重复元素**，因为一旦有重复元素，使用二分查找法返回的元素下标可能不是唯一的，这些都是使用二分法的前提条件，当大家看到题目描述满足如上条件的时候，可要想一想是不是可以用二分法了。



4. 

在本题中实现滑动窗口，主要确定如下三点：

- 窗口内是什么？
- 如何移动窗口的起始位置？
- 如何移动窗口的结束位置？

窗口就是 满足其和 ≥ s 的长度最小的 连续 子数组。

窗口的起始位置如何移动：如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）。

窗口的结束位置如何移动：窗口的结束位置就是遍历数组的指针，窗口的起始位置设置为数组的起始位置就可以了。

解题的关键在于 窗口的起始位置如何移动。



5. 

**一些录友会疑惑为什么时间复杂度是O(n)**。

不要以为for里放一个while就以为是O(n^2)啊， 主要是看每一个元素被操作的次数，每个元素在滑动窗后进来操作一次，出去操作一次，每个元素都是被被操作两次，所以时间复杂度是 2 × n 也就是O(n)。



6. 

模拟顺时针画矩阵的过程:

- 填充上行从左到右
- 填充右列从上到下
- 填充下行从右到左
- 填充左列从下到上

由外向内一圈一圈这么画下去。

可以发现这里的边界条件非常多，在一个循环中，如此多的边界条件，如果不按照固定规则来遍历，那就是**一进循环深似海，从此offer是路人**。



7. 

这里每一种颜色，代表一条边，我们遍历的长度，可以看出每一个拐角处的处理规则，拐角处让给新的一条边来继续画。

这也是坚持了每条边左闭右开的原则。

一些同学做这道题目之所以一直写不好，代码越写越乱。

就是因为在画每一条边的时候，一会左开又闭，一会左闭右闭，一会又来左闭右开，岂能不乱。



8. 

一些同学可能为了处理逻辑：每隔2k个字符的前k的字符，写了一堆逻辑代码或者再搞一个计数器，来统计2k，再统计前k个字符。

其实在遍历字符串的过程中，只要让 i += (2 * k)，i 每次移动 2 * k 就可以了，然后判断是否需要有反转的区间。

因为要找的也就是每2 * k 区间的起点，这样写，程序会高效很多。

**所以当需要固定规律一段一段去处理字符串的时候，要想想在在for循环的表达式上做做文章。**



9. 

有同学问了，为什么要从后向前填充，从前向后填充不行么？

从前向后填充就是O(n^2)的算法了，因为每次添加元素都要将添加元素之后的所有元素向后移动。

**其实很多数组填充类的问题，都可以先预先给数组扩容带填充后的大小，然后在从后向前进行操作。**



10. 

我们习惯看到的表达式都是中缀表达式，因为符合我们的习惯，但是中缀表达式对于计算机来说就不是很友好了。

例如：4 + 13 / 5，这就是中缀表达式，计算机从左到右去扫描的话，扫到13，还要判断13后面是什么运算法，还要比较一下优先级，然后13还和后面的5做运算，做完运算之后，还要向前回退到 4 的位置，继续做加法，你说麻不麻烦！

那么将中缀表达式，转化为后缀表达式之后：["4", "13", "5", "/", "+"] ，就不一样了，计算机可以利用栈里顺序处理，不需要考虑优先级了。也不用回退了， **所以后缀表达式对计算机来说是非常友好的。**

可以说本题不仅仅是一道好题，也展现出计算机的思考方式。

在1970年代和1980年代，惠普在其所有台式和手持式计算器中都使用了RPN（后缀表达式），直到2020年代仍在某些模型中使用了RPN。

参考维基百科如下：

> During the 1970s and 1980s, Hewlett-Packard used RPN in all of their desktop and hand-held calculators, and continued to use it in some models into the 2020s.



11. 

![image-20220627105515451](programmer-carl.assets/image-20220627105515451.png)



12. 

![image-20220627132910130](programmer-carl.assets/image-20220627132910130.png)

13. 

![image-20220630090304993](programmer-carl.assets/image-20220630090304993.png)



14. 

![image-20220630155448419](programmer-carl.assets/image-20220630155448419.png)



15. 

![image-20220701090146596](programmer-carl.assets/image-20220701090146596.png)



16. 

![image-20220704193405441](programmer-carl.assets/image-20220704193405441.png)



17. 

![image-20220704193557211](programmer-carl.assets/image-20220704193557211.png)



18. 

![image-20220705203335352](programmer-carl.assets/image-20220705203335352.png)



19. 

![image-20220706083059063](programmer-carl.assets/image-20220706083059063.png)



20. 

![image-20220706091912019](programmer-carl.assets/image-20220706091912019.png)



21. 

![image-20220707194009619](programmer-carl.assets/image-20220707194009619.png)



22. 

![image-20220707194307949](programmer-carl.assets/image-20220707194307949.png)



23. 

![image-20220708134236460](programmer-carl.assets/image-20220708134236460.png)



24. 

![image-20220708134604717](programmer-carl.assets/image-20220708134604717.png)



25. 

![image-20220708142859710](programmer-carl.assets/image-20220708142859710.png)



26. 

![image-20220708170925665](programmer-carl.assets/image-20220708170925665.png)



26. 

![image-20220712090438501](programmer-carl.assets/image-20220712090438501.png)



27. 

![image-20220715081735801](programmer-carl.assets/image-20220715081735801.png)



28. 

![image-20220715134116393](programmer-carl.assets/image-20220715134116393.png)



29. 

![image-20220715144821717](programmer-carl.assets/image-20220715144821717.png)



30. 

![image-20220719092342621](programmer-carl.assets/image-20220719092342621.png)



31. 

![image-20220722084904219](programmer-carl.assets/image-20220722084904219.png)



32. 

![image-20220722084930933](programmer-carl.assets/image-20220722084930933.png)



33. 

![image-20220722084959956](programmer-carl.assets/image-20220722084959956.png)



34. 

![image-20220722085034341](programmer-carl.assets/image-20220722085034341.png)



35. 

![image-20220722085527511](programmer-carl.assets/image-20220722085527511.png)



36. 

![image-20220722102024446](programmer-carl.assets/image-20220722102024446.png)



37. 

![image-20220722132447520](programmer-carl.assets/image-20220722132447520.png)



38. 

![image-20220722133135599](programmer-carl.assets/image-20220722133135599.png)



39. 

![image-20220722193757011](programmer-carl.assets/image-20220722193757011.png)



40. 

![image-20220725103128299](programmer-carl.assets/image-20220725103128299.png)



41. 

![image-20220725104841380](programmer-carl.assets/image-20220725104841380.png)



42. 

![image-20220726130740123](programmer-carl.assets/image-20220726130740123.png)



43. 

![image-20220726171352677](programmer-carl.assets/image-20220726171352677.png)



44. 

![image-20220726174629204](programmer-carl.assets/image-20220726174629204.png)



45. 

![image-20220727100955265](programmer-carl.assets/image-20220727100955265.png)



46. 

![image-20220829154825493](programmer-carl.assets/image-20220829154825493.png)



47. 

![image-20220920092329853](programmer-carl.assets/image-20220920092329853.png)



48. 

![image-20220923170527068](programmer-carl.assets/image-20220923170527068.png)



49. 

![image-20220923170722795](programmer-carl.assets/image-20220923170722795.png)



50.

![image-20221117091948355](programmer-carl.assets/image-20221117091948355.png)



51. 

![image-20230129084753373](programmer-carl.assets/image-20230129084753373.png)



52. 

![image-20230129085617624](programmer-carl.assets/image-20230129085617624.png)



53. 

![image-20230129085654666](programmer-carl.assets/image-20230129085654666.png)



54. 

![image-20230129085709257](programmer-carl.assets/image-20230129085709257.png)



55. 

![image-20230129091703410](programmer-carl.assets/image-20230129091703410.png)



56. 

![image-20230129091929506](programmer-carl.assets/image-20230129091929506.png)



57. 

![image-20230130112320783](programmer-carl.assets/image-20230130112320783.png)



58. 

![image-20230130141520378](programmer-carl.assets/image-20230130141520378.png)



59. 

![image-20230131195057040](programmer-carl.assets/image-20230131195057040.png)



60. 

![image-20230201132324272](programmer-carl.assets/image-20230201132324272.png)





61. 

![image-20230201150426887](programmer-carl.assets/image-20230201150426887.png)



62. 

![image-20230201150407177](programmer-carl.assets/image-20230201150407177.png)



63. 

![image-20230202093858612](programmer-carl.assets/image-20230202093858612.png)



64. 

![image-20230202094026114](programmer-carl.assets/image-20230202094026114.png)



65. 

![image-20230202094110722](programmer-carl.assets/image-20230202094110722.png)



66. 

![image-20230203133309582](programmer-carl.assets/image-20230203133309582.png)



67. 

![image-20230206090933873](programmer-carl.assets/image-20230206090933873.png)



68. 

![image-20230206090957457](programmer-carl.assets/image-20230206090957457.png)



69. 

![image-20230206091238161](programmer-carl.assets/image-20230206091238161.png)



70. 

![image-20230206095952900](programmer-carl.assets/image-20230206095952900.png)



71. 

![image-20230206162645321](programmer-carl.assets/image-20230206162645321.png)



72. 

![image-20230206163439393](programmer-carl.assets/image-20230206163439393.png)



73. 

![image-20230207143129168](programmer-carl.assets/image-20230207143129168.png)



74. 

![image-20230207162833286](programmer-carl.assets/image-20230207162833286.png)



75. 

![image-20230207163824804](programmer-carl.assets/image-20230207163824804.png)



76. 

![image-20230214091158482](programmer-carl.assets/image-20230214091158482.png)



77. 

![image-20230222113149869](programmer-carl.assets/image-20230222113149869.png)



78. 

![image-20230306150202797](programmer-carl.assets/image-20230306150202797.png)



79. 

![image-20230306150214378](programmer-carl.assets/image-20230306150214378.png)
