#include <iostream>
using namespace std;clude <iostream>
#include<typeinfo>
#include <list>





namespace ConversionFunction
{
class myFraction
{
public:
    myFraction(int num,int den=1):m_numerator(num),m_denominator(den){}
//    template<class T>
//    operator T()const{
//        return (double) m_numerator/m_denominator;//这个东西怎么用
//    }
    operator double()const{
        return (double) m_numerator/m_denominator;
    }
    double operator+(int c){return (double)c+m_numerator;}
private:
    int m_numerator;
    int m_denominator;
};
void fun_ConversionFunction()
{
    myFraction f(3,5);
    double d=4+f;
    std::cout<<d<<std::endl;
    std::cout<<typeid (d).name()<<std::endl;
}
}
namespace NonExplicitOneArgumentCtor
{
 class myFraction1
 {
 public:
     myFraction1(int num,int den=1):m_numerator(num),m_denominator(den){}
     myFraction1 operator+(const myFraction1&f)
     {return myFraction1(f);}
 private:
     int m_numerator;
     int m_denominator;
 };
 class myFraction2
 {
 public:
     myFraction2(int num,int den=1):m_numerator(num),m_denominator(den){}
     operator double()const
     {return (double)m_numerator/m_denominator;}
     myFraction2 operator+(const myFraction2&f)
     {return myFraction2(f);}
 private:
     int m_numerator;
     int m_denominator;
 };
 class myFraction3
 {
 public:
     explicit myFraction3(int num,int den=1):m_numerator(num),m_denominator(den){}
     operator double()const
     {return (double)m_numerator/m_denominator;}
     myFraction3 operator+(const myFraction3&f)
     {return myFraction3(f);}
 private:
     int m_numerator;
     int m_denominator;
 };
 void fun_NonExplicitOneArgumentCtor()
 {
     myFraction1 f1(3,5);
     myFraction1 d1=f1+4;

     myFraction2 f2(3,5);
  //   myFraction2 d2=f2+4;//此时就会报错 因为有2条路径这个语句都可以走的通
     myFraction3 f3(3,5);
     double d3=f3+4; //在3加个explict 不可以隐式转化 ，有一条路径就被禁止了
 }
}
namespace classLikePointer //智能指针
{
template <class T>
class shared_ptr
{
public:
    T& operator*() const
    {return *px;}

    T* operator->() const//因为这个符号比较特别
    {return px;}
    shared_ptr(T* p):px(p){}
private:
    T * px;
    long *pn;
};
struct foo
{
    void method(void){}
};

void fun_classLikePointer()
{
    shared_ptr<foo> sp(new foo);
    (*sp).method();
    sp->method();//如果你觉得它奇怪，因为->在这次操作中就被消耗掉了呀为什么太还可以继续作用，因为-》这个符号特别当它作用完之后还可以继续作用
}
}
namespace classLikeFuncion
{

template <class T1 ,class T2>
struct text
{public:
    typedef T1 first_type;
    typedef T2 second_type;
    T1 first;
    T2 second;

    text():first(T1()),second(T2()){}
    text(const T1& a,const T2& b):first(a),second(b){}

    template<class u1,class u2>
    text(const pair<u1,u2> &p):first(p.first),second(p.second){cout<<"in member template"<<endl;}

};

template<class T>
struct identity
{public:
    const T& operator()(const T&x)const {return x;}
};
template <class Pair>
struct select1s1t{
public:
    const typename Pair::first_type& operator()(const Pair &x)
    {return x.first;}
};

template <class Pair>
struct select2nd{
    public:
    const typename Pair::second_type& operator()(const Pair &x)const
    {return x.second;}
};

void fun_classLikeFuncion()
{
    classLikeFuncion::text<int ,double> teadsd;
    classLikeFuncion::select1s1t<classLikeFuncion::text<int,double>>()(teadsd);
}
}


