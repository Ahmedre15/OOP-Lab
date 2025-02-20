#include <iostream>
#include <string>
using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;

    MenuItem(string n = "", string t = "", double p = 0.0) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    MenuItem menu[5]; 
    string orders[10]; 
    int menuSize, orderCount;

public:
    CoffeeShop(string n) : name(n), menuSize(5), orderCount(0) {
        menu[0] = MenuItem("Espresso", "drink", 2.5);
        menu[1] = MenuItem("Latte", "drink", 3.5);
        menu[2] = MenuItem("Muffin", "food", 4.0);
        menu[3] = MenuItem("Sandwich", "food", 5.0);
        menu[4] = MenuItem("Tea", "drink", 2.0);
    }

    string addOrder(string itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                if (orderCount < 10) {
                    orders[orderCount++] = itemName;
                    return "Order added!";
                }
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string item = orders[0];
            for (int i = 1; i < orderCount; i++) {
                orders[i - 1] = orders[i];
            }
            orderCount--;
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    void listOrders() {
        if (orderCount == 0) {
            cout << "No orders placed." << endl;
            return;
        }
        for (int i = 0; i < orderCount; i++) {
            cout << orders[i] << endl;
        }
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (orders[i] == menu[j].name) {
                    total += menu[j].price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        double minPrice = menu[0].price;
        string cheapest = menu[0].name;
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < minPrice) {
                minPrice = menu[i].price;
                cheapest = menu[i].name;
            }
        }
        return cheapest;
    }

    void drinksOnly() {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                cout << menu[i].name << endl;
            }
        }
    }

    void foodOnly() {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                cout << menu[i].name << endl;
            }
        }
    }
};

int main() {
    CoffeeShop shop("Cafe Affan");

    cout << shop.addOrder("Latte") << endl;
    cout << shop.addOrder("Muffin") << endl;
    cout << shop.addOrder("Burger") << endl;

    cout << "Orders list:" << endl;
    shop.listOrders();

    cout << "Total due: $" << shop.dueAmount() << endl;

    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;

    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    cout << "Drinks menu:" << endl;
    shop.drinksOnly();

    cout << "Food menu:" << endl;
    shop.foodOnly();

    return 0;
}
