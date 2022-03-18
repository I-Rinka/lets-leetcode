# 3月18日题目

剑指 Offer 43. 1～n 整数中 1 出现的次数【困难】https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/

236.二叉树的最近公共祖先【中等】https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

33.搜索旋转排序数组【中等】https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

---

今天apple watch出问题认为我睡觉的时候摘表了，结果早上是被手机而不是手表唤醒的。作为额外花钱买aw就是为了震动唤醒功能的人，这种情况搞得我很生气。

## JZ43

~看到 2^32 次方就感到不妙。总之应该是dp。~

总之是找规律。找到某一位之内会有多少个1，然后依次把位累加起来。

从个位开始遍历。当前1的个数=∑(当前位值*当前位1的个数)

## 236

应该可以用后序遍历来做。

因为后序遍历时本节点仍在栈内，因此当题目给定的两节点都入栈后，在栈中查找公共节点。

我把这个题看作是“namespace”的实现，例如两颗子树只知道自己空间的命名域，但是不知道另一个空间的。只有到顶层节点，统一命名域后才互相知道对方。

---

### c++ hash map


`auto find=parentMap.find(curNode);`

得到的find是pair*类型的，如果需要访问 `key` : `find->first`, 访问 `value` :  `find->second`

```c++
while((find=parentMap.find(curNode))!=parentMap.end()) // 查找代码
```

* 注意，不能直接 set.insert(*迭代器)。这里需要显示类型转换一下，把迭代器转换成元素才可以。

## 33

经典折半查找

先找失序点，接着对失序点两侧进行查找。
