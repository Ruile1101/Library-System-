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

void Admin::admin_main(){
    cout << " ========================================\n" 
            " |        ~ Welcome To Admin Page ~     |\n" 
            " ========================================\n" 
            " |---------- NEW ERA PHARMACY ----------|\n" 
            " ========================================\n" 
            " |                                      |\n" 
            " |     -- Enter desired category:       |\n"
            " |        1.   Customer-related         |\n"
            " |        2.   Finance                  |\n" 
            " |        3.   Gift                     |\n"
            " |        4.   Hospitality              |\n"  
            " |        5.   Personnel-related        |\n"
            " |        6.   Products                 |\n" 
            " |                                      |\n" 
            " |------------ other options -----------|\n" 
            " |        0.   Exit program             |\n" 
            " ========================================\n";
    int category;
    cout << "Please enter your option: ";
    cin >> category;
    switch(category){
        case 1:
        customerRelated();
        break;

        case 2:
        finance();
        break;

        case 3:
        gift();
        break;

        case 4:
        hospitality();
        break;

        case 5:
        personnelRelated();
        break;

        case 6:
        products();
        break;

        case 0:
        exit(0);
        break;

        default:
        cout << "Please enter the correct option's number. "<<endl;
        break;
    }
            }

void Admin::customerRelated(){
    cout << " ========================================\n" 
            " | ~  Welcome To Customer-Related Page ~|\n" 
            " ========================================\n" 
            " |----------- NEW ERA PHARMACY ---------|\n" 
            " ========================================\n" 
            " |                                      |\n" 
            " |        -- Enter your choice:         |\n"
            " |        1.   Booking                  |\n"
            " |        2.   Delivery                 |\n" 
            " |        3.   Feedback                 |\n"
            " |        4.   Receipt                  |\n" 
            " |        5.   User Details             |\n"   
            " |                                      |\n" 
            " |------------ other options -----------|\n"
            " |        99.  Back                     |\n"  
            " |        0.   Exit program             |\n" 
            " ========================================\n";
    int answer;
    cout << "Please enter your option: ";
    cin >> answer;
    switch(answer){
        case 1:
        Booking();
        break;

        case 2:
        Delivery();
        break;

        case 3:
        Feedback();
        break;

        case 4:
        Receipt();
        break;

        case 5:
        UserDetails();
        break;

        case 99:
        admin_main();
        break;

        case 0:
        exit(0);
        break;

        default:
        cout << "Please enter the correct option's number. " << endl;
        break;
    }
}

void Admin::finance(){
    cout << " ========================================\n" 
            " |       ~ Welcome To Finance Page ~    |\n" 
            " ========================================\n" 
            " |----------- NEW ERA PHARMACY ---------|\n" 
            " ========================================\n" 
            " |                                      |\n" 
            " |        -- Enter your choice:         |\n"
            " |        1.   Capital                  |\n"
            " |        2.   Expenses                 |\n" 
            " |        3.   Financial Report         |\n"
            " |        4.   Income                   |\n"  
            " |        5.   Return                   |\n"  
            " |        6.   Transaction              |\n"  
            " |                                      |\n" 
            " |------------ other options -----------|\n" 
            " |        99.  Back                     |\n"  
            " |        0.   Exit program             |\n" 
            " ========================================\n";
    int answer;
    cout << "Please enter your option: ";
    cin >> answer;
    switch(answer){
        case 1:
        Capital();
        break;

        case 2:
        Expenses();
        break;

        case 3:
        FinancialReport();
        break;

        case 4:
        Income();
        break;

        case 5:
        Return();
        break;

        case 6:
        Transaction();
        break;

        case 99:
        admin_main();
        break;

        case 0:
        exit(0);
        break;

        default:
        cout << "Please enter the correct option's number. " << endl;
        break;
    }
}

void Admin::gift(){
    cout << " ========================================\n" 
            " |        ~ Welcome To Gift Page ~      |\n" 
            " ========================================\n" 
            " |----------- NEW ERA PHARMACY ---------|\n" 
            " ========================================\n" 
            " |                                      |\n" 
            " |        -- Enter your choice:         |\n"
            " |        1.   Discount                 |\n"
            " |        2.   Promotion                |\n" 
            " |        3.   Reward                   |\n"
            " |                                      |\n" 
            " |------------ other options -----------|\n" 
            " |        99.  Back                     |\n"  
            " |        0.   Exit program             |\n" 
            " ========================================\n";
    int answer;
    cout << "Please enter your option: ";
    cin >> answer;
    switch(answer){
        case 1:
        Discount();
        break;

        case 2:
        Promotion();
        break;

        case 3:
        Reward();
        break;

        case 99:
        admin_main();
        break;

        case 0:
        exit(0);
        break;

        default:
        cout << "Please enter the correct option's number. " << endl;
        break;
    }
}

void Admin::hospitality(){
    cout << " ========================================\n" 
            " |    ~ Welcome To Hospitality Page ~   |\n" 
            " ========================================\n" 
            " |----------- NEW ERA PHARMACY ---------|\n" 
            " ========================================\n" 
            " |                                      |\n" 
            " |        -- Enter your choice:         |\n"
            " |        1.   Appointment              |\n"
            " |        2.   Doctor                   |\n" 
            " |        3.   Medical Record           |\n"
            " |        4.   Patient                  |\n"
            " |        5.   Prescribed Medication    |\n"
            " |        6.   Prescription             |\n"
            " |        7.   Store                    |\n"
            " |                                      |\n" 
            " |------------ other options -----------|\n" 
            " |        99.  Back                     |\n"  
            " |        0.   Exit program             |\n" 
            " ========================================\n";
    int answer;
    cout << "Please enter your option: ";
    cin >> answer;
    switch(answer){
        case 1:
        Appointment();
        break;

        case 2:
        Doctor();
        break;

        case 3:
        MedicalRecord();
        break;

        case 4:
        Patient();
        break;

        case 5:
        PrescribedMedication();
        break;

        case 6:
        Prescription();
        break;

        case 7:
        Store();
        break;

        case 99:
        admin_main();
        break;

        case 0:
        exit(0);
        break;

        default:
        cout << "Please enter the correct option's number. " << endl;
        break;
    }
}

