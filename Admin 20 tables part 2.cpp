#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "sqlite3.h"
#include "admin.h"
#include <string>
#include <limits>
using namespace std;

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    cout << "\n";
    return 0;
}

void Admin::Others() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|           ~ Others ~                |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1,answer4;
        double answer2;
        int answer3;
        cout << "Adding new Others (create)." << endl;
        cout << "Please enter Others name: ";
        getline(cin, answer1);
        cout << "Please enter Others price: ";
        cin >> answer2;
        cout << "Please enter Others quantity: ";
        cin >> answer3;
        cin.clear();
        cin.ignore();
        cout << "Please enter Others description: ";
        getline(cin, answer4);

        string sql_insert_table21 = "INSERT INTO OTHERS (OTHERS_NAME, OTHERS_PRICE, OTHERS_QUANTITY, OTHERS_DESCRIPTION) VALUES ('" + answer1 + "', '" + to_string(answer2) + "', '" + to_string(answer3) + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table21.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Others();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table21 = "SELECT * FROM  OTHERS";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table21.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Others();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the others ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update others name, 2 to update others price, 3 to update others quantity, 4 to update others description: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table21;

        switch (option) {
            case 1:
                cout << "Enter the new others name: ";
                getline(cin, newanswer);
                sql_update_table21 = "UPDATE OTHERS SET OTHERS_NAME = '" + newanswer + "' WHERE OTHERS_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new others price: ";
                cin >> newanswer;
                sql_update_table21 = "UPDATE OTHERS SET OTHERS_PRICE = '" + newanswer + "' WHERE OTHERS_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new others quantity: ";
                cin >> newanswer;
                sql_update_table21 = "UPDATE OTHERS SET OTHERS_QUANTITY = '" + newanswer + "' WHERE OTHERS_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new others description: ";
                getline(cin, newanswer);
                sql_update_table21 = "UPDATE OTHERS SET OTHERS_DESCRIPTION = '" + newanswer + "' WHERE OTHERS_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table21.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Others();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the others ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete others ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the others page." << endl;
            Others();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table21 = "DELETE FROM OTHERS WHERE OTHERS_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table21.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Others();
    }
    else if(input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Others();
    }
}

void Admin::Patient() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|             ~ Patient ~             |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1, answer2, answer3, answer4;
        cout << "Adding new patient (create)." << endl;
        cout << "Please enter patient name: ";
        getline(cin, answer1);
        cout << "Please enter patient gender: ";
        getline(cin, answer2);
        cout << "Please enter patient email: ";
        getline(cin, answer3);
        cout << "Please enter patient phone number: ";
        getline(cin, answer4);

        string sql_insert_table22 = "INSERT INTO PATIENT (PATIENT_NAME, PATIENT_GENDER, PATIENT_EMAIL, PATIENT_PHONE_NUMBER) VALUES ('" + answer1 + "', '" + answer2 + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table22.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Patient();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table22 = "SELECT * FROM  PATIENT";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table22.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Patient();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the patient ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update patient name, 2 to update patient gender, 3 to update patient email, 4 to update patient phone number: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table22;

        switch (option) {
            case 1:
                cout << "Enter the new patient name: ";
                getline(cin, newanswer);
                sql_update_table22 = "UPDATE PATIENT SET PATIENT_NAME = '" + newanswer + "' WHERE PATIENT_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new patient gender: ";
                getline(cin, newanswer);
                sql_update_table22 = "UPDATE PATIENT SET PATIENT_GENDER = '" + newanswer + "' WHERE PATIENT_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new patient email: ";
                getline(cin, newanswer);
                sql_update_table22 = "UPDATE PATIENT SET PATIENT_EMAIL = '" + newanswer + "' WHERE PATIENT_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new patient phone number: ";
                getline(cin, newanswer);
                sql_update_table22 = "UPDATE PATIENT SET PATIENT_PHONE_NUMBER = '" + newanswer + "' WHERE PATIENT_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table22.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Patient();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the patient ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete patient ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the patient page." << endl;
            Patient();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table22 = "DELETE FROM PATIENT WHERE PATIENT_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table22.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Patient();
    }
    else if(input == 0){
        hospitality();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Patient();
    }
}

void Admin::PrescribedMedication() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|      ~ Prescribed Medication ~      |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1,answer2,answer3;
        cout << "Adding new prescribed medication (create)." << endl;
        cout << "Please enter medication name: ";
        getline(cin, answer1);
        cout << "Please enter medication dosage: ";
        getline(cin, answer2);
        cout << "Please enter instruction: ";
        getline(cin, answer3);

        string sql_insert_table23 = "INSERT INTO PRESCRIBED_MEDICATION (MEDICATION_NAME, MEDICATION_DOSAGE, INSTRUCTION) VALUES ('" + answer1 + "', '" + answer2 + "', '" + answer3 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table23.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        PrescribedMedication();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table23 = "SELECT * FROM PRESCRIBED_MEDICATION";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table23.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        PrescribedMedication();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the medication ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update medication name, 2 to update medication dosage, 3 to update instruction: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table23;

        switch (option) {
            case 1:
                cout << "Enter the new medication name: ";
                getline(cin, newanswer);
                sql_update_table23 = "UPDATE PRESCRIBED_MEDICATION SET MEDICATION_NAME = '" + newanswer + "' WHERE MEDICATION_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new prescribed medication dosage: ";
                getline(cin, newanswer);
                sql_update_table23 = "UPDATE PRESCRIBED_MEDICATION SET MEDICATION_DOSAGE = '" + newanswer + "' WHERE MEDICATION_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new instruction: ";
                getline(cin, newanswer);
                sql_update_table23 = "UPDATE PRESCRIBED_MEDICATION SET INSTRUCTION = '" + newanswer + "' WHERE MEDICATION_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table23.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        PrescribedMedication();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the medication ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete medication ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the prescribed medication page." << endl;
            PrescribedMedication();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table23 = "DELETE FROM PRESCRIBED_MEDICATION WHERE MEDICATION_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table23.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        PrescribedMedication();
    }
    else if(input == 0){
        hospitality();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        PrescribedMedication();
    }
}

