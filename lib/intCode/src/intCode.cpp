#include "intCode.hpp"

IntCode::IntCode(){
    m_functionTable[0] = IntCode::add;
    m_functionTable[1] = IntCode::mul;
    m_functionTable[2] = IntCode::exit;
}

int IntCode::add(const int &input1, const int &input2) {
    return input1 + input2;
}

int IntCode::mul(const int &input1, const int &input2) {
    return input1 + input2;
}

int IntCode::exit(const int &input1, const int &input2) {
    return 0;
}