void Admin::personnelRelated(){
    cout << " ========================================\n" 
            " |~ Welcome To Personnel-Related Page ~ |\n" 
            " ========================================\n" 
            " |----------- NEW ERA PHARMACY ---------|\n" 
            " ========================================\n" 
            " |                                      |\n" 
            " |        -- Enter your choice:         |\n"
            " |        1.   Admin Details            |\n"
            " |        2.   Employee                 |\n" 
            " |        3.   Employee Schedule        |\n"
            " |        4.   Staff Details            |\n"
            " |        5.   Supplier                 |\n"
            " |                                      |\n" 
            " |------------ other options -----------|\n"
            " |        99.  Back                     |\n"   
            " |        0.   Exit program             |\n" 
            " ========================================\n";
    int answer;
    cout << "Please enter your option: ";
    cin >> answer;
    switch(answer){
        case 1:
        AdminDetails();
        break;

        case 2:
        Employee();
        break;

        case 3:
        EmployeeSchedule();
        break;

        case 4:
        StaffDetails();
        break;

        case 5:
        Supplier();
        break;

        case 99:
        admin_main();
        break;

        case 0:
        exit(0);
        break;

        default:
        cout << "Please enter the correct option's number. " << endl;
        break;
    }
}

void Admin::products(){
    cout << " ========================================\n" 
            " |      ~ Welcome To Products Page ~     |\n" 
            " =========================================\n" 
            " |----------- NEW ERA PHARMACY ----------|\n" 
            " =========================================\n" 
            " |                                       |\n" 
            " |        -- Enter your choice:          |\n"
            " |        1.    Antibiotics              |\n"
            " |        2.    Antidepressants          |\n" 
            " |        3.    Antidiabetic             |\n"
            " |        4.    Batch                    |\n"
            " |        5.    Health Food              |\n"
            " |        6.    Medical Supply           |\n"
            " |        7.    Others                   |\n"
            " |        8.    Product Review           |\n"
            " |        9.    Replacement              |\n"
            " |        10.   Skin Care                |\n"
            " |        11.   Stock                    |\n"
            " |        12.   Supplement               |\n"
            " |        13.   Supplier Product         |\n"
            " |        14.   Vitamins                 |\n"
            " |                                       |\n" 
            " |------------ other options ------------|\n" 
            " |        99.   Back                     |\n"  
            " |        0.    Exit program             |\n" 
            " =========================================\n";
    int answer;
    cout << "Please enter your option: ";
    cin >> answer;
    switch(answer){
        case 1:
        Antibiotics();
        break;

        case 2:
        Antidepressants();
        break;

        case 3:
        Antidiabetic();
        break;

        case 4:
        Batch();
        break;

        case 5:
        HealthFood();
        break;

        case 6:
        MedicalSupply();
        break;

        case 7:
        Others();
        break;

        case 8:
        ProductReview();
        break;

        case 9:
        Replacement();
        break;

        case 10:
        SkinCare();
        break;

        case 11:
        Stock();
        break;

        case 12:
        Supplement();
        break;

        case 13:
        SupplierProduct();
        break;

        case 14:
        Vitamins();
        break;

        case 99:
        admin_main();
        break;

        case 0:
        exit(0);
        break;

        default:
        cout << "Please enter the correct option's number. " << endl;
        break;
    }
}

void Admin::AdminDetails() {
    int exit = 0;
    sqlite3* DB;
    cout << "=======================================\n"
         << "|          ~ ADMIN DETAILS ~          |\n"
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
        cout << "Adding new admin details (create)." << endl;
        cout << "Please enter admin username: ";
        getline(cin, answer1);
        cout << "Please enter admin password: ";
        getline(cin, answer2);
        cout << "Please enter admin email: ";
        getline(cin, answer3);
        cout << "Please enter admin phone number: ";
        getline(cin, answer4);

        string sql_insert_table1 = "INSERT INTO ADMIN_DETAILS (ADMIN_USERNAME, ADMIN_PASSWORD, ADMIN_EMAIL, ADMIN_PHONE_NUMBER) VALUES ('" + answer1 + "', '" + answer2 + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table1.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        AdminDetails();
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

        string sql_select_table1 = "SELECT * FROM ADMIN_DETAILS";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table1.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        AdminDetails();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the admin details ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update admin username, 2 to update admin password, 3 to update admin email, 4 to update admin phone number: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table1;

        switch (option) {
            case 1:
                cout << "Enter the new admin username: ";
                getline(cin, newanswer);
                sql_update_table1 = "UPDATE ADMIN_DETAILS SET ADMIN_USERNAME = '" + newanswer + "' WHERE ADMIN_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new admin password: ";
                getline(cin, newanswer);
                sql_update_table1 = "UPDATE ADMIN_DETAILS SET ADMIN_PASSWORD = '" + newanswer + "' WHERE ADMIN_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new admin email: ";
                getline(cin, newanswer);
                sql_update_table1 = "UPDATE ADMIN_DETAILS SET ADMIN_EMAIL = '" + newanswer + "' WHERE ADMIN_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new admin phone number: ";
                getline(cin, newanswer);
                sql_update_table1 = "UPDATE ADMIN_DETAILS SET ADMIN_PHONE_NUMBER = '" + newanswer + "' WHERE ADMIN_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table1.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        AdminDetails();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the admin details ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete admin ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the admin page." << endl;
            AdminDetails();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table1 = "DELETE FROM ADMIN_DETAILS WHERE ADMIN_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table1.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        AdminDetails();
    }
    else if (input == 0){
        personnelRelated();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        AdminDetails();
    }
}

void Admin::Antibiotics() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ ANTIBIOTICS ~            |\n"
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
        double answer3;
        cout << "Adding new antibiotics (create)." << endl;
        cout << "Please enter antibiotics name: ";
        getline(cin, answer1);
        cout << "Please enter antibiotics description: ";
        getline(cin, answer2);
        cout << "Please enter antibiotics price: ";
        cin >> answer3;
        cin.clear();
        cin.ignore();
        cout << "Please enter antibiotics dosage: ";
        getline(cin, answer4);

        string sql_insert_table2 = "INSERT INTO ANTIBIOTICS (ANTIBIOTICS_NAME, ANTIBIOTICS_DESCRIPTION, ANTIBIOTICS_PRICE, ANTIBIOTICS_DOSAGE) VALUES ('" + answer1 + "', '" + answer2 + "', '" + to_string(answer3) + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table2.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Antibiotics();
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

        string sql_select_table2 = "SELECT * FROM ANTIBIOTICS";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table2.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Antibiotics();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the antibiotics ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update antibiotics name, 2 to update antibiotics description, 3 to update antibiotics price, 4 to update antibiotics dosage: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table2;

        switch (option) {
            case 1:
                cout << "Enter the new antibiotics name: ";
                getline(cin, newanswer);
                sql_update_table2 = "UPDATE ANTIBIOTICS SET ANTIBIOTICS_NAME = '" + newanswer + "' WHERE ANTIBIOTICS_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new antibiotics description: ";
                getline(cin, newanswer);
                sql_update_table2 = "UPDATE ANTIBIOTICS SET ANTIBIOTICS_DESCRIPTION = '" + newanswer + "' WHERE ANTIBIOTICS_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new antibiotics price: ";
                cin >> newanswer;
                sql_update_table2 = "UPDATE ANTIBIOTICS SET ANTIBIOTICS_PRICE = '" + newanswer + "' WHERE ANTIBIOTICS_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new antibiotics dosage: ";
                getline(cin, newanswer);
                sql_update_table2 = "UPDATE ANTIBIOTICS SET ANTIBIOTICS_DOSAGE = '" + newanswer + "' WHERE ANTIBIOTICS_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table2.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Antibiotics();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the antibiotics ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete antibiotics ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the antibiotics page." << endl;
            Antibiotics();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table2 = "DELETE FROM ANTIBIOTICS WHERE ANTIBIOTICS_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table2.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Antibiotics();
    }
    else if (input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Antibiotics();
    }
}

