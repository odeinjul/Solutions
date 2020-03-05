#include <iostream>
using namespace std; //头文件和命名空间
bool IsUglyNum(long long iNum){ //判断是不是丑数
    while (iNum >= 2){ //逐层除以2，3，5
        if (iNum % 2 == 0)
            iNum /= 2;
        else if (iNum % 3 == 0) 
            iNum /= 3;
        else if (iNum % 5 == 0) 
            iNum /= 5;
        else //如果这个数大于等于2，但是2，3，5不是其因子
            return false; //肯定不是
    }
    return iNum == 1; //判断最后是不是1，如果是拿这个数就是丑数
}
int main(){
    ios::sync_with_stdio(false); //输入输出加速
    long long iNum=2, nCount = 1; //枚举的数字和已经得到的丑数的个数
    while (1){
        if (IsUglyNum(iNum)){ //如果是丑数
            ++nCount; //个数加一
        }
        if (nCount == 1500){ //如果找到第1500个丑数了
            cout << iNum << endl; //输出
            break; //跳出循环
        }
        ++iNum; //继续枚举
    }
    return 0; //结束
}