void Admin::Prescription() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|         ~ Prescription ~            |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer2,answer3;
        double answer4;
        int answer1;
        cout << "Adding new prescription (create)." << endl;
        cout << "Please enter user ID: ";
        cin >> answer1;
        cin.clear();
        cin.ignore();
        cout << "Please enter docter name: ";
        getline(cin, answer2);
        cout << "Please enter date issued: ";
        getline(cin, answer3);
        cout << "Please enter total cost: ";
        cin >> answer4;

        string sql_insert_table24 = "INSERT INTO PRESCRIPTION (USER_ID, DOCTOR_NAME, DATE_ISSUED, TOTAL_COST) VALUES ('" + to_string(answer1) + "', '" + answer2 + "', '" + answer3 + "', '" + to_string(answer4) + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table24.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Prescription();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table24 = "SELECT * FROM  PRESCRIPTION";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table24.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Prescription();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the prescription ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update user ID, 2 to update doctor name, 3 to update date issued, 4 to update total cost: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table24;

        switch (option) {
            case 1:
                cout << "Enter the new user id: ";
                cin >> newanswer;
                sql_update_table24 = "UPDATE PRESCRIPTION SET USER_ID = '" + newanswer + "' WHERE PRESCRIPTION_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new doctor name: ";
                getline(cin, newanswer);
                sql_update_table24 = "UPDATE PRESCRIPTION SET DOCTOR_NAME = '" + newanswer + "' WHERE PRESCRIPTION_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new date issued: ";
                getline(cin, newanswer);
                sql_update_table24 = "UPDATE PRESCRIPTION SET DATE_ISSUED = '" + newanswer + "' WHERE PRESCRIPTION_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new total cost: ";
                cin >> newanswer;
                sql_update_table24 = "UPDATE PRESCRIPTION SET TOTAL_COST = '" + newanswer + "' WHERE PRESCRIPTION_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table24.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Prescription();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the prescription ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete prescription ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the prescription page." << endl;
            Prescription();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table24 = "DELETE FROM PRESCRIPTION WHERE PRESCRIPTION_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table24.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Prescription();
    }
    else if (input == 0){
        hospitality();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Prescription();
    }
}

void Admin::ProductReview() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|         ~ Product Review ~          |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1, answer2, answer4;
        int answer3;
        cout << "Adding new product review (create)." << endl;
        cout << "Please enter product name: ";
        getline(cin, answer1);
        cout << "Please enter date submitted: ";
        getline(cin, answer2);
        cout << "Please enter user Id: ";
        cin >> answer3;
        cin.clear();
        cin.ignore();
        cout << "Please enter review message: ";
        getline(cin, answer4);

        string sql_insert_table25 = "INSERT INTO PRODUCT_REVIEW (PRODUCT_NAME, DATE_SUBMITTED, USER_ID, REVIEW_MESSAGE) VALUES ('" + answer1 + "', '" + answer2 + "', '" + to_string(answer3) + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table25.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        ProductReview();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table25 = "SELECT * FROM  PRODUCT_REVIEW";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table25.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        ProductReview();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the product review ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update product name, 2 to update date submitted, 3 to update user id, 4 to update review message: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table25;

        switch (option) {
            case 1:
                cout << "Enter the new product name: ";
                getline(cin, newanswer);
                sql_update_table25 = "UPDATE PRODUCT_REVIEW SET PRODUCT_NAME = '" + newanswer + "' WHERE REVIEW_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new date submitted: ";
                getline(cin, newanswer);
                sql_update_table25 = "UPDATE PRODUCT_REVIEW SET DATE_SUBMITTED = '" + newanswer + "' WHERE REVIEW_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new user ID: ";
                cin >> newanswer;
                sql_update_table25 = "UPDATE PRODUCT_REVIEW SET USER_ID = '" + newanswer + "' WHERE REVIEW_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new review message: ";
                getline(cin, newanswer);
                sql_update_table25 = "UPDATE PRODUCT_REVIEW SET REVIEW_MESSAGE = '" + newanswer + "' WHERE REVIEW_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table25.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        ProductReview();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the product review ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete product review ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the product review page." << endl;
            ProductReview();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table25 = "DELETE FROM PRODUCT_REVIEW WHERE REVIEW_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table25.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        ProductReview();
    }
    else if(input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        ProductReview();
    }
}

