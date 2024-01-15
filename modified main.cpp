#include "sqlite3.h"
#include <string>
#include <iostream>
using namespace std;

void insertUserDetails(const string& username, const string& password, const string& gmail, const string& phone_number);
void insertAdminDetails(const string& username, const string& password, const string& gmail, const string& phone_number);
void insertStaffDetails(const string& username, const string& password, const string& gmail, const string& phone_number);

void insertUserDetails(const string& username, const string& password, const string& gmail, const string& phone_number) {
    sqlite3* DB;
    int exit = sqlite3_open("pharmacy.db", &DB);
    char* messageError;

    string sql_insert_data = "INSERT INTO USER_DETAILS (USER_USERNAME, USER_PASSWORD, USER_EMAIL, USER_PHONE_NUMBER) "
                             "VALUES ('" + username + "', '" + password + "', '" + gmail + "', '" + phone_number + "');";

    exit = sqlite3_exec(DB, sql_insert_data.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error inserting data: " << messageError << endl;
        sqlite3_free(messageError);
    } else {
        cout << "Data inserted successfully" << endl;
    }

    sqlite3_close(DB);
}

void insertAdminDetails(const string& username, const string& password, const string& gmail, const string& phone_number) {
    sqlite3* DB;
    int exit = sqlite3_open("pharmacy.db", &DB);
    char* messageError;

    string sql_insert_data = "INSERT INTO ADMIN_DETAILS (ADMIN_USERNAME, ADMIN_PASSWORD, ADMIN_EMAIL, ADMIN_PHONE_NUMBER) "
                             "VALUES ('" + username + "', '" + password + "', '" + gmail + "', '" + phone_number + "');";

    exit = sqlite3_exec(DB, sql_insert_data.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error inserting data: " << messageError << endl;
        sqlite3_free(messageError);
    } else {
        cout << "Data inserted successfully" << endl;
    }

    sqlite3_close(DB);
}

void insertStaffDetails(const string& username, const string& password, const string& gmail, const string& phone_number) {
    sqlite3* DB;
    int exit = sqlite3_open("pharmacy.db", &DB);
    char* messageError;

    string sql_insert_data = "INSERT INTO STAFF_DETAILS (STAFF_USERNAME, STAFF_PASSWORD, STAFF_EMAIL, STAFF_PHONE_NUMBER) "
                             "VALUES ('" + username + "', '" + password + "', '" + gmail + "', '" + phone_number + "');";

    exit = sqlite3_exec(DB, sql_insert_data.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error inserting data: " << messageError << endl;
        sqlite3_free(messageError);
    } else {
        cout << "Data inserted successfully" << endl;
    }

    sqlite3_close(DB);
}

void menu() {
    int choice;
    string username;
    string password;
    string new_password;
    string gmail;
    string phone_number;

    cout << " =======================================\n"
            " |        ~ Welcome To Pharmacy ~      |\n"
            " =======================================\n"
            " |---------- NEW ERA PHARMACY ---------|\n"
            " =======================================\n"
            " |                                     |\n"
            " |        -- Enter your choice:        |\n"
            " |        1. Login                     |\n"
            " |        2. Register                  |\n"
            " |                                     |\n"
            " |----------- other options -----------|\n"
            " |       0. Exit program               |\n"
            " =======================================\n";

    cout << "Enter choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            int registrationChoice;
            cout << "Choose user type to register:\n"
                    "1. User\n"
                    "2. Admin\n"
                    "3. Employee\n"
                    "Enter choice: ";
            cin >> registrationChoice;
            cout << "Username: ";
            cin >> username;
            do {
                cout << "Password: ";
                cin >> password;
                cout << "Confirm Password: ";
                cin >> new_password;
                if (new_password != password) {
                    cout << "Passwords do not match. Please try again." << endl;
                }
            } while (new_password != password);
            cout << "Gmail: ";
            cin >> gmail;
            cout << "Phone Number: ";
            cin >> phone_number;

            if (new_password == password) {
                cout << "Registration successful." << endl;

                switch (registrationChoice) {
                    case 1:
                        insertUserDetails(username, password, gmail, phone_number);
                        break;
                    case 2:
                        insertAdminDetails(username, password, gmail, phone_number);
                        break;
                    case 3:
                        insertStaffDetails(username, password, gmail, phone_number);
                        break;
                    default:
                        cout << "Invalid user type choice." << endl;
                        break;
                }
                menu(); 
            } else {
                cout << "Passwords do not match. Please register again." << endl;
            }
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }
}

void login(){
    int choice;
    string username, password;

    cout << " =======================================\n" 
            " |        ~ Welcome To Pharmacy ~      |\n" 
            " =======================================\n" 
            " |---------- NEW ERA PHARMACY ---------|\n" 
            " =======================================\n" 
            " |                                     |\n" 
            " |        -- Enter your choice:        |\n"
            " |        1.  User                     |\n"
            " |        2.  Admin                    |\n" 
            " |        3.  Employee                 |\n" 
            " |                                     |\n" 
            " |----------- other options -----------|\n" 
            " |        99. Back                     |\n"
            " |        0.  Exit program             |\n" 
            " =======================================\n";

    cout << "Enter choice: ";
    cin >> choice;
    switch (choice){
        case 1:
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            cout << "Login Successful." << endl;
            user.user_main();
            break;
        case 2:
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            cout << "Login Successful." << endl;
            admin.admin_main();
            break;
        case 3:
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            cout << "Login Successful." << endl;
            employee.employee_main();
            break;
        case 99:
            menu();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Invalid choice." << endl; 
            break;
    }
    }