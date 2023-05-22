#include <iostream>
#include <cstring>

using namespace std;

/*
1. Khoi tao Node contact
2. Khoi tao danh sach Contact List (kep)
3. Cac ham thuc hien cong viec
A. Add contact
B. Display contact
C. Search contact
D. Delete contact
E. Update contact
*/

// Khoi tao Node Contact
class contact
{
public:
    char name[50];
    char number[12];
    char mail[30];
    contact *prev, *next;
    contact(char n[], char num[], char m[])
    {
        strcpy(name, n);
        strcpy(number, num);
        strcpy(mail, m);
        prev = NULL;
        next = NULL;
    };

    friend class contactList;
};

// Khoi tao danh sach Contact List
class contactList
{
public:
    contact *head, *temp, *ptr;

    void addContact();
    void displayContact();
    void searchContact();
    void deleteContact(char name[]);
    void updateContact(char name[]);
    void sortContact();

    contactList()
    {
        head = NULL;
        temp = NULL;
        ptr = NULL;
    }
};

// A. Add contact
void contactList::addContact()
{
    char name[50];
    char number[12];
    char mail[30];
    char ans;
    do
    {
        cout << "Nhap ten: ";
        cin >> name;
        cout << "Nhap so dien thoai: ";
        cin >> number;
        while (strlen(number) != 10)
        {
            cout << "So dien thoai khong hop le!!" << endl
                 << "Xin moi nhap lai so khac: ";
            cin >> number;
        }
        cout << "Nhap tai khoan mail: ";
        cin >> mail;
        temp = new contact(name, number, mail);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        }
        cout << "Ban co muon tiep tuc khong? (y/n): " << endl;
        cin >> ans;
    } while (ans == 'y');
}

// B. Display contact
void contactList::displayContact()
{
    ptr = head;
    while (ptr != NULL)
    {
        cout << "Ten: " << ptr->name << endl;
        cout << "SDT: " << ptr->number << endl;
        cout << "Mail: " << ptr->mail << endl;
        cout << endl;
        ptr = ptr->next;
    }
}

// C. Search contact
void contactList::searchContact()
{
    int ans;
    do
    {
        cout << "[1]: Tim theo ten" << endl;
        cout << "[2]: Tim theo so dien thoai" << endl;
        cout << "[3]: Tim theo mail" << endl;
        cout << "[4]: Ket thuc tim kiem" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> ans;
        switch (ans)
        {
        case 1:
            cout << "Nhap ten: ";
            char name[50];
            cin >> name;
            ptr = head;
            while (ptr != NULL)
            {
                if (strcmp(name, ptr->name) == 0)
                {
                    cout << "Found!" << endl;
                    cout << ptr->name << endl
                         << ptr->number << endl
                         << ptr->mail;
                    break;
                }
                ptr = ptr->next;
            }
            cout << "Khong tim thay danh ba" << endl;
            break;
        case 2:
            cout << "Nhap so ";
            char num[12];
            cin >> num;
            ptr = head;
            while (ptr != NULL)
            {
                if (strcmp(num, ptr->number) == 0)
                {
                    cout << "Found!" << endl;
                    cout << ptr->name << endl
                         << ptr->number << endl
                         << ptr->mail;
                    break;
                }
                ptr = ptr->next;
            }
            cout << "Khong tim thay danh ba" << endl;
            break;
        case 3:
            cout << "Nhap mail: ";
            char mail[50];
            cin >> mail;
            ptr = head;
            while (ptr != NULL)
            {
                if (strcmp(mail, ptr->mail) == 0)
                {
                    cout << "Found!" << endl;
                    cout << ptr->name << endl
                         << ptr->number << endl
                         << ptr->mail;
                    break;
                }
                ptr = ptr->next;
            }
            cout << "Khong tim thay danh ba" << endl;
            break;
        case 4:
            break;
        default:
            cout << "So ban nhap khong hop le. Xin vui long nhap lai: ";
            cin >> ans;
            break;
        }
    }while(ans < 4 && ans >= 1);
}


// Phan main
int main()
{
    char name[50];
    char number[12];
    char mail[30];
    contactList phoneBook;
    int selectionInput = 9;
    do
    {
        cout << "----------- Danh ba -------------" << endl;
        cout << "[1]: Nhap danh ba" << endl;
        cout << "[2]: Hien thi danh ba" << endl;
        cout << "[3]: Tim kiem danh ba" << endl;
        cout << "[9]: Exit" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> selectionInput;
        switch (selectionInput)
        {
        case 1:
            phoneBook.addContact();
            break;
        case 2:
            phoneBook.displayContact();
            break;
        case 3:
            phoneBook.searchContact();
            break;
        default:
            break;
        }
    } while (selectionInput != 9);
    return 0;
}