void Admin::Promotion() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|            ~ Promotion ~            |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1,answer3,answer4;
        double answer2;
        cout << "Adding new promotion (create)." << endl;
        cout << "Please enter product name: ";
        getline(cin, answer1);
        cout << "Please enter discount percentage: ";
        cin >> answer2;
        cin.clear();
        cin.ignore();
        cout << "Please enter start date: ";
        getline(cin, answer3);
        cout << "Please enter end date: ";
        getline(cin, answer4);

        string sql_insert_table26 = "INSERT INTO PROMOTION (PRODUCT_NAME, DISCOUNT_PERCENTAGE, START_DATE, END_DATE) VALUES ('" + answer1 + "', '" + to_string(answer2) + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table26.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Promotion();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table26 = "SELECT * FROM  PROMOTION";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table26.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Promotion();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the promotion ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update product name, 2 to update discount percentage, 3 to update start date, 4 to update end date: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table26;

        switch (option) {
            case 1:
                cout << "Enter the new product name: ";
                getline(cin, newanswer);
                sql_update_table26 = "UPDATE PROMOTION SET PRODUCT_NAME = '" + newanswer + "' WHERE PROMOTION_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new discount percentage: ";
                cin >> newanswer;
                sql_update_table26 = "UPDATE PROMOTION SET DISCOUNT_PERCENTAGE = '" + newanswer + "' WHERE PROMOTION_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new start date: ";
                getline(cin, newanswer);
                sql_update_table26 = "UPDATE PROMOTION SET START_DATE = '" + newanswer + "' WHERE PROMOTION_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new end date: ";
                getline(cin, newanswer);
                sql_update_table26 = "UPDATE PROMOTION SET END_DATE = '" + newanswer + "' WHERE PROMOTION_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table26.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Promotion();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the promotion ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete promotion ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the promotion page." << endl;
            Promotion();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table26 = "DELETE FROM PROMOTION WHERE PROMOTION_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table26.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Promotion();
    }
    else if(input == 0){
        gift();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Promotion();
    }
}

void Admin::Receipt() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|             ~ Receipt ~             |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1, answer4;
        double answer3;
        int answer2;
        cout << "Adding new receipt (create)." << endl;
        cout << "Please enter receipt date: ";
        getline(cin, answer1);
        cout << "Please enter item list: ";
        cin >> answer2;
        cout << "Please enter total amount: ";
        cin >> answer3;
        cin.clear();
        cin.ignore();
        cout << "Please enter user name: ";
        getline(cin, answer4);

        string sql_insert_table27 = "INSERT INTO RECEIPT (RECEIPT_DATE, ITEM_LIST, TOTAL_AMOUNT, USER_NAME) VALUES ('" + answer1 + "', '" + to_string(answer2) + "', '" + to_string(answer3) + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table27.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Receipt();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table27 = "SELECT * FROM  RECEIPT";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table27.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Receipt();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the receipt ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update receipt date, 2 to update item list, 3 to update total amount, 4 to update user name: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table27;

        switch (option) {
            case 1:
                cout << "Enter the new receipt date: ";
                getline(cin, newanswer);
                sql_update_table27 = "UPDATE RECEIPT SET RECEIPT_DATE = '" + newanswer + "' WHERE RECEIPT_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new item list: ";
                cin >> newanswer;
                sql_update_table27 = "UPDATE RECEIPT SET ITEM_LIST = '" + newanswer + "' WHERE RECEIPT_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new total amount: ";
                cin >> newanswer;
                sql_update_table27 = "UPDATE RECEIPT SET TOTAL_AMOUNT = '" + newanswer + "' WHERE RECEIPT_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new user name: ";
                getline(cin, newanswer);
                sql_update_table27 = "UPDATE RECEIPT SET USER_NAME = '" + newanswer + "' WHERE RECEIPT_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table27.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Receipt();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the receipt ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete receipt ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the receipt page." << endl;
            Receipt();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table27 = "DELETE FROM RECEIPT WHERE RECEIPT_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table27.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Receipt();
    }
    else if(input == 0){
        customerRelated();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Receipt();
    }
}

void Admin::Replacement() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|           ~ Replacement ~           |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1,answer3,answer4;
        int answer2;
        cout << "Adding new replacement (create)." << endl;
        cout << "Please enter replacement item: ";
        getline(cin, answer1);
        cout << "Please enter replacement quantity: ";
        cin >> answer2;
        cin.clear();
        cin.ignore();
        cout << "Please enter replacement date: ";
        getline(cin, answer3);
        cout << "Please enter replacement reason: ";
        getline(cin, answer4);

        string sql_insert_table28 = "INSERT INTO REPLACEMENT (REPLACEMENT_ITEM, REPLACEMENT_QUANTITY, REPLACEMENT_DATE, REPLACEMENT_REASON) VALUES ('" + answer1 + "', '" + to_string(answer2) + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table28.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Replacement();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table28 = "SELECT * FROM REPLACEMENT";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table28.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Replacement();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the replacement ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update replacement item, 2 to update replacement quantity, 3 to update replacement date, 4 to update replacement reason: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table28;

        switch (option) {
            case 1:
                cout << "Enter the new replacement item: ";
                getline(cin, newanswer);
                sql_update_table28 = "UPDATE REPLACEMENT SET REPLACEMENT_ITEM = '" + newanswer + "' WHERE REPLACEMENT_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new replacement quantity: ";
                cin >> newanswer;
                sql_update_table28 = "UPDATE REPLACEMENT SET REPLACEMENT_QUANTITY = '" + newanswer + "' WHERE REPLACEMENT_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new replacement date: ";
                getline(cin, newanswer);
                sql_update_table28 = "UPDATE REPLACEMENT SET REPLACEMENT_DATE = '" + newanswer + "' WHERE REPLACEMENT_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new replacement reason: ";
                getline(cin, newanswer);
                sql_update_table28 = "UPDATE REPLACEMENT SET REPLACEMENT_REASON = '" + newanswer + "' WHERE REPLACEMENT_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table28.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Replacement();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the replacement ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete replacement ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the replacement page." << endl;
            Replacement();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table28 = "DELETE FROM REPLACEMENT WHERE REPLACEMENT_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table28.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Replacement();
    }
    else if(input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Replacement();
    }
}

