#include <iostream>
#include <typeinfo>
using namespace std;
//Ϊʲô������������Ĺ��캯�����ǿ���ֱ���ù��캯��������
//������lambdas���ʽҲ������ 
//ֻ�������ĺ�����ʱ����� 
 
//class coutX
//{
// public:
// 	coutX()
// 	{
//	 cout<<"���"<<endl;
//	 }
//};

//auto cout=[](void){} ;

void coutX()
 	{
	 cout<<"���"<<endl;
	 }

template <typename T,typename... Arg>
void coutX(const T& ParOut,const Arg&...ParOutNext)
{
//	cout<<sizeof...(ParOutNext)<<endl;
 	 cout<<ParOut<<endl;
 	 coutX(ParOutNext...);
}


int main()
{
  
	coutX(12,"123",10.2);
 return 0;
} 