void Admin::Antidepressants() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ ANTIDEPRESSANTS ~        |\n"
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
        double answer3;
        cout << "Adding new antidepressants (create)." << endl;
        cout << "Please enter antidepressants name: ";
        getline(cin, answer1);
        cout << "Please enter antidepressants description: ";
        getline(cin, answer2);
        cout << "Please enter antidepressants price: ";
        cin >> answer3;
        cin.clear();
        cin.ignore();
        cout << "Please enter antidepressants dosage: ";
        getline(cin, answer4);

        string sql_insert_table3 = "INSERT INTO ANTIDEPRESSANTS (ANTIDEPRESSANTS_NAME, ANTIDEPRESSANTS_DESCRIPTION, ANTIDEPRESSANTS_PRICE, ANTIDEPRESSANTS_DOSAGE) VALUES ('" + answer1 + "', '" + answer2 + "', '" + to_string(answer3) + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table3.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Antidepressants();
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

        string sql_select_table3 = "SELECT * FROM ANTIDEPRESSANTS";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table3.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Antidepressants();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the antidepressants ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update antidepressants name, 2 to update antidepressants description, 3 to update antidepressants price, 4 to update antidepressants dosage: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table3;

        switch (option) {
            case 1:
                cout << "Enter the new antidepressants name: ";
                getline(cin, newanswer);
                sql_update_table3 = "UPDATE ANTIDEPRESSANTS SET ANTIDEPRESSANTS_NAME = '" + newanswer + "' WHERE ANTIDEPRESSANTS_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new antidepressants description: ";
                getline(cin, newanswer);
                sql_update_table3 = "UPDATE ANTIDEPRESSANTS SET ANTIDEPRESSANTS_DESCRIPTION = '" + newanswer + "' WHERE ANTIDEPRESSANTS_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new antidepressants price: ";
                cin >> newanswer;
                sql_update_table3 = "UPDATE ANTIDEPRESSANTS SET ANTIDEPRESSANTS_PRICE = '" + newanswer + "' WHERE ANTIDEPRESSANTS_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new antidepressants dosage: ";
                getline(cin, newanswer);
                sql_update_table3 = "UPDATE ANTIDEPRESSANTS SET ANTIDEPRESSANTS_DOSAGE = '" + newanswer + "' WHERE ANTIDEPRESSANTS_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table3.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Antidepressants();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the antidepressants ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete antidepressants ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the antidepressants page." << endl;
            Antidepressants();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table3 = "DELETE FROM ANTIDEPRESSANTS WHERE ANTIDEPRESSANTS_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table3.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Antidepressants();
    }
    else if (input ==0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Antidepressants();
    }
}

void Admin::Antidiabetic() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ ANTIDIABETIC ~           |\n"
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
        double answer3;
        cout << "Adding new antidiabetic (create)." << endl;
        cout << "Please enter antidiabetic name: ";
        getline(cin, answer1);
        cout << "Please enter antidiabetic description: ";
        getline(cin, answer2);
        cout << "Please enter antidiabetic price: ";
        cin >> answer3;
        cin.clear();
        cin.ignore();
        cout << "Please enter antidiabetic dosage: ";
        getline(cin, answer4);

        string sql_insert_table4 = "INSERT INTO ANTIDIABETIC (ANTIDIABETIC_NAME, ANTIDIABETIC_DESCRIPTION, ANTIDIABETIC_PRICE, ANTIDIABETIC_DOSAGE) VALUES ('" + answer1 + "', '" + answer2 + "', '" + to_string(answer3) + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table4.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Antidiabetic();
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

        string sql_select_table4 = "SELECT * FROM ANTIDIABETIC";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table4.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Antidiabetic();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the antidiabetic ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update antidiabetic name, 2 to update antidiabetic description, 3 to update antidiabetic price, 4 to update antidiabetic dosage: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table4;

        switch (option) {
            case 1:
                cout << "Enter the new antidiabetic name: ";
                getline(cin, newanswer);
                sql_update_table4 = "UPDATE ANTIDIABETIC SET ANTIDIABETIC_NAME = '" + newanswer + "' WHERE ANTIDIABETIC_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new antidiabetic description: ";
                getline(cin, newanswer);
                sql_update_table4 = "UPDATE ANTIDIABETIC SET ANTIDIABETIC_DESCRIPTION = '" + newanswer + "' WHERE ANTIDIABETIC_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new antidiabetic price: ";
                cin >> newanswer;
                sql_update_table4 = "UPDATE ANTIDIABETIC SET ANTIDIABETIC_PRICE = '" + newanswer + "' WHERE ANTIDIABETIC_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new antidiabetic dosage: ";
                getline(cin, newanswer);
                sql_update_table4 = "UPDATE ANTIDIABETIC SET ANTIDIABETIC_DOSAGE = '" + newanswer + "' WHERE ANTIDIABETIC_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table4.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Antidiabetic();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the antidiabetic ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete antidiabetic ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the antidiabetic page." << endl;
            Antidiabetic();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table4 = "DELETE FROM ANTIDIABETIC WHERE ANTIDIABETIC_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table4.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Antidiabetic();
    }
    else if(input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Antidiabetic();
    }
}

