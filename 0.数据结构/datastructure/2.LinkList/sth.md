# 测试代码

```
#include <iostream>
#include "LinkList/LinkList.h"


int main(void) {
    using std::cout;

    LinkList<int> ll;
    cout << "长度为：" << ll.Length() << '\n';
    cout << "链表为空：" << ll.IsEmpty() << '\n';
    cout << ll << '\n';

    cout << "--------\n";
    for (int i = 0; i < 10; i++) {
        ll.Insert(ll.Length() + 1, i);
    }
    cout << ll << '\n';

    cout << "----删除第一个元素---\n";
    ll.Delete(1);
    cout << ll << '\n';

    cout << "---删除最后一个元素----\n";
    ll.Delete(ll.Length());
    cout << ll << '\n';

    cout << "---获取第5个元素----\n";
    int a;
    ll.Get(5, a);
    cout << "第5个元素是：" << a << '\n';

    cout << "----修改第4个元素----\n";
    a = 999;
    ll.Set(4, a);
    cout << ll << '\n';

    cout << "----寻找值为999的元素的位置----\n";
    int b = 999;
    int i = ll.Find(b);
    cout << "索引是：" << i << '\n';

    cout << "----寻找一个不存在的值的位置----\n";
    b = 1000;
    i = ll.Find(b);
    cout << "索引是：" << i << '\n';

    // cout << "----清空链表----\n";
    // ll.Clear();
    // cout << ll << '\n';

    LinkList<int> ll3;
    {
        cout << "---测试复制构造函数---\n";
        LinkList<int> ll2 = ll;

        cout << ll2 << '\n';

        cout << "----测试赋值运算符----\n";
        ll3 = ll;
    }

    cout << ll3 << '\n';

    return 0;
}
```

# 我的实现与书上的不同

在我的插入操作和删除操作的实现中，由于增加了一个长度作为链表的信息，所以不用先尝试寻找第i个元素。而是先判断i的取值是否合理，合理的话再进行操作；

而书上的插入和删除结点前先尝试寻找第i个结点元素，如果能找到就进行操作，不能的话就返回错误。





























