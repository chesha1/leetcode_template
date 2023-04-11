# leetcode_template
leetcode template for C++, with implementation of basic data structure and print function  
leetcode C++ 模板，包括对于常见数据结构的实现和打印函数

## 具体内容
### 打印
STL，基本数据类型，链表  
键值对 map<string,int> 和 map<int,int>  
变量的类型
### 容器
根据vector<int>创建链表并返回头节点地址  

根据vector<vector&lt;int&gt;>创建二叉树并返回头节点地址  
如果值的内容为-1，表示不存在该节点  
举例：
```cpp
vector<vector<int>> nums = {{1},
                            {2, -1}};
TreeNode *root = createTree(nums);
```

