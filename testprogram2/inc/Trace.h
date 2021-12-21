#ifndef __TRACE_H_INCLUDED__
#define __TRACE_H_INCLUDED__

#include <iostream>
#include <string>

using std::cerr;
using std::endl;
using std::string;

class Trace
{
public:
    Trace(const string n)
        : name(n)
    {
        depth++;
        print_name("Entering");
    }

    ~Trace()
    {
        print_name("Leaving ");
        depth--;
    }

private:
    void print_name(const string prefix)
    {
        for (int i = 0; i < depth; i++)
            cerr << " ";
        cerr << prefix << " " << name << " (" << depth << ")" << endl;
    }

private:
    static int depth;

private:
    const string name;
};

#ifdef __TRACE__
#define TRACE(v, n) Trace v(n)
#define COUNT() std::cout << " count = " << count << endl;
#else
#define TRACE(v, n) 
#define COUNT()
#endif

#endif