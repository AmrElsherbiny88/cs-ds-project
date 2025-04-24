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










void resolve() {
    if (front == NULL) {
        cout << "No tickets to resolve." << endl;
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

    cout << current->ID <<"Ticket resolved and added to resolved list." << endl;
}


void AddTicket () { 
    
    Tickets* newTicket = new Tickets;
    cout << "Enter the issue description: ";
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



    cout << "Ticket added successfully." << endl;
}



void ShowTickets () { 
        Tickets* current = front ; 
    
        if (current == NULL) {
            cout << "No tickets available." << endl;
            return;
        }
    
    
        while (current->next != NULL) {

            if (current->status == "open")
            {
                cout << current->issue << " " << current->ID << " " << current->userID << " " << current->status << endl;
                current = current->next;
            }else{
                current = current->next;
            }
            
        
        }

        if (current->status == "open")
        {
            cout << current->issue << " " << current->ID << " " << current->userID << " " << current->status << endl;
        }
             
}




void registration () {
     
    User* newUser = new User;
    int ID;
    string name;
    cout << "Enter your name: ";
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


    cout << "user registered successfully." << endl;
}



void Show () { 
    User* current = users;

    if (current == NULL) {
        cout << "No users registered." << endl;
        return;
    }


    while (current -> next != NULL) {
       
        cout << current->name << " " << current->ID << endl;
        current = current->next;
    }
    cout << current->name << " " << current->ID << endl; 
}


int main() {     
    registration();
    Show();
    AddTicket();
    AddTicket();
    resolve();
    ShowTickets();
    return 0;
}