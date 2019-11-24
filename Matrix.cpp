#include <iostream>
#include "Matrix.h"
using namespace std;

/*
    we use normal indexing system
    start from (1,1) so some method
    change some indexing role :)

*/

Matrix :: Matrix()
{
    //Empty Constructor for some use
}

Matrix :: Matrix(int r, int c)
{
    col = c;
    row = r;
    values = new float*[row];
    for(int i = 0 ; i < row ; i ++)
    {
        values[i] = new float[col];
    }

    for(int i = 0 ; i < row ; i ++)
        for(int j = 0 ; j < col ; j ++)
            values[i][j] = 0 ;
            // set all elemnt to: 0

}

Matrix :: ~Matrix() //bug : this bug is a runtime error
{
    /*
    when we try delete value in this program
    and by this method some bugs apears for examlpe
    some function doesn't work Corectly!


        delete values;
    */
}

void Matrix :: getMatrixByArray(float **arr)
{
    /*
        HELP US TO IMPROVE IT!
        
        how we can complete this function by arrays
        not pointer to pointer?!
    */
    for(int i = 0 ; i < row ; i++)
        for(int j = 0 ; j < col ; j++)
            values[i][j] = arr[i][j];

}

bool Matrix :: addValue(int r, int c, float value)
{
    
        values[r-1][c-1] = value;
        return true;
}

float Matrix :: getValue(int r, int c)
{
    return values[r-1][c-1];
}


void Matrix :: print()
{
    for(int i = 0 ; i < row ; i ++)
    {
        for(int j = 0 ; j < col ; j ++)
        {
            cout << values[i][j] << "\t";
        }
        cout << endl;
    }
}

void Matrix :: getMatrixByUser()
{
    float t;
    cout << "Enter values for Matrix:\n";
    for(int i = 0 ; i < row ; i ++)
        for(int j = 0 ; j < col ; j++)
        {
            cout << "Enter element(" << i+1 << "," << j+1 << "):";
            cin >> t;
            values[i][j] = t;
        }
}

int Matrix :: getRowCount()
{
    return row;
}

int Matrix :: getColCount()
{
    return col;
}

Matrix Matrix :: operator + (Matrix m)
{
    if(m.getRowCount() == row && m.getColCount() == col)
    {
        Matrix temp(row,col);
        for(int i = 1 ; i <= row ; i++)
            for(int j = 1 ; j <= col ; j++)
                temp.addValue(i,j, values[i-1][j-1] + m.getValue(i,j) );

        return temp;
    }
    else
    {
        Matrix temp(1,1);
        return temp;
    }
}


Matrix Matrix :: operator - (Matrix m)
{
    if(m.getRowCount() == row && m.getColCount() == col)
    {
        Matrix temp(row,col);
        for(int i = 1 ; i <= row ; i++)
            for(int j = 1 ; j <= col ; j++)
                temp.addValue(i,j, values[i-1][j-1] - m.getValue(i,j) );

        return temp;
    }
    else
    {
        Matrix temp(1,1);
        return temp;
    }
}

Matrix Matrix :: getTranspose()
{
    Matrix temp(col,row);
    for(int i = 0 ; i < row ; i++)
        for(int j = 0 ; j < col ; j++)
        {
            temp.addValue(j+1, i+1, values[i][j]);
        }
    return temp;
}

Matrix Matrix :: operator *(float num)
{
    Matrix temp(row,col);
    for(int i = 1 ; i <= row ; i++)
        for(int j = 1 ; j <= col ; j++)
            temp.addValue(i,j, num * values[i-1][j-1]);
    return temp;
}

Matrix Matrix :: operator *(Matrix m)
{
    if(col == m.getRowCount())
    {
        Matrix temp(row, m.getColCount());
        float t;
        for(int i = 1 ; i <= row ; i ++)
            for( int j = 1 ; j <= m.getColCount() ; j++ )
            {
                t = 0;
                for(int k = 1 ; k <= col ; k ++ )
                {
                    t = t + (values[i-1][k-1] * m.getValue(k,j));
                }
                temp.addValue(i,j,t);
            }
        return temp;
    }
    else
    {
        Matrix temp(1,1);
        return temp;
    }
}