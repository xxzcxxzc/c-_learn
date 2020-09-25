#include <iostream>
#include <typeinfo>
template <typename T1,typename T2>
auto add(T1 x,T2 y)->decltype(x+y) 
{
 
}
int main()
{auto a=add<double,double> (1.0,1.0);

std::cout<< "123"<<typeid(a).name()<<std::endl;
} 
