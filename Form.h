#ifndef __FORM_H__
#define __FORM_H__

#include <iostream>
#include <sstream>
#include <string>

using std::string;

class Form
{
public:
    Form(int pre);
    Form &scientific();
    Form &fixed();
    void precision(int pre);
    string operator()(double ori);
    
private:
    double origin;
    string output;
    int prec;
    int type; // 0: gen, 1: scientific, 2: fixed
    string s_num;
    string s_point;
    int s_frac;
    void mysci();
    string gen();
    string sci(double);
    string fix(double);
};



#endif