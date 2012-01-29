#include <string>
#include <vector>

class Matrix
{
    public:
        Matrix(std::string filepath);
        std::string toString();
        friend std::ostream& operator<<(std::ostream& out, const Matrix x);
        
    private:
        std::vector<std::vector<int> > _matrix;
        std::vector<int> _vector;
        std::string convertIntToString(int num);
};