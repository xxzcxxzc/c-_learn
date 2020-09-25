#include <iostream>
#include <vector>

using namespace std;
//2.0的特性************************************ 
typedef void(*fun)(int,int);
using p_fun = void(*)(int,int);

//alis template可以用在类内 
class _c
{
  template<class T>
  using container = std::vector<T,allocator<T>>;
};

//alis template不可以用在空间内。	  
void fun1()
{
// template<class T>
// using container = std::vector<T,allocator(T)>;
}

//1.0的特性************************************ 
using namespace std;
using std::cout;
//*******************************// 


int main()
{
 	return 0;
} 
