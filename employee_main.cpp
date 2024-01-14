#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "sqlite3.h"
#include <string>
#include "connect.h"
using namespace std;

void employee_main(){
    cout << "=======================================\n"
         << "|      ~ Welcome To Employee Page ~   |\n"
         << "=======================================\n"
         << "|---------- NEW ERA PHARMACY ---------|\n"
         << "=======================================\n"
         << "|                                     |\n"
         << "|       -- Enter your choice:         |\n"
         << "|       1. Customer                   |\n"
         << "|       2. Stock                      |\n"
         << "|       3. Appoinment                 |\n"
         << "|       4. Delivery                   |\n"
         << "|       5. Return                     |\n"
         << "|                                     |\n"
         << "|----------- other options -----------|\n"
         << "|       0. Exit program               |\n"
         << "=======================================\n";

         int input;
         cout << "Enter choice: ";
         cin >> input;
         switch (input){
            case 1:
                customer_list();
                return employee_main();
                break;

            case 2:
                stock_list();
                return employee_main();
                break;

            case 3:
                appointment_list();
                return employee_main();
                break;
            
            case 4:
                delivery_list();
                return employee_main();
                break;

            case 5:
                return_list();
                return employee_main();
                break;

            case 0:
                int exit(0);
                break;

            default:
            cout << "Invalid choice." << endl;
            break;
         }
}
