include matrix.cpp

then use matrix datatype in this format:

for exmple:

int main()
{
	Matrix m1(4,5);
	Matrix m2(4,5);
	Matrix m3(5,3);

	m1.getMatrixByUser();
	m2.getMatrixByUser();
	m3.getMatrixByUser();
	

	Matrix temp = m1 + m2;
	Matrix temp2 = m1 - m2;

	Matrix temp3 = m1 * m3;
	Matrix tmep4 = m3 * 5;
	Matrix temp5 = m1.getTranspose();

	temp.print();
	temp2.print();
	temp3.print();
	temp4.print();
	temp5.print();
	

	return 0;
}