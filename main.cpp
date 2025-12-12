#include<iostream>

#define Criminal_List_Size 100
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int = 0, int = 0, int = 0);
    Date(const Date&);
    void inputDate();
    void displayDate() const;
};

class Person {
private:
    string name, gender, cnic, address, cellNo;
    int age;
    Date dob;
public:
    void setName(string);
    void setGender(string);
    void setCnic(string);
    void setAdd(string);
    void setCellNo(string);
    void setAge(int);
    void setDob(const Date d);

    string getName()const;
    string getGender()const;
    string getCnic()const;
    string getAdd()const;
    string getCellNo()const;
    int getAge()const;
    Date getDob()const;
    Person(string = "", string = "", string = "", string = "", string = "", int = 0, Date = Date());
    void inputPerson();
    void displayPerson() const;
};

class Criminal : public Person {
private:
    int crimeType;
    string complainerName, investigatingOfficer;
    int punishmentYears;
    Date crimeDate;
    Date punishmentDate;
    string crimeDescription[10] = {"Murder", "Assault", "Robbery", "Drugs" , "Theft", "Burglary", "Arson", "Fraud", "Embezzlement", "Driving Under the Influence (DUI/DWI)"};
public:
    void setCrimeType(int);
    void setComplainerName(string);
    void setInvestiOffi(string);
    void setPuniYears(int);
    void setCrimeDate(const Date d);
    void setPuniDate(const Date d);

    int getCrimeType()const;
    string getComplainerName()const;
    string getInvetiOffi()const;
    int getPuniYr()const;
    Date getCrimeDate()const;
    Date getPuniDate()const;
    string getCrimeDescription(int)const;

    Criminal(string = "", string = "", string ="", string = "", string = "", int = 0, Date = Date(), int = 0 , string= "", string = "", int = 0, Date = Date(), Date = Date());
    Criminal(const Criminal &c);
    void inputCriminal();
    void displayCriminal() const;
    void PrintCrimeType()const;
    bool searchByName(string)const;
    bool searchByCrimeType(int)const;
};


Date::Date(int d, int m, int y){
    month = m;
    year = y;
    day = d;
}

Date::Date(const Date &d){
    month = d.month;
    year = d.year;
    day = d.day;
}

void Date::inputDate(){
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
    cin.ignore();
}

void Date::displayDate()const{

    cout << day << "/" << month << "/" << year;
}

//Date Class End

//Person Class Start

void Person::setName (string t){name = t;}
void Person::setGender (string t){gender = t;}
void Person::setCnic (string t){cnic = t;}
void Person::setAdd (string t){address = t;}
void Person::setCellNo (string t){cellNo = t;}
void Person::setAge (int t){age = t;}
void Person::setDob (const Date d){dob = d;}

string Person::getName()const{return name;}
string Person::getGender()const{return gender;}
string Person::getCnic()const{return cnic;}
string Person::getAdd()const{return address;}
string Person::getCellNo()const{return cellNo;}
int Person::getAge()const{return age;}
Date Person::getDob()const{return dob;}

Person::Person(string n, string g, string c, string a, string cn, int age, Date d){
    setName(n);
    setGender(g);
    setCnic(c);
    setAdd(a);
    setCellNo(cn);
    setAge(age);
    setDob(d);
}

void Person::inputPerson(){
    string temp;
    cout << "Enter Name: ";
    getline(cin, temp);
    setName(temp);

    cout << "Enter Gender: ";
    getline(cin, temp);
    setGender(temp);

    cout << "Enter CNIC: ";
    getline(cin, temp);
    setCnic(temp);

    cout << "Enter Address: ";
    getline(cin, temp);
    setAdd(temp);

    cout << "Enter Cell No: ";
    getline(cin, temp);
    setCellNo(temp);

    cout << "Enter Age: ";
    int a = 0;
    cin >> a;
    cin.ignore();
    setAge(a);

    cout << "Enter Date of Birth" << endl;
    dob.inputDate();
}

