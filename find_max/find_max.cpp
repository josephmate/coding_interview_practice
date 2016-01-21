
#include <vector>     /* vector */
#include <stdexcept>
#include "find_max.hpp"    /* find_max */
	

int find_max(std::vector<int> * values) {
	if(values->size() == 0) {
		throw std::runtime_error("max not defined for emtpy arrays");
	}
	int max_so_far = (*values)[0];
	for(auto i : *values) {
		if(i > max_so_far) {
			max_so_far = i;
		}
	}
	return max_so_far;
}
