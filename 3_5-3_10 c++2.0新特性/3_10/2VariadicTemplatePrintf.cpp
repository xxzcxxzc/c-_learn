#include <iostream> 

void printx(const char *s)
{
 std::cout<<"more error"<<std::endl;
}
template <typename... Arg>
void printx(const Arg... Par)
{
 std::cout<<"less error"<<std::endl;
}

template <typename T,typename... Arg>
void printx(const char* s,const T& par1,const Arg... parNext)
{
 if(*s=='%'&&*++s!='%')
  std::cout<<par1<<std::endl;
  
  std::cout<<"sizeof"<<sizeof...(Arg)<<std::endl; 
  
 printx(++s,parNext...);
}


int main()
{
printx("%d,%s%d",1,2,3);
return 0;
}
