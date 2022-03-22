# 3月22日题目

70.爬楼梯【简单】https://leetcode-cn.com/problems/climbing-stairs/

19.删除链表的倒数第 N 个结点【中等】https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

56.合并区间【中等】https://leetcode-cn.com/problems/merge-intervals/

剑指 Offer 22. 链表中倒数第k个节点【简单】https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/

69.x 的平方根【简单】 https://leetcode-cn.com/problems/sqrtx/

## 70

使用滚动数组

## 19

用双指针。先让第一个指针移动n格，然后再让第二个指针开始移动。这样子可以优化掉一半的时间。

这边有个特殊判断，就是如果有n个节点，然后输入的是n，那么倒数第n节点就是第一个节点，这个时候直接返回head->next即可。

## 56

首先排序，把end最大的放在最后面，然后从后向前遍历。

如果n[i].start<=n[i-1].start,那么后者吞并前者。并且由于最后一项的右边一定是大的，所以只要一直遭遇左边不如自己的，就可以一直吞并。

----

### c++ 自定义sort规则

`std::sort(begin(),end(),cmp)`

#### 使用lambda定义cmp

**lambda 函数内的语句一定要加`;`**！

`[捕获] (参数) -> 返回值类型 {函数体}`

```c++

sort(begin,end,
[](int&a,int&b) -> bool
    {
        return a>b; // 注意分号！
    }
)

// or
sort(begin,end,[](int&a,int&b){return a>b;})

```

### vector删除指定区域元素

`v.erase(v.begin()+offset)` 注意，这里传入的是迭代器位置！

## JZ22

和上面某题一样套路

# 69

二分查找。在0~x/2区间查找即可。

总感觉数值分析好像学过。

这边用例有可能溢出，所以mid最好用unsigned long long

也可以从1开始查找

用x/m<\m而不是m*m>x防止溢出