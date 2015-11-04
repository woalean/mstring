
#include "arena.h"
#include <string.h>

namespace mlib {

static const int kBigSize = 3366;

struct MetaTest {
	char flag;
	int num;
	int index;
	char list[10];
};

class ArenaTest {
public:
	void StructTest() {
		result = arena_.Allocate(sizeof(MetaTest));
		struct MetaTest* ptr = static_cast<MetaTest*>((void*)result.ptr);
		ptr->flag = 'Y';
		ptr->num = 1024;
		std::cout<<"MetaTest flag : "<<ptr->flag<<"| num : "<<ptr->num<<std::endl;
	}
	void StringTest() {
		std::string str = "Everything that has a begin has an end.";
		result = arena_.Allocate(str.size());
		memcpy(result.ptr, str.c_str(), str.length()); 
		std::cout<<"string : "<<result.ptr<<std::endl;
	}
	void BigBlocksTest() {
		result = arena_.Allocate(kBigSize);
		std::string str("If we can only encounter each other rather than stay with each other,then I wish we had never encountered.");
		memcpy(result.ptr, str.c_str(), str.length());
		std::cout<<"new memory : "<<result.ptr<<std::endl;
	}
private:
	mlib::Arena arena_;
	mlib::StatusRet result;
};

} // namespace mlib
