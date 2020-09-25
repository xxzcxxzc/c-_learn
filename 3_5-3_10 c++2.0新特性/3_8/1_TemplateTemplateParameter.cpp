#include<iostream>
#include <vector>
//继续上一个 
using namespace std;

template <class T,template<class,class> class Container>
class class1
{
// 	  Container<T,T> c; 
};

template <class T,template<class,class> class Container>
void fun1()
{	
//	Container<T,a> c;
};


template <typename T>
using vec = vector<T,allocator<T>>;

template <typename T , template<typename > class Container>
void fun2()
{
 
}


int main()
{
 class1<int,vector> a;
 fun1<int , vector>();
}





