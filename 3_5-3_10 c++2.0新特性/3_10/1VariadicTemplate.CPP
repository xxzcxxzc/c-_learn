#include <iostream>
#include <typeinfo>
using namespace std;

 
class coutX
{
 public:
 	coutX()
 	{
	 cout<<"完成"<<endl;
	 }
};

void coutX()//最后是空的时候调用它因为它特化 
{ cout<<"void "<<endl;}

void coutX(int a)//当最后一个参数是int时调用它因为它比较特化 
{ cout<<"int "<<endl;}
template <typename T,typename... Arg>
void coutX(const T& ParOut,const Arg&...ParOutNext)
{
	cout<<sizeof...(ParOutNext)<<endl;
 	 cout<<ParOut<<endl;
 	 coutX(ParOutNext...);
}
template <typename... Arg>//永远不会被调用因为上面的比它更特化 
void coutX(const Arg&...ParOutNext)
{
 cout << "any parameter "<<endl;
} 

int main()
{

	coutX(12,"123",10.2);
 return 0;
} 
