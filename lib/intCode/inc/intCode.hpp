#include <vector>
#include <string>

class IC {
   private:
      typedef enum {
         OP_ADD = 1,
         OP_MUL = 2,
         OP_INP = 3,
         OP_OUT = 4,
         OP_JIT = 5,
         OP_JIF = 6,
         OP_LTH = 7,
         OP_EQU = 8,
         OP_EXT = 99
      } OP_CODES;

      std::vector<int> memory;
      void getModes(const std::string &input, int (&out)[2]);


   public:
      void load(const std::vector<int> program);
      int run(const int &input, std::vector<int> &output);

};
