#include <iostream>
#include <vector>

using namespace std;
//2.0������************************************ 
typedef void(*fun)(int,int);
using p_fun = void(*)(int,int);

//alis template������������ 
class _c
{
  template<class T>
  using container = std::vector<T,allocator<T>>;
};

//alis template���������ڿռ��ڡ�	  
void fun1()
{
// template<class T>
// using container = std::vector<T,allocator(T)>;
}

//1.0������************************************ 
using namespace std;
using std::cout;
//*******************************// 


int main()
{
 	return 0;
} 
