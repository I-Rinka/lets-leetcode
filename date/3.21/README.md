# 3月21日题目

199.二叉树的右视图【中等】https://leetcode-cn.com/problems/binary-tree-right-side-view/

143.重排链表【中等】https://leetcode-cn.com/problems/reorder-list/

94.二叉树的中序遍历【简单】https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

232.用栈实现队列【简单】https://leetcode-cn.com/problems/implement-queue-using-stacks/

704.二分查找【简单】https://leetcode-cn.com/problems/binary-search/

## 199

这道题是层序遍历。每次先放右节点。保证右节点先抵达后，对当前层做一个标记，这样后续节点就不会被添加

设置一个visit set，用于判断是否要输出当前的答案。

## 143

先用栈把节点存起来，然后再一个一个串起来。当栈出来的节点与当前节点，或者是当前节点的下个节点相同时，停止。

## 94

没什么好说的。。不过希望知道非递归求解法。

## 232

两个栈需要明确使用，知道哪个栈式顺序存放的，哪个是逆序存放的。顺序存放的栈适用push操作，逆序存放的栈适合取栈顶操作。如果对应操作类型不符合，就需要把两个栈互相交换着推一遍。

## 704

二分查找注意一下判断的条件，l<=r;l=mid+1;r=mid-1即可.

---

## shared_ptr

分配内存

```c++
shared_ptr<int> sp;//声明一个指向int类型的智能指针
sp.reset(new int(42));
auto sp1 = make_shared<string>("hello");//sp1是一个智能指针
shared_ptr sp2(new int(42));

// 一般常用make_shared
make_shared<type>(构造参数)

// shared_ptr 就是为了指向同一对象存在的
shared_ptr<int> sp;//声明一个指向int类型的智能指针
sp.reset(new int(42));
auto sp1 = make_shared<string>("hello");//sp1是一个智能指针
shared_ptr sp2(new int(42));
```

weak_ptr: 避免循环引用




```c++
struct Owner {std::shared_ptr<Owner> other;};
std::shared_ptr<Owner> p1 (new Owner());
std::shared_ptr<Owner> p2 (new Owner());
p1->other = p2; // p1 引用 p2p2->other = p1; // p2 引用 p1

```
![](https://pica.zhimg.com/80/v2-00d68717c982f39f238be557a3b1ccdc_720w.jpg?source=1940ef5c)

将其中的一个shared_ptr改成weak_ptr

```c++
struct Owner {
    std::shared_ptr<Owner> other;
};

std::weak_ptr<Owner> p1 (new Owner());
std::shared_ptr<Owner> p2 (new Owner());

p1->other=p2;

```

![](https://pic1.zhimg.com/80/v2-7964a2c4b65c12bd1e11d6f569aba610_720w.jpg?source=1940ef5c)