void Person::displayPerson()const{
    cout << "========================================\n";
    cout << "           PERSON INFORMATION           \n";
    cout << "========================================\n";

    cout << " Name       : " << getName() << "\n";
    cout << " Gender     : " << getGender() << "\n";
    cout << " CNIC       : " << getCnic() << "\n";
    cout << " Age        : " << getAge() << "\n";
    cout << " Address    : " << getAdd() << "\n";
    cout << " Cell No    : " << getCellNo() << "\n";

    cout << "========================================";

}

//Person Class End

//Criminal Class Start

    int Criminal::getCrimeType()const{return crimeType;}
    string Criminal::getComplainerName()const{return complainerName;}
    string Criminal::getInvetiOffi()const{return investigatingOfficer;}
    int Criminal::getPuniYr()const{return punishmentYears; }
    Date Criminal::getCrimeDate()const{return crimeDate;}
    Date Criminal::getPuniDate()const{return punishmentDate;}
    string Criminal::getCrimeDescription(int x)const{return crimeDescription[x];}

    void Criminal::setCrimeType(int temp){crimeType = temp;}
    void Criminal::setComplainerName(string temp){complainerName = temp;}
    void Criminal::setInvestiOffi(string temp){investigatingOfficer = temp;}
    void Criminal::setPuniYears(int temp){punishmentYears = temp;}
    void Criminal::setCrimeDate(const Date temp){crimeDate = temp;}
    void Criminal::setPuniDate(const Date temp){punishmentDate = temp;}

    Criminal::Criminal(string name, string gender, string cnic, string add, string cellNo, int age, Date dob,
        int CrimeT, string Complinername, string Investioffi, int puniyr, Date crimeDT, Date puniDT): Person(name,gender,cnic,add,cellNo, age,dob){
        setCrimeType(CrimeT);
        setComplainerName(Complinername);
        setInvestiOffi(Investioffi);
        setPuniYears(puniyr);
        setCrimeDate(crimeDT);
        setPuniDate(puniDT);
    }

    Criminal::Criminal(const Criminal &c):Person(c){
        setCrimeType(c.getCrimeType());
        setComplainerName(c.getComplainerName());
        setInvestiOffi(c.getInvetiOffi());
        setPuniYears(c.getPuniYr());
        setCrimeDate(c.getCrimeDate());
        setPuniDate(c.getPuniDate());
    }

    void Criminal::PrintCrimeType()const{
        cout << "Crime Types:\n";
        for (int i = 0; i < 10; ++i) {
            cout << i + 1 << ". " << getCrimeDescription(i) << endl;
        }
    }

    void Criminal::inputCriminal() {
    inputPerson();

    string temp = "";
    int x = 0;

    PrintCrimeType();

    cout << "Enter Crime Type: ";
    cin >> x;
    setCrimeType(x - 1);
    cin.ignore();

    cout << "Enter Complainer Name: ";
    getline(cin, temp);
    setComplainerName(temp);

    cout << "Enter Investigating Officer: ";
    getline(cin, temp);
    setInvestiOffi(temp);

    x = 0;
    cout << "Enter Punishment Years: ";
    cin >> x;
    setPuniYears(x);

    cout << "Enter Crime Date:" << endl;
    Date tempDate;
    tempDate.inputDate();
    setCrimeDate(tempDate);

    tempDate = Date();
    cout << "Enter Punishment Date:" << endl;
    tempDate.inputDate();
    setPuniDate(tempDate);

}

void Criminal::displayCriminal() const {
    displayPerson();

    cout << "\n";
    cout << "          CRIME INFORMATION          \n";
    cout << "========================================\n";

    cout << " Crime Type            : " << getCrimeDescription(getCrimeType()) << "\n";
    cout << " Complainer            : " << getComplainerName() << "\n";
    cout << " Investigative Officer : " << getInvetiOffi() << "\n";
    cout << " Punishment Years      : " << getPuniYr() << "\n";
    cout << " Crime Date            : ";
    Date tempDate = getCrimeDate();
    tempDate.displayDate();

    cout << "\n Punishment Date      : ";
    tempDate = getPuniDate();
    tempDate.displayDate();
    cout << "\n========================================\n\n";
}

