#pragma

#include <algorithm>
#include <vector>
#include <string>

namespace Parse{
	
	struct Person {

		//0 - secondName, 1 - name, 2 - id
		std::wstring info[3];

	};
	
	void sort(std::vector<Person>& ArgVector, int type);	
};
