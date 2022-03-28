# 3月28日题目

4.寻找两个正序数组的中位数【困难】https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

239.滑动窗口最大值【困难】https://leetcode-cn.com/problems/sliding-window-maximum/

## 4

这道题和我一开始想的不太一样。我原本是想通过直接删去两个数组大小二分之一的长度逐步缩小范围，但是这道题是通过直接删去k，并且两个数组有同一个偏移量来做。

如果 \text{A}[k/2-1]A[k/2−1] 或者 \text{B}[k/2-1]B[k/2−1] 越界，那么我们可以选取对应数组中的最后一个元素。在这种情况下，我们必须根据排除数的个数减少 kk 的值，而不能直接将 kk 减去 k/2k/2。

## 239

直接用set之类的做
