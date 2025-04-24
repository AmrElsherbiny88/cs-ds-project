
#include <iostream>
using namespace std;


struct User {
    string name;
    int ID;
    User* next;
};

User* users = NULL; 




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
    registration();
    Show();
     

   
    

    return 0;
}