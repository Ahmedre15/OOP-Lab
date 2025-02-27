#include <iostream>
#include <vector>

using namespace std;

class CoffeeShop {
    struct MenuItem {
        string name;
        double price;
        string type;
    };

    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string n) : name(n) {}

    void addMenuItem(string itemName, double itemPrice, string itemType) {
        menu.push_back({itemName, itemPrice, itemType});
    }

    string addOrder(string itemName) {
        for (auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added!";
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (auto& order : orders) {
            for (auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "";
        MenuItem cheapest = menu[0];
        for (auto& item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (auto& item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main() {
    CoffeeShop shop("AAR Shop");

    shop.addMenuItem("Tea", 2.5, "drink");
    shop.addMenuItem("Latte", 3.0, "drink");
    shop.addMenuItem("Sandwich", 5.0, "food");
    shop.addMenuItem("Burger", 2.8, "food");

    cout << shop.addOrder("Latte") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.addOrder("Mocha") << endl;

    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;

    cout << "Total Due: $" << shop.dueAmount() << endl;
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;

    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks: ";
    for (string& d : drinks) cout << d << " ";
    cout << endl;

    vector<string> foods = shop.foodOnly();
    cout << "Foods: ";
    for (string& f : foods) cout << f << " ";
    cout << endl;

    return 0;
}