void Admin::Appointment() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ APPOINTMENT ~            |\n"
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
        cout << "Adding new appointment (create)." << endl;
        cout << "Please enter appointment date: ";
        getline(cin, answer1);
        cout << "Please enter appointment time: ";
        getline(cin, answer2);
        cout << "Please enter patient name: ";
        getline(cin, answer3);
        cout << "Please enter store name: ";
        getline(cin, answer4);

        string sql_insert_table5 = "INSERT INTO APPOINTMENT (APPOINTMENT_DATE, APPOINTMENT_TIME, PATIENT_NAME, STORE_NAME) VALUES ('" + answer1 + "', '" + answer2 + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table5.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Appointment();
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

        string sql_select_table5 = "SELECT * FROM APPOINTMENT";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table5.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Appointment();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the appointment ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update appointment date, 2 to update appointment time, 3 to update patient name, 4 to update store name: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table5;

        switch (option) {
            case 1:
                cout << "Enter the new appointment date: ";
                getline(cin, newanswer);
                sql_update_table5 = "UPDATE APPOINTMENT SET APPOINTMENT_DATE = '" + newanswer + "' WHERE APPOINTMENT_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new appointment time: ";
                getline(cin, newanswer);
                sql_update_table5 = "UPDATE APPOINTMENT SET APPOINTMENT_TIME = '" + newanswer + "' WHERE APPOINTMENT_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new patient name: ";
                getline(cin, newanswer);
                sql_update_table5 = "UPDATE APPOINTMENT SET PATIENT_NAME = '" + newanswer + "' WHERE APPOINTMENT_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new store name: ";
                getline(cin, newanswer);
                sql_update_table5 = "UPDATE APPOINTMENT SET STORE_NAME = '" + newanswer + "' WHERE APPOINTMENT_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table5.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Appointment();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the appointment ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete appointment ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the appointment page." << endl;
            Appointment();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table5 = "DELETE FROM APPOINTMENT WHERE APPOINTMENT_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table5.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Appointment();
    }
    else if(input == 0){
        hospitality();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Appointment();
    }
}

void Admin::Batch() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ BATCH ~                  |\n"
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
        int answer1, answer2;
        string answer3, answer4;
        cout << "Adding new batch (create)." << endl;
        cout << "Please enter stock ID: ";
        cin >> answer1;
        cout << "Please enter stock quantity: ";
        cin >> answer2;
        cin.clear();
        cin.ignore();
        cout << "Please enter expiry date: ";
        getline(cin, answer3);
        cout << "Please enter manufacturing date: ";
        getline(cin, answer4);

        string sql_insert_table6 = "INSERT INTO BATCH (STOCK_ID, STOCK_QUANTITY, EXPIRY_DATE, MANUFACTURING_DATE) VALUES ('" + to_string(answer1) + "', '" + to_string(answer2) + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table6.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Batch();
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

        string sql_select_table6 = "SELECT * FROM BATCH";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table6.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Batch();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the batch ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update stock ID, 2 to update stock quantity, 3 to update expiry date, 4 to update manufacturing date: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table6;

        switch (option) {
            case 1:
                cout << "Enter the new stock ID: ";
                cin >> newanswer;
                sql_update_table6 = "UPDATE BATCH SET STOCK_ID = '" + newanswer + "' WHERE BATCH_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new stock quantity: ";
                cin >> newanswer;
                sql_update_table6 = "UPDATE BATCH SET STOCK_QUANTITY = '" + newanswer + "' WHERE BATCH_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new expiry date: ";
                getline(cin, newanswer);
                sql_update_table6 = "UPDATE BATCH SET EXPIRY_DATE = '" + newanswer + "' WHERE BATCH_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new manufacturing date: ";
                getline(cin, newanswer);
                sql_update_table6 = "UPDATE BATCH SET MANUFACTURING_DATE = '" + newanswer + "' WHERE BATCH_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table6.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Batch();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the batch ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete appointment ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the batch page." << endl;
            Batch();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table6 = "DELETE FROM BATCH WHERE BATCH_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table6.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Batch();
    }
    else if(input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Batch();
    }
}

void Admin::Booking() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ BOOKING ~                |\n"
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
        int answer1;
        string answer2, answer3;
        double answer4;
        cout << "Adding new booking (create)." << endl;
        cout << "Please enter item list: ";
        cin >> answer1;
        cin.clear();
        cin.ignore();
        cout << "Please enter customer name: ";
        getline(cin, answer2);
        cout << "Please enter customer phone number: ";
        getline(cin, answer3);
        cout << "Please enter total price: ";
        cin >> answer4;

        string sql_insert_table7 = "INSERT INTO BOOKING (ITEM_LIST, CUSTOMER_NAME, CUSTOMER_PHONE_NUMBER, TOTAL_PRICE) VALUES ('" + to_string(answer1) + "', '" + answer2 + "', '" + answer3 + "', '" + to_string(answer4) + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table7.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Booking();
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

        string sql_select_table7 = "SELECT * FROM BOOKING";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table7.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Booking();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the booking ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update item list, 2 to update customer name, 3 to update customer phone number, 4 to update total price: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table7;

        switch (option) {
            case 1:
                cout << "Enter the new item list: ";
                cin >> newanswer;
                sql_update_table7 = "UPDATE BOOKING SET ITEM_LIST = '" + newanswer + "' WHERE BOOKING_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new customer name: ";
                getline(cin, newanswer);
                sql_update_table7 = "UPDATE BOOKING SET CUSTOMER_NAME = '" + newanswer + "' WHERE BOOKING_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new customer phone number: ";
                getline(cin, newanswer);
                sql_update_table7 = "UPDATE BOOKING SET CUSTOMER_PHONE_NUMBER = '" + newanswer + "' WHERE BOOKING_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new total price: ";
                cin >> newanswer;
                sql_update_table7 = "UPDATE BOOKING SET TOTAL_PRICE = '" + newanswer + "' WHERE BOOKING_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table7.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Booking();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the booking ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete booking ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the booking page." << endl;
            Booking();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table7 = "DELETE FROM BOOKING WHERE BOOKING_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table7.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Booking();
    }
    else if (input == 0){
        customerRelated();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Booking();
    }
}

void Admin::Capital() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ CAPITAL ~                |\n"
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
        int answer1;
        string answer2, answer3;
        cout << "Adding capital (create)." << endl;
        cout << "Please enter capital amount: ";
        cin >> answer1;
        cin.clear();
        cin.ignore();
        cout << "Please enter capital source: ";
        getline(cin, answer2);
        cout << "Please enter capital description: ";
        getline(cin, answer3);

        string sql_insert_table8 = "INSERT INTO CAPITAL (CAPITAL_AMOUNT, CAPITAL_SOURCE, CAPITAL_DESCRIPTION) VALUES ('" + to_string(answer1) + "', '" + answer2 + "', '" + answer3 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table8.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Capital();
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

        string sql_select_table8 = "SELECT * FROM CAPITAL";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table8.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Capital();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the capital ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update capital amount, 2 to update capital source, 3 to update capital description: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table8;

        switch (option) {
            case 1:
                cout << "Enter the new capital amount: ";
                cin >> newanswer;
                sql_update_table8 = "UPDATE CAPITAL SET CAPITAL_AMOUNT = '" + newanswer + "' WHERE CAPITAL_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new capital source: ";
                getline(cin, newanswer);
                sql_update_table8 = "UPDATE CAPITAL SET CAPITAL_SOURCE = '" + newanswer + "' WHERE CAPITAL_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new capital description: ";
                getline(cin, newanswer);
                sql_update_table8 = "UPDATE CAPITAL SET CAPITAL_DESCRIPTION = '" + newanswer + "' WHERE CAPITAL_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table8.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Capital();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the capital ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete capital ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the capital page." << endl;
            Capital();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table8 = "DELETE FROM CAPITAL WHERE CAPITAL_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table8.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Capital();
    }
    else if (input == 0){
        finance();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Capital();
    }
}

