// Створити клас матриця. Даний клас містить вказівник на вказівник на double, розміри
// рядків і стовпців та стан помилки. У класі визначити
// o конструктор без параметрів( виділяє місце для матриці 2 на 2 елемента та
// інінціалізує його в нуль); 
// o конструктор з одним параметром – розмір n матриці (виділяє місце n на n та
// інінціалізує матрицю значенням нуль);

// o конструктор із трьома параметрами розміри матриці (n , m) та значення
// ініціалізації value (виділяє місце перші аргументи та інінціалізує значенням
// третього аргументу - value);

// o конструктор копій та операцію присвоєння; // !!!
// o деструктор звільняє пам'ять;
// o визначити функцію, яка присвоює елементу масиву деяке значення (параметр за
// замовчуванням);

// o функцію яка одержує деякий елемент матриці за індексами i та j;

// o визначити функції друку, додавання, множення, віднімання, які здійснюють ці

// арифметичні операції з даними цього класу;

// o визначити функцію ділення матриці на скаляр типу int (у випадку якщо скаляр
// рівний нулю ділення не виконувати);

// o визначити функції порівняння: більше, менше або рівно, які повертають true або
// false.

// У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі матриці,
// ділення на 0. Передбачити можливість підрахунку числа об'єктів даного типу. Написати
// програму тестування всіх можливостей цього класу.
//
enum ERR{
  OK, ERR_MEM, ERR_DIV, ERR_INDEX
};
#include <iostream>
using namespace std;
class Matrix {
  private:
    int rows, cols;
    double** matrix;
    ERR state = OK;
  public:
    Matrix(int n, int m, double value = 0) {
        this->rows = n;
        this->cols = m;
        this->matrix = new double*[rows];
        for (int i = 0; i < n; i++) {
            this->matrix[i] = new double[m];
            for (int j = 0; j < m; j++) {
                this->matrix[i][j] = value;
            }
        }
    }
    Matrix(int n){
      this->rows=n; 
      this->cols=n;
      this->matrix = new double*[rows];
      for (int i = 0; i < n; i++) {
          this->matrix[i] = new double[this->cols];
          for (int j = 0; j < this->cols; j++) {
              this->matrix[i][j] = 0;
          }
      }

    }
    Matrix(){
      this->rows = 2;
      this->cols = 2;
      this->matrix = new double*[rows];
      for(int i = 0; i < rows; i++){
        this->matrix[i] = new double[cols];
        for(int j = 0; j < cols; j++){
          this->matrix[i][j] = 0;
        }
      }
    }
    ~Matrix(){
      for(int i = 0; i < rows; i++){
        delete[] this->matrix[i]; 
      }
      delete[] this->matrix;
      cout<< "destructed" << endl;
    }
    void print(){
      for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
          cout << matrix[i][j] << " ";
        }
        cout << endl;
      }
    }

    Matrix(const Matrix& other) {
        this->rows = other.rows;
        this->cols = other.cols;
        this->matrix = other.matrix;
    }

    Matrix& operator=(const Matrix& other) {
        
    if (this == &other) return *this;  // Перевірка самоприсвоєння

    // Звільняємо стару пам'ять
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    // Копіюємо нові значення
    this->rows = other.rows;
    this->cols = other.cols;

    this->matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }

    return *this;
}

    void set_matr(int i, int j, double value=0.0) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            state = ERR_INDEX;
            return;
        }
        matrix[i][j] = value;
    }
    double get_matr(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            state = ERR_INDEX;
            return 0.0;
        }
        return matrix[i][j];
    }
    void mult(double a){
      for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
          matrix[i][j] *= a;
        }
      }
    }
    void add(double a){
      for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
          matrix[i][j] += a;
        }
      }
    }
    void sub(double a){
      for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
          matrix[i][j] -= a;
        }
      }
    }
    void div(double a){
      if(a == 0){
        state = ERR_DIV;
        return;
      }
      for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
          matrix[i][j] /= a;
        }
      }
    }
    bool operator==(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            return false; 
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != other.matrix[i][j]) {
                    return false; 
                }
            }
        }
        return true; 
    }
    bool operator>=(const Matrix& other) const {
        if (rows < other.rows || cols < other.cols) {
            return false; 
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] < other.matrix[i][j]) {
                    return false; 
                }
            }
        }
        return true; 
    }
    
    bool operator<=(const Matrix& other) const {
        if (rows > other.rows || cols > other.cols) {
            return false; 
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] > other.matrix[i][j]) {
                    return false; 
                }
            }
        }
        return true; 
    }

};

void unit_matrix() {
    Matrix a(2, 2,3), b;
    cout << "a:\n";
    a.print();
    cout << "b:\n";
    b.print();
    Matrix d(a);
    Matrix c;
    c = a;
    cout << "d:\n";
    d.print();
    cout << "c:\n";
    c.print();
    cout << "\n >=: " << (a>=b)<< " " << (b<=a) ;

    cout << "\n <=: " << (a<=b) <<  " " << (b>=a)  ;
    cout <<"\n ==:" << (a==b) <<" " << (b==a)<<endl ;
    a.set_matr(0,0,3);
    a.print();
    a.set_matr(0,1,2);
    a.print();
    cout << a.get_matr(0,1)<< endl;
    cout << "Add:\n";
    a.add(2);
    a.print();
    cout << "Sub:\n";
    a.sub(2);
    a.print();
    cout << "Mult:\n";
    a.mult(3);
    a.print();
    cout << "div:\n";
    a.div(0);
    a.print();
    
}

