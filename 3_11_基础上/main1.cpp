

#include <iostream>
using namespace std;

namespace  cotr_initializtion
{
class mytext
{
public:
    mytext():a(10),b(11)// variables have to be initialized
    {
        //assignment phase
       a=11;
       b=12;

    }

 private:
    int a;
    int b;
};
}
namespace my_inline
{/*内联函数与普通函数的区别出处c++primer 8.1内联函数*/
//	内联函数是不可递归的
  /*内联函数是非常有效率的，
    lambdas就是内联函数
    内联函数是一种请求
    我们可以把所有的函数都声明成内联函数但是编译器是否把他变为内联函数由编译器决定
    当我们用特别简短的函数时编译器可能自动把他优化成内联函数*/
}
namespace overliding
{
 /*类的构造器可以重载*/
 /*当类的构造函数时私有的我们可以这样
    我们可以在类里面声明一个静态函数，这个静态函数和
     类本身是无关的，我们可以通过静态函数来访问类的私有成员
     比如他的私有构造函数，然后我们可以在里面定义一个 静态的成员类
     然后把他的地址传出去，无论是传指针或者传引用均可以

     其次我们也可以用friend 因为我的只需要访问到他的私有构造函数即可
     因为没有构造函数的化无法初始化类也就是无法创建类

     */
/* class A {
    public:
    static A& getInstance();
    setup() { ... }
    private:
    A();
    A(const A& rhs);

};

A& A::getInstance()
{
    static A a;
    return a;
} */
}
namespace  fun_const
{
/*我们可以在类的成员函数后面加const 代表传入的this指针指向的值是不可以修改的
  因为是代表默认的传入参数this不可以修改故当非类函数，或者类的静态函数加const会报错*/
/*class complex
{
public:
    complex (double r = 0, double i = 0)
    : re (r), im (i)
    { }
    complex& operator += (const complex&);
    double real () const { return re; }
    double imag () const { return im; }

    private:
    double re, im;
}; */
}
namespace Const
{
//     规则：
// 1.常量成员函数不修改对象。
// 2.常量成员函数在定义和声明中都应加const限定
// 3.非常量成员函数不能被常量成员函数调用，但构造函数和析构函数除外。
// 4.常量（const对象）对象只能调用常量成员函数。（const对象的数据成员在对象寿命周期内不能改变，因此其只能调用常量成员函数）。
// 意义：
// 1.使成员函数的意义更加清楚，将成员函数分修改对象和不修改对象两类。
// 2.增加程序的健壮性，常量成员函数企图修改数据成员或调用非常量成员函数，编译器会指出错误。
// 原因：
//      对于X类型的非常量成员函数而言，其this指针的类型是 X * const，该指针自身是常量；但是对于X类型的常量成员函数而言，其this指针的类型是const X * const，是一个常量指针。
    class text1
    {
    public:
        void print(){cout<<"in const"<<endl;};
        void print()const{cout<<"in no const"<<endl;}
    };
    void fun_Const()
    {
         cout<<"/************************Const********************"<<endl;
       const text1 x_const;
       x_const.print();

       text1 x_noconst;
       x_noconst.print();
        cout<<"/********************************************"<<endl;
    }
}
namespace refernce_vs_passbyvalue
{
 /*值传递与引用传递，当然肯定是引用传递的要好，因为效率高*/
 /*当参数是数组时无法传引用，只能用指针*/
 int arr[10]{};
  void fun(int &a)
  {
 //  	   cout<<a
  }
}


int main()
{
    int * c=nullptr;


 return 0;
}
