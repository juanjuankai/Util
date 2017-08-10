#ifndef KAIYUAN_SRC_UTIL_TIMER_H_
#define KAIYUAN_SRC_UTIL_TIMER_H_

#include <string>
#include <vector>

namespace kaiyuan {

// Format string by replacing embedded format specifiers with their respective
// values, see `printf` for more details. This is a modified implementation
// of Google's BSD-licensed StringPrintf function.
std::string StringPrintf(const char* format, ...);

// Replace all occurrences of `old_str` with `new_str` in the given string.
std::string StringReplace(const std::string& str, const std::string& old_str,
													const std::string& new_str);

// Split string into list of words using the given delimiters.
std::vector<std::string> StringSplit(const std::string& str,
																		 const std::string& delim);

// Check whether a string starts with a certain prefix.
bool StringStartsWith(const std::string& str, const std::string& prefix);

// Remove whitespace from string on both, left, or right sides.
void StringTrim(std::string* str);
void StringLeftTrim(std::string* str);
void StringRightTrim(std::string* str);

// Convert string to lower/upper case.
void StringToLower(std::string* str);
void StringToUpper(std::string* str);

} 


#endif