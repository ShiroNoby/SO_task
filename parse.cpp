#include <iostream>

#include "sort/Sort.h"


int main() {

    std::vector<Parse::Person> ArgVector;

    ///////************************************************parse

    while (!std::wcin.eof()) {

        std::wstring str;
        std::getline(std::wcin, str);

        if (str[0] == L'!') break;

        Parse::Person tmp;
        size_t sizeStr = str.size();
        for (size_t size = 0, start = size, index = 0; size < sizeStr; ++size) {

            switch (str[size]) {

            case L':': {

                str.erase(size, 1);
                --size;
                --sizeStr;
                break;

            }
            case L' ': {

                tmp.info[index] = std::move( str.substr(start, size - start) );
                start = size + 1;
                ++index;
                break;

            }
            }

            if (size + 1 == sizeStr) {

                tmp.info[index] = std::move( str.substr(start, size + 1 - start) );
                break;

            }
        }

        ArgVector.push_back( std::move(tmp) );

    }

    ///////************************************************sort

    std::wcout << "vvod: " << std::endl;

    int type;
    std::wcin >> type;

    --type;

    if (type < 0 || type > 2)
        type = 0;

    Parse::sort(ArgVector, type);

    ///////************************************************out

    switch (type) {

        case 0: {

            for (auto a : ArgVector)
                std::wcout << a.info[1] << L' ' << a.info[0] << L": " << a.info[2] << std::endl;

            break;

        }
        case 1: {

            for (auto a : ArgVector)
                std::wcout << a.info[0] << L' ' << a.info[1] << L": " << a.info[2] << std::endl;

            break;

        }
        case 2: {

            for (auto a : ArgVector)
                std::wcout << a.info[2] << L": " << a.info[0] << L' ' << a.info[1] << std::endl;

            break;

        }
    }

    return 0;
}
