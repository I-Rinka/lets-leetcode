# 3.23

124.二叉树中的最大路径和【困难】https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

82.删除排序链表中的重复元素 II【中等】https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

8.字符串转换整数 (atoi)【中等】https://leetcode-cn.com/problems/string-to-integer-atoi/

## 124

假后续遍历。这题是真的坑,没好好读题。总之，需要返回 本, l+本 , r+本的最大值。同时要往优先队列里面把所有的最大值都推进去。

## 82

这题没能用最优法解出来。使用了一个multi set，用来记录重复次数，然后把非重复的再连起来。

## 8

c++ 真的怪。try catch不能抓整形溢出错？那我究竟怎么判断错，int溢出本来想用大于小于0判断法，但是直接这么算，只要有溢出，就自动吐栈，真的邪门，肏。

所以只能换用long long 来做了，很暴力
