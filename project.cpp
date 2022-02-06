#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
void swap2();
int getmax2(int s);
string product[10] = {"", "", "", "", "", "", "", "", "", ""};
string name[10] = {"", "", "", "", "", "", "", "", "", ""};
string gender[10] = {"", "", "", "", "", "", "", "", "", ""};
string city[10] = {"", "", "", "", "", "", "", "", "", ""};
string salary2[10] = {"  ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
string price2[10] = {"  ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
string p2[10] = {"  ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
int salary[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int price[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int p[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int employeecount = 0;
int productcount = 0;
void swap();
int convert(string n);
void store();
void load();
int totalprice();
void salaryalt(string, char, int);
int getmax(int);
string parserecord(string, int);
void mainmenu();
void mainmenu2();
void mainmenu3();
void listpreview();
int addprice();
string addproduct();
string removeproduct();
void emplist();
string addemployeename();
string addemployeecity();
string addemployeegender();
int addemployeesaalry();
void attendance(string, char);
string removeemployee();
int main()
{
    load();
    string r;
    int b;
    int a;

    while (a < 3)
    {
        mainmenu();
        cout << "enter ur option ";
        cin >> a;
        system("cls");
        if (a == 1)
        {

            string pass = "";

            while (pass != "123")
            {
                cout << "enter ur password ";
                cin >> pass;
                system("cls");
            }
            int b = 0;
            while (b < 11)
            {
                mainmenu2();
                cout << "enter ur option ";
                cin >> b;
                system("cls");
                if (b == 1)
                {
                    listpreview();
                    cout << endl
                         << endl
                         << "recomendataion:2.Price of products " << endl;
                }
                else if (b == 2)
                {

                    cout << "PRODUCT"
                         << "\t\t"
                         << "PRICE" << endl;
                    for (int a = 0; a < 10; a++)
                    {
                        if (price[a] != 0)
                            cout << product[a] << "\t\t" << price[a] << endl;
                    }
                    cout << endl
                         << endl
                         << "recomendataion:3.add an product " << endl;
                }
                else if (b == 3)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        if (product[i] == "")
                        {
                            product[i] = addproduct();
                            price[i] = addprice();
                            store();
                            break;
                        }
                    }
                    cout << endl
                         << endl
                         << "recomendataion:2.price of product " << endl;
                }
                else if (b == 4)
                {
                    r = removeproduct();
                    for (int i = 0; i < 10; i++)
                    {
                        if (r == product[i])
                        {
                            product[i] = "";
                            price[i] = 0;
                            break;
                        }
                    }
                    cout << endl
                         << endl
                         << "recomendataion:2.price of product " << endl;
                }
                else if (b == 5)
                {
                    emplist();
                    cout << endl
                         << endl
                         << "recomendataion:6.add an employee " << endl;
                }
                else if (b == 6)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        if (name[i] == "")
                        {
                            name[i] = addemployeename();
                            gender[i] = addemployeegender();
                            city[i] = addemployeecity();
                            salary[i] = addemployeesaalry();
                            break;
                        }
                    }
                    cout << endl
                         << endl
                         << "recomendataion:5 view employee list " << endl;
                }
                else if (b == 7)
                {
                    string h = removeemployee();
                    for (int i = 0; i < 10; i++)
                    {
                        if (h == name[i])
                        {
                            name[i] = " ";
                            salary[i] = 0;
                            gender[i] = " ";
                            city[i] = " ";

                            break;
                        }
                    }
                    cout << endl
                         << endl
                         << "recomendataion:5. view employee list " << endl;
                }
                else if (b == 8)
                {
                    string names;
                    cout << "which employee is marking attendance ";
                    cin >> names;
                    char d;
                    cout << "enter A/a for absent or p/P FOR present ";
                    cin >> d;
                    attendance(names, d);
                    cout << endl
                         << endl
                         << "recomendataion: 10 view employee in sorted order " << endl;
                }
                else if (b == 9)
                {
                    string lo;
                    cout << "enter the name of employee ";
                    cin >> lo;
                    char z;
                    cout << "enter (d/D) for dedtuction n (i/I) for increase ";
                    cin >> z;
                    int y;
                    cout << "enter how much you wanna deduct or add ";
                    cin >> y;
                    salaryalt(lo, z, y);
                    cout << endl
                         << endl
                         << "recomendataion:12 exit " << endl;
                }
                else if (b == 10)
                {
                    swap();

                    emplist();
                    cout << endl
                         << endl
                         << "recomendataion:11 exit " << endl;
                }
            }
        }
        else if (a == 2)
        {
            int B = 0;
            while (B < 5)
            {
                mainmenu3();
                cout << "enter your option ";
                cin >> B;
                system("cls");
                if (B == 1)
                {
                    listpreview();
                    cout << endl
                         << endl
                         << "recomendataion:4 buy goods and bill " << endl;
                }
                else if (B == 2)
                {
                    cout << "PRODUCT"
                         << "\t\t"
                         << "PRICE" << endl;
                    for (int a = 0; a < 10; a++)
                    {
                        if (price[a] != 0)
                            cout << product[a] << "\t\t" << price[a] << endl;
                    }
                    cout << endl
                         << endl
                         << "recomendataion:4 buy goods and bill " << endl;
                }
                else if (B == 3)
                {
                    swap2();
                    cout << "PRODUCT"
                         << "\t\t"
                         << "PRICE" << endl;
                    for (int a = 0; a < 10; a++)
                    {
                        if (price[a] != 0)
                            cout << product[a] << "\t\t" << price[a] << endl;
                    }
                    cout << endl
                         << endl
                         << "recomendataion:4 buy goods and bill " << endl;
                }
                else if (B == 4)
                {

                    int sum2, payable, rest;
                    sum2 = totalprice();
                    store();
                    cout << "total price is " << sum2 << endl;
                    cout << "enter how much money you have give";
                    cin >> payable; // money that user gives to cashier
                    if (payable > sum2)
                    {
                        rest = payable - sum2;
                        cout << "rest money is " << rest << endl;
                        cout << "thanks for shopping" << endl;
                    }
                    else
                    {
                        cout << "thanks for shopping" << endl;
                    }
                    cout << endl
                         << endl
                         << "recomendataion:5.exit" << endl;
                }
            }
        }
    }
    cout << "The program as ended .... have a great day!";
    store();
}
string parserecord(string record, int field) // to separate entities in file
{
    string item;
    int commacount = 0;
    for (int i = 0; i < record.length(); i++)
    {
        if (record[i] == ',')
        {
            commacount++;
        }
        else if (commacount == field)
        {
            item = item + record[i];
        }
    }
    // cout << "Item: " << item << endl;
    return item;
}
void store() // to store values in file
{
    fstream file;
    file.open("p4.txt", ios::out);
    for (int i = 0; i < 10; i++)
    {
        file << product[i];
        file << ",";
        file << price[i];
        file << ",";
        file << name[i];
        file << ",";
        file << gender[i];
        file << ",";
        file << city[i];
        file << ",";
        file << salary[i];
        file << ",";
        file << p[i];
        file << endl;
    }
    file.close();
}
void load() // to load values from fil into arrays
{
    // string employee2, product2;
    string tmp, tmp2;
    string word;
    fstream file;
    file.open("p4.txt", ios::in);
    int i = 0;
    while (!file.eof())
    {

        getline(file, word);

        product[i] = parserecord(word, 0);
        tmp = parserecord(word, 1);
        price[i] = convert(tmp);
        tmp2 = parserecord(word, 2);
        name[i] = tmp2;
        tmp2 = parserecord(word, 3);
        gender[i] = tmp2;
        tmp2 = parserecord(word, 4);
        city[i] = tmp2;
        tmp = parserecord(word, 5);
        salary[i] = convert(tmp);
        tmp = parserecord(word, 6);
        p[i] = convert(tmp);
        i++;
    }

    file.close();
}
int getmax(int s) // to get the most maximum index in array salary
{
    int large = -1;
    int largestindex;
    for (int i = s; i < 10; i++)
    {
        if (large < salary[i])
        {
            large = salary[i];
            largestindex = i;
        }
    }
    return largestindex;
}
void mainmenu3() // menu of user
{
    cout << "*********************************************************************" << endl;
    cout << "*             DEPARTMENTAL STORE MANAGEMENTS SYSTEM                 *" << endl;
    cout << "*********************************************************************" << endl;
    cout << "1.List of available Products" << endl;
    cout << "2.list of available products'price" << endl;
    cout << "3.list of available products'price in sorted order" << endl;
    cout << "4.Billing facility" << endl;
    cout << "5.To exit" << endl;
}
void mainmenu() // main menu
{
    cout << "*********************************************************************" << endl;
    cout << "*             DEPARTMENTAL STORE MANAGEMENTS SYSTEM                 *" << endl;
    cout << "*********************************************************************" << endl;
    cout << " Which is using system" << endl;
    cout << "1.Admin" << endl;
    cout << "2.Costumer" << endl;
    cout << "3.To exit" << endl;
}
void mainmenu2() // menu of admin
{
    cout << "*********************************************************************" << endl;
    cout << "*             DEPARTMENTAL STORE MANAGEMENTS SYSTEM                 *" << endl;
    cout << "*********************************************************************" << endl;
    cout << "choose option as an admin" << endl;
    cout << "1.list of products" << endl;
    cout << "2.Price of products" << endl;
    cout << "3.Add a new product" << endl;
    cout << "4.Remove a product" << endl;
    cout << "5.list of employees" << endl;
    cout << "6.Add a new employee" << endl;
    cout << "7.Remove an employee" << endl;
    cout << "8.Attendace of employees" << endl;
    cout << "9.deduct or increament in salaries of employees" << endl;
    cout << "10.employees sorted according to their salaries" << endl;
    cout << "11.To exit" << endl;
}
void listpreview() // to see the available stock
{
    for (int idx = 0; idx < 10; idx++)
    {
        cout << product[idx] << endl;
    }
}
int addprice() // to add price of new product
{
    int a;
    cout << "enter the price of new product ";
    cin >> a;
    return a;
}
string addproduct() // to add new product
{
    string a;
    cout << "enter the name of product ";
    cin >> a;
    return a;
}
string removeproduct() // to remove an old profuct
{
    string r;
    cout << "which product u wanna remove ";
    cin >> r;
    return r;
}
void emplist() // employees list show;
{
    cout << "NAME"
         << "\t"
         << "GENDER"
         << "\t"
         << "CITY"
         << "\t"
         << "salary" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (salary[i] != 0)
        {
            cout << name[i] << "\t" << gender[i] << "\t" << city[i] << "\t" << salary[i] << endl;
        }
    }
}
string addemployeename() // to add employee name
{
    string name;
    cout << "enter the name of employee ";
    cin >> name;
    employeecount++;
    return name;
}
string addemployeegender() // to an add employee gender
{
    string gender;
    cout << "enter the gender of employee ";
    cin >> gender;
    return gender;
}
string addemployeecity() // to add an  employee city
{
    string city;
    cout << "enter the city in which u live ";
    cin >> city;
    return city;
}
int addemployeesaalry() // to add an employee salary
{
    int sal;
    cout << "enter the salary of employee ";
    cin >> sal;
    return sal;
}
string removeemployee() // to remove an employee
{
    string c;
    cout << "enter the name of employee you want to remove ";
    cin >> c;
    employeecount--;
    return c;
}
void attendance(string names, char d) // to mark attendance
{

    for (int i = 0; i < 10; i++)
    {
        if (names == name[i])
        {
            if (d == 'a' || d == 'A')
            {
                cout << names << " is absent" << endl;
            }
            else if (d == 'p' || d == 'P')
            {
                cout << names << " is present" << endl;
            }
        }
    }
}
void salaryalt(string p, char z, int y) // to change the salary of an employee
{
    for (int i = 0; i < 10; i++)
    {
        if (p == name[i])
        {
            if (z == 'd' || z == 'D')
            {
                salary[i] = salary[i] - y;
            }
            else if (z == 'i' || z == 'I')
            {
                salary[i] = salary[i] + y;
            }
            break;
        }
    }
}
int totalprice() // total bill of an coustmer
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        if (product[i] != "")
        {
            cout << "enter how much u wanna buy " << product[i] << endl;
            cin >> p[i];
        }
    }
    for (int i = 0; i < 10; i++)
    {
        sum = sum + (price[i] * p[i]);
    }
    return sum;
}
void swap() // to swap between employees
{
    string r;
    int largeindex;
    int temp;
    for (int i = 0; i < 10; i++)
    {
        largeindex = getmax(i); // swapping of salaries
        temp = salary[largeindex];
        salary[largeindex] = salary[i];
        salary[i] = temp;

        r = name[largeindex]; // swaping of names
        name[largeindex] = name[i];
        name[i] = r;

        r = gender[largeindex]; // swaping of genders
        gender[largeindex] = gender[i];
        gender[i] = r;

        r = city[largeindex]; // swaping of cities
        city[largeindex] = city[i];
        city[i] = r;
    }
}
void swap2() // swaping of products
{
    string r;
    int largeindex;
    int temp;
    for (int i = 0; i < 10; i++)
    {
        largeindex = getmax2(i);

        temp = price[largeindex]; // swaping of prices
        price[largeindex] = price[i];
        price[i] = temp;

        r = product[largeindex]; // swaping of products names
        product[largeindex] = product[i];
        product[i] = r;
    }
}
int convert(string n) // to convert a string into integer if its interger

{
    if (n == "0")
    {
        return 0;
    }
    float num = 0;
    int x;
    for (int i = 0; i < n.length(); i++)
    {
        x = (n[n.length() - i - 1]) - 48;
        num = num + x * pow(10, i);
    }
    return num;
}
int getmax2(int s) // to get the most maximum index in array
{
    int large = -1;
    int largestindex;
    for (int i = s; i < 10; i++)
    {
        if (large < price[i])
        {
            large = price[i];
            largestindex = i;
        }
    }
    return largestindex;
}
