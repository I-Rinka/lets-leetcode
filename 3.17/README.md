# 3.17

剑指 Offer 14- I. 剪绳子【中等】https://leetcode-cn.com/problems/jian-sheng-zi-lcof/

160.相交链表【简单】https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

103.二叉树的锯齿形层序遍历【中等】https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/

20.有效的括号【简单】https://leetcode-cn.com/problems/valid-parentheses/

88.合并两个有序数组【简单】https://leetcode-cn.com/problems/merge-sorted-array/

## JZ 14

dp, 转移方程应该是

MAX(n)=max((MAX(1)\*MAX(n-1)),(MAX(2),MAX(n-2)),...,(MAX(n/2)\*MAX(n-n/2)))

这边其实我用的应该不是dp，而是备忘录法。MAX(n)指的是拆分n后的最大乘积，使用一个数组把每次n的计算结果存起来即可。

这边还有个小tips，实际上每个转移方程 (MAX(i),MAX(n-i)) 的 MAX(i) 除了算拆分后的值外，还要和自己比。比如 对于`3`在拆分后的最大乘积是 `2`，但是实际上在 `6 -> 3*3` 中我们用的不是 `6 -> 拆分(3)*拆分(3)`，而是使用不拆分的`3`本身的值 => 在拆分后合并乘积时，如果拆分并不能使值变大，那就用值本身而不拆分。

## 160

这题也是属于魔法题，魔法程度类似快慢指针。某链表到尾部时，继续放到头，然后同时遍历另一个指针，直到相遇。因为此时两指针都走过了m+n，所以相遇。对于没有环的，在到n\*m公倍数后，两指针会同时指向null

## 103

和层序遍历其实是一样的。用模2判断是正向推入还是反向推入。

## 20

使用栈即可。

## 88

这道题可以使用很naive的方法，这样就相当于一个简单的归并排序了。但其实可以不使用额外空间，并且时间复杂度为 O(m+n) 这样做。

两个数组都指向自己最末尾元素。并将两个元素中的大值放在nums1处没有填值的位置。

注意，因为最终的效果是nums2中的元素全部放进nums1中，所以结束放置的判断条件为nums2的元素大于零。此时可能会出现nums1游标小于零出界的情况，因此需要额外判断。

---

## C++ 分配数组

```c++
int *p1=new int[10];   //10个未初始化的int
int *p2=new int[10](); //10个初始化为0的int
string *p3=new string[10];  //10个空的string
string *p4=new string[10]();//10个空的string

// c++ 11 只能支持这种级别的初始化。如果是动态长度的，依然需要自己手动循环初始化
int *p1=new int[5]{0,1,2,3,4};
string *p3=new string[3]{"a","the",string(3,'x')};
```

## st::max

`max(a,b)` 返回a和b中的最大者。注意如果a和b是右值，比如 `max(a+1,a+2)`，会出现悬垂引用。

## std::reverse

`reverse(v.start(),v.end())` 翻转数组

## 关于vector

vector有push_back但是没有push_front

可以使用 vector.insert(v.begin(),element) 这种比较慢的方式向前插入。

vector还有 `.front()` 和 `.back()`，可以在某种程度上模拟栈和队列。
