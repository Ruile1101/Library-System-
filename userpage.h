#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "sqlite3.h"
using namespace std;

struct CartItem {
    string name;
    double price;
    int quantity;
    CartItem* next;
};

class User {
public:
    void purchase();
    void supplement();
    void medicalsupplies();
    void skincare();
    void healthfood();
    void others();
    void payment();
    void viewCart();
    void clearCart();
    void user_main();
    void reward();
    void appointment();
    void makeAppointment();
    void viewAppointment();
    void applyVouchers();
    void showVoucherCart();
    void useVoucherOrNot();
    double getTotalVoucherDiscount();
    void addToCart(const CartItem& newItem);
    void insertAppointment(const string& selectedLocation, const string& name, const string& date, const string& time);
};

#endif 