#ifndef BST_H
#define BST_H



#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Converts the provided str into an integer and places the result in the int
 * pointed to by the pointer res.
 *
 * Returns 1 if successful.
 *
 * Returns 0 if the string could not be converted to an integer. In this case,
 * res will be left untouched.
 */
int str_to_int(const char * str, int * res);

/**
 * Converts the provided integer into a string and places it in a new string. We
 * update the char ** pointer to point to our new string
 *
 * Returns 1 if successful.
 *
 * Returns 0 if the integer could not be converted. 
 */
int int_to_str(int val, char ** res) ;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BST_H
