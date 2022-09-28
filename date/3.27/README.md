# 3月27日题目

543.二叉树的直径【简单】https://leetcode-cn.com/problems/diameter-of-binary-tree/

112.路径总和【简单】https://leetcode-cn.com/problems/path-sum/

110.平衡二叉树【简单】https://leetcode-cn.com/problems/balanced-binary-tree/

129.求根节点到叶节点数字之和【中等】https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/

113.路径总和 II【中等】https://leetcode-cn.com/problems/path-sum-ii/

## 543

使用递归

每次递归的时候，都记录 左+右的深度，同时向上返回最大的深度

最后答案返回的就是最大的 左+右

## 112

dfs遍历树。本节点如果是叶子，且本节点值与历史累计值相加为目标值，那么返回true。

## 110

和543题类似

## 129

总之到每层节点后，都生成到当前节点的整数。如果本节点刚好是叶子，那么加到总和中。

## 113

总之还是dfs，类似112，但是这次要存所有的结果，于是也没剪枝了.
