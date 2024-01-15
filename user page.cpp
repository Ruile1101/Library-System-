#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "sqlite3.h"
#include "user.h"
#include <string>
#include <iterator>
#include <limits>
using namespace std;

double totalAfterVouchers = 0.0;
double total = 0.0;

void User::user_main(){
    int choice;
    string password;
    string new_password;

    cout << " =======================================\n" 
            " |              ~ Welcome ~            |\n" 
            " =======================================\n" 
            " |---------- NEW ERA PHARMACY ---------|\n" 
            " =======================================\n" 
            " |                                     |\n" 
            " |        -- Enter your choice:        |\n"
            " |        1. Purchase                  |\n"
            " |        2. Reward                    |\n" 
            " |        3. Appoinment                |\n"   
            " |                                     |\n"  
            " |----------- other options -----------|\n"  
            " |        0. Exit program              |\n"  
            " =======================================\n" ;

    cout << "Enter choice: " ;
    cin >> choice;
    switch (choice){
        case 1:
            purchase();
            break;
        case 2:
            reward();
            break;
        case 3:
            appointment();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Invalid choice." << endl; 
            break;
    }
}

void User::purchase(){
    int input;
    cout << "=======================================\n"
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
    cout << "Enter choice:";
    cin >> input;
    if (input == 1){
        supplement();
        }else if (input == 2){
            medicalsupplies();
        }else if (input == 3){
            skincare();
        }else if (input == 4){
            healthfood();
        }else if (input == 5){
            others();
        }else if (input == 99){
            user_main();
        }else{
            exit(0);
        }
    
}

vector <CartItem> cart;
int points = 0.0;

CartItem* cartHead = nullptr;

void User::addToCart(const CartItem& newItem) {
    CartItem* newCartItem = new CartItem(newItem);
    newCartItem->next = cartHead;
    cartHead = newCartItem;
}

void User::viewCart(){
    CartItem* current = cartHead;
    int total = 0.0;
    cout << "Items in Cart:\n"
            "--------------------------------------------------------------\n"
            "Item                                 Price        Quantity\n";
            "--------------------------------------------------------------\n";
    
    while (current != nullptr) {
        cout << left << setw(37) << current->name
             << "RM " << setw(11) << current->price
             << setw(12) << current->quantity << endl;
        total += (current->price * current->quantity);
        current = current->next;
        points += static_cast<int>(total);
    }

    cout << "--------------------------------------------------------------\n";
    cout << "Total:	RM " << total << endl;
}

void User::clearCart(){
     while (cartHead != nullptr) {
        CartItem* temp = cartHead;
        cartHead = cartHead->next;
        delete temp;
}
}

void User::supplement(){
    vector <CartItem> items1;
    sqlite3* db;
    if (sqlite3_open("pharmacy.db", &db) == SQLITE_OK) {
        const char* query = "SELECT SUPPLEMENT_NAME, SUPPLEMENT_PRICE FROM SUPPLEMENT";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
                double price = sqlite3_column_double(stmt, 1);
                items1.push_back({name, price});
            }

            sqlite3_finalize(stmt);
        }

        sqlite3_close(db);
    } else {
        cerr << "Failed to open the database.\n";
        return;
    }
    cout << "================================================================\n"
            "|                         ~ Supplement ~                       |\n"
            "================================================================\n"
            "|----------------------- NEW ERA PHARMACY ---------------------|\n"
            "================================================================\n"
            "|                                                              |\n"
            "|                     -- Enter your choice:                    |\n";
        int index = 1;
        for (const auto& item : items1) {
        cout << "| " << setw(7) << index << ". " << setw(37) << left << item.name << "RM " << setw(7) << right << fixed << setprecision(2) << item.price << "     |\n";
        index++;
        }

    cout << "|------------------------ other options -----------------------|\n"
            "|      88. View Cart                                           |\n"
            "|      99. Back                                                |\n"
            "|       0. Exit Program                                        |\n"
            "================================================================\n";

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice >= 1 && choice <= 10) {
        int quantity;
        string input;
        cout << "Enter quantity: ";
        cin >> quantity;

        CartItem newItem;
        newItem.name = items1[choice - 1].name;
        newItem.price = items1[choice - 1].price;
        newItem.quantity = quantity;
        
        addToCart(newItem);
        cout << "Item added to cart!\n";
        viewCart();
        cout << "Proceed to payment?(yes/no)\n";
        cin >> input;
        if (input == "yes"){
            useVoucherOrNot();
            payment();
        }else if (input == "no"){
            supplement();
        }else{
            cout << "Invalid choice.";
            supplement();
        }        
        }else if (choice == 88){
        viewCart();
        string input;
        cout << "Proceed to payment?(yes/no)\n";
        cin >> input;
        if (input == "yes"){
            payment();
        }else if (input == "no"){
            others();
        }else{
            cout << "Invalid choice.";
        }     
    } else if (choice == 99){
        purchase();
    } else if (choice == 0){
        exit(0);
    } else {
        cout << "Invalid choice.\n";
    }
}

