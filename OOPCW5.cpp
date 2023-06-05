

#include <iostream>
using namespace std;



class Car {
    string name;
    int number;
    static int num;
    int* sale = nullptr;
    int countSale = 0;

    static int incrNum() {
        num++;
        return num;
    }
public:
    Car() {
        cout << this << " created empty" << endl;
    }
    Car(string name,int* nums) {
        cout << this << " created" << endl;
        delete[]sale;
        int size = _msize(nums) / sizeof(nums[0]);
        sale = new int[size];
        for (int i = 0; i < size; i++) {
            sale[i ] = nums[i];
        }
        this->name = name;
        this->number = incrNum();


    }
    Car(const Car& car) {
        cout << this << " created copy" << endl;
        if (sale != nullptr)delete[] sale;
        sale = new int[car.countSale];
        for (int i = 0; i < car.countSale; i++) {
            sale[i] = car.sale[i];
        }
        countSale = car.countSale;
        this->name = car.name;
        this->number = incrNum();


    }
    void operator=(const Car& car) {
        cout << this << " created copy" << endl;
        if (sale != nullptr)delete[] sale;
        sale = new int[car.countSale];
        for (int i = 0; i < car.countSale; i++) {
            sale[i] = car.sale[i];
        }
        countSale = car.countSale;
        this->name = car.name;
        this->number = incrNum();


    }
    Car(const Car&& car) {
        cout << this << " created move" << endl;
        if (sale != nullptr)delete[] sale;
        sale = new int[car.countSale];
        for (int i = 0; i < car.countSale; i++) {
            sale[i] = car.sale[i];
        }
        countSale = car.countSale;
        this->name = car.name;
        this->number = incrNum();


    }
    void showInfo() {
        cout << name << " " << number << endl;
        for (int i = 0; i < countSale; i++) {
            cout<<sale[i]<<" ";
        }
        cout << endl;
    }
    ~Car() {
        delete[] sale;
        cout << this << " delited" << endl;
    }


};
int Car::num = 0;

Car returnCar(string name, int* nums) {
    Car car1(name, nums);
    return car1;
}


class Pic {
    char* colours=nullptr;
    int counter;
    int size[2]={0,0};
public:
    Pic() {

    }
    Pic( char* newColours, int size[2]) {
        cout << "create" << endl;
        this->size[0] = size[0];
        this->size[1] = size[1];
        int sizeCounter = _msize(newColours) / sizeof(newColours[0]);
        this->colours = new char[sizeCounter];
        for (int i = 0; i < sizeCounter; i++) {
            colours[i] = newColours[i];
        }
    }

    Pic(const Pic& pic) {
        cout << this << " created copy" << endl;
        if (colours != nullptr)delete[]colours;
        colours = new char[pic.counter];
        for (int i = 0; i < pic.counter; i++) {
            colours[i] = pic.colours[i];
        }
        this->size[0] = size[0];
        this->size[1] = size[1];
        counter = pic.counter;
    }

    void operator =(const Pic& pic) {
        cout << this << " created copy" << endl;
        if (colours != nullptr)delete[]colours;
        colours = new char[pic.counter];
        for (int i = 0; i < pic.counter; i++) {
            colours[i] = pic.colours[i];
        }
        this->size[0] = size[0];
        this->size[1] = size[1];
        counter = pic.counter;
    }
    Pic(const Pic&& pic) {
        cout << this << " created move" << endl;
        if (colours != nullptr)delete[]colours;
        colours = new char[pic.counter];
        for (int i = 0; i < pic.counter; i++) {
            colours[i] = pic.colours[i];
        }
        this->size[0] = size[0];
        this->size[1] = size[1];
        counter = pic.counter;
    }
    ~Pic() {
        delete[]colours;
    }
    void showInfo() {
        cout << size << endl;
        for (int i = 0; i < counter; i++) {
            cout << colours[i] << " ";
        }
        cout << endl;
    }


};
class Painter {
    string name;
public:
    Painter(string name) {
        this->name = name;
    }
    Pic createPaint( char* newColours,int size[2]) {
        Pic pic( newColours,size);
        return pic;
    }

};





class Student {
    int** uarterMark;

