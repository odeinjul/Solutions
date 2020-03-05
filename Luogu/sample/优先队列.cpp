有很多种实现优先队列的方式，最常见的就是堆。
最常见的堆就是二叉堆，C++中priority_queue定义了一个以权值为优先级的堆。
#include<queue>
priority_queue<数据类型> q;
这样就声明了一个优先队列。
优先队列初始默认是权值大优先级高。
声明成权值小优先级高：
priority_queue<int,vector<int>,greater<int> > q;