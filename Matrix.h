/*This is header file of the Matrix DataType
    This DateType includes some Basic Operation 
    Such as +, -, *, scaler Mul, Transpose and Also
    Add Value, Get Value */
class Matrix
{
    private:
        int col,row;
        float **values;
    public:
        Matrix();
        Matrix(int r,int c);
        ~Matrix();//bug: this bug is a runtime error goto matrix.cpp for more info :)
        Matrix operator +(Matrix m);
        Matrix operator -(Matrix m);
        Matrix operator *(Matrix m);
        Matrix operator *(float num);
        Matrix getTranspose();
        bool addValue(int r,int c, float value);
        float getValue(int r, int c);
        int getRowCount();
        int getColCount();
        void getMatrixByUser();
        void getMatrixByArray(float **arr);//help us to improve it! :)
        void print();
};