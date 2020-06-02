#include "algebra.h"

int main(){
    int n;
    cout<<"Insert the dimension of the matrix: ";
    cin>>n;
    Matrix m = Matrix(n);
    //Set the values of the matrix
    m.setMatrix();
    for(int k = 0; k != m.dimension-1; k++){
        Matrix x = Matrix(n, 'i');
        
        long double max = m.matrix[k][k];
        unsigned int index = 0;
        for(int i = 1; i != m.dimension; i++){
            if(m.matrix[i][k] > max){
                max = m.matrix[i][k];
                index = i;
            }
        }

        if(index != 0){
            //Instead of using a Permutation Matrix, the rows will be
            //swapped using code (for more efficiency)
            long double app;
            for(int t = k; t != m.dimension; t++){
                app = m.matrix[k][t];
                m.matrix[k][t] = m.matrix[index][t];
                m.matrix[index][t] = app;
            }
            
        }

        //Build the X matrix
        for(int i = k + 1; i != x.dimension; i++){
            //For some strange reason -1*0 equals -0 in C++.............
            if(m.matrix[i][k] == 0)
                x.matrix[i][k] == 0;
            else
                x.matrix[i][k] = -1*(m.matrix[i][k]/m.matrix[k][k]);
        }
        cout<<endl<<endl<<"X"<<k<<" ="<<endl;
        x.printMatrix();
        m = x*m;
        cout<<endl<<endl<<"X"<<k<<"*M ="<<endl;
        m.printMatrix();
    }
}