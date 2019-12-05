#include <vector>
#include <string>

class IntCode {
    private:
      
        int m_opCode;
        int m_input1;
        int m_input2;

    public:
      typedef enum {
         OP_ADD = 1,
         OP_MUL = 2,
         OP_INP = 3,
         OP_OUT = 4,
         OP_EXT = 99
      }  OP_Codes;

        IntCode();
        
        int prepareCommand(const int &opCode, 
                           int *&p_input1,
                           int *&p_input_2,
                           int *&p_target);


        int add(const int &input1, const int &input2, int &target);
        int mul(const int &input1, const int &input2, int &target);
        int inp(const int &input1, int &target);
        int out(const int &input1, int &target);
        int exit(void);
};
