#include <iostream>
#include <vector>

using namespace std;

//default 只可以用在big five，其他时候无任何意义编译会报错 
/* P(const P&) = default;
   P(P&&) = delete
   P& operator= (const P&)
   P& operator= (P&&)
   P() = default*/
   
//析构函数不会报错   virtual ~P()  =  default但是他没有意义 
 //析构函数不可以删除，删除后会报错   
class P
{
	private:
	int d1,d2;
 public:
 	P(int t1,int t2):d1(t1),d2(t2){}
 	P(int t1):d1(t1){}
 	P() = default;
 	//这个是拷贝构造函数 在定义时可以用  P b=a; 和 P b(a) 这个函数可以默认生成 
	P(const P&) = default;
	P(P&&) = default;//这是c++2.0新出的东西 
	P& operator= (const P&) = delete;
	P& operator= (P&&) = default;//这是c++2.0新出的东西 
	virtual ~P()=default; 
	
//	void fun()=default 这个会报错一般的函数又没有什么默认的版本
	void fun()=delete ; //这个很奇怪，因为你不想要这个函数就不要写不就可以了，为什么还要delete 但是语法时允许的
//	void fun()=0; 这个跟delete很像但是没有关系这个用于纯虚函数 
};

//这个空类当被c++处理过后就会加入默认的构造函数和析构函数
//但是这个没有意义的因为他是个空的
//之所以会这样是给空类继承与父类后调用父类的构造函数时可以用这个默认构造函数。	 
class Empty
{
 
}; 
int main(int argc, char** argv) {
	std::cout << "Hello world!\n";
	int int_my(10);
	P a={1,1};
	P b=a;
	//b=a;
	
	P text_1 ={10,10} ;//这样是直接调用构造函数，没用先调用构造函数在调用赋值构造函数
	 text_1 = {10,10}; //这样是调用构造函数在调用赋值函数。 
}