void Admin::Return() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|            ~ Return ~               |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer2, answer3;
        double answer1;
        cout << "Adding new return (create)." << endl;
        cout << "Please enter return Amount: ";
        cin >> answer1;
        cin.clear();
        cin.ignore();
        cout << "Please enter return date: ";
        getline(cin, answer2);
        cout << "Please enter return reason: ";
        getline(cin, answer3);

        string sql_insert_table29 = "INSERT INTO RETURN (RETURN_AMOUNT, RETURN_DATE, RETURN_REASON) VALUES ('" + to_string(answer1) + "', '" + answer2 + "', '" + answer3 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table29.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Return();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table29 = "SELECT * FROM RETURN";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table29.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Return();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the return ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update return amount, 2 to update return date, 3 to update return reason: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table29;

        switch (option) {
            case 1:
                cout << "Enter the new return amount: ";
                cin >> newanswer;
                sql_update_table29 = "UPDATE RETURN SET RETURN_AMOUNT = '" + newanswer + "' WHERE RETURN_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new return date: ";
                getline(cin, newanswer);
                sql_update_table29 = "UPDATE RETURN SET RETURN_DATE = '" + newanswer + "' WHERE RETURN_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new return reason: ";
                getline(cin, newanswer);
                sql_update_table29 = "UPDATE RETURN SET RETURN_REASON = '" + newanswer + "' WHERE RETURN_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table29.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Return();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the return ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete return ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the return page." << endl;
            Return();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table29 = "DELETE FROM RETURN WHERE RETURN_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table29.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Return();
    }
    else if (input == 0){
        finance();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Return();
    }
}

void Admin::Reward() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|             ~ Reward ~              |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1, answer3;
        int answer2, answer4;
        cout << "Adding new reward (create)." << endl;
        cout << "Please enter user username: ";
        getline(cin, answer1);
        cout << "Please enter voucher value: ";
        cin >> answer2;
        cin.clear();
        cin.ignore();
        cout << "Please enter voucher expiry date: ";
        getline(cin, answer3);
        cout << "Please enter voucher quantity: ";
        cin >> answer4;

        string sql_insert_table30 = "INSERT INTO REWARD (USER_USERNAME, VOUCHER_VALUE, VOUCHER_EXPIRY_DATE, VOUCHER_QUANTITY) VALUES ('" + answer1 + "', '" + to_string(answer2) + "', '" + answer3 + "', '" + to_string(answer4) + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table30.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Reward();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table30 = "SELECT * FROM REWARD";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table30.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Reward();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the reward ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update user username, 2 to update voucher value, 3 to update voucher expiry date, 4 to update voucher quantity: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table30;

        switch (option) {
            case 1:
                cout << "Enter the new user username: ";
                getline(cin, newanswer);
                sql_update_table30 = "UPDATE REWARD SET USER_USERNAME = '" + newanswer + "' WHERE REWARD_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new voucher value: ";
                cin >> newanswer;
                sql_update_table30 = "UPDATE REWARD SET VOUCHER_VALUE = '" + newanswer + "' WHERE REWARD_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new voucher expiry date: ";
                getline(cin, newanswer);
                sql_update_table30 = "UPDATE REWARD SET VOUCHER_EXPIRY_DATE = '" + newanswer + "' WHERE REWARD_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new voucher quantity: ";
                cin >> newanswer;
                sql_update_table30 = "UPDATE REWARD SET VOUCHER_QUANTITY = '" + newanswer + "' WHERE REWARD_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table30.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Reward();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the reward ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete reward ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the reward page." << endl;
            Reward();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table30 = "DELETE FROM REWARD WHERE REWARD_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table30.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Reward();
    }
    else if (input == 0){
        gift();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Reward();
    }
}

