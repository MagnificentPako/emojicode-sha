#include <Runtime.h>
#include <String.h>
#include <string.h>
#include <sha512.h>

class ESHA : public runtime::Object<ESHA> {};

extern "C" ESHA* newsha() {
    return ESHA::init();
}

extern "C" s::String esha512(s::String input) {
    return sha512(input.cString()).c_str();
}

SET_INFO_FOR(ESHA, sha, 1f3c0)