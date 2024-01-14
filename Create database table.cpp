#include "user.h"
#include "admin.h"
#include "employee.h"
#include "sqlite3.h"
#include <string>
#include <iostream>
using namespace std;

void createTables();

void createTables(){
    sqlite3* DB;
    int exit=0;

 string sql_create_table1 = "CREATE TABLE USER_DETAILS("
                                   "USER_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "USER_USERNAME TEXT NOT NULL, "
                                   "USER_PASSWORD TEXT NOT NULL, "
                                   "USER_EMAIL TEXT NOT NULL, "
                                   "USER_PHONE_NUMBER TEXT NOT NULL );";
    
    string sql_create_table2 = "CREATE TABLE ADMIN_DETAILS("
                                   "ADMIN_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "ADMIN_USERNAME TEXT NOT NULL, "
                                   "ADMIN_PASSWORD TEXT NOT NULL, "
                                   "ADMIN_EMAIL TEXT NOT NULL, "
                                   "ADMIN_PHONE_NUMBER TEXT NOT NULL );";
    
    string sql_create_table3 = "CREATE TABLE DELIVERY("
                                   "DELIVERY_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "DELIVERY_ADDRESS TEXT NOT NULL, "
                                   "USER_PHONE_NUMBER TEXT NOT NULL, "
                                   "USER_NAME TEXT NOT NULL, "
                                   "ITEM_LIST TEXT NOT NULL );";

    string sql_create_table4 = "CREATE TABLE REWARD("
                                   "REWARD_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "USER_USERNAME TEXT NOT NULL, "
                                   "VOUCHER_VALUE INTEGER NOT NULL, "
                                   "VOUCHER_EXPIRY_DATE DATE NOT NULL, "
                                   "VOUCHER_QUANTITY INTEGER NOT NULL );";

    string sql_create_table5 = "CREATE TABLE STOCK("
                                   "STOCK_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "STOCK_NAME TEXT NOT NULL, "
                                   "STOCK_QUANTITY INTEGER NOT NULL, "
                                   "STOCK_PRICE DOUBLE NOT NULL, "
                                   "STOCK_DESCRIPTION TEXT NOT NULL );";

    string sql_create_table6 = "CREATE TABLE FINANCIAL_REPORT("
                                   "FINANCIAL_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "FINANCIAL_YEAR INTEGER NOT NULL, "
                                   "TOTAL_INCOME DOUBLE NOT NULL, "
                                   "TOTAL_PROFIT DOUBLE NOT NULL, "
                                   "CAPITAL DOUBLE NOT NULL );";
        
    string sql_create_table7 = "CREATE TABLE PRODUCT_REVIEW("
                                   "REVIEW_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "PRODUCT_NAME TEXT NOT NULL, "
                                   "DATE_SUBMITTED DATE NOT NULL, "
                                   "USER_ID INTEGER NOT NULL, "
                                   "REVIEW_MESSAGE TEXT NOT NULL );";

    string sql_create_table8 = "CREATE TABLE EMPLOYEE_SCHEDULE("
                                   "SCHEDULE_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "SCHEDULE_DATE DATE NOT NULL, "
                                   "STAFF_ID INTEGER NOT NULL, "
                                   "WORKING_HOUR INTEGER NOT NULL);";

    string sql_create_table9 = "CREATE TABLE APPOINTMENT("
                                   "APPOINTMENT_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "APPOINTMENT_DATE DATE NOT NULL, "
                                   "APPOINTMENT_TIME TIME NOT NULL, "
                                   "PATIENT_NAME TEXT NOT NULL, "
                                   "STORE_BRANCH TEXT NOT NULL );";

    string sql_create_table10 = "CREATE TABLE DOCTOR("
                                   "DOCTOR_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "DOCTOR_NAME TEXT NOT NULL, "
                                   "DOCTOR_PHONE_NUMBER TEXT NOT NULL, "
                                   "DOCTOR_EXPERTISE TEXT NOT NULL, "
                                   "DOCTOR_GENDER TEXT NOT NULL );";

    string sql_create_table11 = "CREATE TABLE FEEDBACK("
                                   "FEEDBACK_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "USER_ID INTEGER NOT NULL, "
                                   "DATE_SUBMITTED DATE NOT NULL, "
                                   "TIME_SUBMITTED TIME NOT NULL, "
                                   "FEEDBACK_MESSAGE TEXT NOT NULL );";

    string sql_create_table12 = "CREATE TABLE EXPENSES("
                                   "EXPENSES_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "EXPENSES_TYPE TEXT NOT NULL, "
                                   "EXPENSES_AMOUNT DOUBLE NOT NULL, "
                                   "EXPENSES_DATE DATE NOT NULL, "
                                   "EXPENSES_DESCRIPTION TEXT NOT NULL );";

    string sql_create_table13 = "CREATE TABLE PRESCRIBED_MEDICATION("
                                   "MEDICATION_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "MEDICATION_NAME TEXT NOT NULL, "
                                   "MEDICATION_DOSAGE TEXT NOT NULL, "
                                   "INSTRUCTION TEXT NOT NULL);";

    string sql_create_table14 = "CREATE TABLE CAPITAL("
                                   "CAPITAL_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "CAPITAL_AMOUNT INTEGER NOT NULL, "
                                   "CAPITAL_SOURCE TEXT NOT NULL, "
                                   "CAPITAL_DESCRIPTION TEXT NOT NULL );";

    string sql_create_table15 = "CREATE TABLE INCOME("
                                   "INCOME_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "INCOME_AMOUNT DOUBLE NOT NULL, "
                                   "INCOME_SOURCE TEXT NOT NULL, "
                                   "INCOME_DATE DATE NOT NULL );";

    string sql_create_table16 = "CREATE TABLE DISCOUNT("
                                   "DISCOUNT_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "DISCOUNT_AMOUNT INTEGER NOT NULL, "
                                   "REWARD_ID INTEGER NOT NULL );";

    string sql_create_table17 = "CREATE TABLE RETURN("
                                   "RETURN_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "RETURN_AMOUNT DOUBLE NOT NULL, "
                                   "RETURN_DATE DATE NOT NULL, "
                                   "RETURN_REASON TEXT NOT NULL );";

    string sql_create_table18 = "CREATE TABLE TRANSACTION("
                                   "TRANSACTION_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "USER_ID INTEGER NOT NULL, "
                                   "TRANSACTION_AMOUNT DOUBLE NOT NULL, "
                                   "TRANSACTION_DATE DATE NOT NULL, "
                                   "PAYMENT_METHOD TEXT NOT NULL );";

    string sql_create_table19 = "CREATE TABLE PRESCRIPTION("
                                   "PRESCRIPTION_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "USER_ID INTEGER NOT NULL, "
                                   "DOCTOR_NAME TEXT NOT NULL, "
                                   "DATE_ISSUED DATE NOT NULL, "
                                   "TOTAL_COST DOUBLE NOT NULL );";

    string sql_create_table20 = "CREATE TABLE STORE("
                                   "STORE_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "STORE_NAME TEXT NOT NULL, "
                                   "STORE_ADDRESS TEXT NOT NULL, "
                                   "STORE_PHONE_NUMBER TEXT NOT NULL, "
                                   "STORE_EMAIL TEXT NOT NULL );";

    string sql_create_table21 = "CREATE TABLE RECEIPT("
                                   "RECEIPT_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "RECEIPT_DATE DATE NOT NULL, "
                                   "ITEM_LIST INTEGER NOT NULL, "
                                   "TOTAL_AMOUNT DOUBLE NOT NULL, "
                                   "USER_NAME TEXT NOT NULL );";
    
    string sql_create_table22 = "CREATE TABLE BOOKING("
                                   "BOOKING_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "ITEM_LIST INTEGER NOT NULL, "
                                   "CUSTOMER_NAME TEXT NOT NULL, "
                                   "CUSTOMER_PHONE_NUMBER TEXT NOT NULL, "
                                   "TOTAL_PRICE DOUBLE NOT NULL );";
    
    string sql_create_table23 = "CREATE TABLE MEDICAL_RECORD("
                                   "RECORD_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "PATIENT_NAME TEXT NOT NULL, "
                                   "DOCTOR_NAME TEXT NOT NULL, "
                                   "DIAGNOSIS TEXT NOT NULL, "
                                   "TREATMENT TEXT NOT NULL );";

    string sql_create_table24 = "CREATE TABLE REPLACEMENT("
                                   "REPLACEMENT_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "REPLACEMENT_ITEM TEXT NOT NULL, "
                                   "REPLACEMENT_QUANTITY INTEGER NOT NULL, "
                                   "REPLACEMENT_DATE DATE NOT NULL, "
                                   "REPLACEMENT_REASON TEXT NOT NULL );";

    string sql_create_table25 = "CREATE TABLE EMPLOYEE("
                                   "EMPLOYEE_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "EMPLOYEE_NAME TEXT NOT NULL, "
                                   "EMPLOYEE_POSITION TEXT NOT NULL, "
                                   "EMPLOYEE_SALARY DOUBLE NOT NULL );";

    string sql_create_table26 = "CREATE TABLE BATCH("
                                   "BATCH_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "STOCK_ID INTEGER NOT NULL, "
                                   "STOCK_QUANTITY INTEGER NOT NULL, "
                                   "EXPIRY_DATE DATE NOT NULL, "
                                   "MANUFACTURING_DATE DATE NOT NULL );";
        
    string sql_create_table27 = "CREATE TABLE SUPPLIER_PRODUCT("
                                   "SUPPLIER_PRODUCT_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "SUPPLIER_ID INTEGER NOT NULL, "
                                   "STOCK_ID INTEGER NOT NULL, "
                                   "QUANTITY INTEGER NOT NULL, "
                                   "PRICE DOUBLE NOT NULL );";

    string sql_create_table28 = "CREATE TABLE PROMOTION("
                                   "PROMOTION_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "PRODUCT_NAME TEXT NOT NULL, "
                                   "DISCOUNT_PERCENTAGE DOUBLE NOT NULL, "
                                   "START_DATE DATE NOT NULL, "
                                   "END_DATE DATE NOT NULL );";

    string sql_create_table29 = "CREATE TABLE VITAMINS("
                                   "VITAMINS_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "VITAMINS_NAME TEXT NOT NULL, "
                                   "VITAMINS_DESCRIPTION TEXT NOT NULL, "
                                   "VITAMINS_PRICE DOUBLE NOT NULL, "
                                   "VITAMINS_DOSAGE TEXT NOT NULL );";

    string sql_create_table30 = "CREATE TABLE ANTIDEPRESSANTS("
                                   "ANTIDEPRESSANTS_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "ANTIDEPRESSANTS_NAME TEXT NOT NULL, "
                                   "ANTIDEPRESSANTS_DESCRIPTION TEXT NOT NULL, "
                                   "ANTIDEPRESSANTS_PRICE DOUBLE NOT NULL, "
                                   "ANTIDEPRESSANTS_DOSAGE TEXT NOT NULL );";

    string sql_create_table31 = "CREATE TABLE ANTIDIABETIC("
                                   "ANTIDIABETIC_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "ANTIDIABETIC_NAME TEXT NOT NULL, "
                                   "ANTIDIABETIC_DESCRIPTION TEXT NOT NULL, "
                                   "ANTIDIABETIC_PRICE DOUBLE NOT NULL, "
                                   "ANTIDIABETIC_DOSAGE TEXT NOT NULL );";

    string sql_create_table32 = "CREATE TABLE ANTIBIOTICS("
                                   "ANTIBIOTICS_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "ANTIBIOTICS_NAME TEXT NOT NULL, "
                                   "ANTIBIOTICS_DESCRIPTION TEXT NOT NULL, "
                                   "ANTIBIOTICS_PRICE DOUBLE NOT NULL, "
                                   "ANTIBIOTICS_DOSAGE TEXT NOT NULL );";

    string sql_create_table33 = "CREATE TABLE SKIN_CARE("
                                   "SKIN_CARE_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "SKIN_CARE_NAME TEXT NOT NULL, "
                                   "SKIN_CARE_PRICE DOUBLE NOT NULL, "
                                   "SKIN_CARE_QUANTITY INTEGER NOT NULL, "
                                   "SKIN_CARE_DESCRIPTION TEXT NOT NULL );";

    string sql_create_table34 = "CREATE TABLE SUPPLEMENT("
                                   "SUPPLEMENT_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "SUPPLEMENT_NAME TEXT NOT NULL, "
                                   "SUPPLEMENT_PRICE DOUBLE NOT NULL, "
                                   "SUPPLEMENT_QUANTITY INTEGER NOT NULL, "
                                   "SUPPLEMENT_DESCRIPTION TEXT NOT NULL );";

    string sql_create_table35 = "CREATE TABLE MEDICAL_SUPPLY("
                                   "MEDICAL_SUPPLY_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "MEDICAL_SUPPLY_NAME TEXT NOT NULL, "
                                   "MEDICAL_SUPPLY_PRICE DOUBLE NOT NULL, "
                                   "MEDICAL_SUPPLY_QUANTITY INTEGER NOT NULL, "
                                   "MEDICAL_SUPPLY_DESCRIPTION TEXT NOT NULL );";

    string sql_create_table36 = "CREATE TABLE STAFF_DETAILS("
                                   "STAFF_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "STAFF_USERNAME TEXT NOT NULL, "
                                   "STAFF_PASSWORD DOUBLE NOT NULL, "
                                   "STAFF_EMAIL TEXT NOT NULL, "
                                   "STAFF_PHONE_NUMBER TEXT NOT NULL );";

    string sql_create_table37 = "CREATE TABLE SUPPLIER("
                                   "SUPPLIER_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "SUPPLIER_NAME TEXT NOT NULL, "
                                   "SUPPLIER_CONTACT TEXT NOT NULL, "
                                   "SUPPLIER_ADDRESS TEXT NOT NULL );";

    string sql_create_table38 = "CREATE TABLE HEALTH_FOOD("
                                   "HEALTH_FOOD_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "HEALTH_FOOD_NAME TEXT NOT NULL, "
                                   "HEALTH_FOOD_PRICE DOUBLE NOT NULL, "
                                   "HEALTH_FOOD_QUANTITY INTEGER NOT NULL, "
                                   "HEALTH_FOOD_DESCRIPTION TEXT NOT NULL );";

    string sql_create_table39 = "CREATE TABLE PATIENT("
                                   "PATIENT_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "PATIENT_NAME TEXT NOT NULL, "
                                   "PATIENT_GENDER TEXT NOT NULL, "
                                   "PATIENT_EMAIL TEXT NOT NULL, "
                                   "PATIENT_PHONE_NUMBER TEXT NOT NULL );";

    string sql_create_table40 = "CREATE TABLE OTHERS("
                                   "OTHERS_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                                   "OTHERS_NAME TEXT NOT NULL, "
                                   "OTHERS_PRICE DOUBLE NOT NULL, "
                                   "OTHERS_QUANTITY INTEGER NOT NULL, "
                                   "OTHERS_DESCRIPTION TEXT NOT NULL );";

    exit = sqlite3_open("pharmacy.db", &DB);
    char* messaggeError;

    exit = sqlite3_exec(DB, sql_create_table1.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table2.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table3.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table4.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table5.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table6.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table7.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table8.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table9.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table10.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table11.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table12.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table13.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table14.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table15.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table16.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table17.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table18.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table19.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table20.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table21.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table22.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table23.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table24.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table25.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table26.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table27.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table28.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table29.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table30.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table31.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table32.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table33.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table34.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table35.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table36.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table37.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table38.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table39.c_str(), NULL, 0, &messaggeError);
    exit = sqlite3_exec(DB, sql_create_table40.c_str(), NULL, 0, &messaggeError);


    if (exit != SQLITE_OK) {
        cerr << "Error creating table: " << messaggeError << endl;
        sqlite3_free(messaggeError);
    } else {
        cout << "Table created successfully" << endl;
    }

    sqlite3_close(DB);
}