# 3月24日题目

148.排序链表【中等】https://leetcode-cn.com/problems/sort-list/

2.两数相加【中等】https://leetcode-cn.com/problems/add-two-numbers/

31.下一个排列【中等】https://leetcode-cn.com/problems/next-permutation/

144.二叉树的前序遍历【简单】https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

---

## 148

用优先队列先存后连。性能应该是 nlog(n)

## 2

简单题，两列表遍历

## 31

从后向前找。如果能在尾巴找到一个“最小的比当前数大的值”，交换位置，并且sort后面的数。

如果一直没找到，就sort整个数组

## 144

遍历

### 优先队列自定义规则

有点反常常识，优先级大的排在后面

```c++
struct cmp{
    bool operator() ( Node a, Node b ){
        //返回true时，a的优先级低于b的优先级（a排在b的后面）
        if( a.x== b.x ) return a.y> b.y;      
        return a.x> b.x; }
};
int main(){
    priority_queue<Node, vector<Node>, cmp> q;
```
