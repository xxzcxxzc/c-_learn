#include <iostream>
using namespace std;


class P
{
	int a;
public:
	   P(initializer_list<int> initlist) {
	   	
	   }
	  explicit P(int a,int b)
	   {
	   	
	   }

} 	;
template<class date>
class mytextclass
{
private:
	/* data */
	int mydata;
	mytextclass(date* a,data len):mydata(len) {}
public:
	mytextclass(/* args */);
	~mytextclass();
};
template<class date>
mytextclass<date>::mytextclass(/* args */)
{
}
template<class date>
mytextclass<date>::~mytextclass()
{
}

int main(int argc, char** argv) {
	// int a_par_int{};
	// for(const  P  temxt:{10,1022})
	// {
	//  cout<<a_par_int++<<a_aut<<endl;
	//   }
	// fun();
	// P  A{10,10};
	// fun();
	// P  B(10,10);
	// fun();
	// return 0;
	mytextclass<int> mytext = {10,1,1};
	P myinitlist({10,11,12,13,14,15});
	int * p =nullptr;
	int len = 10;
	initializer_list<int> data={10,1,1};  
}