bool Criminal::searchByName(string temp_name)const{
    if(temp_name == getName())
        return true;
    return false;
}

bool Criminal::searchByCrimeType(int temp)const{
    if(temp == getCrimeType())
        return true;
    return false;
}

//Criminal Class End

class Node{
public:
    Criminal rec;
    Node* next;
    Node(Criminal &tempCriminalRecord) {
        rec.setName(tempCriminalRecord.getName());
        rec.setGender(tempCriminalRecord.getGender());
        rec.setCnic(tempCriminalRecord.getCnic());
        rec.setAdd(tempCriminalRecord.getAdd());
        rec.setCellNo(tempCriminalRecord.getCellNo());
        rec.setAge(tempCriminalRecord.getAge());
        rec.setDob(tempCriminalRecord.getDob());
        rec.setCrimeType(tempCriminalRecord.getCrimeType());
        rec.setComplainerName(tempCriminalRecord.getComplainerName());
        rec.setInvestiOffi(tempCriminalRecord.getInvetiOffi());
        rec.setPuniYears(tempCriminalRecord.getPuniYr);
        rec.setCrimeDate(tempCriminalRecord.getCrimeDate());
        rec.setPuniDate(tempCriminalRecord.getPuniDate());
        next = NULL;
    }

};

class PoliceRecordSystemLL{
private:
    Node* head;

public:
    PoliceRecordSystemLL(){ head = NULL; }

    void insertAtBeginning(){
        Criminal tempCriminalRecord;
        tempCriminalRecord.inputCriminal();
        Node* newNode = new Node(tempCriminalRecord);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(){
        Criminal tempCriminalRecord;
        tempCriminalRecord.inputCriminal();
        Node* newNode = new Node(tempCriminalRecord);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAtEnd(Criminal tempCriminalRecord){
        tempCriminalRecord.inputCriminal();
        Node* newNode = new Node(tempCriminalRecord);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteByValue(string name) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->rec.getName() == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->rec.getName() != name)
            temp = temp->next;
        if (temp->next == NULL)
            cout << "Value not found.\n";
        else {
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }

    void displayList() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            temp->rec.displayCriminal();
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void search(string);
    int countNodes();
    void reverse();

};

// Definitions
void PoliceRecordSystemLL::search(string name) {
    Node* temp = head;
    int pos = 0;
    bool found = false;
    while (temp != NULL) {
        if (temp->rec.getName() == name) {
            cout << "Record found at position " << pos << endl;
            temp->rec.displayCriminal();
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (!found)
        cout << "Value not found in the list." << endl;
}

int PoliceRecordSystemLL::countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void PoliceRecordSystemLL::reverse() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    cout << "List has been reversed successfully." << endl;
}

void displayEnhancedMenu() {
    system("cls");

    // Enhanced header with simple borders
    cout << "\n";
    cout << "##################################################\n";
    cout << "#                POLICE DEPARTMENT               #\n";
    cout << "#          CRIMINAL RECORD SYSTEM v2.0          #\n";
    cout << "##################################################\n";
    cout << "\n";

    // Menu with section dividers
    cout << "+------------------------------------------------+\n";
    cout << "|                   MAIN MENU                    |\n";
    cout << "+------------------------------------------------+\n";
    cout << "| --> 1. Add Criminal Record                    |\n";
    cout << "| --> 2. Search by Name                         |\n";
    cout << "| --> 3. Search by Crime Type                   |\n";
    cout << "+------------------------------------------------+\n";
    cout << "| --> 4. Show Murder Cases                      |\n";
    cout << "| --> 5. Show Theft Cases                       |\n";
    cout << "| --> 6. Delete Record                          |\n";
    cout << "| --> 7. Display All Records                    |\n";
    cout << "+------------------------------------------------+\n";
    cout << "| --> 8. Exit System                            |\n";
    cout << "+------------------------------------------------+\n";
    cout << "\n";
}

int main(){
    PoliceRecordSystemLL perp_list;
}
