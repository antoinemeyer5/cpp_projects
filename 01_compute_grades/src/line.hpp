#include <utility> // std::pair

enum Types {
    Int,
    Double,
};

union ValueType {
    int i;
    double d;
};

class Line
{
    private:
        std::string subject;
        std::pair<Types, ValueType> coef;
        double grades;

    public:
        template <typename T>
        Line(std::string m, T c, double n): subject(m), grades(n) {
            if constexpr(std::is_same_v<T, int>) {
                coef.first = Int;
                coef.second.i = c;
            } else {
                coef.first = Double;
                coef.second.d = c;
            }
        }

        int showMe() const {
            switch (coef.first) {
                case Int:
                    return printf("|%15s|%15d|%15.2f|\n",
                        subject.c_str(), coef.second.i, grades);
                default:
                    return printf("|%15s|%15.2f|%15.2f|\n",
                        subject.c_str(), coef.second.d, grades);
            }
        }

        std::pair<Types, ValueType> getCoef() const { return coef; }
        double getGrades() const { return grades; }
};
