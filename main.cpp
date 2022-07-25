#include <iostream>
#include "iomanip"
using namespace std;
#define high 2
#define width 3
typedef int T;
class Matrix{
public:
//    Matrix() {}
    explicit Matrix(const string& s="default");
    friend Matrix operator-(Matrix &t1, Matrix &t2);
    friend Matrix operator+(Matrix &t1,Matrix &t2);
    void initMatrix();
    void display();
    ~Matrix(){cout<< this->name<<" is destroying!\n";};
private:
    T mat[high][width];
    string name;
};
Matrix::Matrix(const string& s) {
    name=s;
    cout<<s<<" is construed"<<endl;
}

void Matrix::initMatrix() {
    cout<<"input the value of matrix "<<name<<" :\n";
    for(int i=0;i<high;i++)
        for(int j=0;j<width;j++)
            cin>>mat[i][j];
}

void Matrix::display() {
    cout<<name<<":\n";
    for(int i=0;i<high;i++) {
        for (int j = 0; j < width; j++)
            cout << setw(6) << mat[i][j];
        cout << "\n";
    }
    cout<<endl;
}

Matrix operator-(Matrix &t1, Matrix &t2) {
    Matrix matrix;
    for(int i=0;i<high;i++)
        for(int j=0;j<width;j++)
            matrix.mat[i][j]=t1.mat[i][j]-t2.mat[i][j];
    return matrix;
}

Matrix operator+(Matrix &t1, Matrix &t2) {
    Matrix matrix;
    for(int i=0;i<high;i++)
        for(int j=0;j<width;j++)
            matrix.mat[i][j]=t1.mat[i][j]+t2.mat[i][j];
    return matrix;
}

int main() {
    Matrix a("A"),b("B");
    a.initMatrix();b.initMatrix();
    a.display();b.display();
    Matrix c("C");c=a+b;c.display();
    Matrix d("D");d=a-b;d.display();
    return 0;
}
