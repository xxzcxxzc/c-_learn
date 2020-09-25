#include <iostream>
#include <typeinfo>
using namespace std;
//为什么这样不可以类的构造函数不是可以直接用构造函数调用吗
//或者用lambdas表达式也不可以 
//只是真正的函数的时候可以 
 
//class coutX
//{
// public:
// 	coutX()
// 	{
//	 cout<<"完成"<<endl;
//	 }
//};

//auto cout=[](void){} ;

void coutX()
 	{
	 cout<<"完成"<<endl;
	 }

template <typename T,typename... Arg>
void coutX(const T& ParOut,const Arg&...ParOutNext)
{
//	cout<<sizeof...(ParOutNext)<<endl;
 	 cout<<ParOut<<endl;
 	 coutX(ParOutNext...);
}


int main()
{
  
	coutX(12,"123",10.2);
 return 0;
} 
