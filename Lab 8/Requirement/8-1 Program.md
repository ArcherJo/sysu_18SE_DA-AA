# Lab Work 08-1. Implementation of a M-way Merge Sort by Making Use of min-Heap

*Note. Programming in C++, including <iostream>/<iostream.h>, <cstdlib>/<cstdlib.h> and <cmath>/<math.h> only* 

### 问题描述：

设有 M = 8 个有序队列，每个队列的关键字从小到大排列，需要将这些队列元素归并成一个新的从小到大的有序队列。

### 算法描述：

取出每个队列的队头元素，构造一个有 M 个节点的完全小顶堆，利用这个小顶堆实现 M-路归并排序。

排序的每一趟是：

* Pop 堆顶得到当前的最小元素 x，设 x 来自队列 k；
* Dequeue 队列 k 得到元素 y，将 y 装入堆顶；
* 实施 Percolating 维护堆。

说明：队列 k 为空时，Dequeue 操作失败，此时将堆尾元素移入堆顶并维护堆；直至所有队列为空。此时堆也被清空。

### 数据结构描述：

设计上述实现的数据结构，包括队列结构和堆结构。

### *思考：*

你没有更好的想法，不妨试试看。

(End)