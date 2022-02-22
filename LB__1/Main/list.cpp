#include "list.h"

TList::~TList() {

    while (head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
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
    Data* temp = new Data;
    temp->next = NULL;
    temp->data = d;

    if (head != NULL)
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
}

void TList::create(int num) {
    int a = 1;
    double d;
    for (int i = 0; i < num; i++) {
        cout << "Введите данные для "<<a++<<" ячейки -> ";
        cin >> d;
        Add(d);
    }
    a = 0;
    system("cls");
}

void TList::show()
{
   
        Data* temp = head;
        cout << "Данные списка -> ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n" << "\n";
    

    /* temp = tail;
     while (temp != NULL)
     {
         cout << temp->data << " ";
         temp = temp->prev;
     }
     cout << "\n";*/
}

short TList::number() {
    
        short number = 0;
        Data* tempH = head;

        while (tempH)
        {
            number++;
            tempH = tempH->next;
        }
        return number;
    }


void TList::deleteFromList(int poz) {
   
        if (head != NULL) {
            if (poz == 1 && head->next) {
                Data* temp = head;
                head = head->next;
                head->prev = NULL;
                return;

            }
            else if ((poz == 1) && (head == tail)) {

                head->next = NULL;
                head = NULL;
                delete head;
                return;

            }
            if (poz == number()) {
                Data* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                return;
            }

            Data* temp = head, * temp2;

            for (int i = 0; i < poz - 1; ++i)
                temp = temp->next;
            temp2 = temp;
            temp2->prev->next = temp->next;
            temp2->next->prev = temp->prev;

        }

        system("cls");
        cout << "Успех!!\nУдаление элемента было выполнено!\n\nДля перехода в меню нажмите Enter..." << endl;
        _getch();
    }

    void TList::change(int num) {
        int a = number();


        if (num <= 0) {
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
        if (num <= number() && num > 0)
        {
            Data* temp1 = head;
            Data* temp2 = temp1->next;
            if (num == 1)
            {
                temp1 = head->next;
                head->next = head->next->next;
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

    void TList::addition(TList& LIST) {

        Data* temp = LIST.head;

        while (temp) {
            this->Add(temp->data);
            temp = temp->next;

        }
        LIST.~TList();
    }

    void TList::save() {
        Data* temp = head;

        fstream f("Data_List.txt", ios::out);
        if (!f.is_open())
            cout << "Ошибка! Файл не найден!";
        else {
            while (temp) {
                f << temp->data << '\t';
                temp = temp->next;
            }
        }

    }

    void TList::in(double s) {
        Data* temp = new Data;
        temp->next = NULL;
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