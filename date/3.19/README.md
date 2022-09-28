# 3月19日题目

5.最长回文子串【中等】https://leetcode-cn.com/problems/longest-palindromic-substring/

200.岛屿数量【中等】https://leetcode-cn.com/problems/number-of-islands/

46.全排列【中等】https://leetcode-cn.com/problems/permutations/

415.字符串相加【简单】https://leetcode-cn.com/problems/add-strings/

## 5

使用dp，转移方程：dp[i][j]=(s[i]==s[j])&&dp[i-1][j-1]

注意这里有个边界情况，就是j==i-1时，也就是子串长度为2，这个时候需要单独判断 dp[i][i]

## 200

bfs. 其实这边也可以有个技巧，就比如不单独开visit数组了，直接填陆地

## 46

dfs. 其实这个东西是个np问题

## 415

属于是过于简单了

---

C++ vector二维数组

```c++

vector<int> line(10,1);
vector<vector<int>>square(9,line);

```

C++ bitset

注意！bitset写题的时候不好用。bitset初始化时只能跟个常量

```c++

// 初始化
bitset<n> b; // b有n位0

bitset<n> b(u); // b是 unsigned long long的低n位拷贝。超出部分填0
bitset<32> b(1U) // 32位，低位为1

bitset<n> b(string("01111"),pos,length); // 从01串中pos开始的length长字符串


// 操作
b.any(); // 存在为1的返回true
b.all(); // 全部都为1才返回true
b.count(); // b中为1的个数
b.test(pos); // b中第pos位为1时返回true
b.set(pos,bl); // 将b中pos为值为一个bool值

b.set(); // 所有位变为1
b.reset(); // 所有位变为0

b[pos]; // 这个是引用吗？

b.to_ulong(); // 返回一个unsigned long
b.to_ullong(); // 返回一个unsigned long long

```

vector 版bitset

```c++
    vector<bool>v({true,false,true});
    vector<vector<bool>>bs(10,v);

    // size*size大小的矩阵. 注意初始化的时候是先大小再构造！
    vector<bool>v(s.size(),false);
    vector<vector<bool>>dp(s.size(),v);
```

c++ string

```c++

str.substr(pos,len); // 这边是len，而不是结束位置！

str.push_back('c');

std::reverse(str.begin(),str.end());

```

c++ pair, 用于计算 x y坐标的时候还比较管用

```c++
pair<T1, T2> p1;            //创建一个空的pair对象（使用默认构造），它的两个元素分别是T1和T2类型，采用值初始化。
pair<T1, T2> p1(v1, v2);    //创建一个pair对象，它的两个元素分别是T1和T2类型，其中first成员初始化为v1，second成员初始化为v2。
make_pair(v1, v2);          // 以v1和v2的值创建一个新的pair对象，其元素类型分别是v1和v2的类型。
p1 < p2;                    // 两个pair对象间的小于运算，其定义遵循字典次序：如 p1.first < p2.first 或者 !(p2.first < p1.first) && (p1.second < p2.second) 则返回true。
p1 == p2；                  // 如果两个对象的first和second依次相等，则这两个对象相等；该运算使用元素的==操作符。
p1.first;                   // 返回对象p1中名为first的公有数据成员
p1.second;  
```