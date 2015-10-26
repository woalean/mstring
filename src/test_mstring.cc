
#include "mstring.h"

namespace mlib {

class MstringTest {
    public:
        MstringTest() { }
        ~MstringTest() { }

        void CopyTest() {
            MString str("hello string copy!");
            MString str_test(str); 
            std::cout<<"copy test:"<<str_test<<std::endl;            
        }
        void operatorTest() {
        	MString str("you are my world");
        	MString str1("yes, it is");
			std::cout<<"str = "<<str<<"|"<<"str1 = "<<str1<<std::endl;
			MString str2;
			str2 = str + str1;
			std::cout<<"str add = "<<str2<<std::endl;
		}
        void AssignmentTest() {
            MString str("hello string Assignment!");
            MString str1("hello string Assignment #2!");
            MString str_test = str;
            str_test = str1;
            //str_test = str;
            std::cout<<"assignment test:"<<str_test<<std::endl;
        }
        void FindTest() {
            MString str("where is we find , steel? strong? choice one");
			const char* s = "str";
			size_t pos = str.find(s);
			size_t len = str.length();
			std::cout<<"str length is :"<<len<<std::endl;
			std::cout<<"str pos is :"<<pos<<std::endl;
            MString pst("str");
            std::cout<<"mstring str pos is :"<<str.find(pst)<<std::endl;
        }
};

}

int main()
{
    mlib::MstringTest test;
    test.CopyTest();
    test.operatorTest();
    test.AssignmentTest();
	test.FindTest();
    return 0;
}
