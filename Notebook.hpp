#include "Direction.hpp"
#include <string>
#include <vector>
#include <map>

struct emptyC
{
    char val='_';
};
using namespace std;
namespace ariel{
    class Notebook{
    private:
        unsigned int min_pages, min_row, min_column;
        unsigned int max_pages, max_row, max_column;
        map<unsigned int, map< unsigned int, emptyC> > notebook;
    
    
    public:
        Notebook(){
            min_column=min_row=UINT16_MAX;
            max_row=max_column=0;
        }
    
    
    void write(unsigned int page, unsigned int row, unsigned int column, Direction direction, string const &message);
    static std:: string read(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length);
    void erase(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int length);
    void show(unsigned int page);
    };
}