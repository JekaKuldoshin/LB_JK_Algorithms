#include "list.h"

TList::~TList() {              //\\//\\ КпоУ //\\//\\

    while (head)
    {
        tail = head->next;    //Смена адреса следующего элемента
        delete head;         //Освобождаем память от активного элемента
        head = tail;
    }
}

bool TList::check() {        //\\//\\ Функ-я проверки на наличие элементов списка //\\//\\ 
    if (head == NULL) {
        system("cls");
        cout << "Ошибка! Список отсутствует!!!\n\nНажмите на Enter чтобы продолжить...";
        _getch();
        return false;
    }
    else
        return true;     //Если возврашает True, то мы можем пользоваться всем функционалом программы
}

void TList::Add(double d)     //\\//\\ Функ-я для добавления данных в конец списка //\\//\\ 
{
    Data* temp = new Data;       //Выделяем память для нового элемента списка
    temp->next = NULL;          //
    temp->data = d;            //Записываем в выделенную ячейку памяти значения data
     
    if (head != NULL)        //В том случае если список не пустой
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else                 //Если список пуст создаем первый элемент
    {
        temp->prev = NULL;
        head = tail = temp;
    }
}

void TList::create(int num) {       //\\//\\ Функ-я для создания списка //\\//\\ 
    int a = 1;     //Счеткик элементов
    double d;     //Переменная для ввода
    for (int i = 0; i < num; i++) {
        cout << "Введите данные для "<<a++<<" ячейки -> ";
        cin >> d;
        Add(d);    //Переход в функ-ю добавления элементов в конец списка
    }
    a = 0;
    system("cls");
}

void TList::show()                 //\\//\\ Функ-я вывода //\\//\\ 
{
        Data* temp = head;
        cout << "Данные списка -> ";
        while (temp != NULL)               //Пока не дойдем до конца
        {
            cout << temp->data << " ";   //Выводим данные через пробел
            temp = temp->next;          //Смена адреса следующего элемента
        }
        cout << "\n" << "\n";
}

short TList::number() {            //\\//\\ Функ-я для нахождения кол-ва элементов списка //\\//\\
    
        short number = 0;               //Переменная для подсчета кол-ва
        Data* tempH = head;            //Ставим на начало

        while (tempH)                //Цикл пока не дойдем до конца
        {
            number++;              //Счетчик для подсчета кол-ва элементов списка
            tempH = tempH->next;  //Смена адреса следующего элемента
        }
        return number;
    }

 
