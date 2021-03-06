# 问题描述

构造一个 $ M=64 $ $bins$ 的双哈希表，用来存储长为24位的数字，并且用低6位作为哈希函数的输出，高6位作为冲突时的 jump size。

# 算法流程描述

哈希表需要实现：插入，删除，查找；

而三个功能在操作前都需要做类似的定位操作，因此先描述定位功能的算法流程：

1. 将低六位赋给 i ，高六位赋给jump；
2. 查看哈希表中第 i 个位置是否已经被占用或是否与需定位元素相等，若没有或相等则返回 i；
3. 令 i = (i + jump) & 63，重复63次步骤2；
4. 返回 -1。

首先解释一下步骤3中的算式：63 = 64-1 = 0b0111111，因此一个数字与63按位求与，就会只保留其低六位。这样做的方法是保证每次jump之后的 i 值不会越出哈希表的边界。

## 插入

插入元素entry：

1. 定位entry
2. 若定位函数返回值为-1（代表无空间存储新元素）或返回的位置处已被占用（代表该元素已经存在），则返回 -1。
3. 令返回位置处的值为entry，然后维护哈希表的其余参数如size，sign；返回定位位置。

## 删除

删除元素entry：

1. 定位entry
2. 若定位函数返回-1（代表该元素不存在）或返回的位置处未被占用（代表该元素不存在），则返回失败。
3. 维护哈希表的参数如size，sign；返回成功。

## 查找

查找元素entry：

1. 定位entry
2. 若定位函数返回-1（代表该元素不存在）或返回的位置处未被占用（代表该元素不存在），则返回-1。
3. 返回定位位置。

# 算法实现

具体在实现的时候，由于需要测试插入的冲突次数，因此定位函数的参数还有一个默认为nullptr的冲突次数指针，只有插入函数调用时会传一个变量进去，其余两个函数则不会。

# 算法测试

## 功能测试

整个算法很简单清晰，这里只展示插入冲突元素时的处理结果。

插入数据如下（为了方便看在这里加上了空格，但过不了编译，所以实际运行时是没有空格的）：

![](..\Image\entrys.png)

最终在哈希表中存的结果如下：

![](..\Image\t.png)



## 随机测试

按照老师的要求，随机插入32个数字，并且统计探针次数。代码如下：

随机生成32个24位大小的数字并插入：

![](..\Image\code1.png)

展示哈希表：

![](..\Image\code2.png)

最终结果

![](..\Image\res1.png)



![](..\Image\res2.png)



![](..\Image\res3.png)

# 算法分析

首先根据程序运行的结果来看，平均探针次数是在1.3上下浮动，这是一个很好的结果。

但这其实只是插入32个数据的情况，当我将插入个数改为48时，平均探针次数已经来到了2，并且开始不太稳定，偶尔会突破四次。

当数据个数来到64，也就是插满的时候，冲突次数在6到7直接，偶尔甚至会到10。

因此，这也让我更直观的理解老师课件上的那个曲线图。