#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Function to register a user
void registerUser()
{
    string username, password;
    string existingUsername, existingPassword;

    cout << "\n===== Registration =====" << endl;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Basic input validation
    if (username.empty())
    {
        cout << "\nUsername cannot be empty!" << endl;
        return;
    }

    if (password.length() < 4)
    {
        cout << "\nPassword must contain at least 4 characters!" << endl;
        return;
    }

    // Check for duplicate username
    ifstream infile("users.txt");

    while (infile >> existingUsername >> existingPassword)
    {
        if (existingUsername == username)
        {
            cout << "\nUsername already exists! Please choose another username." << endl;
            infile.close();
            return;
        }
    }

    infile.close();

    // Save new user
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "\nRegistration Successful!" << endl;
}

// Function to login
void loginUser()
{
    string inputUsername, inputPassword;
    string username, password;
    bool found = false;

    cout << "\n===== Login =====" << endl;

    cout << "Enter Username: ";
    cin >> inputUsername;

    cout << "Enter Password: ";
    cin >> inputPassword;

    ifstream infile("users.txt");

    while (infile >> username >> password)
    {
        if (inputUsername == username && inputPassword == password)
        {
            found = true;
            break;
        }
    }

    infile.close();

    if (found)
    {
        cout << "\nLogin Successful! Welcome " << inputUsername << "!" << endl;
    }
    else
    {
        cout << "\nInvalid Username or Password!" << endl;
    }
}

int main()
{
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
            registerUser();
            break;

        case 2:
            loginUser();
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
