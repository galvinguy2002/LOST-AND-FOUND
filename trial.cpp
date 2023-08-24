// sample testing code file!! THIS IS NOT THE ACTUAL WORKING CODE.
// IT IS PRESENT IN "final.cpp"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
class school
{
    char item[30];
    char colour[10];
    int modelno;

public:
    void found()
    {
        cout << "\nEnter the name of the lost item that you have found!\n";
        gets(item);
        cout << "\nEnter the colour of the item please.\n";
        gets(colour);
        cout << "\nEnter the model number of the item please.\n";
        cin >> modelno;
        cout << "\n\t\t\t Thankyou for showing your honesty and depositing the lost item. We appreciate your sincere effort";
    }
    school()
    {
        strcpy(item, "\0");
        strcpy(colour, "\0");
        modelno = 0;
    }
    char *getitem()
    {
        return item;
    }
    char *getcolour()
    {
        return colour;
    }
    int getmodelno()
    {
        return modelno;
    }
    void reset()
    {
        strcpy(item, "\0");
        strcpy(colour, "\0");
        modelno = 0;
    }
    void lost();
    void display()
    {
        cout << item << colour << modelno;
    }
} try[5];

void title()
{
    for (int i = 0; i < 80; i++)
        cout << "-";
    cout << "\n\t\t\t WELCOME TO THE \n\t\t\t LOST AND FOUND DEPARTMENT FOR STUDENTS.\n";
    for (int i = 0; i < 80; i++)
        cout << "-";
    cout << endl;
}

void main()
{
    //clrscr();
    int choice, i, n, m;
    char ch;
    char it[30];
    char c[10];
    char ab[30];
    char cd[10];
    int mo;
    int x, s;
    ifstream fin;
    ofstream fout;
    do
    {
        title();
        cout << "1.ITEM FOUND" << endl;
        cout << "2.ITEM LOST" << endl;
        cout << "3.EXIT" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            fout.open("project.dat", ios::binary);
            if (!fout)
            {
                cout << "error";
                return;
            }
            cout << "\nEnter the no.of items found.\n";
            cin >> n;
            for (i = 0; i < n; i++)
            {
                try[i].found();
                fout.write((char *)&try, sizeof(try));
            }
            fout.close();
            break;
        case 2:
            fin.open("project.dat", ios::binary);
            if (!fin)
            {
                cout << "error";
                return;
            }
            cout << "\n Enter the no.of items you have lost\n";
            cin >> s;
            for (i = 0; i < s; i++)
            {
                cout << "\nENTER THE NAME OF ITEM U HAVE LOST\n";
                gets(ab);
                cout << "\n enter the colour of item please\n";
                gets(cd);
                cout << "\n enter the code of the item u have lost\n";
                cin >> mo;
                while (fin)
                    for (int k = 0; k < 10; k++)
                    {
                        fin.read((char *)&try[k], sizeof(try));
                        strcpy(it, try[k].getitem());
                        strcpy(c, try[k].getcolour());
                        if (it == ab && c == cd && try[k].getmodelno() == mo)
                        {
                            cout << "\n we have your lost item";
                            break;
                        }
                    }
            }
            break;
        case 3:
            return;
        default:
            cout << "/n WRONG CHOICE";
        }
        cout << "\n DO YOU WANT TO CONTINUE(Y/N)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    getch();
}
