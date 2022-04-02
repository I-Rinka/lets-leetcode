# lets-leetcode
Push me to update algorithm notes every day.

## C++ 刷算法常用操作

### 声明二维数组

先大小，再初始化

```c++
 vector<bool>v(s.size(),false);
 vector<vector<bool>>dp(s.size(),v);
```

### 常用数据结构及操作

`string.substr(pos,len)`

`vector.push_back()` no push_front!

`stack.top()`

`queue.front()`

### 字符串操作

转换成整数：



### hashmap

`std::unordered_map`

#### 遍历

```c++
for(auto &kv:hashmap)
{
  kv.first;kv.second;
}
```

#### 查找元素，判断是否存在

`auto find=parentMap.find(key_element);`

得到的find是pair*类型的，如果需要访问 `key` : `find->first`, 访问 `value` :  `find->second`

```c++
while((find=parentMap.find(element))!=parentMap.end()) // 查找代码
```

* 注意，不能直接 set.insert(*迭代器)。这里需要显示类型转换一下，把迭代器转换成元素才可以。

#### 关于pair

### std常用算法

reverse

sort

find

### set

#### 初始化

std::set<int> numbers {8, 7, 6, 5, 4, 3, 2, 1};

#### 遍历

**注意！！！只能用`!=`而不是`<`**

```c++
for(auto i=st.begin();i!=st.end();i++)
{

}
```

#### 和vector互相转换

set<type>st(vec.begin(),vec.end())
vec.assing(st.begin(),st.end())

vector<type>vec(st.begin(),st.end())