    int counter[4] = { 0,0,0,0 };
    string name;
public:

    void addMark(int uarter, int mark) {
        int* buf = new int[counter[uarter - 1] + 1];
        for (int i = 0; i < counter[uarter - 1]; i++) {
            buf[i] = uarterMark[counter[uarter - 1]][i];
        }
        uarterMark[counter[uarter - 1]][counter[uarter - 1]] = mark;
        counter[uarter - 1]++;
        delete[]uarterMark[counter[uarter - 1]];
        uarterMark[counter[uarter - 1]] = buf;
    }
  bool showAllUarter(){
  for(int i=0;i<4;i++){
  cout<<"uarter "<<i<<endl;
    showUarter(i,0);

  }
  
  
  
  }
    bool showUarter(int uarter,bool flag=1) {
        if (counter[uarter - 1] == 0) return 0;
      if(flag!=0){
      cout << "index|mark" << endl;
        for (int i = 0; i < counter[uarter-1]; i++) {
            cout<<i<<"    |" << uarterMark[uarter - 1][i] << endl;

        }
        cout << endl;
      
      }
        
        for (int i = 0; i < counter[uarter-1]; i++) {
            cout<< uarterMark[uarter - 1][i]<<" ";

        }
        cout << endl;
        return 1;
    }
    void deleteMark(int index,int uarter) {
        if (index != -1) {
            int* buf = new int[counter[uarter-1]-1];
            for (int i = 0; i < index; i++) {
                buf[i] = uarterMark[uarter-1][i];
            }
            for (int i = index + 1; i < counter[uarter - 1]; i++) {
                buf[i - 1] = uarterMark[uarter - 1][i];
            }
            counter[uarter - 1]--;
            delete[] uarterMark[uarter - 1];
            uarterMark[uarter - 1] = buf;
        }
        
    }

    void editMark(int uarter, int index,int newMark) {
        uarterMark[uarter - 1][index] = newMark;
    }


};

class Group {
    string name;
    Student* students = nullptr;
    int counterStudent=0;


void addStudent(string nameStudent){
  
  
  
  }
int searchStudent(string nameStudent){
  for(int i=0;i<counterStudents;i++){
    if(students[i].getName()==nameStudent)return i;
    
    }
  
  }


};
class Journal{
  Group* groups=nullptr;
  int counter=0;
  
   public:
  void addGroup(string nameGroup){
    int index=searchGroup(string nameGroup);
    if(index!=-1){
      Group* buf= new Group[counter+1];
      for(int i=0;i<counter;i++){
        buf[i]=groups[i];
        
        }
      buf[counter++]=Group(nameGroup);
      delete[] groups;
      groups=buf;
      
      }
    
    }
  int searchGroup(string nameGroup){
    for (int i=0;i<counter;i++;){
      if(nameGroup==groups[i]) return i;
      }
    return -1;
    
    }
  void addStudent(string nameStudent,string nameGroup){
    int index=searchGroup(nameGroup);
    if (index!=-1){
      groups[i].addStudent(nameStudent);
      
      
      }
      
      

    }
  
  
  
  
  
  };
int main()
{
    /* классный журнал
    интерфйес консольный
    фаилы хранятся в фаиле
    журнал позволяет выставлять оценки студентам
    получать инфу о конкретном классе 
    выбрать дисциплину
    подсчитать всем оценки за четверть
    исправить оценку 
    добавить оценку
    добавть группу(класс)


    ФАИЛ хранит класс, в классе дисциплины, в каждой дисциплине студенты 

    4 четверти 
    
    1 дисциплина 1 препод
    

    
    
    
    
    
    */
    




    //Painter painter("lolo");
    //int size[2] = { 23,23 };
    //Pic pic1 = painter.createPaint(new char[] {'b', 'g', 'g', 'l'},size);
    //pic1.showInfo();
    //Pic pic2;
    //pic2 = pic1;
    //pic2.showInfo();

    //Car car1("car1", new int[] { 1, 2, 3, 4, 5 });
    //Car car2 = car1;
    //Car car3;
    //car3 = car1;
    //Car car4 = returnCar("car4", new int[] { 1, 2, 3, 4, 5 });
    //car1.showInfo();

}

