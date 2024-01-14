#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "sqlite3.h"
#include <string>
#include "connect.h"
using namespace std;

void purchase();
void supplement();
void medicalsupplies();
void skincare();
void healthfood();
void others();
void payment();
void viewCart();
void menu();
void login();
void user_main();
void admin_main();
void AdminDetails();
void reward();
void appointment();
void makeAppointment();
void viewAppointment();
void applyVouchers();
void showVoucherCart();
void useVoucherOrNot();
void insertUserDetails(const string& username, const string& password, const string& gmail, const string& phone_number);
double totalAfterVouchers = 0.0;
double total = 0.0;

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
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            cout << "Confirm Password: ";
            cin >> new_password;
            cout << "Gmail: ";
            cin >> gmail;
            cout << "Phone Number: ";
            cin >> phone_number;
            if (new_password == password) {
                cout << "Register successful." << endl;
                insertUserDetails(username, password, gmail, phone_number);
                menu();
            } else {
                cout << "Please register again." << endl;
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
            user_main();
            break;
        case 2:
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            admin_main();
            break;
        case 3:
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            //employee_main();
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

void user_main(){
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

struct CartItem {
    string name;
    double price;
    int quantity;
    CartItem* next;
};

vector <CartItem> cart;
int points = 0.0;

CartItem* cartHead = nullptr;

void addToCart(const CartItem& newItem) {
    CartItem* newCartItem = new CartItem(newItem);
    newCartItem->next = cartHead;
    cartHead = newCartItem;
}

void viewCart(){
    CartItem* current = cartHead;
    total = 0.0;
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

void clearCart(){
     while (cartHead != nullptr) {
        CartItem* temp = cartHead;
        cartHead = cartHead->next;
        delete temp;
}
}

void useVoucherOrNot(){
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

void purchase(){
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
        }else{
            exit(0);
        }
    
}

vector <CartItem> items1 = {
    {"Probiotics", 60.00},
    {"Amino acids", 159.90},
    {"Impact Whey Protein", 210.00},
    {"Clear Collagen Powder", 300.00},
    {"Testosterone Support Supplement", 140.00},
    {"Glucosamine Chondroitin Capsules", 250.00},
    {"Cell Cure Cotton", 450.00},
    {"Cranberry and Probiotics", 600.00},
    {"Prostate Health Supplement", 150.00},
    {"Creatine Gummies", 139.00}
};

void supplement(){
    cout << "================================================================\n"
            "|                         ~ Supplement ~                       |\n"
            "================================================================\n"
            "|----------------------- NEW ERA PHARMACY ---------------------|\n"
            "================================================================\n"
            "|                                                              |\n"
            "|                     -- Enter your choice:                    |\n";
        int index = 1;
        for (const auto& item : items1) {
        cout << "| " << setw(7) << index << ". " << setw(37) << left << item.name << "RM " << setw(7) << right << fixed << setprecision(2) << item.price << "      |\n";
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

vector <CartItem> items2 = {
    {"Silk'n ReVit Prestige Filters", 80.00},
    {"Wizard 210 Nasal CPAP Mask", 1900.00},
    {"Wizard 220 Full Face CPAP Mask", 2200.00},
    {"XT Auto CPAP Machine", 2500.00},
    {"Resmed Airsense 10 Autoset", 1500.00},
    {"Fade Magic Hair Eraser", 599.00},
    {"Silk'n Lipo Fat Reduction Device", 700.00},
    {"TriPollar STOP Vx", 209.00},
    {"Silk'n Tightra 2.0", 800.00},
    {"SUYUDD Knee Support Brace", 700.00}
};

void medicalsupplies(){
    cout << "================================================================\n"
            "|                      ~ Medical Supplies ~                    |\n"
            "================================================================\n"
            "|----------------------- NEW ERA PHARMACY ---------------------|\n"
            "================================================================\n"
            "|                                                              |\n"
            "|                     -- Enter your choice:                    |\n";
        int index = 1;
        for (const auto& item : items2) {
        cout << "| " << setw(7) << index << ". " << setw(37) << left << item.name << "RM " << setw(7) << right << fixed << setprecision(2) << item.price << "      |\n";
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

vector <CartItem> items3 = {
    {"Spotless Brightening Cleansing Foam", 72.00},
    {"Hada Labo Mild Peeling Lotion", 69.50},
    {"Garnier Hydra Bomb Green Tea Mask", 9.50},
    {"Oxy Oil Control Film 50s", 11.50},
    {"Acne-Aid Bar Soap 100g", 17.20},
    {"Bio-Essence Bio Bright Essence", 65.90},
    {"St. Ives Apricot Face Scrub", 32.50},
    {"Sukin Foaming Facial Cleanser", 36.90},
    {"Nivea Lip Fruity Shine Cherry", 17.50},
    {"Nivea Sun Protect & Moisture", 33.60}
};

void skincare(){
    cout << "================================================================\n"
            "|                      ~ Skin Care Product ~                   |\n"
            "================================================================\n"
            "|----------------------- NEW ERA PHARMACY ---------------------|\n"
            "================================================================\n"
            "|                                                              |\n"
            "|                     -- Enter your choice:                    |\n";
        int index = 1;
        for (const auto& item : items3) {
        cout << "| " << setw(7) << index << ". " << setw(37) << left << item.name << "RM " << setw(7) << right << fixed << setprecision(2) << item.price << "      |\n";
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

vector <CartItem> items4 = {
    {"Brands Essence of Chicken", 86.10},
    {"NH Detoxlim Natural Clenx Tea", 66.80},
    {"MH Mushroom Seasoning Powder", 21.50},
    {"MH Vegetable Seasoning Powder", 21.50},
    {"Royal Bird Nest Drink with Red Date", 53.30},
    {"Lennox Collagen Powder 5000mg", 128.00},
    {"Kinohimitsu Phytox", 65.90},
    {"Brands Essence of Chicken", 85.10},
    {"Good Morning Gsure Refill Pack", 98.90},
    {"Radiant Code Rolled Oat", 10.50}
};

void healthfood(){
    cout << "================================================================\n"
            "|                         ~ Health Food ~                      |\n"
            "================================================================\n"
            "|----------------------- NEW ERA PHARMACY ---------------------|\n"
            "================================================================\n"
            "|                                                              |\n"
            "|                     -- Enter your choice:                    |\n";
        int index = 1;
        for (const auto& item : items4) {
        cout << "| " << setw(7) << index << ". " << setw(37) << left << item.name << "RM " << setw(7) << right << fixed << setprecision(2) << item.price << "      |\n";
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

vector <CartItem> items5 = {
    {"Cola", 3.00},
    {"Pepsi", 3.00},
    {"Sprite", 3.00},
    {"A&W", 3.00},
    {"Heaven & Earth", 3.20},
    {"Multi-purpose Disinfecting Wipes", 7.00},
    {"Antabax Antibac Cleansing Wipe", 16.90},
    {"Sticky Candy Mix Rock 170gm", 9.00},
    {"Wrigley's Boomer Soft Bubble Gum", 1.00},
    {"Laurier Super Slimguard", 15.00}
};

void others(){
    cout << "================================================================\n"
            "|                           ~ Others ~                         |\n"
            "================================================================\n"
            "|----------------------- NEW ERA PHARMACY ---------------------|\n"
            "================================================================\n"
            "|                                                              |\n"
            "|                     -- Enter your choice:                    |\n";
        int index = 1;
        for (const auto& item : items5) {
        cout << "| " << setw(7) << index << ". " << setw(37) << left << item.name << "RM " << setw(7) << right << fixed << setprecision(2) << item.price << "      |\n";
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

void payment(){
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

void reward(){
    int input;
    cout << "=======================================\n"
            "|           ~ REWARD CENTRE ~         |\n"
            "=======================================\n"
            "|---------- NEW ERA PHARMACY ---------|\n"
            "=======================================\n"
            "|           Available points:         |\n"
            "|                 "<<points<<"                |\n"
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

void showVoucherCart(){
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

double getTotalVoucherDiscount() {
    double totalDiscount = 0.0;
    for (const Voucher& voucher : voucherCart) {
        totalDiscount += voucher.discount;
    }
    return totalDiscount;
}

void applyVouchers() {
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

struct Appointment {
    string location;
    string date;
    string time;
};

vector<Appointment> appointments;

void makeAppointment() {
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

    string date, time;
    cout << "Enter date (dd/mm/yyyy): ";
    cin >> date;

    cout << "Enter time (hh:mm): ";
    cin >> time;

    Appointment newAppointment = {selectedLocation, date, time};
    appointments.push_back(newAppointment);

    cout << "Appointment scheduled successfully!" << endl;
}

void viewAppointment() {
    cout << "Scheduled Appointments:\n";
    for (const Appointment& appointment : appointments) {
        cout << "Location: " << appointment.location << ", Date: " << appointment.date << ", Time: " << appointment.time << endl;
    }
}
void appointment(){
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

int main(){ 
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
                                   "STORE_NAME TEXT NOT NULL );";

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
    menu();
    return 0;
}

void admin_main(){
    cout << " =======================================\n" 
            " |        ~ Welcome To Admin Page ~    |\n" 
            " =======================================\n" 
            " |---------- NEW ERA PHARMACY ---------|\n" 
            " =======================================\n" 
            " |                                     |\n" 
            " |        -- Enter your choice:        |\n"
            " |        1.   Admin Details           |\n"
            " |        2.   Antibiotics             |\n" 
            " |        3.   Antidepressants         |\n"
            " |        4.   Antidiabetic            |\n"  
            " |        5.   Appointment             |\n"
            " |        6.   Batch                   |\n" 
            " |        7.   Booking                 |\n"  
            " |        8.   Capital                 |\n"  
            " |        9.   Delivery                |\n"
            " |        10.  Discount                |\n" 
            " |        11.  Doctor                  |\n"
            " |        12.  Employee                |\n"  
            " |        13.  Employee Schedule       |\n" 
            " |        14.  Expenses                |\n" 
            " |        15.  Feedback                |\n"  
            " |        16.  Financial Report        |\n" 
            " |        17.  Health Food             |\n" 
            " |        18.  Income                  |\n"
            " |        19.  Medical Record          |\n"
            " |        20.  Medical Supply          |\n"
            " |        21.  Others                  |\n" 
            " |        22.  Patient                 |\n"    
            " |        23.  Prescribed Medication   |\n" 
            " |        24.  Prescription            |\n" 
            " |        25.  Product Review          |\n"
            " |        26.  Promotion               |\n" 
            " |        27.  Receipt                 |\n"
            " |        28.  Replacement             |\n"  
            " |        29.  Return                  |\n"  
            " |        30.  Reward                  |\n" 
            " |        31.  Skin Care               |\n"
            " |        32.  Staff Details           |\n"  
            " |        33.  Stock                   |\n"
            " |        34.  Store                   |\n"
            " |        35.  Supplement              |\n" 
            " |        36.  Supplier                |\n" 
            " |        37.  Supplier Product        |\n" 
            " |        38.  Transaction             |\n"     
            " |        39.  User Details            |\n"
            " |        40.  Vitamins                |\n" 
            " |                                     |\n" 
            " |----------- other options -----------|\n" 
            " |        99. Back                     |\n"
            " |        0.  Exit program             |\n" 
            " =======================================\n";
    int input;
    cout << "Enter choice: ";
    cin >> input;
    switch (input){
            case 99:
            login();
            break;

            case 0:
            exit(0);
            break;

            case 1:
            AdminDetails();
            break;

            default:
            cout << "Invalid choice." << endl;
            break;
    }
}

int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    cout << "\n";
    return 0;
}

void AdminDetails() {
    sqlite3* DB;
    int exit = 0;
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
         << "|       8. Exit program               |\n"
         << "=======================================\n";

    int input;
    cout << "Enter your choice: " << endl;
    cin >> input;

    if (input == 1) {
        string answer1, answer2, answer3, answer4;
        cout << "Adding new admin details (create)." << endl;
        cout << "Please enter admin username: ";
        cin >> answer1;
        cout << "Please enter admin password: ";
        cin >> answer2;
        cout << "Please enter admin email: ";
        cin >> answer3;
        cout << "Please enter admin phone number: ";
        cin >> answer4;

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
        } else if (input == 2) {
        int exit = 0;
        sqlite3* DB;

        exit = sqlite3_open("pharmacy.db", &DB);

        if (exit != SQLITE_OK) {
            cerr << "Error opening database." << endl;
            sqlite3_close(DB);
            return;
        }

        string sql_select = "SELECT * FROM ADMIN_DETAILS";
        char* messaggeError;
        exit = sqlite3_exec(DB, sql_select.c_str(), callback, 0, &messaggeError);

        if (exit != SQLITE_OK) {
            cerr << "Error selecting data: " << messaggeError << endl;
            sqlite3_free(messaggeError);
        }

        sqlite3_close(DB);
    } else if (input == 3) {
        int answer, option;
        cout << "Please enter the admin details ID you wish to update." << endl;
        cin >> answer;
        cout << "Enter 1 to update admin username, 2 to update admin password, 3 to update admin email, 4 to update admin phone number: ";
        cin >> option;

        string newanswer;
        string sql_update_table1;

        switch (option) {
            case 1:
                cout << "Enter the new admin username: ";
                cin >> newanswer;
                sql_update_table1 = "UPDATE ADMIN_DETAILS SET ADMIN_USERNAME = '" + newanswer + "' WHERE ADMIN_ID = " + to_string(answer);
                break;

            case 2:
                cout << "Enter the new admin password: ";
                cin >> newanswer;
                sql_update_table1 = "UPDATE ADMIN_DETAILS SET ADMIN_PASSWORD = '" + newanswer + "' WHERE ADMIN_ID = " + to_string(answer);
                break;

            case 3:
                cout << "Enter the new admin email: ";
                cin >> newanswer;
                sql_update_table1 = "UPDATE ADMIN_DETAILS SET ADMIN_EMAIL = '" + newanswer + "' WHERE ADMIN_ID = " + to_string(answer);
                break;

            case 4:
                cout << "Enter the new admin phone number: ";
                cin >> newanswer;
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
    } else if (input == 4) {
        int answer, option;
        cout << "Please enter the admin details ID you wish to delete: ";
        cin >> answer;
        cout << "Are you sure you want to delete admin ID " << answer << "? This action will not restore lost data." << endl;
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> option;

        if (option == 'N' || option == 'n') {
            cout << "No was selected. You will be directed back to the admin page." << endl;
            return;
        } else if (option == 'Y' || option == 'y') {
            int newanswer;
            cout << "Enter the admin ID you wish to delete: ";
            cin >> newanswer;
            string sql_delete_table1 = "DELETE FROM ADMIN_DETAILS WHERE ADMIN_ID = " + to_string(newanswer);

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
    }
}