void User::medicalsupplies(){
    vector <CartItem> items2;
    sqlite3* db;
    if (sqlite3_open("pharmacy.db", &db) == SQLITE_OK) {
        const char* query = "SELECT MEDICAL_SUPPLY_NAME, MEDICAL_SUPPLY_PRICE FROM MEDICAL_SUPPLY";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
                double price = sqlite3_column_double(stmt, 1);
                items2.push_back({name, price});
            }

            sqlite3_finalize(stmt);
        }

        sqlite3_close(db);
    } else {
        cerr << "Failed to open the database.\n";
        return;
    }
    cout << "================================================================\n"
            "|                      ~ Medical Supplies ~                    |\n"
            "================================================================\n"
            "|----------------------- NEW ERA PHARMACY ---------------------|\n"
            "================================================================\n"
            "|                                                              |\n"
            "|                     -- Enter your choice:                    |\n";
        int index = 1;
        for (const auto& item : items2) {
        cout << "| " << setw(7) << index << ". " << setw(37) << left << item.name << "RM " << setw(7) << right << fixed << setprecision(2) << item.price << "     |\n";
        index++;
        }
        
    cout << "|------------------------ other options -----------------------|\n"
            "|      88. View Cart                                           |\n"
            "|      99. Back                                                |\n"
            "|       0. Exit Program                                        |\n"
            "================================================================\n";

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice >= 1 && choice <= 10) {
        int quantity;
        string input;
        cout << "Enter quantity: ";
        cin >> quantity;

        CartItem newItem;
        newItem.name = items2[choice - 1].name;
        newItem.price = items2[choice - 1].price;
        newItem.quantity = quantity;

        addToCart(newItem);
        cout << "Item added to cart!\n";
        viewCart();
        cout << "Proceed to payment?(yes/no)\n";
        cin >> input;
        if (input == "yes"){
            useVoucherOrNot();
            payment();
        }else if (input == "no"){
            medicalsupplies();
        }else{
            cout << "Invalid choice.";
            medicalsupplies();
        }        
    } else if (choice == 88){
        viewCart();
        string input;
        cout << "Proceed to payment?(yes/no)\n";
        cin >> input;
        if (input == "yes"){
            payment();
        }else if (input == "no"){
            others();
        }else{
            cout << "Invalid choice.";
        }  
    } else if (choice == 99){
        purchase();
    } else if (choice == 0){
        exit(0);
    } else {
        cout << "Invalid choice.\n";
    }
}

void User::skincare(){
    vector <CartItem> items3;
    sqlite3* db;
    if (sqlite3_open("pharmacy.db", &db) == SQLITE_OK) {
        const char* query = "SELECT SKIN_CARE_NAME, SKIN_CARE_PRICE FROM SKIN_CARE";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
                double price = sqlite3_column_double(stmt, 1);
                items3.push_back({name, price});
            }

            sqlite3_finalize(stmt);
        }

        sqlite3_close(db);
    } else {
        cerr << "Failed to open the database.\n";
        return;
    }
    cout << "================================================================\n"
            "|                      ~ Skin Care Product ~                   |\n"
            "================================================================\n"
            "|----------------------- NEW ERA PHARMACY ---------------------|\n"
            "================================================================\n"
            "|                                                              |\n"
            "|                     -- Enter your choice:                    |\n";
        int index = 1;
        for (const auto& item : items3) {
        cout << "| " << setw(7) << index << ". " << setw(37) << left << item.name << "RM " << setw(7) << right << fixed << setprecision(2) << item.price << "     |\n";
        index++;
        }
        
    cout << "|------------------------ other options -----------------------|\n"
            "|      88. View Cart                                           |\n"
            "|      99. Back                                                |\n"
            "|       0. Exit Program                                        |\n"
            "================================================================\n";

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice >= 1 && choice <= 10) {
        int quantity;
        string input;
        cout << "Enter quantity: ";
        cin >> quantity;

        CartItem newItem;
        newItem.name = items3[choice - 1].name;
        newItem.price = items3[choice - 1].price;
        newItem.quantity = quantity;

        addToCart(newItem);
        cout << "Item added to cart!\n";
        viewCart();
        cout << "Proceed to payment?(yes/no)\n";
        cin >> input;
        if (input == "yes"){
            useVoucherOrNot();
            payment();
        }else if (input == "no"){
            skincare();
        }else{
            cout << "Invalid choice.";
            skincare();
        }        
    } else if (choice == 88){
        viewCart();
        string input;
        cout << "Proceed to payment?(yes/no)\n";
        cin >> input;
        if (input == "yes"){
            payment();
        }else if (input == "no"){
            others();
        }else{
            cout << "Invalid choice.";
        }  
    } else if (choice == 99){
        purchase();
    } else if (choice == 0){
        exit(0);
    } else {
        cout << "Invalid choice.\n";
    }
}

