#ifndef CLASSES_H
#define CLASSES_H
#define Criminal_List_Size 100

#include<iostream>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int = 0, int = 0, int = 0);       
    Date(const Date&);                // default constructor
    void inputDate();              
    void displayDate() const;
};

class Person {
private:
    string name, gender, cnic, address, cellNo;
    int age;
    Date dob;          // composition: Person "has-a" Date
protected:
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
public:
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
protected:
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

public:
    Criminal(string = "", string = "", string ="", string = "", string = "", int = 0, Date = Date(), int = 0 , string= "", string = "", int = 0, Date = Date(), Date = Date());
    Criminal(const Criminal &c);
    void inputCriminal();
    void displayCriminal() const;
    void PrintCrimeType()const;
    bool searchByName(string)const;
    bool searchByCrimeType(int)const;
};

class PoliceRecordSystem {
private:
    Criminal criminals[Criminal_List_Size];
    int count;

protected:
    void setcriminal(Criminal, int);
    void increaseCount();

    Criminal getCriminal(int)const;
    int getcount()const;

public:
    PoliceRecordSystem();   //done
    void addCriminal(); //done
    void displayAll()const; //done
    void searchByName()const; //done
    void searchByCrimeType()const; //done
    void searchByCrimeType(int)const; //done
    void deleteCriminal(); //done
    void showMurderCases()const; //done
    void showTheftCases()const; //done
};

#endif