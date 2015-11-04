
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
        void SubStrTest() {
			MString str("Life was like a box of chocolates, you never know what you're going to get.");
			MString result = str.substr(0,20);
			MString result1 = str.substr(1);
			MString result2 = str.substr(0,20);
			MString result3 = str.substr(24,20);
			std::cout<<"string result : "<<result<<std::endl;
			std::cout<<"string result1 : "<<result1<<std::endl;
			std::cout<<"string result2 : "<<result2<<std::endl;
			std::cout<<"string result3 : "<<result3<<std::endl;
		}
};

}
