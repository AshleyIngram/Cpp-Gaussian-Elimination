#include <string>
#include <vector>

class Matrix
{
    public:
        Matrix(std::string filepath);
        std::string toString();
        friend std::ostream& operator<<(std::ostream& out, const Matrix x);
        void solve(bool verbose);
        
    private:
        std::vector<std::vector<double> > _matrix;
        std::vector<double> _vector;
        bool _verbose;
        std::vector<double> _solution;
        std::string convertIntToString(int num);
        void triangularForm();
        std::vector<double> backwardsSubstitution();
};
