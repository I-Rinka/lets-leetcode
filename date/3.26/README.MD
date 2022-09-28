# 3月26日题目
72.编辑距离【困难】https://leetcode-cn.com/problems/edit-distance/

1143.最长公共子序列【中等】https://leetcode-cn.com/problems/longest-common-subsequence/

22.括号生成【中等】https://leetcode-cn.com/problems/generate-parentheses/

## 72

这题最难的就是它的思考过程：把删除抽象成“给目标串添加一个当前字母”是最困难的。

这题的dp解法，i和j代表的是到word1[i]和word2[j]时两者一样。这里思考的起点主要是word[i-1]和word[j-1]。如果从0开始思考边界情况真的很难，所以我就从过程中间开始思考，比如假设

`xxhorse`

`xxrose`

前面的xx表示均为相同，当前i和j分别指向 `h` 和 `r`，然后我们从这里开始思考替换、插入、删除的操作。删除之所以不是单纯的删掉word1，是因为我们无法保证`xxhorse`删除i处位置的单词 `xxorse` 与 `xxrose` 的新ij处相等，毕竟现在 `o` 是不等于 `r` 的，所以真实是等效向word2中插入一个单词，变为 `xxhorse` 与 `xxhrose`，这样ij的生成，就可以理解为从当前i位置的dp，和word2对应的上一个相等位置`j-1`也就是`x`处拿value生成的。

## 1143

dp经典问题

这题自己做的时候漏了一个条件：当i处和j处不相等时，应该取此时dp[i-1][j]和dp[i][j-1]中的最大值，而不是dp[i-1][j-1]，因为这个意味着有一处转移了，但是另一边没转移，而不是两边都不转移。

## 22

感觉以后回溯题要多练练。不能总是一遇到回溯就想hashmap
