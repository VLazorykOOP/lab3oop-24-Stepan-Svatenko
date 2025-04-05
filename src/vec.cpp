#include <iostream>
#include <math.h>
// Створити тип даних - клас вектор, який має поля x, y та z типу float і змінну стану. У класі
// визначити X
// o конструктор без параметрів(інінціалізує поля в нуль);V
// o конструктор з одним параметром типу float (інінціалізує поля x, y та z значенням
// параметру);
// o конструктор з одним параметром вказівник на тип (інінціалізує поля x, y та z
// значенням масиву за вказівником, якщо вказівник NULL (nulptr) то встановити
// код помилки);
// o деструктор із виведенням інформації про стан вектора;
//o визначити функцію, яка присвоює полю x, y або z деяке значення (параметр за
// замовчуванням);
// o функцію яка одержує деякий елемент з полів x, y та z;
// o конструктор копій та операцію присвоєння; // !!!
// o визначити функції друку, додавання, віднімання, векторний добуток які
// здійснюють ці арифметичні операції з даними цього класу;
// o функцію ділення на ціле типу short(при діленні на 0 змінити стан, а ділення не
// виконувати
// o визначити функції порівняння: більше, менше або рівно, які повертають true або
// false.

// У змінну стани встановлювати код помилки, діленні на 0, при передачі NULL (nulptr) в
// конструкторі із вказівником. Передбачити можливість підрахунку числа об'єктів даного типу.
// Написати програму тестування всіх можливостей цього класу.
//

using namespace std;

enum STATE {
  OK, BAD_INIT, BAD_DIV
};

// Створити тип даних - клас вектор, який має поля x, y та z типу float і змінну стану. У класі
// визначити

class Vec3 {
  private:
    float x;
    float y;
    float z;
    STATE state;
    static int count;
  public:
    
    Vec3(float *p){
      count++;
      // значенням масиву за вказівником, якщо вказівник NULL (nulptr) то встановити
      // код помилки);
      if(p != NULL){
        this->x = p[0];
        this->y = p[1];
        this->z = p[2];
        this->state = OK;
      }else{
        this->state = BAD_INIT;
      }
    }
    Vec3(){
      // o конструктор без параметрів(інінціалізує поля в нуль);V

      count++;
      this->x = 0;
      this->y = 0;
      this->z = 0;
      this->state = OK;
    }
    Vec3(float uni){
      // o конструктор з одним параметром типу float (інінціалізує поля x, y та z значенням
      // параметру);

      count++;
      this->x = uni;
      this->y = uni;
      this->z = uni;
      this->state = OK;
    }
    Vec3(float x, float y, float z){
      count++;
      this->x = x;
      this->y = y;
      this->z = z;
    }
    
    ~Vec3(){
      count--;
      cout << "x: " << x << " y: " << y << " z: " << z << " state: " << state << endl;
    }



    //o визначити функцію, яка присвоює полю x, y або z деяке значення (параметр за
    // замовчуванням);

    void set_x(float x = 1.0){
      this->x = x;
    }
    void set_y(float y = 1.0){
      this->y = y;
    }
    void set_z(float z = 1.0){
      this->z = z;
    }
    void print(){
      cout << "x: " << x << " y: " << y << " z: " << z << " state: " << state << endl;
    }
    // o функцію яка одержує деякий елемент з полів x, y та z;
    float get_x(){
      return x;
    }
    float get_y(){
      return y;
    }
    float get_z(){
      return z;
    }
    // o конструктор копій та операцію присвоєння; // !!!
    Vec3(const Vec3& other) {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        this->state = other.state;
    }

    Vec3& operator=(const Vec3& other) {
        if (this == &other) return *this;  // Перевірка самоприсвоєння

        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        this->state = other.state;

        return *this;
    }
    // o визначити функції друку, додавання, віднімання, векторний добуток які
    // здійснюють ці арифметичні операції з даними цього класу;
    Vec3 Add(Vec3& d){
      return Vec3(this->x + d.x, this->y + d.y, this->z + d.z);
    }
    Vec3 Sub(Vec3& d){
      return Vec3(this->x - d.x, this->y - d.y, this->z - d.z);
    }
    Vec3 Mul(float d){
      return Vec3(this->x * d, this->y * d, this->z * d);
    }
    Vec3 vec_mult(Vec3& other){
      return Vec3(
            this->y * other.z - this->z * other.y,  // x-компонента
            this->z * other.x - this->x * other.z,  // y-компонента
            this->x * other.y - this->y * other.x   // z-компонента
      );
    }      
    // o функцію ділення на ціле типу short(при діленні на 0 змінити стан, а ділення не
    // виконувати);
    Vec3 Div(short d){
      if(d == 0){
        this->state = BAD_DIV;
        return *this;
      }
      return Vec3(this->x / d, this->y / d, this->z / d);
    }
    // o визначити функції порівняння: більше, менше або рівно, які повертають true або
    // false.
    bool Compare(Vec3 &d ){
      float a = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
      float b = sqrt(d.x * d.x + d.y * d.y + d.z * d.z);
      if(a == b){
        return true;
      }
      else if(a < b){
        return false;
      }
      else if(a > b){
        return true;
      }

    }


};
int Vec3::count = 0;  

void unit_vec () {
  float a[3];
  a[0] = 1.0;
  a[1] = 1.0;
  a[2] = 1.0;
  Vec3 v1(a);
  Vec3 v2(5);
  Vec3 v3;
  cout<< "Print:\n";
  v1.print();
  v2.print();
  v3.print();
  cout << "Setter:\n";
  v1.set_y();
  v1.print();
  cout << "Getter\n";
  cout << v1.get_y()<< endl;
  cout << "Copier\n";
  Vec3 v0(v2);
  v0.print();
  cout << "appropriation\n";
  v0 = v1;
  v0.print();
  cout << "Add:\n";
  v3 = v3.Add(v1);
  v3.print();
  cout << "Sub:\n";
  v3 = v3.Sub(v3);
  v3.print();
  cout << "Mul:\n";
  v3 = v3.Mul(0.0);
  v3.print();
  cout << "Div:\n";
  v3 = v3.Div(2.1);
  v3.print();
  v3 = v3.Div(0.0);
  v3.print();
  cout << "Vec Mult:\n";
  v1.vec_mult(v2).print();
  cout << "Compare:\n";
  v3.Compare(v1);

  cout << "Deconstract:"<< endl;
  
}
