#include <thread>
#include <iostream>
#include <memory>
using namespace std;

struct AStruct {
	int number = 888;
	std::string string_name = "";
};

class TestClass {
 public:
	// AStruct* a_struct_test_;
	std::shared_ptr<AStruct> a_struct_ptr;
	int test_number_;
};

void test() {
	// AStruct a;
	TestClass tester;
	// tester.a_struct_test_ = &a;
	// cout<<tester.a_struct_test_->number<<endl;

	tester.a_struct_ptr = make_shared<AStruct> (AStruct{111,"hello"});
	std::cout<< tester.a_struct_ptr.use_count() <<std::endl;
	cout<<tester.a_struct_ptr->number<<endl;
}

int main() {
	test();
	return 0;
}