void Admin::Delivery() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ DELIVERY ~               |\n"
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
        cout << "Adding new delivery (create)." << endl;
        cout << "Please enter delivery address: ";
        getline(cin, answer1);
        cout << "Please enter user phone number: ";
        getline(cin, answer2);
        cout << "Please enter user name: ";
        getline(cin, answer3);
        cout << "Please enter item list: ";
        getline(cin, answer4);

        string sql_insert_table9 = "INSERT INTO DELIVERY (DELIVERY_ADDRESS, USER_PHONE_NUMBER, USER_NAME, ITEM_LIST) VALUES ('" + answer1 + "', '" + answer2 + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table9.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Delivery();
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

        string sql_select_table9 = "SELECT * FROM DELIVERY";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table9.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Delivery();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the delivery ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update delivery address, 2 to update user phone number, 3 to update user name, 4 to update item list: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table9;

        switch (option) {
            case 1:
                cout << "Enter the new delivery address: ";
                getline(cin, newanswer);
                sql_update_table9 = "UPDATE DELIVERY SET DELIVERY_ADDRESS = '" + newanswer + "' WHERE DELIVERY_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new user phone number: ";
                getline(cin, newanswer);
                sql_update_table9 = "UPDATE DELIVERY SET USER_PHONE_NUMBER = '" + newanswer + "' WHERE DELIVERY_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new user name: ";
                getline(cin, newanswer);
                sql_update_table9 = "UPDATE DELIVERY SET USER_NAME = '" + newanswer + "' WHERE DELIVERY_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new item list: ";
                getline(cin, newanswer);
                sql_update_table9 = "UPDATE DELIVERY SET ITEM_LIST = '" + newanswer + "' WHERE DELIVERY_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table9.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Delivery();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the delivery ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete delivery ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the delivery page." << endl;
            Delivery();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table9 = "DELETE FROM DELIVERY WHERE DELIVERY_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table9.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Delivery();
    }
    else if(input == 0){
        customerRelated();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Delivery();
    }
}

void Admin::Discount() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ DISCOUNT ~               |\n"
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
        int answer1, answer2;
        cout << "Adding new discount (create)." << endl;
        cout << "Please enter discount amount: ";
        cin >> answer1;
        cout << "Please enter reward ID: ";
        cin >> answer2;

        string sql_insert_table10 = "INSERT INTO DISCOUNT (DISCOUNT_AMOUNT, REWARD_ID) VALUES ('" + to_string(answer1) + "', '" + to_string(answer2) + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table10.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Discount();
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

        string sql_select_table10 = "SELECT * FROM DISCOUNT";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table10.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Discount();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the discount ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update discount amount, 2 to update reward ID: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table10;

        switch (option) {
            case 1:
                cout << "Enter the new discount amount: ";
                cin >> newanswer;
                sql_update_table10 = "UPDATE DISCOUNT SET DISCOUNT_AMOUNT = '" + newanswer + "' WHERE DISCOUNT_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new reward ID: ";
                cin >> newanswer;
                sql_update_table10 = "UPDATE DISCOUNT SET REWARD_ID = '" + newanswer + "' WHERE DISCOUNT_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table10.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Discount();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the discount ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete discount ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the discount page." << endl;
            Discount();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table10 = "DELETE FROM DISCOUNT WHERE DISCOUNT_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table10.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Discount();
    }
    else if (input == 0){
        gift();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Discount();
    }
}

void Admin::Doctor() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ DOCTOR ~                 |\n"
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
        cout << "Adding new doctor (create)." << endl;
        cout << "Please enter doctor name: ";
        getline(cin, answer1);
        cout << "Please enter doctor phone number: ";
        getline(cin, answer2);
        cout << "Please enter doctor expertise: ";
        getline(cin, answer3);
        cout << "Please enter doctor gender: ";
        getline(cin, answer4);

        string sql_insert_table11 = "INSERT INTO DOCTOR (DOCTOR_NAME, DOCTOR_PHONE_NUMBER, DOCTOR_EXPERTISE, DOCTOR_GENDER) VALUES ('" + answer1 + "', '" + answer2 + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table11.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Doctor();
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

        string sql_select_table11 = "SELECT * FROM DOCTOR";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table11.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Doctor();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the doctor ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update doctor name, 2 to update doctor phone number, 3 to update doctor expertise, 4 to update doctor gender: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table11;

        switch (option) {
            case 1:
                cout << "Enter the new doctor name: ";
                getline(cin, newanswer);
                sql_update_table11 = "UPDATE DOCTOR SET DOCTOR_NAME = '" + newanswer + "' WHERE DOCTOR_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new doctor phone number: ";
                getline(cin, newanswer);
                sql_update_table11 = "UPDATE DOCTOR SET DOCTOR_PHONE_NUMBER = '" + newanswer + "' WHERE DOCTOR_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new doctor expertise: ";
                getline(cin, newanswer);
                sql_update_table11 = "UPDATE DOCTOR SET DOCTOR_EXPERTISE = '" + newanswer + "' WHERE DOCTOR_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new doctor gender: ";
                getline(cin, newanswer);
                sql_update_table11 = "UPDATE DOCTOR SET DOCTOR_GENDER = '" + newanswer + "' WHERE DOCTOR_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table11.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Doctor();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the doctor ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete doctor ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the doctor page." << endl;
            Doctor();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table11 = "DELETE FROM DOCTOR WHERE DOCTOR_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table11.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Doctor();
    }
    else if (input == 0){
        hospitality();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Doctor();
    }
}

