#include<iostream>
#include "Classes.h"

using namespace std;

class Node {
public:
    Criminal rec;
    Node* next;
    Node(Criminal &tempCriminalRecord) {
        rec = tempCriminalRecord;
        next = NULL;
    }

    void operator = (const Criminal &temp){
        setName(temp.getName());
        setGender(temp.Gender());
        setCnic(temp.getCnic());
        setAdd(temp.getAdd(););
        setCellNo(temp.getCellNo());
        setAge(temp.getAge());
        setDob(temp.getDob());
        setCrimeType(temp.getCrimeType());
        setComplainerName(temp.getComplainerName());
        setInvestiOffi(temp.getInvetiOffi());
        setPuniYears(temp.getPuniYr);
        setCrimeDate(temp.getCrimeDate());
        setPuniDate(temp.getPuniDate());
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

    void insertAtEnd(const Criminal tempCriminalRecord){
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
        if (head->rec->getName() == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->rec->getName() != name)
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
            cout << temp->rec->displayCriminal();
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
        if (temp->rec->getName() == name) {
            cout << "Record found at position " << pos << endl;
            temp->rec->displayCriminal();
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (!found)
        cout << "Value " << val << " not found in the list." << endl;
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
    PoliceRecordSystem perp_list;
    int op = 0;
    
    do{
        op = 0;
        displayEnhancedMenu();
        cout << "Enter Option";
        cin >> op;
        cin.ignore();

        if(cin.fail()){
            cout << "Enter valid option" << endl;
            system("pause");
            continue;
        }
        if(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7){
            cout << "Enter valid option" << endl;
            system("pause");
            continue;
        }

        switch(op){
            case 1:
                perp_list.addCriminal();
                break;
            case 2:
                perp_list.searchByName();
                break;
            case 3:
                perp_list.searchByCrimeType();
                break;
            case 4:
                perp_list.showMurderCases();
                break;
            case 5:
                perp_list.showTheftCases();
                break;
            case 6:
                perp_list.deleteCriminal();
                break;
            case 7:
                perp_list.displayAll();
                break;
            case 8:
                return 0;
            default:
                continue;
        }
    }while(true);

}