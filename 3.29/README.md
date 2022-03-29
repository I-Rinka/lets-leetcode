# 3月29日题目

101.对称二叉树【简单】https://leetcode-cn.com/problems/symmetric-tree/

155.最小栈【简单】https://leetcode-cn.com/problems/min-stack/

234.回文链表【简单】https://leetcode-cn.com/problems/palindrome-linked-list/

98.验证二叉搜索树【中等】https://leetcode-cn.com/problems/validate-binary-search-tree/

470.用 Rand7() 实现 Rand10()【中等】https://leetcode-cn.com/problems/implement-rand10-using-rand7/

---

~~今天的题中等的都是简单题，简单题都是中等题~~

## 101

递归同时传入镜像的点。第一次提交的时候漏了一个条件：l->val != r->val

## 155

这个题和昨天的滑动窗口题有些类似。我们需要额外维护一个单调栈：只把小于栈顶的元素给推入

## 98

使用二叉搜索树的性质：中序遍历可以还原出一个有序数组，遍历完后判断数组是否有序

## 234

这道题思路不难，但是需要实现的话比较难。时间O(n)，空间O(1)解法：

1. 快慢链表遍历。快链表到头时，慢链表刚好到中心节点
2. 头～中心节点翻转
3. 遍历原链表和翻转后到链表
4. 复原

## 470

一开始想的是：10个Rand7相加，然后除以7

但是显然，这样做出来的结果应该是正太分布。

lc答案里给了一种“拒绝分布”的方法：先手动统计乘积后可能出现的所有数的概率，再随机选取相同概率的数。如果没有抽中给定的数，就拒绝并进入下一循环
