#include "Sort.h"

void Parse::sort(std::vector<Person>& ArgVector, int type){
	
	std::sort(ArgVector.begin(), ArgVector.end(), [&](const Person& a, const Person& b) ->bool {

		switch (type) {
		
			case 0: {

				if (a.info[1] == b.info[1]) {

					if (a.info[0] == b.info[0]) {

						int sz1 = std::stoi(a.info[2]);
						int sz2 = std::stoi(b.info[2]);
						return sz1 < sz2;

					}

					return a.info[0] < b.info[0];
				}

				return a.info[1] < b.info[1];				
			}
			case 1: {

				if (a.info[0] == b.info[0]) {

					if (a.info[1] == b.info[1]) {

						int sz1 = std::stoi(a.info[2]);
						int sz2 = std::stoi(b.info[2]);
						return sz1 < sz2;

					}

					return a.info[1] < b.info[1];
				}

				return a.info[0] < b.info[0];
			}
			case 2: {
		
				int sz1 = std::stoi(a.info[2]);
				int sz2 = std::stoi(b.info[2]);

				if (sz1 == sz2) {
				
					if (a.info[0] == b.info[0]) 
						return a.info[1] < b.info[1];

					return a.info[0] < b.info[0];
				
				}

				return sz1 < sz2;
			}        
		}
	});
}