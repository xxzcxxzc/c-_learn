#include<iostream>
#include <vector>
#include <typeinfo>
using namespace std;
class t
{
 public:
 	t(int a)
 	{
	 	  std::cout<<a<<std::endl;
	 }
};
	
	
	
int main()
{
	cout<<typeid([](){return int(0);}).name()<<endl;
	cout<<typeid(t(10)).name()<<endl;
 	return 0;
} 