void Admin::SkinCare() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|           ~ Skin Care ~             |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1,answer4;
        double answer2;
        int answer3;
        cout << "Adding new skin care (create)." << endl;
        cout << "Please enter skin care name: ";
        getline(cin, answer1);
        cout << "Please enter skin care price: ";
        cin >> answer2;
        cout << "Please enter skin care quantity: ";
        cin >> answer3;
        cin.clear();
        cin.ignore();
        cout << "Please enter skin care description: ";
        getline(cin, answer4);

        string sql_insert_table31 = "INSERT INTO SKIN_CARE (SKIN_CARE_NAME, SKIN_CARE_PRICE, SKIN_CARE_QUANTITY, SKIN_CARE_DESCRIPTION) VALUES ('" + answer1 + "', '" + to_string(answer2) + "', '" + to_string(answer3) + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table31.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        SkinCare();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table31 = "SELECT * FROM  SKIN_CARE";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table31.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        SkinCare();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the skin care ID you wish to update." << endl;
        cin >> answer;
        cout << "Enter 1 to update skin care name, 2 to update skin care price, 3 to update skin care quantity, 4 to update skin care description: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table31;

        switch (option) {
            case 1:
                cout << "Enter the new skin care name: ";
                getline(cin, newanswer);
                sql_update_table31 = "UPDATE SKIN_CARE SET SKIN_CARE_NAME = '" + newanswer + "' WHERE SKIN_CARE_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new skin care price: ";
                cin >> newanswer;
                sql_update_table31 = "UPDATE SKIN_CARE SET SKIN_CARE_PRICE = '" + newanswer + "' WHERE SKIN_CARE_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new skin care quantity: ";
                cin >> newanswer;
                sql_update_table31 = "UPDATE SKIN_CARE SET SKIN_CARE_QUANTITY = '" + newanswer + "' WHERE SKIN_CARE_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new skin care description: ";
                getline(cin, newanswer);
                sql_update_table31 = "UPDATE SKIN_CARE SET SKIN_CARE_DESCRIPTION = '" + newanswer + "' WHERE SKIN_CARE_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table31.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        SkinCare();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the skin care ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete skin care ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the skin care page." << endl;
            SkinCare();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table31 = "DELETE FROM SKIN_CARE WHERE SKIN_CARE_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table31.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        SkinCare();
    }
    else if(input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        SkinCare();
    }
}

void Admin::StaffDetails() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ STAFF DETAILS ~          |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1, answer2, answer3, answer4;
        cout << "Adding new staff details (create)." << endl;
        cout << "Please enter staff username: ";
        getline(cin, answer1);
        cout << "Please enter staff password: ";
        getline(cin, answer2);
        cout << "Please enter staff email: ";
        getline(cin, answer3);
        cout << "Please enter staff phone number: ";
        getline(cin, answer4);

        string sql_insert_table32 = "INSERT INTO STAFF_DETAILS (STAFF_USERNAME, STAFF_PASSWORD, STAFF_EMAIL, STAFF_PHONE_NUMBER) VALUES ('" + answer1 + "', '" + answer2 + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table32.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        StaffDetails();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table32 = "SELECT * FROM STAFF_DETAILS";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table32.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        StaffDetails();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the staff details ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update staff username, 2 to update staff password, 3 to update staff email, 4 to update staff phone number: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table32;

        switch (option) {
            case 1:
                cout << "Enter the new staff username: ";
                getline(cin, newanswer);
                sql_update_table32 = "UPDATE STAFF_DETAILS SET STAFF_USERNAME = '" + newanswer + "' WHERE STAFF_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new staff password: ";
                getline(cin, newanswer);
                sql_update_table32 = "UPDATE STAFF_DETAILS SET STAFF_PASSWORD = '" + newanswer + "' WHERE STAFF_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new staff email: ";
                getline(cin, newanswer);
                sql_update_table32 = "UPDATE STAFF_DETAILS SET STAFF_EMAIL = '" + newanswer + "' WHERE STAFF_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new staff phone number: ";
                getline(cin, newanswer);
                sql_update_table32 = "UPDATE STAFF_DETAILS SET STAFF_PHONE_NUMBER = '" + newanswer + "' WHERE STAFF_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table32.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        StaffDetails();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the staff details ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete staff ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the staff page." << endl;
            StaffDetails();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table32 = "DELETE FROM STAFF_DETAILS WHERE STAFF_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table32.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        StaffDetails();
    }
    else if(input == 0){
        personnelRelated();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        StaffDetails();
    }
}

void Admin::Stock() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|              ~ Stock ~              |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1, answer4;
        double answer3;
        int answer2;
        cout << "Adding new stock (create)." << endl;
        cout << "Please enter stock name: ";
        getline(cin, answer1);
        cout << "Please enter stock quantity: ";
        cin >> answer2;
        cout << "Please enter stock price: ";
        cin >> answer3;
        cin.clear();
        cin.ignore();
        cout << "Please enter stock description: ";
        getline(cin, answer4);

        string sql_insert_table33 = "INSERT INTO STOCK (STOCK_NAME, STOCK_QUANTITY, STOCK_PRICE, STOCK_DESCRIPTION) VALUES ('" + answer1 + "', '" + to_string(answer2) + "', '" + to_string(answer3) + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table33.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Stock();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table33 = "SELECT * FROM STOCK";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table33.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Stock();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the stock ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update stock name, 2 to update stock quantity, 3 to update stock price, 4 to update stock description: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table33;

        switch (option) {
            case 1:
                cout << "Enter the new stock name: ";
                getline(cin, newanswer);
                sql_update_table33 = "UPDATE STOCK SET STOCK_NAME = '" + newanswer + "' WHERE STOCK_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new stock quantity: ";
                cin >> newanswer;
                sql_update_table33 = "UPDATE STOCK SET STOCK_QUANTITY = '" + newanswer + "' WHERE STOCK_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new stock price: ";
                cin >> newanswer;
                sql_update_table33 = "UPDATE STOCK SET STOCK_PRICE = '" + newanswer + "' WHERE STOCK_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new stock description: ";
                getline(cin, newanswer);
                sql_update_table33 = "UPDATE STOCK SET STOCK_DESCRIPTION = '" + newanswer + "' WHERE STOCK_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table33.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Stock();
    } 
    else if (input == 4) {
        int answer; 
        char option;
        cout << "Please enter the stock ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete stock ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the stock page." << endl;
            Stock();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table33 = "DELETE FROM STOCK WHERE STOCK_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table33.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Stock();
    }
    else if(input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Stock();
    }
}