void User::healthfood(){
    vector <CartItem> items4;
    sqlite3* db;
    if (sqlite3_open("pharmacy.db", &db) == SQLITE_OK) {
        const char* query = "SELECT HEALTH_FOOD_NAME, HEALTH_FOOD_PRICE FROM HEALTH_FOOD";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
                double price = sqlite3_column_double(stmt, 1);
                items4.push_back({name, price});
            }

            sqlite3_finalize(stmt);
        }

        sqlite3_close(db);
    } else {
        cerr << "Failed to open the database.\n";
        return;
    }
    cout << "================================================================\n"
            "|                         ~ Health Food ~                      |\n"
            "================================================================\n"
            "|----------------------- NEW ERA PHARMACY ---------------------|\n"
            "================================================================\n"
            "|                                                              |\n"
            "|                     -- Enter your choice:                    |\n";
        int index = 1;
        for (const auto& item : items4) {
        cout << "| " << setw(7) << index << ". " << setw(37) << left << item.name << "RM " << setw(7) << right << fixed << setprecision(2) << item.price << "     |\n";
        index++;
        }
        
    cout << "|------------------------ other options -----------------------|\n"
            "|      88. View Cart                                           |\n"
            "|      99. Back                                                |\n"
            "|       0. Exit Program                                        |\n"
            "================================================================\n";

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice >= 1 && choice <= 10) {
        int quantity;
        string input;
        cout << "Enter quantity: ";
        cin >> quantity;

        CartItem newItem;
        newItem.name = items4[choice - 1].name;
        newItem.price = items4[choice - 1].price;
        newItem.quantity = quantity;

        addToCart(newItem);
        cout << "Item added to cart!\n";
        viewCart();
        cout << "Proceed to payment?(yes/no)\n";
        cin >> input;
        if (input == "yes"){
            useVoucherOrNot();
            payment();
        }else if (input == "no"){
            healthfood();
        }else{
            cout << "Invalid choice.";
            healthfood();
        }        
    } else if (choice == 88){
        viewCart();
        string input;
        cout << "Proceed to payment?(yes/no)\n";
        cin >> input;
        if (input == "yes"){
            payment();
        }else if (input == "no"){
            others();
        }else{
            cout << "Invalid choice.";
        }  
    } else if (choice == 99){
        purchase();
    } else if (choice == 0){
        exit(0);
    } else {
        cout << "Invalid choice.\n";
    }
}

void User::others(){
    vector <CartItem> items5;
    sqlite3* db;
    if (sqlite3_open("pharmacy.db", &db) == SQLITE_OK) {
        const char* query = "SELECT OTHERS_NAME, OTHERS_PRICE FROM OTHERS";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
                double price = sqlite3_column_double(stmt, 1);
                items5.push_back({name, price});
            }

            sqlite3_finalize(stmt);
        }

        sqlite3_close(db);
    } else {
        cerr << "Failed to open the database.\n";
        return;
    }
    cout << "================================================================\n"
            "|                           ~ Others ~                         |\n"
            "================================================================\n"
            "|----------------------- NEW ERA PHARMACY ---------------------|\n"
            "================================================================\n"
            "|                                                              |\n"
            "|                     -- Enter your choice:                    |\n";
        int index = 1;
        for (const auto& item : items5) {
        cout << "| " << setw(7) << index << ". " << setw(37) << left << item.name << "RM " << setw(7) << right << fixed << setprecision(2) << item.price << "     |\n";
        index++;
        }

    cout << "|                                                              |\n"  
            "|------------------------ other options -----------------------|\n"
            "|      88. View Cart                                           |\n"
            "|      99. Back                                                |\n"
            "|       0. Exit Program                                        |\n"
            "================================================================\n";

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice >= 1 && choice <= 10) {
        int quantity;
        string input;
        cout << "Enter quantity: ";
        cin >> quantity;

        CartItem newItem;
        newItem.name = items5[choice - 1].name;
        newItem.price = items5[choice - 1].price;
        newItem.quantity = quantity;

        addToCart(newItem);
        cout << "Item added to cart!\n";
        viewCart();
        cout << "Proceed to payment?(yes/no)\n";
        cin >> input;
        if (input == "yes"){
            useVoucherOrNot();
            payment();
        }else if (input == "no"){
            others();
        }else{
            cout << "Invalid choice.";
            others();
        }        
    } else if (choice == 88){
        viewCart();
        string input;
        cout << "Proceed to payment?(yes/no)\n";
        cin >> input;
        if (input == "yes"){
            payment();
        }else if (input == "no"){
            others();
        }else{
            cout << "Invalid choice.";
        }  
    } else if (choice == 99){
        purchase();
    } else if (choice == 0){
        exit(0);
    } else {
        cout << "Invalid choice.\n";
    }   
}

