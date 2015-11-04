
#include "test_arena.h"
#include "test_mstring.h"

int main()
{
	// mstring test
    mlib::MstringTest test;
    test.CopyTest();
    test.operatorTest();
    test.AssignmentTest();
	test.FindTest();
	test.SubStrTest();
	// arena test
	mlib::ArenaTest test_arena;
	test_arena.StructTest();
	test_arena.StringTest();
	test_arena.BigBlocksTest();
	return 0;
}
