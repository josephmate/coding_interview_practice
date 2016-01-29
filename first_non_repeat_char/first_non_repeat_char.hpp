#ifndef FIRST_NON_REPEAT_CHAR_HPP
#define FIRST_NON_REPEAT_CHAR_HPP

#include <string>

/**
 * Given ASCII characters, determine the first non repeated character.
 *
 * Returns true, if found and places it in the character pointed to by the res
 * pointer.
 *
 * Returns false, if not found. res will be left untouched.
 */
bool first_non_repeat_char(const char * string, char * res) ;

/**
 * Given UTF32 characters, determine the first non repeated character.
 *
 * Returns true, if found and places it in the character pointed to by the res
 * pointer.
 *
 * Returns false, if not found. res will be left untouched.
 */
bool first_non_repeat_char(std::u32string string, char32_t * res) ;

#endif 
