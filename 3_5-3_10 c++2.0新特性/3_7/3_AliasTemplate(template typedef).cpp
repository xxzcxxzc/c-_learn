#include <iostream>
#include <list>
#include <vector>
//using namespace std;
//1 ，using 2.0的新功能可以定义一个别名 （这个别名具有这个类型的全部性质）  
//因为用typedef与define都不可以实现 typedef只是一个特点的类型 而define更是啥也不是了 
template <typename T>
using class1 = std::initializer_list<T>;
class1<int> myint;


//当然这个using不只是为了省写几个字母或者定义一个别名
//想想一个问题如果我想操作操作，你传进来的参数的类型，注意：我不是要操作确定的参数类型 
//比如我想操作 一个传进来的容器的类型然后  然后用他传进来的类型和另一个组合
//比如 void text(Container ,T) {Container <T>}  我想这么操作 
//然后我就想到了如下操作因为模板可以自动推导  比如 text<>(list,10);这样就推到除了list和10的类型 
template<class Container,class T>
void text(Container cntr,T elem)
{
 //Container<T> c;
}
//显然这也是不可以的  因为template推到出来的 是一个特定的类型并不是一个 类型的本身，与typedef相似
 
//*************************************//

template<class Container,class T>
void text1(Container cntr,T elem)
{
 //typename Container<T> c;//这样还是不行 
} 


//这样就可以了 ， 但是我只能传一个参数 
//我还是想要2个参数的形式 
template <typename Container >
void text2(Container c)
{
 typedef typename std::iterator_traits<typename Container::iterator>::value_typen Alty;
}


template <class T,template <class,class> class Container>
void text3()
{
 
} 

int main(int argc, char** argv) {
	std::list<int> list_1;
// 	list_1::iterator;
 	text3<int , std::vector>();
// 	iterator
// 	iterator_traits
}
