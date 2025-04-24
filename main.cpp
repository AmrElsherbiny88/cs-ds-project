#include <iostream>
using namespace std;

struct User {
    string name;
    int ID;
    User* next;
};

struct Tickets {
    string issue;
    int ID;
    int userID;
    string status;
    Tickets* next;
};

User* users = NULL; 

Tickets* front = NULL;
Tickets* rear = NULL;

Tickets** resolvedTickets = new Tickets*[10];
int resolvedSize = 10;
int resolvedCount = 0;

void search() {
    cout << "\nEnter the Ticket ID or User ID to search: ";
    int searchID;
    cin >> searchID;

    Tickets* current = front;

    if (current != NULL) {
        cout << "\nSearching in Open Tickets:\n";
        if (searchID == current->ID || searchID == current->userID) {
            cout << "Issue: " << current->issue << " | Ticket ID: " << current->ID << " | User ID: " << current->userID << " | Status: " << current->status << endl;
        }
        current = current->next;
    }

    while (current != NULL) {
        if (searchID == current->ID || searchID == current->userID) {
            cout << "Issue: " << current->issue << " | Ticket ID: " << current->ID << " | User ID: " << current->userID << " | Status: " << current->status << endl;
        }
        current = current->next;
    }

    cout << "\nSearching in Resolved Tickets:\n";
    for (int i = 0; i < resolvedCount; i++) {
        if (searchID == resolvedTickets[i]->ID || searchID == resolvedTickets[i]->userID) {
            cout << "Issue: " << resolvedTickets[i]->issue << " | Ticket ID: " << resolvedTickets[i]->ID << " | User ID: " << resolvedTickets[i]->userID << " | Status: " << resolvedTickets[i]->status << endl;
        }
    }
}

void resolve() {
    if (front == NULL) {
        cout << "\nNo tickets to resolve." << endl;
        return;
    }

    Tickets* current = front;
    front = front->next;

    current->status = "resolved";
    current->next = NULL;

    if (resolvedCount == resolvedSize) {
        Tickets** newArray = new Tickets*[resolvedSize * 2];
        for (int i = 0; i < resolvedSize; i++) {
            newArray[i] = resolvedTickets[i];
        }
        delete[] resolvedTickets;
        resolvedTickets = newArray;
        resolvedSize *= 2;
    }

    resolvedTickets[resolvedCount++] = current;

    cout << "\nTicket ID: " << current->ID << " resolved and added to resolved list." << endl;
}

void AddTicket () { 
    Tickets* newTicket = new Tickets;
    cout << "\nEnter the issue description: ";
    cin >> newTicket->issue;    
    cout << "Enter the Ticket ID: ";
    cin >> newTicket->ID;  
    cout << "Enter the user ID: ";
    cin >> newTicket->userID;  
    newTicket->status = "open";
    newTicket->next = NULL;

    if (front == NULL) {
        front= rear = newTicket;
    } else {
        while (rear->next != NULL) {
            rear = rear->next;
        }
        rear->next = newTicket;
        rear = newTicket;
    }

    cout << "\nTicket added successfully." << endl;
}

void ShowTickets () { 
    Tickets* current = front ; 

    if (current == NULL) {
        cout << "\nNo tickets available." << endl;
        return;
    }

    cout << "\nOpen Tickets:\n";
    while (current->next != NULL) {
        if (current->status == "open") {
            cout << "Issue: " << current->issue << " | Ticket ID: " << current->ID << " | User ID: " << current->userID << " | Status: " << current->status << endl;
        }
        current = current->next;
    }

    if (current->status == "open") {
        cout << "Issue: " << current->issue << " | Ticket ID: " << current->ID << " | User ID: " << current->userID << " | Status: " << current->status << endl;
    }
}

void registration () {
    User* newUser = new User;
    int ID;
    string name;
    cout << "\nEnter your name: ";
    cin >> newUser->name;    
    cout << "Enter your ID: ";
    cin >> newUser->ID;  
    newUser->next = NULL;

    if (users == NULL) {
        users = newUser;
    } else {
        User* temp = users;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newUser;
    }

    cout << "\nUser registered successfully." << endl;
}

void Show () { 
    User* current = users;

    if (current == NULL) {
        cout << "\nNo users registered." << endl;
        return;
    }

    cout << "\nRegistered Users:\n";
    while (current->next != NULL) {
        cout << "Name: " << current->name << " | User ID: " << current->ID << endl;
        current = current->next;
    }
    cout << "Name: " << current->name << " | User ID: " << current->ID << endl; 
}

void select (){
    int choice;
    cout << "\n1. Register User" << endl;
    cout << "2. Show Users" << endl;
    cout << "3. Add Ticket" << endl;
    cout << "4. Show Tickets" << endl;
    cout << "5. Resolve Ticket" << endl;
    cout << "6. Search Ticket" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            registration();
            select();
            break;
        case 2:
            Show();
            select();
            break;
        case 3:
            AddTicket();
            select();
            break;
        case 4:
            ShowTickets();
            select();
            break;
        case 5:
            resolve();
            select();
            break;
        case 6:
            search();
            select();
            break;
        case 7:
            exit(0);
        default:
            cout << "\nInvalid choice. Please try again." << endl;
    }
}

int main() {     
    select();
    return 0;
}
