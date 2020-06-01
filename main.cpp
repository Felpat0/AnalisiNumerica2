#include "algebra.h"

int main(){
    int n;
    cout<<"Insert the dimension of the matrix: ";
    cin>>n;
    Matrix m = Matrix(n);
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
            u.myvector[k] = app.myvector[k + i];
        }
        temp.myvector[0] = u.norm2();
        u = u - temp;
        //Calculate alpha
        long double alpha = 2/(u.norm2()*u.norm2());
        //Create the matrix of this step (initialized to all 0)
        Matrix householder = Matrix(m.dimension);
        //Calculate the matrix of dimension n-i, where i is the current step number
        //NOTES:
        //(Matrix(m.dimension - i, 'i') is the Identity Matrix with n-i dimension
        //Matrix(u, u) is u*u^t
        Matrix smallHouseHolder = (Matrix(m.dimension - i, 'i') - (Matrix(u, u) * alpha));
        //Check if the current step is the first
        if(i > 0){
            //If it is not, build the householder matrix starting from the small one
            //Insert the elements of the small matrix into the n dimension one
            for(int k = i; k != householder.dimension; k++){
                for(int j = i; j != householder.dimension; j++){
                    householder.matrix[k][j] = smallHouseHolder.matrix[k - i][j - i];
                }
            }
            //To not change the 0,..,i columns and the 0,...,i rows of the m matrix, make the Householder matrix (0,0),...,(i,i) elements be 1
            //NB: the other elements of those columns/rows are already 1
            for(int k = 0; k != i; k++){
                householder.matrix[k][k] = 1;
            }
            //Apply the Householder matrix
            m = householder * m;
        }else{
            //The step is the first, so smallHouseHolder equals HouseHolder
            m = smallHouseHolder * m;
        }

        //Put the right 0s (because of the not perfect precision)
        for(int j = i+1; j != m.dimension; j++){
            m.matrix[j][i] = 0;
        }
    }

    m.printMatrix();
    cout<<endl;
    system("pause");
    return 0;
}