
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
    Car(string name, int* nums) {
        cout << this << " created" << endl;
        delete[]sale;
        int size = _msize(nums) / sizeof(nums[0]);
        sale = new int[size];
        for (int i = 0; i < size; i++) {
            sale[i] = nums[i];
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
            cout << sale[i] << " ";
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
    char* colours = nullptr;
    int counter;
    int size[2] = { 0,0 };
public:
    Pic() {

    }
    Pic(char* newColours, int size[2]) {
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
    Pic createPaint(char* newColours, int size[2]) {
        Pic pic(newColours, size);
        return pic;
    }

};





class Student {
    int** uarterMark;

    int counter[4] = { 0,0,0,0 };
    string name;
public:
    Student() {

    }
    Student(string newName) {
        name = newName;
    }
    void addMark(int uarter, int mark) {
        int counterX = counter[uarter - 1];//ввел доп переменную чтобы не запутаться
        int* buf = new int[counterX + 1];
        for (int i = 0; i < counterX; i++) {
            buf[i] = uarterMark[counterX][i];
        }
        uarterMark[counter[uarter - 1]][counterX] = mark;
        counter[uarter - 1]++;
        delete[]uarterMark[counterX];
        uarterMark[counter[uarter - 1]] = buf;
    }
    bool showAllUarter() {
        for (int i = 0; i < 4; i++) {
            cout << "uarter " << i << endl;
            showUarter(i, 0);

        }
    }
    bool showUarter(int uarter, bool showIndex = 0) {
        if (counter[uarter - 1] == 0) return 0;
        if (showIndex != 0) {
            cout << "index|mark" << endl;
            for (int i = 0; i < counter[uarter - 1]; i++) {
                cout << i << "    |" << uarterMark[uarter - 1][i] << endl;

            }
            cout << endl;
        }
        else
            for (int i = 0; i < counter[uarter - 1]; i++) {
                cout << uarterMark[uarter - 1][i] << " ";

            }
        cout << endl;
        return 1;
    }
    void deleteMark(int index, int uarter) {
        if (index != -1) {
            int* buf = new int[counter[uarter - 1] - 1];
            for (int i = 0; i < index; i++) {
                buf[i] = uarterMark[uarter - 1][i];
            }
            for (int i = index + 1; i < counter[uarter - 1]; i++) {
                buf[i - 1] = uarterMark[uarter - 1][i];
            }
            counter[uarter - 1]--;
            delete[] uarterMark[uarter - 1];
            uarterMark[uarter - 1] = buf;
        }

    }

    void editMark(int uarter, int index, int newMark) {
        uarterMark[uarter - 1][index] = newMark;
    }
    string getName() {
        return name;
    }
    int getCounterUarter(int indexUarter) {
        return counter[indexUarter];
    }

};

class Group {
    string name;
    Student* students = nullptr;
    int counter = 0;

public:
    Group() {

    }
    Group(string nameGroup) {
        name = nameGroup;
    }
    void addStudent(string nameStudent) {

    }
    int searchStudent(string nameStudent) {
        for (int i = 0; i < counter; i++) {
            if (students[i].getName() == nameStudent)return i;

        }

    }
    string getName() {
        return name;
    }
    void showAll(bool showIndex = 0) {
        if (showIndex) {
            for (int i = 0; i < counter; i++) {
                cout << i << " | " << name << endl;
            }
        }
        else for (int i = 0; i < counter; i++) {
            cout << name << endl;
        }
    }
    int getCounter() {
        return counter;
    }
    void showAllUartersMarks(int indexStudent,bool showIndex=0) {
        students[indexStudent].showAllUarter();
    }
    void showUarterStudent(int indexStudent,int indexUarter int showIndex = 0) {
        students[indexStudent]->showUarter(indexUarter, 1);

    }
    int getCounterUarter(int indexStudent, int indexUarter) {
        return students[indexStunedt].getCounterUarter(indexUarter);
    }

};


class Journal {
    Group* groups = nullptr;
    int counter = 0;

public:
    bool addGroup(string nameGroup) {
        int index = searchGroup(nameGroup);
        if (index != -1) {
            Group* buf = new Group[counter + 1];
            for (int i = 0; i < counter; i++) {
                buf[i] = groups[i];

            }
            Group newGroup(nameGroup);
            buf[counter++] = Group(nameGroup);
            delete[] groups;
            groups = buf;
            return 1;
        }
        return 0;

    }
    int searchGroup(string nameGroup) {
        for (int i = 0; i < counter; i++) {
            if (nameGroup == groups[i].getName()) return i;
        }
        return -1;
    }
    bool addStudent(string nameStudent, string nameGroup) {
        int index = searchGroup(nameGroup);
        if (index != -1) {
            groups[index].addStudent(nameStudent);
            return 1;
        }
        return 0;
    }
    void showAllGroups(bool showIndex = 0) {
        if (showIndex) {
            for (int i = 0; i < counter; i++) {
                cout << groups[i].getName() << endl;
            }
        }
        else for (int i = 0; i < counter; i++) {
            cout << groups[i].getName() << endl;
        }
    }
    int getCounter() {
        return counter;
    }
    bool showStudentsInGroup(int indexGroup, bool showIndex = 0) {
        groups[indexGroup].showAll(showIndex);
    }
    int getCounterGroup(int index) {
        return groups[index].getCounter();
    }
    void showAllUartersMarks(int indexGroup, int indexStudent,bool showIndex=0) {
        groups[indexGroup].showAllUartersMarks(indexStudent);
    }
    void showAllMarksOneUarters(int indexGroup,int indexStudent) {




    }
    void showUarterMarksStudent(int indexGroup, int indexStudent, int indexUarter,int showIndex=0) {
        groups[indexGroup].showUarterStudent(indexStudent, indexUarter,showIndex);

    }
    int getCounterMarks(int indexStudent, int indexGroup, int indexUarter) {
        return groups[indexGroup].getCounterUarter(indexStudent, indexUarter);
    }

};

void showMainMenu(Journal& journal) {
    int choice;

    while (true) {
        // Отображение главного меню
        cout << "Главное меню:" << endl;
        cout << "1. Вывести все группы" << endl;
        cout << "2. Выбрать группу" << endl;
        cout << "3. Добавить группу" << endl;
        cout << "0. Выход" << endl;
        cout << "Введите номер пункта: ";
        cin >> choice;

        switch (choice) {
        case 1:
            journal.showAllGroups();
            break;
        case 2:
            selectGroupMenu(journal);
            break;
        case 3:
            addGroupMenu(journal);
            break;
        case 0:
            cout << "До свидания!" << endl;
            return;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
            break;
        }
    }
}


void selectActionsUarters(Journal& journal, int indexGroup,int indexStudent,int indexUarter) {
    while (true) {
        // Отображение меню действий со студентом
        cout << "Меню действий c кварталом:" << endl;
        cout << "1. Изменить оценку" << endl;
        cout << "2. Добавить оценку" << endl;
        cout << "3. Показать квартал" << endl;
        cout << "0. Выход" << endl;
        cout << "Введите номер пункта: ";
        cin >> choice;

        switch (choice) {
        case 1:
            journal.showUarterMarksStudent(int indexGroup, int indexStudent, int indexUarter)
            break;
        case 2:
            int numMarks;
            cout << "Введите номер оценки" << endl;
            cin >> numMarks;
            if (numMarks >= 1 && numMarks <= journal.getCounterMarks(indexStudent,indexGroup,indexGroup)) {
                selectActionsLocaleMenu(journal, indexGroup, indexStudent);

            }
            else if (Uarter == 0) {
                cout << "Выход из меню выбора квартала" << endl;
                return;
            }
            else {
                cout << "Некорректный номер квартала. Попробуйте снова." << endl;
            }
            break;
        case 3:
            journal.showUarterMarksStudent(int indexGroup, int indexStudent, int indexUarter);
        case 0:
            cout << "Выход из меню действий со студентом" << endl;
            return;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
            break;
        }
    }



}
// Меню управлени студентом
void selectActionsStudentMenu(Journal& journal, int indexGroup, int indexStudent) {
    int choice;

    while (true) {
        // Отображение меню действий со студентом
        cout << "Меню действий со студентом:" << endl;
        cout << "1. Вывести все кварталы с оценками" << endl;
        cout << "2. Выбрать квартал" << endl;
        cout << "0. Выход" << endl;
        cout << "Введите номер пункта: ";
        cin >> choice;

        switch (choice) {
        case 1:
            journal.showAllUartersMarks(indexGroup, indexStudent,0);
            break;
        case 2:
            int uarter;
            cout << "Введите номер квартала (от 1 до 4): ";
            cin >> uarter;
            if (Uarter >= 1 && Uarter <= 4) {
                selectActionsLocaleMenu(journal, indexGroup, indexStudent,uarter);



            }
            else if (Uarter == 0) {
                cout << "Выход из меню выбора квартала" << endl;
                return;
            }
            else {
                cout << "Некорректный номер квартала. Попробуйте снова." << endl;
            }
            break;
        case 0:
            cout << "Выход из меню действий со студентом" << endl;
            return;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
            break;
        }
    }
}
void selectGroupMenu(Journal& journal) {
    int choice;

    while (true) {
        // Отображение меню выбора группы
        cout << "Меню выбора группы:" << endl;
        cout << "0. Выход" << endl;

        // Отображение списка групп
        journal.showAllGroups(true);

        cout << "Введите номер группы: ";
        cin >> choice;
        choice--;
        if (choice == 0) {
            cout << "Выход из меню выбора группы" << endl;
            return;
        }

        if (journal.getCounter() > choice) {

        }
        else cout << "Группы с таким индексом не существует." << endl;

    }
}
void selectStudentMenu(Journal& journal, int indexGroup) {
    int choice;

    while (true) {
        // Отображение меню выбора студента
        cout << "Меню выбора студента:" << endl;
        cout << "0. Выход" << endl;

        // Отображение списка студентов в заданной группе
        journal.showStudentsInGroup(indexGroup);

        cout << "Введите номер студента: ";
        cin >> choice;
        choice--;
        if (choice == 0) {
            cout << "Выход из меню выбора студента" << endl;
            return;
        }

        if (journal.getCounterGroup(indexGroup) > choice) {
            selectActionsStudentMenu(journal, indexGroup, choice);
        }
        else cout << "Студента с таким индексом не существует." << endl;
    }
}
void selectStudentsMenu(Journal& journal, int indexGroup) {
    int choice;

    while (true) {
        // Отображение меню действий со студентами
        cout << "Меню действий со студентами:" << endl;
        cout << "1. Вывести список студентов" << endl;
        cout << "2. Выбрать студента" << endl;
        cout << "3. Удалить студента" << endl;
        cout << "0. Выход" << endl;
        cout << "Введите номер пункта: ";
        cin >> choice;

        switch (choice) {
        case 1:
            journal.showAllStudents(indexGroup);
            break;
        case 2:
            selectStudent(journal);
            break;
        case 3:
            deleteStudent(journal);
            break;
        case 0:
            cout << "Выход из меню действий со студентами" << endl;
            return;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
            break;
        }
    }
}




void addGroupMenu(Journal& journal) {
    int choice;

    while (true) {
        // Отображение меню добавления группы
        cout << "Меню добавления группы:" << endl;
        cout << "1. Ввести название группы" << endl;
        cout << "0. Выход" << endl;
        cout << "Введите номер пункта: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string newNameGroup;
            cout << "Введите название новой группы: ";
            cin >> newNameGroup;
            if (journal.addGroup(newNameGroup)) {
                cout << "Группа " << newNameGroup << " добавлена" << endl << endl;
            }
            else {
                cout << "Такая группа уже существует" << endl << endl;
            }
            break;
        }
        case 0:
            cout << "Выход из меню добавления группы" << endl;
            return;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
            break;
        }
    }
}

