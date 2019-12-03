/* */
#include <string>
#include <vector>

namespace inPa
{

class inputParser
{
    public:
        static void get(std::string filePath, std::vector<std::string> &data, const char delim = '\0');
        static void get(std::string filePath, std::vector<std::vector<std::string>> &data, const char delim = '\0');
        static void get(std::string filePath, std::vector<int> &data, const char delim = '\0');
};

} //end namespace inPa
