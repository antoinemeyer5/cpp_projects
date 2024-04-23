#include <sstream>
#include <tuple>
#include <vector>

#include "line.hpp"

Line parse(std::string const& str) {
    std::istringstream ss(str);

    std::string m; ss >> m;
    std::string c; ss >> c;
    std::string n; ss >> n;

    if (c.find('.') == c.npos) {
        return Line(m, atoi(c.c_str()), atof(n.c_str())); // int, float
    } else {
        return Line(m, atof(c.c_str()), atof(n.c_str())); // float, float
    }
}

std::tuple<double, double> compute(std::vector<Line> grades) {
    double total = 0.0;
    double coef = 0.0;

    for(auto v: grades){
        if(v.getCoef().first) {
            double c = v.getCoef().second.d;
            total += c * v.getGrades();
            coef += c;
        } else {
            int c = v.getCoef().second.i;
            total += c * v.getGrades();
            coef += c;
        }
    }

    return {total, coef};
}

void display(std::vector<Line> grades, double average)
{
    printf("+%15s+%15s+%15s+\n", "---------------", "---------------",  "---------------"   );
    printf("|%15s|%15s|%15s|\n", "SUBJECT",         "COEFFICIENT",      "GRADE"             );
    printf("|%15s+%15s+%15s|\n", "---------------", "---------------",  "---------------"   );
    for(auto v: grades){
        v.showMe();
    }
    printf("+%15s+%15s+%15s+\n", "---------------", "---------------",  "---------------"   );

    printf("\nAVERAGE GRADE = %.2f/20\n", average);
}
