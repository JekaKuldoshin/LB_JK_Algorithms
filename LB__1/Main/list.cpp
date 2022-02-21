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
    int b;
    if (num <= (number() - 1) && num > 0)
		{
			Data* temp1 = head;
			Data* temp2 = head;
			for (int i = 1; i < a; i++)
			{
				if ((i == num) && (num < a))
				{
					double aa = temp1->data;
					temp1->data = temp1->next->data;
					temp1->next->data = aa;
				}
				temp1 = temp1->next;
			}
		}
    //Data* temp1 = head, * temp2 = head;

    //if (number() != num) {

    //    for (int i = 0; i < num - 1; ++i)
    //        temp1 = temp1->next;

    //    for (int i = 0; i < num; ++i)
    //        temp2 = temp2->next;
    //}
    //else {
    //    for (int i = 0; i < num; ++i)
    //        temp1 = temp1->next;

    //    for (int i = 0; i < num; ++i)
    //        temp2 = temp2->next;
    //}
    //if (temp1 == head && temp2 == tail) { // åñëè ñïèñîê èç äâóõ åëåìåíòîâ

    //    temp1->next = NULL;
    //    temp2->next = temp1;
    //    temp1->prev = temp2;
    //    temp2->prev = NULL;
    //    head = temp2;
    //    tail = temp1;
    //    return;

    //}
    ////if (temp1 == tail && temp2 == head) { // åñëè ñïèñîê èç äâóõ åëåìåíòîâ

    ////    temp2->next = NULL;
    ////    temp1->next = temp2;
    ////    temp2->prev = temp1;
    ////    temp1->prev = NULL;
    ////    head = temp1;
    ////    tail = temp2;
    ////    return;

    ////}

    //if (temp1->prev == NULL) { // åñëè äâà ïåðâûõ åëåìåíòà

    //    temp2->next->prev = temp1;

    //    temp1->next = temp2->next;
    //    temp2->next = temp1;
    //    temp1->prev = temp2;
    //    temp2->prev = NULL;
    //    head = temp2;
    //    return;
    //}

    //if (temp2->next == NULL) { // åñëè äâà ïîñëåäíèõ åëåìåíòà
    //    temp1->prev->next = temp2;

    //    temp2->prev = temp1->prev;
    //    temp2->next = temp1;
    //    temp1->prev = temp2;
    //    temp1->next = NULL;
    //    tail = temp1;

    //    return;
    }

    /*else {
        temp1->prev->next = temp2;
        temp2->next->prev = temp1;

        temp1->next = temp2->next;
        temp2->next = temp1;

        temp2->prev = temp1->prev;
        temp1->prev = temp2;

        return;
    }*/

