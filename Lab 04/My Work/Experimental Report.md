# 程序描述

该程序实现了一个有序多元树，并且实现了多元树向LCRS树的转换



# 程序实现
有序树的实现比较简单，这里就不给出代码了。这一部分主要对转换的代码进行分析。

给出代码前，我们先考虑一下这个问题怎样拆解，由于LCRS树的定义很简单，加上看到老师给的LCRS树的图，我第一时间想到了递归的方法来实现。

其实转换的工作可以看做：
1. 首先，根节点的值直接赋值
2. 然后对于多元树该根节点g的n个子节点，从LCRS树的根节点L的左节点开始，不断申请n-1个右节点的空间。
3. 接下来，将每个L的子代节点的指针与对应的g的子节点作为新的输入，重复n次。

代码如下：

	void LCRS::trans(PtrToLNode *L,PtrTogNode g) {
		if(g == nullptr)//为空直接退出
				return;
				
		*L = new LNode(g->val);//为根节点申请空间并赋值
		
		if (g->size == 0)//如果没有子节点则结束
				return;
				
		PtrToLNode* p = &((*L)->left);//为左节点完成转换
		trans(p,g->child[0]);
		for (int i = 1; i < g->size; ++i){//不断申请右节点并
			p=&((*p)->right);//因为每个节点经过转换之后已经申请了空间，所以不会存在越界访问的问题
			trans(p,g->child[i]);//不断为右节点进行转换
		}
	}

# 程序测试
由于时间问题，树的可视化方法没有想到很好地解决办法，这里直接用调试功能给出展示。

## 测例1：一般功能测试
检测有序树的与LCRS树是否能正确生成。

输入情况如下：

		my_g_tree gtree;
        PtrTogNode pr = gtree.root;
        for (int i = 1; i <= 5; ++i)
            my_g_tree::addNode(pr, i);
        for (auto &j : pr->child) {
            for (int k = 6; k <= 10; ++k) {
                my_g_tree::addNode(j, k);
            }
        }
        LCRS ltree(gtree);

多元树：

![file](/api/users/image?path=6788/images/1571384238503.png)


![file](/api/users/image?path=6788/images/1571384266403.png)

![file](/api/users/image?path=6788/images/1571384395507.png)

![file](/api/users/image?path=6788/images/1571384406213.png)





## 测例2：极限测试——全逆序输入

只要多元树正确生成，那么根据测例1，LCRS也会正确生成

		my_g_tree gtree;
        PtrTogNode pr = gtree.root;
        for (int i = 1; i <= 5; ++i)
            my_g_tree::addNode(pr, 5-i);
        for (auto &j : pr->child) {
            for (int k = 6; k <= 10; ++k) {
                my_g_tree::addNode(j, 20-k);
            }
        }
        LCRS ltree(gtree);
				
				
![file](/api/users/image?path=6788/images/1571384639460.png)

![file](/api/users/image?path=6788/images/1571384651847.png)

## 测例3：极限测试——不平衡树

根据测例1、2，多元树正确性不需要考虑。

		my_g_tree gtree;
        PtrTogNode pr = gtree.root;
        for (int i = 1; i <= 5; ++i){
            my_g_tree::addNode(pr, i);
            pr=pr->child[0];
        }

        LCRS ltree(gtree);
				
![file](/api/users/image?path=6788/images/1571384680971.png)










