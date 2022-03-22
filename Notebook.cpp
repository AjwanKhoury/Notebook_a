#include "Notebook.hpp"
#include <iostream>
using namespace std;

namespace ariel
{
    void Notebook::write(unsigned int page, unsigned int row, unsigned int column, Direction direction, string const &message)
    {
    }
    string Notebook::read(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length)
    {
        return "OK";
    }
    void Notebook::erase(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length)
    {
    }
    void Notebook::show(unsigned int page) {
    }
}