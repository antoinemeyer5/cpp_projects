#include <fstream>

#include "utils.hpp"

int main(int argc, char** argv)
{
    // init
    std::ifstream file(argv[1]);
    std::vector<Line> grades{};

    // load data
    if(file.is_open()){
        std::string line;
        while(std::getline(file, line)){
            Line l = parse(line);
            grades.push_back(l);
        }
    }
    file.close();

    // compute average grade
    auto [total, coef] = compute(grades);

    // display data & average grade
    display(grades, total/coef);

	return 0;
}
