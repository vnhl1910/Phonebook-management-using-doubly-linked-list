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
    contact *next, *prev;
    contact(char n[], char num[], char m[])
    {
        strcpy(name, n);
        strcpy(number, num);
        strcpy(mail, m);
        next = NULL;
        prev = NULL;
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
    void searchByName(char n[]);
    void searchByNumber(char nu[]);
    void searchByMail(char m[]);
    void deleteContact(char name[]);
    void updateContact(char n[]);
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
    char number[30];
    char mail[30];
    char ans;
    do
    {
        cout << "Nhap ten: ";
        cin >> name;
        cout << "Nhap so dien thoai: ";
        cin >> number;
        ptr = head;
        while (ptr != NULL)
        {
            if (strcmp(number, ptr->number) == 0)
                while ((strlen(number) != 10) || (strcmp(number, ptr->number) == 0))
                {
                    cout << "So dien thoai khong hop le hoac bi trung!!" << endl
                         << "Xin moi nhap lai so khac: ";
                    cin >> number;
                }
            ptr = ptr->next;
        }
        cout << "Nhap tai khoan mail: ";
        cin >> mail;
        ptr = head;
        while (ptr != NULL)
        {
            if (strcmp(mail, ptr->mail) == 0)
                while (strcmp(mail, ptr->mail) == 0)
                {
                    cout << "Mail bi trung!!" << endl
                         << "Xin moi nhap lai mail khac: ";
                    cin >> mail;
                }
            ptr = ptr->next;
        }
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
/*void contactList::searchContact()
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
    } while (ans < 4 && ans >= 1);
}
*/
// Tim danh ba theo ten
void contactList::searchByName(char n[])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(n, ptr->name) == 0)
        {
            cout << "Da tim thay thong tin: " << endl;
            cout << "Ten: " << ptr->name << endl;
            cout << "SDT: " << ptr->number << endl;
            cout << "Mail: " << ptr->mail << endl;
        }
        ptr = ptr->next;
    }
}
// Tim danh ba theo SDT
void contactList::searchByNumber(char nu[])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(nu, ptr->number) == 0)
        {
            cout << "Da tim thay thong tin: " << endl;
            cout << "Ten: " << ptr->name << endl;
            cout << "SDT: " << ptr->number << endl;
            cout << "Mail: " << ptr->mail << endl;
        }
        ptr = ptr->next;
    }
}
// Tim danh ba theo Mail
void contactList::searchByMail(char m[])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(m, ptr->mail) == 0)
        {
            cout << "Da tim thay thong tin: " << endl;
            cout << "Ten: " << ptr->name << endl;
            cout << "SDT: " << ptr->number << endl;
            cout << "Mail: " << ptr->mail << endl;
        }
        ptr = ptr->next;
    }
}
// Tim danh ba
void contactList::searchContact()
{
    int ans;
    cin >> ans;
    switch (ans)
    {
    case 1:
        char n[50];
        cin >> n;
        searchByName(n);
        break;
    case 2:
        char nu[12];
        cin >> nu;
        searchByMail(nu);
        break;
    case 3:
        char m[50];
        cin >> m;
        searchByMail(m);
        break;
    default:
        break;
    }
}

// Xoa lien he trong danh ba
void contactList::deleteContact(char s[50])
{
    int c = 0;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(s, ptr->name) == 0)
        {
            c = 1;
            break;
        }
        else
        {
            c = 2;
        }
        ptr = ptr->next;
    }
    if (ptr = head)
    {
        head = head->next;
        head->prev = NULL;
        delete (ptr);
    }
    else if (ptr->next == NULL)
    {
        ptr->prev->next = NULL;
        delete (ptr);
    }
    else if (ptr != head && ptr->next != NULL)
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete (ptr);
    }
}

// Cap nhat thong tin trong lien he
void contactList::updateContact(char n[])
{
    int c;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(n, ptr->name) == 0)
        {
            cin >> c;
            switch (c)
            {
            case 1:
                cin >> ptr->name;
                break;
            case 2:
                cin >> ptr->number;
                break;
            case 3:
                cin >> ptr->mail;
                break;
            default:
                break;
            }
        }
    }
}

void contactList::sortContact()
{
    contact *i, *j;
    int temp;
    char n[50];
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            temp = strcmp(i->name, j->name);
            if (temp > 0)
            {
                strcpy(n, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, n);
                strcpy(n, i->number);
                strcpy(i->number, j->number);
                strcpy(j->number, n);
                strcpy(n, i->mail);
                strcpy(i->mail, j->mail);
                strcpy(j->mail, n);
            }
        }
    }
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
            // phoneBook.sortContact();
            break;
        case 2:
            phoneBook.sortContact();
            phoneBook.displayContact();
            break;
        case 3:
            phoneBook.searchContact();
            break;
        case 4:
            cin >> name;
            phoneBook.deleteContact(name);
            break;
        case 5:
            cin >> name;
            phoneBook.updateContact(name);
            break;
        default:
            break;
        }
    } while (selectionInput != 9);
    return 0;
}