# 3.20

一天遇上三个一生之敌.

54.螺旋矩阵【中等】https://leetcode-cn.com/problems/spiral-matrix/ ✨

300.最长递增子序列【中等】https://leetcode-cn.com/problems/longest-increasing-subsequence/ ✨

42.接雨水【困难】https://leetcode-cn.com/problems/trapping-rain-water/ ✨

---

## 54

这题是属于一生之敌了。

比较容易错的地方是，注意打印的时候判断不会打印重，比如从左往右打很可能会和从右往左打处于一行。

## 300

首先是dp做法。这题的dp时间复杂度也是比较高的，每到位置n的时候，需要判断前面n-1个元素长度最大值且那个位置上的元素大小小于n。dp只是记录了最长信息，没有额外的大小判断，主要是大小判断的地方需要花时间。

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size());
        
        for(int i=0;i<nums.size();i++)
        {
            int maxL=1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    maxL=std::max(maxL,dp[j]+1);
                }
            }
            dp[i]=maxL;
        }

        int maxL=1;
        for(int i=0;i<dp.size();i++)
        {
            if(dp[i]>maxL)
            {
                maxL=dp[i];
            }
        }
        return maxL;
    }
};
```

接着题目说还有个nlogn的算法,本质上是直接在答案中插入。由于答案是基本有序的，所以能优化到nlogn

---

### 关于手写折半查找

尽量使用循环而不是函数递归

```c++

int l=0,r=max-1;

while(l<=r)
{
    int mid=(l+r)/2;

    if(...)
    {
        // 保存position或者直接返回之类的
        r=mid+1;
    }
    else
    {
        l=mid-1;
    }
}


```

## 42

这题出事故了。本来想左边填一下，右边填一下，最坏情况是O(n^2)，然后就能出结果的，但是没想到有个特殊用例刚好卡了 O(n^2) 算法。

原思路：这里还被C++ map遍历删除给坑了一下

```c++
class Solution {
public:
    auto mkPair(int a,int b)
    {
        if(a>b)
        {
            return make_pair(b,a);
        }
        else
        {
            return make_pair(a,b);
        }
    }
    int trap(vector<int>& height) {
        int ans=0;
        map<pair<int,int>,int>visit;
        for(int i=0;i<height.size()-1;i++)
        {
            int solid=0;
            int j=i+1;
            for(;j<height.size();j++)
            {
                if(height[j]>=height[i])
                {
                    if(j-i>1)
                    {
                        visit[this->mkPair(i,j)]=height[i]*(j-i-1)-solid;
                    }
                    i=j-1;
                    break;
                }
                else
                {
                    solid+=height[j];
                }
            }
        }

        for(int i=height.size()-1;i>0;i--)
        {
            int solid=0;
            int j=i-1;
            
            for(;j>=0;j--)
            {
                if(height[j]>=height[i])
                {
                    if(i-j==1)
                    {
                        break;
                    }

                    auto newPair=this->mkPair(i,j);
                    bool insert=true;

                    // 清除所有被囊括的 如果有加速算法，应该就在这里使用
                    for(auto kv=visit.begin();kv!=visit.end();)
                    {
                        if(newPair.first <= kv->first.first && newPair.second>=kv->first.second)
                        {
                            visit.erase(kv++);
                        }
                        else
                        {
                            ++kv;
                        }
                    }
                    
                    // 判断自己是否要被插入
                    if(newPair.second-newPair.first<=1)
                    {
                        insert=false;
                    }
                    else
                    {
                        for(auto &kv:visit)
                        {
                            if((newPair.first >= kv.first.first && newPair.second<=kv.first.second))
                            {
                                insert=false;
                                break;
                            }
                        }
                    }
                    if(insert)
                    {
                        visit[newPair]=height[i]*(newPair.second-newPair.first-1)-solid;
                    }
                    i=j+1;
                    break;
                }
                else
                {
                    solid+=height[j];
                }
            }
        }
        
        for(auto &kv:visit)
        {
            ans+=kv.second;
        }

        return ans;
    }
};
```

实际上这题我想的没错，但是用dp会更快，总之还是左边填一下，右边填一下。然后填的面积为左填和右填的交。最后把土地的面积减去，就是水坑的面积。


## c++自定义find函数

`find_if(.begin,.end,()=>{compare})`

用迭代器的话就让人觉得是o(n)复杂度，如果有顺序的话，还得是手写二分查找

## 关于map

unordered_map的key通常不能是复杂结构，因为可能没有结构对应的哈希函数。所以如果用pair作为key，需要用map

### map的使用

```c++
// 插入pair | unordered_map不能插入pair
visit[this->mkPair(i,j)]=height[i]*(j-i-1)-solid;

// 边循环边删除。如果不这么删，会导致意料之外的情况
 for(auto kv=visit.begin();kv!=visit.end();)
{
    if(...)
    {
        cout<<"erase"<<endl;
        visit.erase(kv++); // 注意这里一定要删的时候++
    }
    else
    {
        ++kv;
    }
    
}

```

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
