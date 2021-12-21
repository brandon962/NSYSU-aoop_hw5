#include "Form.h"

using std::ostringstream;
using std::to_string;
using namespace std;

Form::Form(int pre) : prec(pre) { type = 0; }

Form &Form::scientific()
{
    type = 1;
    return *this;
}

Form &Form::fixed()
{
    type = 2;
    return *this;
}

void Form::precision(int pre) { prec = pre; }

string Form::operator()(double ori)
{
    origin = ori;
    if (type == 0)
    {
        mysci();
        return gen();
    }
    else if (type == 1)
        return sci(ori);
    else if (type == 2)
        return fix(ori);
    else
        return "Error Type.";
}

void Form::mysci()
{
    std::ostringstream oss;
    oss.precision(prec);
    oss << std::scientific << origin;

    int epos = oss.str().find("e");
    int dpos = oss.str().find(".");
    string temp = oss.str();

    s_num = temp[0];
    s_point = temp.substr(dpos + 1, epos - dpos - 1);
    s_frac = stoi(temp.substr(epos + 2, temp.size() - epos + 2));
}

string Form::gen()
{
    int itemp = prec - 1;
    int point = s_frac;
    output = s_num;
    size_t i;
    for (i = 0; i < s_point.size(); i++)
    {
        if (itemp == 0)
            break;
        if (point == 0)
            output += ".";
        output += s_point[i];
        --itemp;
        --point;
    }
    using std::cout;
    using std::endl;
    if (stoi(s_point.substr(i, 1)) > 4)
    {
        int itemp = stoi(s_point.substr(i - 1, 1));
        output.pop_back();
        output += to_string(itemp + 1);
    }
    if (point > 0)
        for (int i = 0; i < point; i++)
            output += "0";
    return output;
}

string Form::sci(double ori)
{
    std::ostringstream oss;
    oss.precision(prec);
    oss << std::scientific << origin;
    return oss.str();
}

string Form::fix(double ori)
{
    std::ostringstream oss;
    oss.precision(prec);
    oss << std::fixed << origin;
    return oss.str();
}
