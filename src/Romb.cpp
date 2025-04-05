#include <iostream>
#include <math.h>
using namespace std;

// Створити клас типу – ромб ( поля : сторона, діагональ, колір). У класі визначити
// o конструктори ( не менше двох);
// o функції-члени обчислення площі, периметру;
// o функції-члени встановлення значення сторони, діагоналі та кольору, функції
// встановлення полів класу повинні перевіряти коректність параметрів, що задаються;
// o функції-члени що повертають значення полів;
// o функцію друку.
// Написати програму тестування всіх можливостей цього класу.

class Romb {
  private:
    int side;
    int d1, d2;
    char color;
  public:
    Romb(int s, int d1, int d2, char color = 'B') {
      this->side = s;
      this->d1 = d1;
      this->d2 = d2;
      this->color = color;
    }
    Romb(int s, float d1, char color = 'B') {
        this->side = s;
        this->d1 = d1;
        this->d2 = d1;  // ✅ d2 is set equal to d1
        this->color = color;
    }

    // Constructor 2: Given two diagonals, calculates side using Pythagoras' theorem
    Romb(int d1, int d2) {
        this->d1 = d1;
        this->d2 = d2;
        this->side = sqrt((d1 / 2.0) * (d1 / 2.0) + (d2 / 2.0) * (d2 / 2.0));
        this->color = 'B'; // Default color
    }
    void print() {
      cout << "Romb " << side << " 1: " << d1 <<" 2: "<< d2 << " col: " << color << endl;
    }
    void set_side(int s) {
      if (s > 0) {
        this->side = s;
      } else {
        cout << "Error set side" << endl;
      }
    }
    void set_d1(int d1){
    if (d1 > 0) {
        this->d1 = d1;
      } else {
        cout << "Error set d1" << endl;
      }
    }
    void set_d2(int d2){
    if (d1 > 0) {
        this->d2 = d2;
      } else {
        cout << "Error set d2" << endl;
      }
    }
    void set_color(char color = ' '){
    if (color != ' ') {
        this->color = color;
      } else {
        cout << "Error set color" << endl;
      }
    }
    int side_r(bool r = false){
      if(r){
        return this->side;
      }else{ 
        cout << this->side << endl;
        return 0;
      }
    }
    int d1_r(bool r = false){
      if(r){
        return d1;
      }else{
         cout << d1 << endl;
         return 0;

      }
    }
    int d2_r(bool r = false){
      if(r){
        return d2;
      }else{
         cout << d2 << endl; 
         return 0;
      }
    }
    char color_r(bool r = false){
      if(r){
        return color;
      }else{
       cout << color << endl;
       return 0;
      }
    }
    float S(){
      return 0.5 * d1 * d2;
    }
    float P(){
      return d1 + d2 + side;
    }
    


};

void unit_Romb () {
  Romb a(3,1,2,'c');
  Romb b(3,1.0,'c'); 
  Romb c(1,2);
  a.set_side(5);
  b.set_d1(3);
  a.set_color('R');
  c.set_d2(6);
  a.d1_r();
  b.d2_r();
  c.color_r();

  a.print();
  b.print();
  c.print();
  
  cout << a.S()<< ' '<< b.P();

}
