#include <iostream>
#include <vector>
#include <math.h> 
#include <cstdio>

using namespace std;

class myVector{
    public:
    unsigned int dimension;
    vector<long double> myvector;

    myVector(unsigned int d) : dimension(d){
        myvector.resize(dimension);
        for (unsigned i = 0; i < dimension; i++){
            myvector[i] = 0;
        }
    }

    void setVector(){
        for(int j = 0; j != dimension; j++){
                cout<<"Element "<<j<<" :";
                cin>>this->myvector[j];
        }
    }

    void printVector() const{
        for(int j = 0; j != dimension; j++){
            cout<<myvector[j]<<endl;
        }
    }

    long double norm2() const{
        long double temp = 0;
        for(int i = 0; i != dimension; i ++)
            temp += myvector[i] * myvector[i];
        return sqrt(temp);
    }

    myVector operator+(myVector other){
        for(int i = 0; i != dimension; i ++)
            this->myvector[i] += other.myvector[i];
        return (*this);
    }

    myVector operator-(myVector other){
        for(int i = 0; i != dimension; i ++)
            this->myvector[i] -= other.myvector[i];
        return (*this);
    }
};

class Matrix{
    public:
    unsigned int dimension;
    vector<vector<long double>> matrix;

    Matrix(unsigned int n) : dimension(n) {
		matrix.resize(n);

        for (unsigned i = 0; i < matrix.size(); i++){
            matrix[i].resize(n, 0);
        }
    }

    Matrix(unsigned int n, char a) : dimension(n) {
		matrix.resize(n);

        for (unsigned int i = 0; i < matrix.size(); i++){
            matrix[i].resize(n, 0);
        }

        for (unsigned int i = 0; i < matrix.size(); i++){
            matrix[i][i] = 1;
        }
    }

    Matrix (myVector first, myVector other) : dimension(first.dimension){
        matrix.resize(first.dimension);
        for (int i = 0; i < matrix.size(); i++){
            matrix[i].resize(first.dimension, 0);
        }
        for(int i = 0; i != first.dimension; i ++){
            for(int j = 0; j != first.dimension; j++){
                matrix[i][j] = first.myvector[i] * other.myvector[j];
            }
        }
    }

    void setMatrix(){
        for(int i = 0; i != dimension; i++){
            for(int j = 0; j != dimension; j++){
                cout<<"Element "<<i<<","<<j<<" :";
                cin>>this->matrix[i][j];
            }
        }
    }

    void printMatrix() const{
        for(int i = 0; i != dimension; i++){
            for(int j = 0; j != dimension; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    Matrix transposeMatrix(){
        Matrix temp = Matrix(dimension);
        for(int i = 0; i != dimension; i++){
            for(int j = i; j != dimension; j++){
                temp.matrix[i][j] = matrix[j][i];
                temp.matrix[j][i] = matrix[i][j];
            }
        }

        return temp;
    }

    myVector getColumn(int j){
        myVector temp = myVector(dimension);
        for(int i = 0; i != dimension; i++){
            temp.myvector[i] = this->matrix[i][j];
        }
        return temp;
    }

    Matrix operator*(Matrix other){
        Matrix temp = Matrix(other.dimension);
        for(int i = 0; i != other.dimension; i++){
            for(int j = 0; j != other.dimension; j++){
                for(int k = 0; k != other.dimension; k++){
                    temp.matrix[i][j] += (this->matrix)[i][k] * other.matrix[k][j];
                }
            }
        }

        return temp;
    }

    Matrix operator+(Matrix other){
        for(int i = 0; i != dimension; i++){
            for(int j = 0; j != dimension; j++){
                matrix[i][j] += other.matrix[i][j];
            }
        }
        return (*this);
    }

    Matrix operator-(Matrix other){
        for(int i = 0; i != dimension; i++){
            for(int j = 0; j != dimension; j++){
                matrix[i][j] -= other.matrix[i][j];
            }
        }
        return (*this);
    }

    Matrix operator*(long double other){
        for(int i = 0; i != dimension; i++){
            for(int j = 0; j != dimension; j++){
                matrix[i][j] *= other;
            }
        }
        return (*this);
    }

    Matrix operator/(long double other){
        for(int i = 0; i != dimension; i++){
            for(int j = 0; j != dimension; j++){
                matrix[i][j] /= other;
            }
        }
        return (*this);
    }

    
    
};