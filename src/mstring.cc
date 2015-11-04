
#include "mstring.h"
#include <string.h>

namespace mlib {

MString::MString() {
	len_ = 0;
	str_ = new char[1];
	str_[0] = '\0';
}

MString::~MString() {
	if(NULL != str_) {
        delete [] str_;
        str_ = NULL;
    }
}

MString::MString(const MString &rhs) {
    if(NULL != rhs.str_) {
        len_ = strlen(rhs.str_) + 1;
        str_ = new char[len_];
        memcpy(str_, rhs.str_, len_);
        str_[len_] = '\0';
    }
}

MString::MString(const char *pstr) {
    if(NULL != pstr) {
        len_ = strlen(pstr) + 1;
        str_ = new char[len_];
        memcpy(str_, pstr, len_);
        str_[len_] = '\0';
    } else {
        str_ = new char[1];
        str_ = '\0';
    }
}

MString MString::operator=(const MString &rhs) {
    if(this != &rhs) {
        delete[] str_;
        len_ = rhs.length(); 
        str_ = new char[len_];
        memcpy(str_, rhs.str_, len_);
        str_[len_] = '\0';
        return *this;
    }
    return *this;
}

MString MString::operator+(const MString &rhs) {
#if 0
	// only C coding
    size_t len = strlen(rhs.str_);
    const char* pstr = rhs.str_;
    const char* old = str_;
    const char* result = NULL;
    if(this != &rhs) {
        char* temp = new char[len_ + len + 1];
        result = temp;
        for(int i = 0; i < len_ - 1; i++)
            *temp++ = *old++;
        *temp++  = ' ';
        for(int i = 0; i < len; i++)
            *temp++ = *pstr++;

		MString rs(result);
        return rs;
    } 
#endif
	size_t len = strlen(rhs.str_) + len_;
	char* result = new char[len];
	const char* itor = result;
	memcpy(result, str_, len_);
	for(int i = 0; i < len_ - 1; i++)
		result++;
	*result++ = ' ';
	memcpy(result, rhs.str_, strlen(rhs.str_));
	MString rs(itor);
	delete itor;
	return rs;
}

const char* MString::c_str() const {
    return (NULL != str_) ? str_ : NULL;
}

const size_t MString::length() const {
    return (NULL != str_) ? strlen(str_) : 0;
}

bool MString::empty() const {
    return (str_ == "") ? true : false;
}

size_t MString::size() const {
    return len_;
}

const size_t MString::find(MString& str, size_t pos) const {
    size_t result = pos;
    const char* old = str_;
    const char* in = str.c_str();
    const char* ptr_in = NULL;
    const char* ptr_old = NULL;
    while(0 < pos--)
        old++;
    while(*old != '\0') {
        result++;
        if(*in == *old) {
        	ptr_in = in;
        	ptr_old = old;
            while((*ptr_in++ == *ptr_old++) && (*ptr_old != '\0')) {
                if(*ptr_in == '\0')
                    return result;
            }
        }
        old++;
    }
        
    return npos;
}

const size_t MString::find(const char* s, size_t pos) const {
    size_t result = pos;
    const char* old = str_; 
    const char* in = s;
    const char* ptr_in = NULL;
    const char* ptr_old = NULL;
    while(0 < pos--)
        old++;
    while(*old != '\0') {
        result++;
        if(*in == *old) {
        	ptr_in = in;
        	ptr_old = old;
            while((*ptr_in++ == *ptr_old++) && (*ptr_old != '\0')) {
                if(*ptr_in == '\0')
                    return result;
            }
        }
        old++;
    }
        
    return npos;
}

MString MString::substr(size_t pos, size_t len) const {
	// return empty string if pos is equal to len_.
	if(pos == len_) {
		MString out("");
		return out;
	}
	const char* result = NULL;
	const char* old = str_;
	char* itor = NULL;
	int pos_ = pos;
	if(pos < len_) {
		while(pos_-- > 0) {
			old++;
		}
		if(npos == len) {
			itor = new char[len_ - pos];
			memcpy(itor, old, len_ - pos);
		}
		if(len < len_ - pos) {
			itor = new char[len];
			memcpy(itor, old, len);
		}
		MString out(itor);

		if(NULL != itor)
			delete itor;
		return out;
	}
}

std::ostream& operator<<(std::ostream& os, MString& str) {
    os<<str.str_;
    return os;
}

std::istream& operator>>(std::istream& is, MString& str) {
    is>>str.str_;
    str.len_ = strlen(str.str_);
    return is;
}


} // namespace mlib