void Admin::Store() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|             ~ Store ~               |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1, answer2, answer3, answer4;
        cout << "Adding new store (create)." << endl;
        cout << "Please enter store name: ";
        getline(cin, answer1);
        cout << "Please enter store address: ";
        getline(cin, answer2);
        cout << "Please enter store phone number: ";
        getline(cin, answer3);
        cout << "Please enter store email: ";
        getline(cin, answer4);

        string sql_insert_table34 = "INSERT INTO STORE (STORE_NAME, STORE_ADDRESS, STORE_PHONE_NUMBER, STORE_EMAIL) VALUES ('" + answer1 + "', '" + answer2 + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table34.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Store();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table34 = "SELECT * FROM STORE";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table34.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Store();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the store ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update store name, 2 to update store address, 3 to update store phone number, 4 to update store email: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table34;

        switch (option) {
            case 1:
                cout << "Enter the new store name: ";
                getline(cin, newanswer);
                sql_update_table34 = "UPDATE STORE SET STORE_NAME = '" + newanswer + "' WHERE STORE_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new store address: ";
                getline(cin, newanswer);
                sql_update_table34 = "UPDATE STORE SET STORE_ADDRESS = '" + newanswer + "' WHERE STORE_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new store phone number: ";
                getline(cin, newanswer);
                sql_update_table34 = "UPDATE STORE SET STORE_PHONE_NUMBER = '" + newanswer + "' WHERE STORE_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new store email: ";
                getline(cin, newanswer);
                sql_update_table34 = "UPDATE STORE SET STORE_EMAIL = '" + newanswer + "' WHERE STORE_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table34.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Store();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the store ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete store ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the store page." << endl;
            Store();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table34 = "DELETE FROM STORE WHERE STORE_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table34.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Store();
    }
    else if(input == 0){
        hospitality();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Store();
    }
}

void Admin::Supplement() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|            ~ Supplement ~           |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1,answer4;
        double answer2;
        int answer3;
        cout << "Adding new supplement (create)." << endl;
        cout << "Please enter supplement name: ";
        getline(cin, answer1);
        cout << "Please enter supplement price: ";
        cin >> answer2;
        cout << "Please enter supplement quantity: ";
        cin >> answer3;
        cin.clear();
        cin.ignore();
        cout << "Please enter supplement description: ";
        getline(cin, answer4);

        string sql_insert_table35 = "INSERT INTO SUPPLEMENT (SUPPLEMENT_NAME, SUPPLEMENT_PRICE, SUPPLEMENT_QUANTITY, SUPPLEMENT_DESCRIPTION) VALUES ('" + answer1 + "', '" + to_string(answer2) + "', '" + to_string(answer3) + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table35.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Supplement();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table35 = "SELECT * FROM  SUPPLEMENT";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table35.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Supplement();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the supplement ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update supplement name, 2 to update supplement price, 3 to update supplement quantity, 4 to update supplement description: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table35;

        switch (option) {
            case 1:
                cout << "Enter the new supplement name: ";
                getline(cin, newanswer);
                sql_update_table35 = "UPDATE SUPPLEMENT SET SUPPLEMENT_NAME = '" + newanswer + "' WHERE SUPPLEMENT_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new supplement price: ";
                cin >> newanswer;
                sql_update_table35 = "UPDATE SUPPLEMENT SET SUPPLEMENT_PRICE = '" + newanswer + "' WHERE SUPPLEMENT_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new supplement quantity: ";
                cin >> newanswer;
                sql_update_table35 = "UPDATE SUPPLEMENT SET SUPPLEMENT_QUANTITY = '" + newanswer + "' WHERE SUPPLEMENT_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new supplement description: ";
                getline(cin, newanswer);
                sql_update_table35 = "UPDATE SUPPLEMENT SET SUPPLEMENT_DESCRIPTION = '" + newanswer + "' WHERE SUPPLEMENT_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table35.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Supplement();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the supplement ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete supplement ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the supplement page." << endl;
            Supplement();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table35 = "DELETE FROM SUPPLEMENT WHERE SUPPLEMENT_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table35.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Supplement();
    }
    else if(input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Supplement();
    }
}

