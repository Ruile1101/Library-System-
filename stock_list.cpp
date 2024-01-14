#include "connect.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "sqlite3.h"
#include <string>
#include "connect.h"
#include <map>
using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

// Function to execute a query
void executeQuery(sqlite3* db, const string& tableName) {
    string query = "SELECT * FROM " + tableName;

    char *zErrMsg = nullptr;
    int rc = sqlite3_exec(db, query.c_str(), callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    } else {
        cout << "Operation done successfully\n";
    }
}

void stock_list(){
    int choice;

    cout <<  "=======================================\n"
            "|            ~ BEST DEAL ~            |\n"
            "=======================================\n"
            "|---------- NEW ERA PHARMACY ---------|\n"
            "=======================================\n"
            "|                                     |\n"
            "|       -- Enter your choice:         |\n"
            "|       1.  Supplement                |\n"
            "|       2.  Medical Supplies          |\n"
            "|       3.  Skin Care Product         |\n"
            "|       4.  Health Food               |\n"
            "|       5.  Others                    |\n"
            "|                                     |\n"  
            "|----------- other options -----------|\n"
            "|       99. Back                      |\n"
            "|       0.  Exit Program              |\n"
            "=======================================\n";

    cout << "Enter your choice: " << endl;
    cin >> choice;
    cout << endl;

        // Open a database connection
    sqlite3* DB;
    int exit = sqlite3_open("pharmacy.db", &DB);

    if (!DB) {
        cerr << "Failed to open database. Exiting.\n";
        return;
    }

    // Determine the table name based on user input
    string tableName;
    switch (choice) {
        case 1:
            tableName = "SUPPLEMENT";
            break;
        case 2:
            tableName = "MEDICAL_SUPPLY";
            break;
        case 3:
            tableName = "SKIN_CARE";
            break;
        case 4:
            tableName = "HEALTH_FOOD";
            break;
        case 5:
            tableName = "OTHERS";
            break;
        case 99:
            employee_main();
            break;
        case 0:
            int exit(0);
            break;
        default:
            cout << "Invalid input. \n";
    }

    // Execute the query for the selected table
    executeQuery(DB, tableName);

    // Close the database connection
    sqlite3_close(DB);

    return;
}