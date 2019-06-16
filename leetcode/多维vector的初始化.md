# 1. 分别进行初始化
```
#include<vector>

using namespace std;

int main()
{
    vector<vector<bool>> vec;
    vec.resize(10);  //调整容器的长度大小，使其能容纳n个元素。
    //https://github.com/sysuleo/leetcode/blob/master/leetcode/vector中resize和reserve的区别.md
    for (int i = 0; i < vec.size(); i++) vec[i].resize(10);
    vec[0][0] = 0;
    return 0;
}
```
 
# 2. 采用构造函数
```
#include<vector>

using namespace std;

int main()
{
    vector<vector<bool>> col(9,vector<bool>(9,false));
    col[0][0] = true;
    return 0;
}
```

一维vector初始化：https://blog.csdn.net/yjunyu/article/details/77728410