void Admin::Supplier() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|            ~ Supplier ~             |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1, answer2, answer3;
        cout << "Adding new supplier (create)." << endl;
        cout << "Please enter supplier name: ";
        getline(cin, answer1);
        cout << "Please enter supplier contact: ";
        getline(cin, answer2);
        cout << "Please enter supplier address: ";
        getline(cin, answer3);

        string sql_insert_table36 = "INSERT INTO SUPPLIER (SUPPLIER_NAME, SUPPLIER_CONTACT, SUPPLIER_ADDRESS) VALUES ('" + answer1 + "', '" + answer2 + "', '" + answer3 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table36.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Supplier();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table36 = "SELECT * FROM  SUPPLIER";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table36.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Supplier();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the supplier ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update supplier name, 2 to update supplier contact, 3 to update supplier address: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table36;

        switch (option) {
            case 1:
                cout << "Enter the new supplier name: ";
                getline(cin, newanswer);
                sql_update_table36 = "UPDATE SUPPLIER SET SUPPLIER_NAME = '" + newanswer + "' WHERE SUPPLIER_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new supplier contact: ";
                getline(cin, newanswer);
                sql_update_table36 = "UPDATE SUPPLIER SET SUPPLIER_CONTACT = '" + newanswer + "' WHERE SUPPLIER_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new supplier address: ";
                getline(cin, newanswer);
                sql_update_table36 = "UPDATE SUPPLIER SET SUPPLIER_ADDRESS = '" + newanswer + "' WHERE SUPPLIER_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table36.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Supplier();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the supplier ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete supplier ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the supplier page." << endl;
            Supplier();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table36 = "DELETE FROM SUPPLIER WHERE SUPPLIER_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table36.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Supplier();
    }
    else if(input == 0){
        personnelRelated();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Supplier();
    }
}

void Admin::SupplierProduct() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|         ~ Supplier Product ~        |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        int answer1, answer2, answer3;
        double answer4;
        cout << "Adding new supplier product (create)." << endl;
        cout << "Please enter supplier id: ";
        cin >> answer1;
        cout << "Please enter stock id: ";
        cin >> answer2;
        cout << "Please enter quantity: ";
        cin >> answer3;
        cout << "Please enter price: ";
        cin >> answer4;

        string sql_insert_table37 = "INSERT INTO SUPPLIER_PRODUCT (SUPPLIER_ID, STOCK_ID, QUANTITY, PRICE) VALUES ('" + to_string(answer1)+ "', '" + to_string(answer2) + "', '" + to_string(answer3) + "', '" + to_string(answer4) + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table37.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        SupplierProduct();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table37 = "SELECT * FROM  SUPPLIER_PRODUCT";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table37.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        SupplierProduct();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the supplier product ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update supplier ID, 2 to update stock ID, 3 to update quantity, 4 to update price: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table37;

        switch (option) {
            case 1:
                cout << "Enter the new supplier ID: ";
                cin >> newanswer;
                sql_update_table37 = "UPDATE SUPPLIER_PRODUCT SET SUPPLIER_ID = '" + newanswer + "' WHERE SUPPLIER_PRODUCT_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new stock ID: ";
                cin >> newanswer;
                sql_update_table37 = "UPDATE SUPPLIER_PRODUCT SET STOCK_ID = '" + newanswer + "' WHERE SUPPLIER_PRODUCT_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new  quantity: ";
                cin >> newanswer;
                sql_update_table37 = "UPDATE SUPPLIER_PRODUCT SET QUANTITY = '" + newanswer + "' WHERE SUPPLIER_PRODUCT_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new price: ";
                cin >> newanswer;
                sql_update_table37 = "UPDATE SUPPLIER_PRODUCT SET PRICE = '" + newanswer + "' WHERE SUPPLIER_PRODUCT_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table37.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        SupplierProduct();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the supplier product ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete supplier product ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the supplier product page." << endl;
            SupplierProduct();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table37 = "DELETE FROM SUPPLIER_PRODUCT WHERE SUPPLIER_PRODUCT_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table37.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        SupplierProduct();
    }
    else if(input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        SupplierProduct();
    }
}

void Admin::Transaction() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|            ~ Transaction ~          |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer3, answer4;
        double answer2;
        int answer1;
        cout << "Adding new transaction (create)." << endl;
        cout << "Please enter user ID: ";
        cin >> answer1;
        cout << "Please enter transaction amount: ";
        cin >> answer2;
        cin.clear();
        cin.ignore();
        cout << "Please enter transaction date: ";
        getline(cin, answer3);
        cout << "Please enter payment method: ";
        getline(cin, answer4);

        string sql_insert_table38 = "INSERT INTO \"TRANSACTION\" (USER_ID, TRANSACTION_AMOUNT, TRANSACTION_DATE, PAYMENT_METHOD) VALUES ('" + to_string(answer1) + "', '" + to_string(answer2) + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table38.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Transaction();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table38 = "SELECT * FROM \"TRANSACTION\"";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table38.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Transaction();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the transaction ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update user id, 2 to update transaction amount, 3 to update transaction date, 4 to update payment method: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table38;

        switch (option) {
            case 1:
                cout << "Enter the new user ID: ";
                cin >> newanswer;
                sql_update_table38 = "UPDATE \"TRANSACTION\" SET USER_ID = '" + newanswer + "' WHERE TRANSACTION_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new transaction amount: ";
                cin >> newanswer;
                sql_update_table38 = "UPDATE \"TRANSACTION\" SET TRANSACTION_AMOUNT = '" + newanswer + "' WHERE TRANSACTION_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new transaction quantity: ";
                getline(cin, newanswer);
                sql_update_table38 = "UPDATE \"TRANSACTION\" SET TRANSACTION_DATE = '" + newanswer + "' WHERE TRANSACTION_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new payment method: ";
                getline(cin, newanswer);
                sql_update_table38 = "UPDATE \"TRANSACTION\" SET PAYMENT_METHOD = '" + newanswer + "' WHERE TRANSACTION_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table38.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Transaction();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the transaction ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete transaction ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the transaction page." << endl;
            Transaction();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table38 = "DELETE FROM \"TRANSACTION\" WHERE TRANSACTION_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table38.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Transaction();
    }
    else if(input == 0){
        finance();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Transaction();
    }
}

