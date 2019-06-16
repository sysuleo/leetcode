#1. 分别进行初始化
```
#include<vector>

using namespace std;

int main()
{
    vector<vector<int>> vec;
    vec.resize(10);
    for (int i = 0; i < vec.size(); i++) vec[i].resize(10);
    vec[0][0] = 0;
    return 0;
}
```
 
#2. 采用构造函数
```
#include<vector>

using namespace std;

int main()
{
    vector<vector<bool>> col(9,(9, vector<bool>(false)));
    col[0][0] = true;
    return 0;
}
```