int main() {
    Journal journal;
    showMainMenu(journal);

    return 0;
}
//
//int main()
//{
//    /* классный журнал
//    интерфйес консольный
//    фаилы хранятся в фаиле
//    журнал позволяет выставлять оценки студентам
//    получать инфу о конкретном классе
//    выбрать дисциплину
//    подсчитать всем оценки за четверть
//    исправить оценку
//    добавить оценку
//    добавть группу(класс)
//
//
//    ФАИЛ хранит класс, в классе дисциплины, в каждой дисциплине студенты
//
//    4 четверти
//
//    1 дисциплина 1 препод
//
//
//
//
//
//
//
//    */
//
//
//
//
//
//    //Painter painter("lolo");
//    //int size[2] = { 23,23 };
//    //Pic pic1 = painter.createPaint(new char[] {'b', 'g', 'g', 'l'},size);
//    //pic1.showInfo();
//    //Pic pic2;
//    //pic2 = pic1;
//    //pic2.showInfo();
//
//    //Car car1("car1", new int[] { 1, 2, 3, 4, 5 });
//    //Car car2 = car1;
//    //Car car3;
//    //car3 = car1;
//    //Car car4 = returnCar("car4", new int[] { 1, 2, 3, 4, 5 });
//    //car1.showInfo();
//
//}