void User::payment(){
    int input;
    int phoneNumber;
    int pinNumber;
    int cardNumber;
    int CVV;
    string username;
    string password;
    cout << "=======================================\n"
            "|         ~ PAYMENT SECTION ~         |\n"
            "=======================================\n"
            "|---------- NEW ERA PHARMACY ---------|\n"
            "=======================================\n"
            "|                                     |\n"
            "|       -- Payment method:            |\n"
            "|       1.  TNG                       |\n"
            "|       2.  Cash                      |\n"
            "|       3.  Credit Card               |\n"  
            "|       4.  Online Banking            |\n"  
            "|                                     |\n"  
            "|----------- other options -----------|\n"
            "|       99. Back                      |\n"
            "|       0.  Exit program              |\n"
            "=======================================\n";
    cout << "Enter choice: ";
    cin >> input; 
    if (input == 1){
        cout << "Phone number: ";
        cin >> phoneNumber;
        cout << "Pin Number: ";
        cin >> pinNumber;
        cout << "Payment Successful.\n";
        user_main();
        }else if (input == 2){
            cout << "Payment upon delivery.\n";
            user_main();
        }else if (input == 3){
            cout << "Card Number: ";
            cin >> cardNumber;
            cout << "CVV: ";
            cin >> CVV;
            cout << "Payment Successful.\n";
            user_main();
        }else if (input == 4){
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            cout << "Payment Successful.\n";
            user_main();
        }else if (input == 99){
            purchase();
        }else{
            exit(0);
        }
    }

struct Voucher {
    string name;
    double discount;
};

vector<Voucher> vouchers = {
    {"RM 1 Voucher", 1.00},
    {"RM 10 Voucher", 10.00},
    {"RM 50 Voucher", 50.00}
};

vector<Voucher> voucherCart;

void User::reward(){
    int input;
    cout << "=======================================\n"
            "|           ~ REWARD CENTRE ~         |\n"
            "=======================================\n"
            "|---------- NEW ERA PHARMACY ---------|\n"
            "=======================================\n"
            "|           Available points:         |\n"
            "|                    "<<points<<"                |\n"
            "|                                     |\n"
            "|       -- Voucher redemption:        |\n"
            "|       1.  RM 1  - 100  pts          |\n"
            "|       2.  RM 10 - 500  pts          |\n"
            "|       3.  RM 50 - 1000 pts          |\n"
            "|                                     |\n"  
            "|----------- other options -----------|\n"
            "|       88. View Voucher Cart         |\n"
            "|       99. Back                      |\n"
            "|       0.  Exit program              |\n"
            "=======================================\n";
    cout << "Enter choice: ";
    cin >> input;    
    if (input >= 1 && input <= 3){
        Voucher selectedVoucher = vouchers[input - 1];
        voucherCart.push_back(selectedVoucher);
        cout << "Voucher added to cart!\n";
        reward();
    }else if (input == 88){
        cout << "Vouchers in Cart:\n";
        for (const auto& voucher : voucherCart) {
            cout << voucher.name << " - RM " << voucher.discount << " off\n";
        }
        reward();
    }else if (input == 99){
        user_main();
    }else{
        exit(0);
    }
}

void User::showVoucherCart(){
    if (voucherCart.empty()) {
        cout << "Voucher cart is empty.\n";
        payment();
    } else {
        int index = 1;
        cout << "Voucher Cart:\n"
                "----------------------------------------------\n"
                "No.  Voucher          Discount Amount\n"
                "----------------------------------------------\n";
        
        for (const auto& voucher : voucherCart) {
            cout << setw(5) << index << left << setw(17) << voucher.name << "RM " << voucher.discount << endl;
            index++;
        }
    }
}

