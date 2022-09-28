# 3.16

1. 两数之和【简单】https://leetcode-cn.com/problems/two-sum/

121. 买卖股票的最佳时机【简单】https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

141. 环形链表【简单】https://leetcode-cn.com/problems/linked-list-cycle/

剑指 Offer 26. 树的子结构【中等】https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/

102. 二叉树的层序遍历【中等】https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

## 1

排序+二分查找。时间复杂度 O(logN)

c++ set转vector:

```c++

vector<int>v(st.begin(),st.end());

```

## 121

没什么好说的。。从后往前遍历即可。

## 141

两种方法：

如果内存 O(n)，则做一个bool visit数组，判定是否访问过某节点。

如果内存常量，则快慢指针即可。

## 剑指 Offer 26. 树的子结构 

在A树上选定某根节点，接着以B树为基准，以和B树遍历相同的方式遍历A树，如果B树上所有节点和A树对应节点相等，那么说明子结构相同。

std::queue 用法:

```c++

q.front(); // 访问第一个
q.back(); // 访问最后一个
q.pop(); // 删除

q.push(); // 插入

```

## 102

小学生题，easy难度

---

如果要返回空vector，可以在return处直接构造：

```c++

#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> GetVector()
{
    return vector<vector<int>>();
}
int main(int argc, char const *argv[])
{

    cout << GetVector().size();
    return 0;
}

```