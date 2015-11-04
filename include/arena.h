
#ifndef _ARENA_H_
#define _ARENA_H_

#include <iostream>
#include <stdint.h>
#include <vector>

namespace mlib {

struct StatusRet {
	// true if sucess and default true.
	bool bRet;
	// the point we alloc and default NULL.
	char* ptr;
	//
	StatusRet():bRet(true),ptr(NULL) { }
};

class Arena {
public:
	Arena():alloc_bytes_remain_(0),alloc_ptr_(NULL),memory_used_(0) { }
	~Arena();

	// allocate bytes memory and return true when new sucess. 
	StatusRet Allocate(size_t bytes);
	// return size of memory used 
	size_t MemoryUsed();
private:
	// allocate new memory
	StatusRet AllocateNewMem(size_t bytes);
	// strategy about allocate
	StatusRet AllocateStrategy(size_t bytes);

	// remain size of block
	uint32_t alloc_bytes_remain_;
	// itor point of memory
	char* alloc_ptr_;
	uint32_t memory_used_;

	std::vector<char*> blocks_;
	// no copying allowed
	Arena(const Arena&);
	void operator=(const Arena&);
};

} // namespace mlib

#endif // _ARENA_H_