void User::useVoucherOrNot(){
    string applyVoucher;
    cout << "Do you want to apply vouchers? (yes/no): ";
    cin >> applyVoucher;

    if (applyVoucher == "yes"){
        showVoucherCart();
        applyVouchers();   
        cout << "Total after discounts: RM " << totalAfterVouchers << endl;
    }
    else if (applyVoucher == "no"){
        payment();
    }
}

double User::getTotalVoucherDiscount() {
    double totalDiscount = 0.0;
    for (const Voucher& voucher : voucherCart) {
        totalDiscount += voucher.discount;
    }
    return totalDiscount;
}

void User::applyVouchers() {
    string applyMore;
    do {
        int voucherChoice;
        cout << "Enter the number of the voucher you want to apply (or 0 to finish): ";
        cin >> voucherChoice;

        if (voucherChoice >= 1 && voucherChoice <= voucherCart.size()) {
            Voucher selectedVoucher = voucherCart[voucherChoice - 1];
            totalAfterVouchers = total - getTotalVoucherDiscount();
            voucherCart.erase(voucherCart.begin() + voucherChoice - 1);
            cout << "Voucher applied successfully!\n";
            showVoucherCart(); 
        } else if (voucherChoice == 0) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }

        cout << "Do you want to apply more vouchers? (yes/no): ";
        cin >> applyMore;
    } while (applyMore == "yes");
}

void User::appointment(){
    int input;
    cout << "=======================================\n"
            "|          ~ MAKE APPOINTMENT ~       |\n"
            "=======================================\n"
            "|---------- NEW ERA PHARMACY ---------|\n"
            "=======================================\n"
            "|                                     |\n"
            "|       -- Enter your choice:         |\n"
            "|       1. Make Appointment           |\n"
            "|       2. View Appointment           |\n"
            "|                                     |\n"  
            "|----------- other options -----------|\n"
            "|       0. Back                       |\n"
            "|       8. Exit program               |\n"
            "=======================================\n";
    cout << "Enter choice: ";
    cin >> input;
    switch (input) {
            case 1:
                makeAppointment();
                break;
            case 2:
                viewAppointment();
                break;
            case 0:
                user_main();
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
}
    }

struct Appointment {
    string location;
    string name;
    string date;
    string time;
};

struct AppointmentNode {
    Appointment data;
    AppointmentNode* next;
};

AppointmentNode* appointmentHead = nullptr;

void User::makeAppointment() {
    int locationChoice;
    cout << "Select a location:\n"
         << "1. Kuala Lumpur\n"
         << "2. Penang\n"
         << "3. Johor\n"
         << "Enter choice: ";
    cin >> locationChoice;

    if (locationChoice < 1 || locationChoice > 3) {
        cout << "Invalid choice." << endl;
        return;
    }

    string locations[3] = {"Kuala Lumpur", "Penang", "Johor"};
    string selectedLocation = locations[locationChoice - 1];

    string name, date, time;
    cout << "Enter patient's name:";
    cin >> name;

    cout << "Enter date (dd/mm/yyyy): ";
    cin >> date;

    cout << "Enter time (hh:mm): ";
    cin >> time;

    insertAppointment(selectedLocation, name, date, time);

    cout << "Appointment scheduled successfully!" << endl;
    appointment();
}

void User::insertAppointment(const string& selectedLocation, const string& name, const string& date, const string& time) {
    AppointmentNode* newAppointmentNode = new AppointmentNode{{selectedLocation, name, date, time}, nullptr};
    if (appointmentHead == nullptr) {
        appointmentHead = newAppointmentNode;
    } else {
        AppointmentNode* current = appointmentHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newAppointmentNode;
    }

    sqlite3* DB;
    int exit = sqlite3_open("pharmacy.db", &DB);
    char* messageError;

    string sql_insert_data = "INSERT INTO APPOINTMENT (STORE_BRANCH, PATIENT_NAME, APPOINTMENT_DATE, APPOINTMENT_TIME) "
                             "VALUES ('" + selectedLocation + "', '" + name + "', '" + date + "', '" + time + "');";

    exit = sqlite3_exec(DB, sql_insert_data.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error inserting data: " << messageError << endl;
        sqlite3_free(messageError);
    } else {
        cout << "Data inserted successfully" << endl;
    }

    sqlite3_close(DB);
}

void User::viewAppointment() {
    cout << "Scheduled Appointments:\n";
    AppointmentNode* current = appointmentHead;
    while (current != nullptr) {
        const Appointment& appointment = current->data;
        cout << "Location: " << appointment.location << ", Patient's name: " << appointment.name << ", Date: " << appointment.date << ", Time: " << appointment.time << endl;
        current = current->next;
    }
}

