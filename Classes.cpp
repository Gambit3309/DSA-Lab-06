#include "Classes.h"
#include <iomanip>

using namespace std;

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

//PolicRecordSystem Class Start

int PoliceRecordSystem::getcount()const{return count;}
Criminal PoliceRecordSystem::getCriminal(int index)const{return criminals[index];}

void PoliceRecordSystem::setcriminal(Criminal temp, int index){criminals[index] = temp;}
void PoliceRecordSystem::increaseCount(){count++;}

PoliceRecordSystem::PoliceRecordSystem(){count = 0;}

void PoliceRecordSystem::addCriminal(){
    Criminal temp;
    temp.inputCriminal();
    if(count == 100){
        cout << "\n========================================\n";
        cout << "        MAXIMUM CAPACITY REACHED        \n";
        cout << "========================================\n";
        return;
    }
    setcriminal(temp, count);
    increaseCount();
}


void PoliceRecordSystem::displayAll()const{
    for(int i = 0; i < getcount(); i++){
        cout << "\n========================================\n";
            cout <<   "                INDEX " << i << "                  \n";
        criminals[i].displayCriminal();
    }
}

void PoliceRecordSystem::searchByName()const{
    string temp_name = "0000000000";
    cout << "Enter Name of Criminal: ";
    getline(cin, temp_name);
    int index[100];
    int count = -1;
    fill(index, index + 100, -1);
    for(int i = 0; i < getcount(); i++){
        if(criminals[i].searchByName(temp_name)){
            count++;
            index[count] = i;
        }
    }

    if(count > -1){
        cout << "\n========================================\n";
        cout << "             SEARCH COMPLETED           \n";
        cout << "========================================\n";

        cout << "TOTAL ENTRIES FOUND: " << count + 1 << endl;
        cout << "Press Y TO DISPLAY ALL ENDTRIES";
        char temp;
        if(temp != 'Y' || temp != 'y')
            return;

        for(int i = 0; i < count; i++){
            cout << "\n========================================\n";
            cout <<   "                INDEX " << index[i] << "                  \n";
            criminals[index[i]].displayCriminal();
        }
    }
}
    
void PoliceRecordSystem::searchByCrimeType()const{
    int temp_crime_Type = -1;
    
    Criminal temp;
    temp.PrintCrimeType();

    cout << "Enter Crime Type: ";
    cin >> temp_crime_Type;

    int index[100];
    int count = -1;
    fill(index, index + 100, -1);
    for(int i = 0; i < getcount(); i++){
        if(criminals[i].searchByCrimeType(temp_crime_Type)){
            count++;
            index[count] = i;
        }
    }

    if(count > -1){
        cout << "\n========================================\n";
        cout << "             SEARCH COMPLETED           \n";
        cout << "========================================\n";

        cout << "TOTAL ENTRIES FOUND: " << count + 1 << endl;
        cout << "Press Y TO DISPLAY ALL ENDTRIES";
        char temp;
        if(temp != 'Y' || temp != 'y')
            return;

        for(int i = 0; i < count; i++){
            cout << "\n========================================\n";
            cout <<   "                INDEX " << index[i] << "                  \n";
            criminals[index[i]].displayCriminal();
        }
    }
}
//
//
//
//
//
//
//
//

void PoliceRecordSystem::searchByCrimeType(int temp_crime_type)const{
    int index[100];
    int count = -1;
    fill(index, index + 100, -1);
    for(int i = 0; i < getcount(); i++){
        if(criminals[i].searchByCrimeType(temp_crime_type)){
            count++;
            index[count] = i;
        }
    }

    if(count > -1){
        cout << "\n========================================\n";
        cout << "             SEARCH COMPLETED           \n";
        cout << "========================================\n";

        cout << "TOTAL ENTRIES FOUND: " << count + 1 << endl;
        cout << "Press Y TO DISPLAY ALL ENDTRIES";
        char temp;
        if(temp != 'Y' || temp != 'y')
            return;
        for(int i = 0; i < count; i++){
            cout << "\n========================================\n";
            cout <<   "                INDEX " << index[i] << "                  \n";
            criminals[index[i]].displayCriminal();
        }
    }
}

//
//
//
//
//
//
//
//
//

void PoliceRecordSystem::deleteCriminal(){

    system("CLS");

    cout << "  1. Search by Name" << endl;
    cout << "  2. Search by Crime Type" << endl;
    cout << "  3. Display All Records" << endl;
    char ch = '0';
    cout << "Enter choice > ";
    if(ch != '1' || ch != '2' || ch != '3'){
        cout << "Enter valid option" << endl;
        system("pause");
        return;
    }
    
    if(ch == '1'){
        searchByName();
    }
    else if(ch == '2'){
        searchByCrimeType();
    }
    else{
        displayAll();
    }


    cout << "Enter Index of Record to delete: ";
    int x = -1;
    cin >> x;

    if(cin.fail())
        return;

    if(x == -1){
        cout << "Enter valid option" << endl;
        system("pause");
        return;
    }

    setcriminal(Criminal(), x);
    cout << "Successfull Deleted Entry" << endl;
    system("pause");
}

void PoliceRecordSystem::showMurderCases()const{
    searchByCrimeType(0);
}

void PoliceRecordSystem::showTheftCases()const{
    searchByCrimeType(4);
}

