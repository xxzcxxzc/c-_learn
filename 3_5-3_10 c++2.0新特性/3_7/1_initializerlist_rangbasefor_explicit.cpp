#include <iostream>

using namespace std;
class P
{
 public:
 	P(std::initializer_list<int>  initializerlist)
	 {
	 	 
    } 
    P(int a)//��explicit��ǰ��ʱ����ĳ�ʼ��ʱ���ɹ��� 
    {
	 
 	 }
 explicit	 P(const std::string& str)
 	 {
	 }
	 explicit P (int date,int date1,int date2)
	 {

	 }
};	
//for �����÷�

int main(int argc, char** argv) {//������3����һ���ġ� 


//1 
	for(const P &a:{10,11,12})
	{
	 cout<<"123"<<endl;
	}
	
	
	
//2 
/*	��������ͬ ����������벻ͨ����Ϊfor�÷����� 
	int del=0;
	initializer_list<int> col{10,11,12};
	for(auto *pos = col.begin(),auto *end = col.end();pos!=end;pos++)
	{	
	 del = *pos;
	 cout<<"123"<<endl;
	}*/
	
	
	
	
//3 
//���������ͬ 
	int del=0;
	initializer_list<int> col{10,11,12};
	for(auto *pos = col.begin();pos!=col.end();pos++)
	{	
	 del = *pos;
	 cout<<"123"<<endl;
	}
	
	
	return 0;
}
