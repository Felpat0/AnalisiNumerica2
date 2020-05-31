#include "algebra.h"

int main(){
    Matrix m = Matrix(4);
    //Set the values of the matrix
    m.setMatrix();
    int i = 0;
    for(int i = 0; i != m.dimension -1; i++){
        myVector app = myVector(m.dimension);
        myVector temp = myVector(m.dimension - i);
        //Calculate the u tilde vector of this column
        app = m.getColumn(i);
        myVector u = myVector(m.dimension - i);
        for(int k = 0; k != m.dimension-i; k++){
            u.myvector[k] = temp.myvector[k + i];
        }
        temp.myvector[0] = u.norm2();
        u = u - temp;
        //Calculate alpha
        long double alpha = 2/(u.norm2()*u.norm2());
        //Calculate the Householder matrix and apply it to m
        Matrix householder = (Matrix(m.dimension, 'i') - (Matrix(u, u) * alpha));
        m = householder * m;

        //Put the right 0s (because of the not perfect precision)
        for(int j = i+1; j != m.dimension; j++){
            m.matrix[j][i] = 0;
        }
    }
    /*
    //Put the right 0s again (because of the not perfect precision)
    for(int i = 0; i != m.dimension -1; i++){
        for(int j = i+1; j != m.dimension; j++){
            m.matrix[j][i] = 0;
        }
    }*/

    m.printMatrix();
    return 0;
}