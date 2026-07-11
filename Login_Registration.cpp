#include <iostream>
#include <string>

using namespace std;

// Function to register a user
void registerUser(string &username, string &password)
{
    cout << "\n===== Registration =====" << endl;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    cout << "\nRegistration Successful!" << endl;
}

// Function to login
void loginUser(string username, string password)
{
    string inputUsername, inputPassword;

    cout << "\n===== Login =====" << endl;

    cout << "Enter Username: ";
    cin >> inputUsername;

    cout << "Enter Password: ";
    cin >> inputPassword;

    if (inputUsername == username && inputPassword == password)
    {
        cout << "\nLogin Successful! Welcome " << username << "." << endl;
    }
    else
    {
        cout << "\nInvalid Username or Password!" << endl;
    }
}

int main()
{
    string username = "";
    string password = "";
    int choice;

    do
    {
        cout << "\n======================================" << endl;
        cout << " LOGIN & REGISTRATION SYSTEM" << endl;
        cout << "======================================" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser(username, password);
            break;

        case 2:
            if (username == "")
            {
                cout << "\nPlease register first!" << endl;
            }
            else
            {
                loginUser(username, password);
            }
            break;

        case 3:
            cout << "\nThank you for using the program!" << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while (choice != 3);

    return 0;
}