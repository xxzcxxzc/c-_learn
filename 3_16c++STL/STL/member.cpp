#include<iostream>


using namespace std;


namespace NewAndOpratorNew
{
    class xx1
    {
    public:
        xx1(){cout<<"xx cotr"<<endl;}
        void fun(){}
    };
    void fun()
    {

        void * p = :: operator new(sizeof (xx1));//没有调用构造函数
        xx1 *myp = static_cast<xx1*>(p);
      //  myp->xx1();
       myp->~xx1();
        xx1 *myp1 = new xx1();//显示调用构造函数

        new(myp1)xx1();//显示指针调用构造函数
    }
}
namespace NewArray
{
class x1
{
public:
    int par;
    x1():par(0){cout<<this<<"   "<<par<<endl;};
    x1(int i):par(i){cout<<"in ctor"<<endl;}
    ~x1(){cout<<this<<"   "<<par<<endl;}
};

void fun()
{
   x1 *p = new x1[3];

   cout<<*(int*)(p-1)<<endl;//这个是内存上面的记录分配了多少个对象
   for(int i=0;i<3;i++)
   new(p+i)x1(100+i);

   delete []p;//用他调用3此析构函数

  //  delete p;//用它调用1次析构函数 为什么释放完内存后 里面的内容会改变 我当时看完生前死后记得现在忘了


}
}
namespace  PlacementNew
{

}

class t{int a;char b;char c;};
class t1{char a;char b;double c;};
int main()
{
    NewAndOpratorNew::fun();
    NewArray::fun();
    cout<<sizeof (t)<<sizeof (t1)<<endl;
    return  0 ;
}
