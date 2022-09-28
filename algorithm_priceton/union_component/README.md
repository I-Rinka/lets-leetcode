# Ilustartion

The union component in Chinese is called 并查集. In this section, we will learn how to dynamically add and find whether two node belongs to a same union component.

## Quick-find: eager algorithm (贪心)

    1. make the value of each component in the array equals its index
    2. In union operation, make operated component have the same value. **It is a recursive operation**
    3. Find Operation: check if two components has the same number

Initialize is O(N), Union Op is O(N), Find is O(1). Union is slow when union N objects (O(N^2)).

## Quick-union

Avoid doing work until we have to.

    1. make union operation as connecting a forest
    2. Find Operation: Check if two components have the same root
    3. Union Operation: Override the value of each component. Make the component's root index as the value.

In the worst situation, Find is O(n), but the Union is much faster.

## Improvement

Using Quick-union algorithm. But balance the three after merging. Put the smaller tree lower.

Union and Find is O(logN) since the depth of the tree is log(n). 

## Improvement2: Path compression

Make every forest node to the root (grand parent). N+Mlog*(N). log*(N) is iterated logarithm, increases very slowly (usually less than 5), so the complexity is basically O(n).

---

The result should be:

```shell

cat ./test.txt | ./a.out

--
connected 4 3
connected 3 8
connected 6 5
connected 9 4
connected 2 1
8 9 are connected
connected 5 0
connected 7 2
connected 6 1
1 0 are connected
6 7 are connected

```
