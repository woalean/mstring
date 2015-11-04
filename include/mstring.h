
// brief  : this is string realization
// author : ReadOnly
// time   : 2014/10/23

#ifndef _MSTRING_H_
#define _MSTRING_H_

#include <stddef.h>
#include <iostream>

namespace mlib {

const size_t npos = -1;

class MString
{
public:
    MString();

    ~MString();

    MString(const char *pstr);

    MString(const MString &rhs);

    MString operator=(const MString &rhs);

    MString operator+(const MString &rhs); 

    const char* c_str() const;

    const size_t length() const;

    const size_t find(MString& str, size_t pos = 0) const;

    const size_t find(const char* s, size_t pos = 0) const;

	MString substr(size_t pos = 0, size_t len = npos) const;

    bool empty() const;

    size_t size() const;
    
    friend std::ostream& operator<<(std::ostream& os, MString& str);

    friend std::istream& operator>>(std::istream& is, MString& str);
private:
    char* str_;
    size_t len_;
};

} // namespace mlib 

#endif /* mstring.h */