void Admin::UserDetails() {
    sqlite3* DB;
    int exit = 0;
    int input;
    cout << "=======================================\n"
         << "|          ~ USER DETAILS ~           |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "=======================================\n";

    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1, answer2, answer3, answer4;
        cout << "Adding new user details (create)." << endl;
        cout << "Please enter user username: ";
        getline(cin, answer1);
        cout << "Please enter user password: ";
        getline(cin, answer2);
        cout << "Please enter user email: ";
        getline(cin, answer3);
        cout << "Please enter user phone number: ";
        getline(cin, answer4);

        string sql_insert_table39 = "INSERT INTO USER_DETAILS (USER_USERNAME, USER_PASSWORD, USER_EMAIL, USER_PHONE_NUMBER) VALUES ('" + answer1 + "', '" + answer2 + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table39.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        UserDetails();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table39 = "SELECT * FROM USER_DETAILS";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table39.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        UserDetails();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the user details ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update user username, 2 to update user password, 3 to update user email, 4 to update user phone number: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table39;

        switch (option) {
            case 1:
                cout << "Enter the new user username: ";
                cin >> newanswer;
                sql_update_table39 = "UPDATE USER_DETAILS SET USER_USERNAME = '" + newanswer + "' WHERE USER_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new user password: ";
                cin >> newanswer;
                sql_update_table39 = "UPDATE USER_DETAILS SET USER_PASSWORD = '" + newanswer + "' WHERE USER_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new user email: ";
                cin >> newanswer;
                sql_update_table39 = "UPDATE USER_DETAILS SET USER_EMAIL = '" + newanswer + "' WHERE USER_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new user phone number: ";
                cin >> newanswer;
                sql_update_table39 = "UPDATE USER_DETAILS SET USER_PHONE_NUMBER = '" + newanswer + "' WHERE USER_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table39.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        UserDetails();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the user details ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete user ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the user details page." << endl;
            UserDetails();
        } 
        else if (option == 'Y' || option == 'y') {
            string sql_delete_table39 = "DELETE FROM USER_DETAILS WHERE USER_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table39.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        UserDetails();
    }
    else if(input == 0){
        customerRelated();
    }
    else{
        cout<< "Invalid choice. Please enter a valid option. " <<endl;
        UserDetails();
    }
}

void Admin::Vitamins() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|              ~ Vitamins ~           |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Create                     |\n"
         << "|       2. Read                       |\n"
         << "|       3. Update                     |\n"
         << "|       4. Delete                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Back                       |\n"
         << "|       8. Exit program               |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    if (input == 1) {
        string answer1, answer2, answer4;
        double answer3;
        cout << "Adding new vitamins (create)." << endl;
        cout << "Please enter vitamins name: ";
        getline(cin, answer1);
        cout << "Please enter vitamins description: ";
        getline(cin, answer2);
        cout << "Please enter vitamins price: ";
        cin >> answer3;
        cin.clear();
        cin.ignore();
        cout << "Please enter vitamins dosage: ";
        getline(cin, answer4);

        string sql_insert_table40 = "INSERT INTO VITAMINS (VITAMINS_NAME, VITAMINS_DESCRIPTION, VITAMINS_PRICE, VITAMINS_DOSAGE) VALUES ('" + answer1 + "', '" + answer2 + "', '" + to_string(answer3) + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table40.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Vitamins();
        } 
        else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select_table40 = "SELECT * FROM VITAMINS";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table40.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Vitamins();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the vitamins ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update vitamins name, 2 to update vitamins description, 3 to update vitamins price, 4 to update vitamins dosage: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table40;

        switch (option) {
            case 1:
                cout << "Enter the new vitamins name: ";
                getline(cin, newanswer);
                sql_update_table40 = "UPDATE VITAMINS SET VITAMINS_NAME = '" + newanswer + "' WHERE VITAMINS_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new vitamins description: ";
                getline(cin, newanswer);
                sql_update_table40 = "UPDATE VITAMINS SET VITAMINS_DESCRIPTION = '" + newanswer + "' WHERE VITAMINS_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new vitamins price: ";
                cin >> newanswer;
                sql_update_table40 = "UPDATE VITAMINS SET VITAMINS_PRICE = '" + newanswer + "' WHERE VITAMINS_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new vitamins dosage: ";
                getline(cin, newanswer);
                sql_update_table40 = "UPDATE VITAMINS SET VITAMINS_DOSAGE = '" + newanswer + "' WHERE VITAMINS_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table40.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Vitamins();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the vitamins ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete vitamins ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the vitamins page." << endl;
            Vitamins();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table40 = "DELETE FROM VITAMINS WHERE VITAMINS_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table40.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Vitamins();
    }
    else if(input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Vitamins();
    }
}