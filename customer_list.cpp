#include "connect.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "sqlite3.h"
#include <string>
#include "connect.h"
using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void customer_list(){
int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select = "SELECT * FROM USER_DETAILS";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
}