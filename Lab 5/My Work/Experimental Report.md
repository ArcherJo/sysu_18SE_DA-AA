# 程序功能
实现了AVL平衡树，保证树的叶节点的高度差不会超过1

# 程序设计

### 旋转

![file](/api/users/image?path=6788/images/1571988760672.PNG)

### 平衡因子

![file](/api/users/image?path=6788/images/1571988770231.PNG)

### 平衡（四种旋转方式）

![file](/api/users/image?path=6788/images/1571988774994.PNG)



# 程序测试

### 测例1：随机测试

- 代码：
```C++
	AVLTree<int> tree;
    int size = rand() % 10 + 10;
    for (int i=0; i < size; i++)
        tree.insert(rand());
    cout<<endl<<"            The AVL's size is: "<<tree.size()<<endl;
    tree.display();
```
- 结果：

![file](/api/users/image?path=6788/images/1571990025042.PNG)

![Uploading file...]()


### 测例2：极限测试（有序输入）

- 代码：
```C++
	AVLTree<int> tree;
    for (int i=0; i < 20; i++)
        tree.insert(i+11);
    tree.display();
```
- 结果：

![file](/api/users/image?path=6788/images/1571989526771.PNG)

- 代码：
```C++
	AVLTree<int> tree;
    for (int i=0; i < 30; i++)
        tree.insert(i+11);
    tree.display();
```
- 结果：

![file](/api/users/image?path=6788/images/1571989602067.PNG)

# 程序分析

| 函数 | 定义 | 时间复杂度|
| --- | --- | --- |
| `insert(T value)` | 插入元素 | O(logN) |
| `erase(T value)` | 删除元素 | O(logN) |
| `find(T value)` | 查找元素 | O(logN) |
| `operator[](int idx)` | 查找元素 | O(logN) |
| `clear()` |清空AVL | O(N) |
| `display()` |展示AVL | O(N) |