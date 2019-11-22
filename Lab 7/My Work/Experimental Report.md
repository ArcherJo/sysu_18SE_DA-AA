# 算法描述
利用堆结构进行的原地（In-place）排序算法。

# 算法设计

将输入的线性表理解为完全树，即如下图：

![Heap](..\Image\Heap.png)

这样，我们可以很简单的发现两个规律：

1. 设任一节点的下标为 $ i $，那么该节点的两个子节点（若有的话）的下标为 $ 2i,2i+1 $ ；
2. 设任一节点的下标为 $ i $，那么该节点的父节点（若有的话）的下标为 $ \frac{i}{2} $ 。

注：第一个元素下标为1。

因此，可以利用类似Lab6中min-heap的思想构造一个max-heap，再辅以一点改变，就可以实现原地堆排序算法。

# 算法流程

整个堆排序的步骤可大体分为2步

1. 构造max-heap
2. 重复pop堆顶，将pop出的元素置于表尾，同时更新max-heap的结构

在本程序中有一个很关键的Max_family方法。通过该方法能构造与更新max-heap。下面将逐步描述流程。

## Max_family

1. 输入 $ i $ 表示对第 $ i $ 个元素进行操作。
2. 令 $ tmp $ 为 $ i $ 与其两个子节点（若有的话）之中最大者的下标。
3. 若 $ tmp=i $ ，则结束；否则，交换第 $ tmp $ 个元素与第  $ i $ 个元素的值，以 $ tmp $ 为输入调用Max_family。

## construct

1. 令 $ i $ 等于数组长度。
2. 若 $ i\geqslant1 $ ，则以 $ i $ 为输入调用Max_family；否则返回。
3.  $ i $ 自减1，重复步骤2。

## sort

1. 令 $ len $ 等于数组长度。
2. 若 $ len\geqslant1 $ ，则交换第一个元素与第 $ len $ 个元素，以 $ 1 $ 为输入调用Max_family。
3.  $ len $ 自减1，重复步骤2。

# 测例设计与程序测试

直接进行随机测试。

## 随机测试

实现如下：

```c++
for (int & i : array)
        i=rand()%100;
heap_sort a(array);
a.show();
```

三次测试结果如下：

![t](..\Image\t_1.png)

![t](..\Image\t_2.png)

![t](..\Image\t_3.png)

# 复杂度分析

There are no worst-case scenarios for heap sort.

| 操作      | 最好情况                       | 最坏情况                            | 平均情况                            |
| --------- | ------------------------------ | ----------------------------------- | ----------------------------------- |
| Heap-sort | $ \varTheta \left( n \right) $ | $ \varTheta \left( nln(n) \right) $ | $ \varTheta \left( nln(n) \right) $ |