void Admin::Employee() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ EMPLOYEE ~               |\n"
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
        string answer1, answer2;
        double answer3;
        cout << "Adding new employee (create)." << endl;
        cout << "Please enter employee name: ";
        getline(cin, answer1);
        cout << "Please enter employee position: ";
        getline(cin, answer2);
        cout << "Please enter employee salary: ";
        cin >> answer3;

        string sql_insert_table12 = "INSERT INTO EMPLOYEE (EMPLOYEE_NAME, EMPLOYEE_POSITION, EMPLOYEE_SALARY) VALUES ('" + answer1 + "', '" + answer2 + "', '" + to_string(answer3) + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table12.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Employee();
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

        string sql_select_table12 = "SELECT * FROM EMPLOYEE";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table12.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Employee();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the employee ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update employee name, 2 to update employee position, 3 to update employee salary: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table12;

        switch (option) {
            case 1:
                cout << "Enter the new employee name: ";
                getline(cin, newanswer);
                sql_update_table12 = "UPDATE EMPLOYEE SET EMPLOYEE_NAME = '" + newanswer + "' WHERE EMPLOYEE_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new employee position: ";
                getline(cin, newanswer);
                sql_update_table12 = "UPDATE EMPLOYEE SET EMPLOYEE_POSITION = '" + newanswer + "' WHERE EMPLOYEE_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new employee salary: ";
                cin >> newanswer;
                sql_update_table12 = "UPDATE EMPLOYEE SET EMPLOYEE_SALARY = '" + newanswer + "' WHERE EMPLOYEE_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table12.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Employee();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the employee ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete employee ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the employee page." << endl;
            Employee();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table12 = "DELETE FROM EMPLOYEE WHERE EMPLOYEE_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table12.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Employee();
    }
    else if(input == 0){
        personnelRelated();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Employee();
    }
}

void Admin::EmployeeSchedule() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|       ~ EMPLOYEE SCHEDULE ~         |\n"
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
        string answer1;
        int answer2, answer3;
        cout << "Adding new employee schedule (create)." << endl;
        cout << "Please enter schedule date: ";
        getline(cin, answer1);
        cout << "Please enter staff ID: ";
        cin >> answer2;
        cout << "Please enter working hour: ";
        cin >> answer3;

        string sql_insert_table13 = "INSERT INTO EMPLOYEE_SCHEDULE (SCHEDULE_DATE, STAFF_ID, WORKING_HOUR) VALUES ('" + answer1 + "', '" + to_string(answer2) + "', '" + to_string(answer3) + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table13.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        EmployeeSchedule();
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

        string sql_select_table13 = "SELECT * FROM EMPLOYEE_SCHEDULE";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table13.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        EmployeeSchedule();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the employee schedule ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update schedule date, 2 to update staff ID, 3 to update working hour: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table13;

        switch (option) {
            case 1:
                cout << "Enter the new schedule date: ";
                getline(cin, newanswer);
                sql_update_table13 = "UPDATE EMPLOYEE_SCHEDULE SET SCHEDULE_DATE = '" + newanswer + "' WHERE SCHEDULE_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new staff ID: ";
                cin >> newanswer;
                sql_update_table13 = "UPDATE EMPLOYEE_SCHEDULE SET STAFF_ID = '" + newanswer + "' WHERE SCHEDULE_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new working hour: ";
                cin >> newanswer;
                sql_update_table13 = "UPDATE EMPLOYEE_SCHEDULE SET WORKING_HOUR = '" + newanswer + "' WHERE SCHEDULE_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table13.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        EmployeeSchedule();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the employee schedule ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete employee schedule ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the employee schedule page." << endl;
            EmployeeSchedule();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table13 = "DELETE FROM EMPLOYEE_SCHEDULE WHERE SCHEDULE_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table13.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        EmployeeSchedule();
    }
    else if(input == 0){
        personnelRelated();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        EmployeeSchedule();
    }
}

void Admin::Expenses() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|           ~ EXPENSES ~              |\n"
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
        string answer1, answer3, answer4;
        double answer2;
        cout << "Adding new expenses (create)." << endl;
        cout << "Please enter expenses type: ";
        getline(cin, answer1);
        cout << "Please enter expenses amount: ";
        cin >> answer2;
        cin.clear();
        cin.ignore();
        cout << "Please enter expenses date: ";
        getline(cin, answer3);
        cout << "Please enter expenses description: ";
        getline(cin, answer4);

        string sql_insert_table14 = "INSERT INTO EXPENSES (EXPENSES_TYPE, EXPENSES_AMOUNT, EXPENSES_DATE, EXPENSES_DESCRIPTION) VALUES ('" + answer1 + "', '" + to_string(answer2) + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table14.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Expenses();
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

        string sql_select_table14 = "SELECT * FROM EXPENSES";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table14.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Expenses();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the expenses ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update expenses type, 2 to update expenses amount, 3 to update expenses date, 4 to update expenses description: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table14;

        switch (option) {
            case 1:
                cout << "Enter the new expenses type: ";
                getline(cin, newanswer);
                sql_update_table14 = "UPDATE EXPENSES SET EXPENSES_TYPE = '" + newanswer + "' WHERE EXPENSES_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new expenses amount: ";
                cin >> newanswer;
                sql_update_table14 = "UPDATE EXPENSES SET EXPENSES_AMOUNT = '" + newanswer + "' WHERE EXPENSES_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new expenses date: ";
                getline(cin, newanswer);
                sql_update_table14 = "UPDATE EXPENSES SET EXPENSES_DATE = '" + newanswer + "' WHERE EXPENSES_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new expenses description: ";
                getline(cin, newanswer);
                sql_update_table14 = "UPDATE EXPENSES SET EXPENSES_DESCRIPTION = '" + newanswer + "' WHERE EXPENSES_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table14.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Expenses();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the expenses ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete expenses ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the expenses page." << endl;
            Expenses();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table14 = "DELETE FROM EXPENSES WHERE EXPENSES_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table14.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Expenses();
    }
    else if(input == 0){
        finance();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Expenses();
    }
}

void Admin::Feedback() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|           ~ FEEDBACK ~              |\n"
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
        int answer1;
        string answer2, answer3, answer4;
        cout << "Adding new feedback (create)." << endl;
        cout << "Please enter user ID: ";
        cin >> answer1;
        cin.clear();
        cin.ignore();
        cout << "Please enter date submitted: ";
        getline(cin, answer2);
        cout << "Please enter time submitted: ";
        getline(cin, answer3);
        cout << "Please enter feedback message: ";
        getline(cin, answer4);

        string sql_insert_table15 = "INSERT INTO FEEDBACK (USER_ID, DATE_SUBMITTED, TIME_SUBMITTED, FEEDBACK_MESSAGE) VALUES ('" + to_string(answer1) + "', '" + answer2 + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table15.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Feedback();
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

        string sql_select_table15 = "SELECT * FROM FEEDBACK";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table15.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Feedback();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the feedback ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update user ID, 2 to update date submitted, 3 to update time submitted, 4 to update feedback message: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table15;

        switch (option) {
            case 1:
                cout << "Enter the new user ID: ";
                cin >> newanswer;
                sql_update_table15 = "UPDATE FEEDBACK SET USER_ID = '" + newanswer + "' WHERE FEEDBACK_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new date submitted: ";
                getline(cin, newanswer);
                sql_update_table15 = "UPDATE FEEDBACK SET DATE_SUBMITTED = '" + newanswer + "' WHERE FEEDBACK_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new time submitted: ";
                getline(cin, newanswer);
                sql_update_table15 = "UPDATE FEEDBACK SET TIME_SUBMITTED = '" + newanswer + "' WHERE FEEDBACK_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new feedback message: ";
                getline(cin, newanswer);
                sql_update_table15 = "UPDATE FEEDBACK SET FEEDBACK_MESSAGE = '" + newanswer + "' WHERE FEEDBACK_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table15.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Feedback();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the feedback ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete feedback ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the feedback page." << endl;
            Feedback();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table15 = "DELETE FROM FEEDBACK WHERE FEEDBACK_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table15.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Feedback();
    }
    else if(input == 0){
        customerRelated();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Feedback();
    }
}

