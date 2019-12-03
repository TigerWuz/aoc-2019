class IntCode {
    private:
        int m_opCode;
        int m_input1;
        int m_input2;

        int (IntCode::* m_functionTable[3]) (const int&, const int&);

    public:
        IntCode();

        int add(const int &input1, const int &input2);
        int mul(const int &input1, const int &input2);
        int exit(const int &input1, const int &input2);
};