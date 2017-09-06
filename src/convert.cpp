#include <cerrno>
#include <cstdlib>
#include <cstdio>
#include <stdexcept>

#include "convert.h"


#define ERR_BUFF_LENGTH 256


char err[ERR_BUFF_LENGTH];


#define CONVERT_FN(TYPE, NAME, FN) \
TYPE NAME(const char *str) \
{ \
    char *end = '\0'; \
    TYPE n_value = FN; \
    if ((errno == ERANGE) || (*end != '\0')) { \
        snprintf(err, ERR_BUFF_LENGTH, "Value {%s} is not a valid {%s}", str, #TYPE); \
        throw std::invalid_argument(err); \
    } \
    return n_value; \
}

#define STRING_ARG str
#define END &end

CONVERT_FN(float,         str_to_float,  strtof(STRING_ARG, END))
CONVERT_FN(unsigned long, str_to_ulong, strtoul(STRING_ARG, END, 10))
CONVERT_FN(long int,      str_to_int,    strtol(STRING_ARG, END, 10))