void TList::deleteFromList(int poz) {       //\\//\\ Функ-я удаления //\\//\\
   
        if (head != NULL) {                  //Если список не пуст
            if (poz == 1 && head->next) {   //Расматриваем если первая позиция
                Data* temp = head;         //temp на начало
                head = head->next;        //Смена адреса следующего элемента
                head->prev = NULL;       //А прошлый удаляем
                return;

            }
            else if ((poz == 1) && (head == tail)) {  //Если первая и позиция последняя

                head->next = NULL;        
                head = NULL;
                delete head;            //После всех сдигов удаляем начало
                return;

            }
            if (poz == number()) {
                Data* temp = tail;       //Поставили на конец
                tail = tail->prev;      //Переход на прошлый элемент
                tail->next = NULL;     //Удаляем
                return;
            }

            Data* temp = head, * temp2;     //Поставили на начало, а вторая для обмена

            for (int i = 0; i < poz - 1; ++i)
                temp = temp->next;              //Смена адреса следующего элемента
            temp2 = temp;                      //Присваивание
            temp2->prev->next = temp->next;
            temp2->next->prev = temp->prev;

        }

        system("cls");
        cout << "Успех!!\nУдаление элемента было выполнено!\n\nДля перехода в меню нажмите Enter..." << endl;
        _getch();
    }

    void TList::change(int num) {       //\\//\\ Смена соседних значений //\\//\\ 
        int a = number();


        if (num <= 0) {         //Проверка на ввод
            system("cls");
            cout << "Вы ввели число меньше нуля! Попробуйте ввести другое число!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
            _getch();
            goto link1;
        }
        if (num > number()) {
            system("cls");
            cout << "Вы ввели число, больше чем задано в списке! Попробуйте ввести другое число!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
            _getch();
            goto link1;
        }
        if (num <= number() && num > 0)      //Проверка на ввод
        {
            Data* temp1 = head;                 //Переменная поставлена на начало
            Data* temp2 = temp1->next;         //Переменная с переходом на следующий элемент
            if (num == 1)                     //Если выбрана позиция на первый элемент
            {
                temp1 = head->next;                   //Смещаем на одну позицию вперед
                head->next = head->next->next;       //Смещаем на одну позицию вперед
                head->next->prev = head;
                temp1->next = head;
                head->prev = temp1;
                head = temp1;
            }
            else if (num == number())
            {
                temp1 = head; temp2 = tail;
                temp2->next = temp1->next;
                temp1->next->prev = temp2;
                temp2->prev->next = temp1;
                temp1->prev = temp2->prev;
                head = temp2;
                head->prev = NULL;
                tail = temp1;
                tail->next = NULL;
            }
            else
            {
                for (int i = 1; i < number(); i++)
                {
                    if (i == num)
                    {
                        if (temp1->next == tail)
                        {
                            tail->prev = temp1->prev;
                            temp1->prev->next = tail;
                            tail->next = temp1;
                            temp1->prev = tail;
                            temp1->next = NULL;
                            tail = temp1;

                        }
                        else
                        {
                            temp1->prev->next = temp2;
                            temp2->prev = temp1->prev;
                            temp2->next->prev = temp1;
                            temp1->next = temp2->next;
                            temp1->prev = temp2;
                            temp2->next = temp1;
                        }
                    }
                    temp1 = temp1->next;
                }
            }
        }
        TList::show();
        _getch();
        system("cls");
        cout << "Успех! Данные списка были поменяны местами!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
        _getch();
    link1:;
    }

    void TList::addition(TList& LIST) {      //\\//\\ Функ-я обьединения двух списков //\\//\\ 

        Data* temp = LIST.head;        //Создали переменную для работы с вторым списком, поставили на начало

        while (temp) {                  //Исходя из размера списка будет работать цикл
            this->Add(temp->data);     //Заходим в функ-ю доб. в конец и передаем значения списка №2
            temp = temp->next;        //Шаг вперед

        }
        LIST.~TList();             //КпУ список №2, обнулили
    } 

    void TList::save() {            //\\//\\ Функ-я сохранения в файл //\\//\\ 
        Data* temp = head;     //Поставили на начало

        fstream f("Data_List.txt", ios::out);        //Создали переменную для работы с файлом, создали файл.
        if (!f.is_open())                           //Проверка на открытие файла
            cout << "Ошибка! Файл не найден!";
        else {
            while (temp) {                       //Цикл пока не дойдем до конца
                f << temp->data << '\t';        //Запись данных списка в файл
                temp = temp->next;             //Шаг вперед
            }
        }

    }

    void TList::in(double s) {         //\\//\\ Функ-я для работы  с чтением с файла //\\//\\ 
        Data* temp = new Data;      //Выделяем память для нового элемента списка
        temp->next = NULL;         //Первый элемент пуст
        temp->data = s;           //Переносим с переменной файла в переменную класса 
        if (head)                //Если это первый элемент
        {
            temp->prev = tail;
            tail->next = temp;     //Переход к следующему 
            tail = temp;          //Подставили данные
        }
        else
        {
            temp->prev = NULL;
            head = tail = temp;
        }
        
    }

    void TList::form_the_file() {                   //\\//\\ Функ-я чтения с файла //\\//\\ 
        fstream f("Data_List.txt", ios::in);   //Переменная для работы с файлом, открыли файл
        if (!f.is_open())                     //Проверка на открытие файла
            cout << "Ошибка! Файл не найден!";
        else {
            double s;                       //Переменная для заполнения с файла
            while (f >> s)                 //Ввод
            {
                in(s);                   //Вход в функцию
            }
            f.close();                 //Закрыли файл

        }
    }