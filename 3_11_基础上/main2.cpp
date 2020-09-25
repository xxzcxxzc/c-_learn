#include <iostream>

using namespace std;


namespace composition
{
//构造函数调用得顺序和析构函数调用得顺序
    class base//sizeof = 12
    {public:
        int a;
        int b;
        int c;
        base(int a){}
        ~base(){}
    };
    class furture//sizeof 12*2
    {
    public:
        base text;//这就是复合得概念 has-a
         base text1;
         furture():text(10),text1(11){}//构造函数在初始化列表，先把里面得构造了在构造自己得
         ~furture()
         {
            // ~text();~text1()析构函数在里面 先把自己得析构了在析构包含得
         }

    };
    void fun_composition()
    {
        furture a;
    }
}
namespace Delegation//composition by reference
{
    class base//sizeof = 12
    {
      public:
            int a;
            int b;
            int c;
            base(int a){}
            ~base(){}
    };
    class furture//sizeof 12*2
    {
        public:

         furture(){}//构造函数在初始化列表，先把里面得构造了在构造自己得
         void fun_composition()
         {
             furture a;
         }
        private:
          base* text;//pimpl 指针实现，指针指向得是实现这个只是个接口
                      //还可以共享 比如现在有3个这样得类可以指向同一个base类但是如果一个想修改base 那么就拷贝给它一个副本让他区修改
    };

}
namespace Inherritence//is a
{
    template <class T ,class C>
    class mylist_base
    {

    };
    template <class T ,class C>
    class mylist:public mylist_base<int,double>
    {

    };
}
namespace InherritenceWithViretualFunction
{
//虚函数一种大名顶顶得设计模式 template method
//application framework 应用程序框架

    class myCDocument
    {
    public:
        void OnFileOpen()
        {
            cout<<"\n\ndialog..."<<endl;
            cout<<"check file status..."<<endl;
            cout<<"open file"<<endl;
            Seralize();
            cout<<"close file"<<endl;
            cout<<"update all views\n\n"<<endl;

        }
        virtual void Seralize(){};
        virtual ~myCDocument(){}

        myCDocument(){cout<<"in inherritence"<<endl;}
    };

    class Cmydoc:public myCDocument
    {
    public:
           virtual void Seralize(){cout <<"OKOK enter Seralize"<<endl;}
        Cmydoc():myCDocument()
        {}
    };

    void fun_InherritenceWithViretualFunction()
    {
            Cmydoc mydoc;
           mydoc.OnFileOpen();//大家可以认为是 在OnFileOpen得第一个参数传进得是一个mydoc的this指针
    }
}
namespace compositionAndInherritence
{
    class mycomposition
    {
    public:
        mycomposition(){cout<<"in composition"<<endl;}
    };
    class myinherritence
    {
    public:
        myinherritence(){cout<<"in inherritence"<<endl;}
    };

    class  parent:public myinherritence
    {
    public:
        mycomposition x;
        parent():x(),myinherritence()//注意这句的警告就是我们所测试的
        {}
    };
    void fun_compositionAndInherritence()
    {
        cout<<"/************************compositionAndInherritence********************"<<endl;

        parent x;
        cout<<"/************************************************************"<<endl;
    }
}
namespace DelegationAndInherritence
{
    class myObserver
    {
    public:
        myObserver(){cout<<"in delegation"<<endl;}
        virtual void update()=0;
    };

    class base1:public myObserver
    {
    public:
        virtual void update(){cout<<"base1 updated~!"<<endl;}
    };

    class base2:public myObserver
    {
    public:
        virtual void update(){cout<<"base2 updated~!"<<endl;}
    };

    class parent
    {
    public:
        myObserver* p;

        void parent_update()
        {
            p->update();
        }
    };



    void fun_compositionAndInherritence()
    {
        cout<<"/************************compositionAndInherritence********************"<<endl;
        base1 x_base1;
        base2 x_base2;
        parent x;
        x.p = &x_base1;
        x.parent_update();

        x.p = &x_base2;
        x.parent_update();
        cout<<"/*******************************************************************"<<endl;
    }
}
namespace ObjectModelVptrVtal
{

    class A
    {
    public:
        int a=10;
        virtual void fun(){cout<<"in A fun"<<endl;}
        virtual void fun1(){cout<<"in A fun1"<<endl;}
    };

    class B:public A
    {
    public:
        int b=10;
        virtual void fun(){cout<<"in B fun"<<endl;}
    };

    class C:public A
    {
    public:
        int c=10;
        virtual void fun(){cout<<"in C fun"<<endl;}
    };

    void fun_ObjectModelVptrVtal()
    {

         cout<<"/************************ObjectModelVptrVtal********************"<<endl;
         B *p_b=new B;
         C *p_c = new C;

         int *v_Bptr = *(int**)p_b;
         int *v_Cptr = *(int**)p_c;

        A * p_text = new A;
        int * p= (int *)*(int*)(p_text);
        void(*p_fun)(void) = (void(*)()) (*p);
        p_fun();
        intptr_t new_vtal[] = {
           v_Bptr[0],
           v_Cptr[0]
        } ;
        *(int**)p_text=new_vtal;
        p_text->fun();
        p_text->fun1();
         cout<<"/**************************************************"<<endl;

    }
}
namespace myNewAndDelete
{
    class Foo
    {
    public:
        int id;
        Foo():id{}{}
        Foo(int i):id(i){}

        ~Foo(){cout<<"this id "<<id<<endl;}
        static void* operator new(size_t size)
        {
            cout<<"in my new"<<endl;
            Foo*p = (Foo*)malloc(size);
            return p;
        }
        static void* operator new[](size_t size)
        {
            cout<<"in my new[]"<<endl;
            Foo *p = (Foo*)malloc(size);
            return p;
        }

        static void operator delete(void * pdead ,size_t size)
        {
             cout<<"in my delete"<<endl;
            free(pdead);
        }
        static void operator delete[](void *pdead,size_t size)
        {
            cout<<"in my delete[]"<<endl;
            free(pdead);
        }
    };
    void my_myNewAndDelete()
    {
        //Foo *a =(Foo *) Foo::operator new(sizeof (Foo));
        cout<<"/************************myNewAndDelete********************"<<endl;

         Foo *a =new Foo;
         cout<<sizeof (a)<<endl;
        delete a;
         Foo * parray = new Foo[7];
         cout<<*(int*)parray<<endl;
         delete [] parray;
         cout<<"/*****************************************************"<<endl;
    }
}


int main(){

InherritenceWithViretualFunction::fun_InherritenceWithViretualFunction();
compositionAndInherritence::fun_compositionAndInherritence();
DelegationAndInherritence::fun_compositionAndInherritence();
ObjectModelVptrVtal::fun_ObjectModelVptrVtal();
// Const::fun_Const();
myNewAndDelete::my_myNewAndDelete();

return 0;
}
