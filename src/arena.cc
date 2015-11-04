
#include "arena.h"

namespace mlib {

// size of block
static const int kBlockSize = 4096;

Arena::~Arena() {
	for(int i = 0; i < blocks_.size(); i++) {
		delete[] blocks_[i];
	}
}

StatusRet Arena::Allocate(size_t bytes) {
	if(bytes <= alloc_bytes_remain_) {
		StatusRet result;
		result.ptr = alloc_ptr_;
		alloc_ptr_ += bytes;
		alloc_bytes_remain_ -= bytes;
		return result; 
	}

	return AllocateStrategy(bytes);
}

size_t Arena::MemoryUsed() {
	return memory_used_ + blocks_.capacity() * sizeof(char*) + alloc_bytes_remain_; 
}

StatusRet Arena::AllocateNewMem(size_t bytes) {
	StatusRet result;
	result.ptr = new char[bytes];
	blocks_.push_back(result.ptr);
	memory_used_ += bytes;	
	return result;
}

StatusRet Arena::AllocateStrategy(size_t bytes) {
	// if bytes greater than 1M
	if(bytes > kBlockSize / 4) {
		StatusRet result;
		result = AllocateNewMem(bytes);
		return result;
	}

	StatusRet result;
	result = AllocateNewMem(kBlockSize);
	alloc_ptr_ = result.ptr;
	alloc_bytes_remain_ = kBlockSize;

	alloc_ptr_ += bytes;
	alloc_bytes_remain_ -= bytes;
	return result;
}

} // namespace mlib
