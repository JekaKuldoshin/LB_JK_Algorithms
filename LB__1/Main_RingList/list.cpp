#include "list.h"

TList::~TList() {

    while (head != tail)                //Пока размерность списка не станет нулевой
    {
        Data* temp = head;
        head = head->next;          //Смена адреса следующего элемента
        delete temp;               //Освобождаем память от активного элемента
    }
    tail = head = NULL;
    size = 0;
}

int TList::Count() {                //Функ-я возвращающая число элементов
    return size; 
}

bool TList::check() {
    if (head == NULL) {
        system("cls");
        cout << "Ошибка! Список отсутствует!!!\n\nНажмите на Enter чтобы продолжить...";
        _getch();
        return false;
    }
    else
        return true;
}

void TList::Add(double d)
{
    size++;                        //При каждом добавлении элемента увеличиваем число элемента 
    Data* temp = new Data;        //Выделяем память для нового элемента списка
    temp->next = head;           //Замыкание контура. Последний элемент - это начало списка
    temp->data = d;             //Записываем в выделенную ячейку памяти значения data

    if (head != NULL)         //В том случае если списко не пустой
    {
        tail->next = temp;
        tail = temp;
    }
    else                   //Если списко пуст создаме первый элемент
    {
        head = tail = temp;
    }
}

void TList::create(int num) {
    int a = 1;
    double d;
    for (int i = 0; i < num; i++) {
        cout << "Введите данные для " << a++ << " ячейки (double)-> ";
        cin >> d;
        Add(d);
    }
    a = 0;
    system("cls");
}

void TList::show(int temp)
{

    Data* tempHead = head;
    temp = size;
    cout << "Данные списка -> ";
    while (temp != 0)
    {
        cout << tempHead->data << " ";
        tempHead = tempHead->next;
        temp--;
    }
    cout << "\n" << "\n";
}

short TList::number(int temp) {

    short number = 0;
    Data* tempHead = head;
    temp = size;
    while (temp != 0)
    {
        number++;
        tempHead = tempHead->next;
        temp--;
    }
    return number;
}

void TList::deleteFromList(int poz) {

    if (head != NULL) {
        Data* temp = tail;
        size--;
        for (int i = 1; i < poz; i++)//temp уже указывает на следующий элемент, поэтому количество итераций -1
            temp = temp->next;
        Data* buf = temp->next;
        if (buf == head) head = buf->next;
        if (buf == tail) tail = temp;
        temp->next = buf->next;
        delete buf;
        }

        system("cls");
        cout << "Успех!!\nУдаление элемента было выполнено!\n\nДля перехода в меню нажмите Enter..." << endl;
        _getch();
    }

void TList::change(int num) {
    


    if (num <= 0) {
        system("cls");
        cout << "Вы ввели число меньше нуля! Попробуйте ввести другое число!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
        _getch();
        goto link1;
    }
    if (num > number(Count())) {
        system("cls");
        cout << "Вы ввели число, больше чем задано в списке! Попробуйте ввести другое число!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
        _getch();
        goto link1;
    }
    if (num <= size && num > 0)
    {
        Data* temp1 = head;
        Data* temp2 = head;
        if (num == 1)
        {
            double a = head->data;
           head->data = head->next->data;
            head->next->data = a;
        }
        else if (num == size)
        {
            double a = head->data;
            head->data = tail->data;
            tail->data = a;
        }
        else
        {
            Data* tmp = head->next;
            for (int i = 2; i < size; i++)
            {
                if (num == i)
                {
                    double a = tmp->data;
                    tmp->data = tmp->next->data;
                    tmp->next->data = a;
                }
                tmp = tmp->next;
            }
        }
    }
    TList::show(size);
    _getch();
    system("cls");
    cout << "Успех! Данные списка были поменяны местами!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
    _getch();
link1:;
}

void TList::addition(TList& LIST) {

    Data* temp = LIST.head;

    for(int i = 0; i<LIST.Count();i++){
        this->Add(temp->data);
        if (temp->next != LIST.head)
        {
            temp = temp->next;
        }
    }
    LIST.~TList();
}

void TList::save() {
    Data* temp = head;

    fstream f("Data_List.txt", ios::out);
    if (!f.is_open())
        cout << "Ошибка! Файл не найден!";
    else {
        do {
            f << temp->data << '\t';
            temp = temp->next;
        } while (temp != head);
    }

}

void TList::in(double s) {
    Data* temp = new Data;
    temp->data = s;
    if (head)
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else
    {
        temp->prev = NULL;
        head = tail = temp;
    }
    size++;
}

void TList::form_the_file() {
    fstream f("Data_List.txt", ios::in);
    if (!f.is_open())
        cout << "Ошибка! Файл не найден!";
    else {
        double s;
        while (f >> s)
        {
            in(s);
        }
        f.close();

    }
}