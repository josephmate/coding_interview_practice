
#include <stddef.h>      // NULL definition
#include <stdio.h>      // printf
#include <unordered_map> // unordered_map
#include <stdexcept>

#include "first_non_repeat_char.hpp"


bool first_non_repeat_char(const char * string, char * res) {
	if(string == NULL) {
		throw std::runtime_error("NULL pointer 'string' not supported by first_non_repeat_char(char * string, char * res)");
	}
	if(res == NULL) {
		throw std::runtime_error("NULL pointer 'res' not supported by first_non_repeat_char(char * string, char * res)");
	}

	// init array map to 0 for all entries
	int map[128];
	std::fill(map, map + 128, 0 );
	char curr;
	int i = 0;

	// fill up map with number of occurences of each character
	while( (curr = string[i]) != '\0') {
		map[(int)curr]++;
		i++;
	}
	
	// find the first character that has one occurence by looking up each
	// character in the map produced above
	i=0;
	while( (curr = string[i]) != '\0') {
		if(map[(int)curr] == 1) {
			*res = curr;
			return true;
		}
		i++;
	}

	return false;
}

typedef std::unordered_map<char32_t,int> char32map;
bool first_non_repeat_char(std::u32string string, char32_t * res) {
	if(res == NULL) {
		throw std::runtime_error("NULL pointer 'res' not supported by first_non_repeat_char(char * string, char * res)");
	}
	char32map map;
	
	// fill up map with number of occurences of each character
	for(int i=0; i < string.length(); i++) {
		char32_t curr = string[i]; 
		char32map::const_iterator searchquery = map.find (curr);
		if(searchquery != map.end()) {
			map[curr] = searchquery->second + 1;
		} else {
			map[curr] = 1;
		}
	}

	// find the first character that has one occurence by looking up each
	// character in the map produced above
	for(int i=0; i < string.length(); i++) {
		char32_t curr = string[i]; 
		if(map[curr] == 1) {
			*res = curr;
			return true;
		}
	}


	return false;
}
