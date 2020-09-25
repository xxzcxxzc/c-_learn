#include <iostream>

using namespace std;
class P
{
 public:
 	P(std::initializer_list<int>  initializerlist)
	 {
	 	 
    } 
    P(int a)//当explicit在前面时下面的初始化时不成功的 
    {
	 
 	 }
 explicit	 P(const std::string& str)
 	 {
	 }
	 explicit P (int date,int date1,int date2)
	 {

	 }
};	
//for 的新用法

int main(int argc, char** argv) {//下面这3段是一样的。 


//1 
	for(const P &a:{10,11,12})
	{
	 cout<<"123"<<endl;
	}
	
	
	
//2 
/*	与上面相同 但是这个编译不通过因为for用法不对 
	int del=0;
	initializer_list<int> col{10,11,12};
	for(auto *pos = col.begin(),auto *end = col.end();pos!=end;pos++)
	{	
	 del = *pos;
	 cout<<"123"<<endl;
	}*/
	
	
	
	
//3 
//与上面的相同 
	int del=0;
	initializer_list<int> col{10,11,12};
	for(auto *pos = col.begin();pos!=col.end();pos++)
	{	
	 del = *pos;
	 cout<<"123"<<endl;
	}
	
	
	return 0;
}