void Admin::FinancialReport() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|       ~ FINANCIAL REPORT ~          |\n"
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
        int answer1;
        double answer2, answer3, answer4;
        cout << "Adding new financial report (create)." << endl;
        cout << "Please enter financial year: ";
        cin >> answer1;
        cout << "Please enter total income: ";
        cin >> answer2;
        cout << "Please enter total profit: ";
        cin >> answer3;
        cout << "Please enter capital: ";
        cin >> answer4;

        string sql_insert_table16 = "INSERT INTO FINANCIAL_REPORT (FINANCIAL_YEAR, TOTAL_INCOME, TOTAL_PROFIT, CAPITAL) VALUES ('" + to_string(answer1) + "', '" + to_string(answer2) + "', '" + to_string(answer3) + "', '" + to_string(answer4) + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table16.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        FinancialReport();
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

        string sql_select_table16 = "SELECT * FROM FINANCIAL_REPORT";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table16.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        FinancialReport();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the financial report ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update financial year, 2 to update total income, 3 to update total profit, 4 to update capital: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table16;

        switch (option) {
            case 1:
                cout << "Enter the new financial year: ";
                cin >> newanswer;
                sql_update_table16 = "UPDATE FINANCIAL_REPORT SET FINANCIAL_YEAR = '" + newanswer + "' WHERE FINANCIAL_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new total income: ";
                cin >> newanswer;
                sql_update_table16 = "UPDATE FINANCIAL_REPORT SET TOTAL_INCOME = '" + newanswer + "' WHERE FINANCIAL_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new total profit: ";
                cin >> newanswer;
                sql_update_table16 = "UPDATE FINANCIAL_REPORT SET TOTAL_PROFIT = '" + newanswer + "' WHERE FINANCIAL_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new capital: ";
                cin >> newanswer;
                sql_update_table16 = "UPDATE FINANCIAL_REPORT SET CAPITAL = '" + newanswer + "' WHERE FINANCIAL_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table16.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        FinancialReport();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the financial report ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete financial report ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the financial report page." << endl;
            FinancialReport();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table16 = "DELETE FROM FINANCIAL_REPORT WHERE FINANCIAL_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table16.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        FinancialReport();
    }
    else if(input == 0){
        finance();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        FinancialReport();
    }
}

void Admin::HealthFood() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|          ~ HEALTH FOOD ~            |\n"
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
        double answer2;
        int answer3;
        cout << "Adding new health food (create)." << endl;
        cout << "Please enter health food name: ";
        getline(cin, answer1);
        cout << "Please enter health food price: ";
        cin >> answer2;
        cout << "Please enter health food quantity: ";
        cin >> answer3;
        cin.clear();
        cin.ignore();
        cout << "Please enter health food description: ";
        getline(cin, answer4);

        string sql_insert_table17 = "INSERT INTO HEALTH_FOOD (HEALTH_FOOD_NAME, HEALTH_FOOD_PRICE, HEALTH_FOOD_QUANTITY, HEALTH_FOOD_DESCRIPTION) VALUES ('" + answer1 + "', '" + to_string(answer2) + "', '" + to_string(answer3) + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table17.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        HealthFood();
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

        string sql_select_table17 = "SELECT * FROM HEALTH_FOOD";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table17.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        HealthFood();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the health food ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update health food name, 2 to update health food price, 3 to update health food quantity, 4 to update health food description: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table17;

        switch (option) {
            case 1:
                cout << "Enter the new health food name: ";
                getline(cin, newanswer);
                sql_update_table17 = "UPDATE HEALTH_FOOD SET HEALTH_FOOD_NAME = '" + newanswer + "' WHERE HEALTH_FOOD_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new health food price: ";
                cin >> newanswer;
                sql_update_table17 = "UPDATE HEALTH_FOOD SET HEALTH_FOOD_PRICE = '" + newanswer + "' WHERE HEALTH_FOOD_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new health food quantity: ";
                cin >> newanswer;
                sql_update_table17 = "UPDATE HEALTH_FOOD SET HEALTH_FOOD_QUANTITY = '" + newanswer + "' WHERE HEALTH_FOOD_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new health food description: ";
                getline(cin, newanswer);
                sql_update_table17 = "UPDATE HEALTH_FOOD SET HEALTH_FOOD_DESCRIPTION = '" + newanswer + "' WHERE HEALTH_FOOD_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table17.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        HealthFood();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the health food ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete health food ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the health food page." << endl;
            HealthFood();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table17 = "DELETE FROM HEALTH_FOOD WHERE HEALTH_FOOD_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table17.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        HealthFood();
    }
    else if(input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        HealthFood();
    }
}

void Admin::Income() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|            ~ INCOME ~               |\n"
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
        double answer1;
        string answer2, answer3;
        cout << "Adding new income (create)." << endl;
        cout << "Please enter income amount: ";
        cin >> answer1;
        cin.clear();
        cin.ignore();
        cout << "Please enter income source: ";
        getline(cin, answer2);
        cout << "Please enter income date: ";
        getline(cin, answer3);

        string sql_insert_table18 = "INSERT INTO INCOME (INCOME_AMOUNT, INCOME_SOURCE, INCOME_DATE) VALUES ('" + to_string(answer1) + "', '" + answer2 + "', '" + answer3 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table18.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        Income();
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

        string sql_select_table18 = "SELECT * FROM INCOME";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table18.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        Income();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the income ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update income amount, 2 to update income source, 3 to update income date: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table18;

        switch (option) {
            case 1:
                cout << "Enter the new income amount: ";
                cin >> newanswer;
                sql_update_table18 = "UPDATE INCOME SET INCOME_AMOUNT = '" + newanswer + "' WHERE INCOME_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new income source: ";
                getline(cin, newanswer);
                sql_update_table18 = "UPDATE INCOME SET INCOME_SOURCE = '" + newanswer + "' WHERE INCOME_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new income date: ";
                getline(cin, newanswer);
                sql_update_table18 = "UPDATE INCOME SET INCOME_DATE = '" + newanswer + "' WHERE INCOME_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table18.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        Income();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the income ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete income ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the income page." << endl;
            Income();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table18 = "DELETE FROM INCOME WHERE INCOME_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table18.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        Income();
    }
    else if(input == 0){
        finance();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        Income();
    }
}

