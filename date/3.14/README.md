# 3月14日题目

53.最大子数组和【简单】<https://leetcode-cn.com/problems/maximum-subarray/>

206.反转链表【简单】<https://leetcode-cn.com/problems/reverse-linked-list/>

21.合并两个有序联表【简单】<https://leetcode-cn.com/problems/merge-two-sorted-lists/>

3.无重复字符的最长子串【中等】<https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/>

215.数组中的第K个最大元素【中等】<https://leetcode-cn.com/problems/kth-largest-element-in-an-array/>

## 53

这道题很容易想复杂了，一开始我想的是滑动窗口之类的，需要维护start和end。但仔细思考会发现，最大子数组和其实就是“找到一个最大的起始点，从尾巴数过去到起始点和最大的值”。

因此算法思路很简单，一直维护一个当前值 `curVal` 意味着当前位置 `i` 到之前起始值的和，因此如果当前位置的值本身大于了 `curVal`，那么从当前位置开始累加的值一定是大于之前值的和继续往后累加所得的结果。

## 206

我觉得这道题应该有时间复杂度 `O(n)` 空间复杂度 `O(n)` 以及 时间复杂度 `O(n^2)` 空间复杂度 `O(1)` 的两种解法。面试前最好问问面试官有没有额外要求。

这里我用了时间复杂度 `O(n)` 法。总之就是维护一个栈，链表是先进先出，栈是先进后出，倒过来再连一遍即可

## 21

这道题主要的难点应该是边界情况而非算法本身：例如什么时候 `list1` 的当前值是空，什么时候 `list2` 的当前值是空等。

当属于1的节点为空值或，属于2节点的值更小且属于2的节点非空时，加入属于2的节点。反之亦然。

## 3

这题我认为肯定有比我更好的解法。我是使用了hashmap同时判断字符是否重复，以及本字符上一次出现的位置。最大非重复子串=当前位置 - 当前开始值 + 1

这里有个小debug的点，如果当前的开始值比上一次出现的位置大，则使用当前的开始值而不是某字符上一次出现的位置，否则对于串 `abba` 会出现读入最后一个 `a` 时，开始值取到了第一个 `a`，但是由于中间有重复的 `b` 的存在，所以只能从当前开始值 `b` 取。

## 215

跳票了，属于是直接 `python` sort了一遍。

但是印象中算法导论有说过一个分治划分法，将区域划分成田字格一样的四份，可以以 `O(n)` 的时间复杂度找到k大。但是那个算法很复杂，而且debug困难，考虑到要吃午饭了，因此先咕咕咕

实际算法：快速选择算法。类似快排，但是只负责划分与返回对应每次划分的偏移，不进行排序。

---

老年人康复训练。争取把3和215用cpp的hash map以及堆重写一遍

## C++ unordered_map

插入:

- `mp[value] = i`

删除:

- `mp.erase(s[i])`

查找:

- `mp.find(s[i]) != mp.end()`

遍历:

```c++
for(auto it=map.begin();it!=map.end();it++){
        cout<<it->first<<it->second<<endl;
    }

for(auto& kv:map){
        cout<<kv.first<<kv.second<<endl;
    }

for(auto& [k,v]:map){
        cout<<k<<v<<endl;
    }
```