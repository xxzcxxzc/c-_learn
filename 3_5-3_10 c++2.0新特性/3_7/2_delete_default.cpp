#include <iostream>
#include <vector>

using namespace std;

//default ֻ��������big five������ʱ�����κ��������ᱨ�� 
/* P(const P&) = default;
   P(P&&) = delete
   P& operator= (const P&)
   P& operator= (P&&)
   P() = default*/
   
//�����������ᱨ��   virtual ~P()  =  default������û������ 
 //��������������ɾ����ɾ����ᱨ��   
class P
{
	private:
	int d1,d2;
 public:
 	P(int t1,int t2):d1(t1),d2(t2){}
 	P(int t1):d1(t1){}
 	P() = default;
 	//����ǿ������캯�� �ڶ���ʱ������  P b=a; �� P b(a) �����������Ĭ������ 
	P(const P&) = default;
	P(P&&) = default;//����c++2.0�³��Ķ��� 
	P& operator= (const P&) = delete;
	P& operator= (P&&) = default;//����c++2.0�³��Ķ��� 
	virtual ~P()=default; 
	
//	void fun()=default ����ᱨ��һ��ĺ�����û��ʲôĬ�ϵİ汾
	void fun()=delete ; //�������֣���Ϊ�㲻��Ҫ��������Ͳ�Ҫд���Ϳ����ˣ�Ϊʲô��Ҫdelete �����﷨ʱ�����
//	void fun()=0; �����delete������û�й�ϵ������ڴ��麯�� 
};

//������൱��c++�������ͻ����Ĭ�ϵĹ��캯������������
//�������û���������Ϊ���Ǹ��յ�
//֮���Ի������Ǹ�����̳��븸�����ø���Ĺ��캯��ʱ���������Ĭ�Ϲ��캯����	 
class Empty
{
 
}; 
int main(int argc, char** argv) {
	std::cout << "Hello world!\n";
	int int_my(10);
	P a={1,1};
	P b=a;
	//b=a;
	
	P text_1 ={10,10} ;//������ֱ�ӵ��ù��캯����û���ȵ��ù��캯���ڵ��ø�ֵ���캯��
	 text_1 = {10,10}; //�����ǵ��ù��캯���ڵ��ø�ֵ������ 
}