namespace functionTemplateOverloading
{
 //如下函数模板也可以重载
 template<typename T>
 void fun(T a, T b){}
 template<typename T>
 void fun(T *a, T *b){}
 template<typename T>
 void fun(T *a, T *b,int c){}
}
namespace templateBoundedness_andSolution
{
//出处c++primer 8.5.2模板的局限性
/*很多情况下类模板时无法处理一些类型的
 比如你穿了一个数组或者结构和类进去然后你进行了a=1的操作但是显然这是错误的
 template <class t>
void fun(t a)
{
         a=1;
}
fun<int *>(c);
解决这种问题的方法有
重载运算符， 以便你的类和结构能处理特定的类型
 另一个解决办法就是j具体化模板的定义
 当用具体化模板时，有个优先级，即非模板原型 > 显式具体化模板 > 普通模板原型，
 //下面那个就是模板的显式具体化
        下面的那个注意下面的那个的参数个数与返回值必须与上面的那个未具体化模板的一致
        因为他只是具体化的类型
        所以改变的只是他的类型
        并且第三个的那个尖括号省略的原因是编译器可以根据参数推出模板的类型
        所以这个时候编译没报错是因为他具体化的第二个因为他只能推出来第二个的模板
        如何你将第二个注释掉他会报错，因为他不知道第一个的那个f是什么他无法推出来
 */
template <class T,class f>
void fun(T a){cout<<"2"<<endl;}

template <class T>
void fun(T a){}

template <> void fun<>(int a){cout<<"具体化"<<endl;}
}
namespace templateExternalize_and_instantiate
{
/*编译器在遇到模板函数的时候并不会生成函数的定义
因为他并不知道这个函数的具体的类型，但是在你调用它的时候它就会默认生成一个函数的定义
还可以显示具体化
函数模板并不能缩短可执行程序，最终的代码不包括任何的模板，而只包含为程序而生的实际函数，使用模板的好处是使它们的生成更简单，更泛化---出自cpp primer 8.5.1上边带点
与普通函数相似，函数模板只是一个一堆函数可以用使用这个，但是如果你需要的不满足你可以继续对他进行重载，需要注意的是重载的特征值必须不同
除了重载当你的模板并不是参数不够，需要更改参数的类型
还有就可能是你的当某个参数时你这个模板的程序不是你想要的，这个时候你就可以显式具体化，写出你想要的类型的函数。
当然如果你要显示具体化的化必须跟你要具体化的模样是一样的而且template<>这里面不写，其他的只要能编译器推出了就可以*/

template<class T,class C>
class text
{
public:
    int a=10;
    double b{};
    void fun1();
};

template <>
void text<char,int>::fun1(){}


template<class T>
class text<T,int>
{
public:
    int a=10;
    double b{};
    void fun();
};
template <>
void text<int,int>::fun(){}
template <>
void text<double,int>::fun(){}

}


namespace membertemplate
{

    template <class T1 ,class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;
        T1 first;
        T2 second;

        pair(pair &) =delete ;

        pair():first(T1()),second(T2()){}
        pair(const T1& a,const T2& b):first(a),second(b){}

        template<class u1,class u2>
        pair(const pair<u1,u2> &p):first(p.first),second(p.second){cout<<"in member template"<<endl;}

    };

    class base1{};
    class Derived1:public base1{};
    class base2{};
    class Derived2:public base2{};

    void fun_membertemplate()
    {
        pair<Derived1,Derived2>p1;
        pair<base1,base2> p2(p1);
        pair<base1,base2> p(pair<Derived1,Derived2> par);//这个调用的是什么构造函数

    }
}
namespace SpecializationTemplate
{
    template<class key>
    class hash{};

    template<>
    class hash<int>{
        size_t operator()(char x)const{return x;}
    };
}
namespace PartialSpecialization//偏特化局部特化
{
/*个数上的偏*///注意绑定的时候要从左到右，不许跳。
template <typename T,typename Alloc>
class vector{};

template <typename Alloc>
class vector<bool,Alloc>{};
/************/
/*范围上的偏*/
template<class T>
class C{};
template<class T>//这个就是说如果你T是一个指针就用如下的代码
class C<T*>{};
}
namespace TemplateTemplateParameter
{
template <class T>
using lst = std::list<T,allocator<T>>;

template<typename T,template<typename C>class Container>
class myXCLs
{
public:
    Container<T> c;
};

void fun_TemplateTemplateParameter()
{
    myXCLs<int,lst> text;
}

}
namespace Reference
{
typedef  struct{int a,b,c,d;} mystructReference;

//不调用是可以的通过的，因为并没有什么语法错误，而且它确实也不完全一样
//但是一旦调用就会出错 因为它分不清调用哪个它会说 myimag is ambiguious 这个函数是含糊不清的
double myimag(const double im){return im;}
double myimag(const double& im){return im;}


void fun_Reference()
{
 mystructReference x;
 mystructReference &r = x;
 std::cout<<"reference_sizeof:"<<sizeof(r)<<std::endl;
 std::cout<<"reference_address"<<&r<<std::endl;

 std::cout<<"paramemer_sizeof:"<<sizeof(x)<<std::endl;
 std::cout<<"paramemer_address"<<&x<<std::endl;

 double text{};
// myimag(text);
}

}





int main()
{
    membertemplate::fun_membertemplate();
    classLikeFuncion::fun_classLikeFuncion();

  ConversionFunction::fun_ConversionFunction();
  TemplateTemplateParameter::fun_TemplateTemplateParameter();
  return 0;

}




