#include <iostream>
#include <list>
#include <vector>
//using namespace std;
//1 ��using 2.0���¹��ܿ��Զ���һ������ �������������������͵�ȫ�����ʣ�  
//��Ϊ��typedef��define��������ʵ�� typedefֻ��һ���ص������ ��define����ɶҲ������ 
template <typename T>
using class1 = std::initializer_list<T>;
class1<int> myint;


//��Ȼ���using��ֻ��Ϊ��ʡд������ĸ���߶���һ������
//����һ�����������������������㴫�����Ĳ��������ͣ�ע�⣺�Ҳ���Ҫ����ȷ���Ĳ������� 
//����������� һ��������������������Ȼ��  Ȼ�����������������ͺ���һ�����
//���� void text(Container ,T) {Container <T>}  ������ô���� 
//Ȼ���Ҿ��뵽�����²�����Ϊģ������Զ��Ƶ�  ���� text<>(list,10);�������Ƶ�����list��10������ 
template<class Container,class T>
void text(Container cntr,T elem)
{
 //Container<T> c;
}
//��Ȼ��Ҳ�ǲ����Ե�  ��Ϊtemplate�Ƶ������� ��һ���ض������Ͳ�����һ�� ���͵ı�����typedef����
 
//*************************************//

template<class Container,class T>
void text1(Container cntr,T elem)
{
 //typename Container<T> c;//�������ǲ��� 
} 


//�����Ϳ����� �� ������ֻ�ܴ�һ������ 
//�һ�����Ҫ2����������ʽ 
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
