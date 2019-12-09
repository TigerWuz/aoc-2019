#include <vector>
#include <string>

class IntCode {
    private:
         std::vector<int> memory;

         int pc;

        int opCode;
        int in1;
        int in2;
        int *target;

         int input;
         int output;

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
      }  OP_Codes;

      void evalModes(int &opCode, int &out1, int &out2, int *target);
      //   int add(const int &input1, const int &input2, int &target);
      //   int mul(const int &input1, const int &input2, int &target);
      //   int inp(const int &input1, int &target);
      //   int out(const int &input1, int &target);
      //   int exit(void);



    public:
        IntCode();
        void loadProgram(const std::vector<int> &program);
        int run(const int &input, std::vector<int> &output);
};