void Admin::MedicalRecord() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|         ~ MEDICAL RECORD ~          |\n"
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
        cout << "Adding new medical record (create)." << endl;
        cout << "Please enter patient name: ";
        getline(cin, answer1);
        cout << "Please enter doctor name: ";
        getline(cin, answer2);
        cout << "Please enter diagnosis: ";
        getline(cin, answer3);
        cout << "Please enter treatment: ";
        getline(cin, answer4);

        string sql_insert_table19 = "INSERT INTO MEDICAL_RECORD (PATIENT_NAME, DOCTOR_NAME, DIAGNOSIS, TREATMENT) VALUES ('" + answer1 + "', '" + answer2 + "', '" + answer3 + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table19.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        MedicalRecord();
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

        string sql_select_table19 = "SELECT * FROM MEDICAL_RECORD";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table19.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        MedicalRecord();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the medical record ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update patient name, 2 to update doctor name, 3 to update diagnosis, 4 to update treatment: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table19;

        switch (option) {
            case 1:
                cout << "Enter the new patient name: ";
                getline(cin, newanswer);
                sql_update_table19 = "UPDATE MEDICAL_RECORD SET PATIENT_NAME = '" + newanswer + "' WHERE RECORD_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new doctor name: ";
                getline(cin, newanswer);
                sql_update_table19 = "UPDATE MEDICAL_RECORD SET DOCTOR_NAME = '" + newanswer + "' WHERE RECORD_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new diagnosis: ";
                getline(cin, newanswer);
                sql_update_table19 = "UPDATE MEDICAL_RECORD SET DIAGNOSIS = '" + newanswer + "' WHERE RECORD_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new treatment: ";
                getline(cin, newanswer);
                sql_update_table19 = "UPDATE MEDICAL_RECORD SET TREATMENT = '" + newanswer + "' WHERE RECORD_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table19.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        MedicalRecord();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the medical record ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete medical record ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the medical record page." << endl;
            MedicalRecord();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table19 = "DELETE FROM MEDICAL_RECORD WHERE RECORD_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table19.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        MedicalRecord();
    }
    else if(input == 0){
        hospitality();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        MedicalRecord();
    }
}

void Admin::MedicalSupply() {
    sqlite3* DB;
    int exit = 0;
    cout << "=======================================\n"
         << "|         ~ MEDICAL SUPPLY ~          |\n"
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
        cout << "Adding new medical supply (create)." << endl;
        cout << "Please enter medical supply name: ";
        getline(cin, answer1);
        cout << "Please enter medical supply price: ";
        cin >> answer2;
        cout << "Please enter medical supply quantity: ";
        cin >> answer3;
        cin.clear();
        cin.ignore();
        cout << "Please enter medical supply description: ";
        getline(cin, answer4);

        string sql_insert_table20 = "INSERT INTO MEDICAL_SUPPLY (MEDICAL_SUPPLY_NAME, MEDICAL_SUPPLY_PRICE, MEDICAL_SUPPLY_QUANTITY, MEDICAL_SUPPLY_DESCRIPTION) VALUES ('" + answer1 + "', '" + to_string(answer2) + "', '" + to_string(answer3) + "', '" + answer4 + "')";
        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_insert_table20.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error inserting table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data inserted successfully!" << endl;
        }

        sqlite3_close(DB);
        MedicalSupply();
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

        string sql_select_table20 = "SELECT * FROM MEDICAL_SUPPLY";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select_table20.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
        MedicalSupply();
    } 
    else if (input == 3) {
        int answer, option;
        cout << "Please enter the medical supply ID you wish to update." << endl;
        cin >> answer;
        cin.clear();
        cin.ignore();
        cout << "Enter 1 to update medical supply name, 2 to update medical supply price, 3 to update medical supply quantity, 4 to update medical supply description: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        string newanswer;
        string sql_update_table20;

        switch (option) {
            case 1:
                cout << "Enter the new medical supply name: ";
                getline(cin, newanswer);
                sql_update_table20 = "UPDATE MEDICAL_SUPPLY SET MEDICAL_SUPPLY_NAME = '" + newanswer + "' WHERE MEDICAL_SUPPLY_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new medical supply price: ";
                cin >> newanswer;
                sql_update_table20 = "UPDATE MEDICAL_SUPPLY SET MEDICAL_SUPPLY_PRICE = '" + newanswer + "' WHERE MEDICAL_SUPPLY_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new medical supply quantity: ";
                cin >> newanswer;
                sql_update_table20 = "UPDATE MEDICAL_SUPPLY SET MEDICAL_SUPPLY_QUANTITY = '" + newanswer + "' WHERE MEDICAL_SUPPLY_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new medical supply description: ";
                getline(cin, newanswer);
                sql_update_table20 = "UPDATE MEDICAL_SUPPLY SET MEDICAL_SUPPLY_DESCRIPTION = '" + newanswer + "' WHERE MEDICAL_SUPPLY_ID = " + to_string(answer);
                break;

            default:
                cout << "Invalid option." << endl;
                return;
        }

        exit = sqlite3_open("pharmacy.db", &DB);
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_update_table20.c_str(), NULL, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error updating table: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        } else {
            cout << "Data updated successfully!" << endl;
        }

        sqlite3_close(DB);
        MedicalSupply();
    } 
    else if (input == 4) {
        int answer;
        char option;
        cout << "Please enter the medical supply ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete medical supply ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;
        cin.clear();
        cin.ignore();

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the medical supply page." << endl;
            MedicalSupply();
        } else if (option == 'Y' || option == 'y') {
            string sql_delete_table20 = "DELETE FROM MEDICAL_SUPPLY WHERE MEDICAL_SUPPLY_ID = " + to_string(answer);

            exit = sqlite3_open("pharmacy.db", &DB);
            char* messaggeError;
            exit = sqlite3_exec(DB, sql_delete_table20.c_str(), NULL, 0, &messaggeError);

            if (exit != SQLITE_OK) {
                cerr << "Error deleting table: " << messaggeError << endl;
                sqlite3_free(messaggeError);
            } else {
                cout << "Data deleted successfully!" << endl;
            }

            sqlite3_close(DB);
        }
        MedicalSupply();
    }
    else if(input == 0){
        products();
    }
    else{
        cout<< "Please enter a correct option." <<endl;
        MedicalSupply();
    }
}