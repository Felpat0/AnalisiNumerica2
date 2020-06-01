#include "algebra.h"

int main(){
    int n;
    cout<<"Insert the dimension of the matrix: ";
    cin>>n;
    Matrix m = Matrix(n);
    //Set the values of the matrix
    m.setMatrix();
    Matrix l = Matrix(n);
    for(int i = 0; i != m.dimension; i++){
        int s = 0;
        

        for(int j = 0; j != i + 1; j++){
            long double s = 0;
            if(i == j){
                for(int k = 0; k != j + 1; k++){
                    s += ((l.matrix[j][k]) * (l.matrix[j][k]));
                }
                l.matrix[j][j] = sqrt(m.matrix[j][j] - s);
            }else{
                for(int k = 0; k != i; k++)
                    s += l.matrix[j][k] * l.matrix[i][k];
                l.matrix[i][j] = (1/l.matrix[j][j]) * (m.matrix[i][j] - s);
            }
        }
    }
    cout<<endl<<endl;
    cout<<"L:"<<endl;
    l.printMatrix();
    cout<<endl<<endl;
    cout<<"Transposed L:"<<endl;
    (l.transposeMatrix()).printMatrix();
    cout<<endl<<endl;
    cout<<"L*Transposed L:"<<endl;
    (l*(l.transposeMatrix())).printMatrix();
}