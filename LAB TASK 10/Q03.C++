#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int MAX = 100;

class User {
public:
    string user_id, first_name, last_name, address, email;

    User() {}

    User(string uid, string fname, string lname, string addr, string mail)
        : user_id(uid), first_name(fname), last_name(lname), address(addr), email(mail) {}

    string serialize() {
        return user_id + "," + first_name + "," + last_name + "," + address + "," + email;
    }

    static User deserialize(string line) {
        stringstream ss(line);
        string uid, fname, lname, addr, mail;
        getline(ss, uid, ',');
        getline(ss, fname, ',');
        getline(ss, lname, ',');
        getline(ss, addr, ',');
        getline(ss, mail, ',');
        return User(uid, fname, lname, addr, mail);
    }
};

class Product {
public:
    string product_id, product_name, description;
    int price;

    Product() {}

    Product(string pid, string pname, string desc, int pr)
        : product_id(pid), product_name(pname), description(desc), price(pr) {}

    string serialize() {
        return product_id + "," + product_name + "," + description + "," + to_string(price);
    }

    static Product deserialize(string line) {
        stringstream ss(line);
        string pid, pname, desc, pr;
        getline(ss, pid, ',');
        getline(ss, pname, ',');
        getline(ss, desc, ',');
        getline(ss, pr, ',');
        return Product(pid, pname, desc, stoi(pr));
    }
};

class Order {
public:
    string order_id, user_id, product_id;
    int total_paid;

    Order() {}

    Order(string oid, string uid, string pid, int paid)
        : order_id(oid), user_id(uid), product_id(pid), total_paid(paid) {}

    string serialize() {
        return order_id + "," + user_id + "," + product_id + "," + to_string(total_paid);
    }

    static Order deserialize(string line) {
        stringstream ss(line);
        string oid, uid, pid, paid;
        getline(ss, oid, ',');
        getline(ss, uid, ',');
        getline(ss, pid, ',');
        getline(ss, paid, ',');
        return Order(oid, uid, pid, stoi(paid));
    }
};

// Dummy data creation
void createDummyData() {
    ofstream userFile("users.txt");
    userFile << User("U01", "Linus", "Torvalds", "Helsinki", "linus@linux.com").serialize() << endl;
    userFile << User("U02", "Who", "Lovelace", "London", "who@history.com").serialize() << endl;
    userFile.close();

    ofstream productFile("products.txt");
    productFile << Product("P01", "Linux Book", "Kernel architecture", 600).serialize() << endl;
    productFile << Product("P02", "Algorithms", "Book on computer algorithms", 750).serialize() << endl;
    productFile.close();

    ofstream orderFile("orders.txt");
    orderFile << Order("O01", "U01", "P01", 600).serialize() << endl;
    orderFile << Order("O02", "U01", "P02", 750).serialize() << endl;
    orderFile.close();
}

int loadUsers(User users[]) {
    ifstream inFile("users.txt");
    string line;
    int count = 0;
    while (getline(inFile, line) && count < MAX) {
        users[count++] = User::deserialize(line);
    }
    return count;
}

int loadProducts(Product products[]) {
    ifstream inFile("products.txt");
    string line;
    int count = 0;
    while (getline(inFile, line) && count < MAX) {
        products[count++] = Product::deserialize(line);
    }
    return count;
}

int loadOrders(Order orders[]) {
    ifstream inFile("orders.txt");
    string line;
    int count = 0;
    while (getline(inFile, line) && count < MAX) {
        orders[count++] = Order::deserialize(line);
    }
    return count;
}

void queryProductsForUser(string targetFirstName) {
    User users[MAX];
    Product products[MAX];
    Order orders[MAX];

    int userCount = loadUsers(users);
    int productCount = loadProducts(products);
    int orderCount = loadOrders(orders);

    string targetUserId = "";
    for (int i = 0; i < userCount; ++i) {
        if (users[i].first_name == targetFirstName) {
            targetUserId = users[i].user_id;
            break;
        }
    }

    if (targetUserId == "") {
        cout << "User not found.\n";
        return;
    }

    cout << "Products purchased by " << targetFirstName << ":\n";

    for (int i = 0; i < orderCount; ++i) {
        if (orders[i].user_id == targetUserId) {
            string pid = orders[i].product_id;
            for (int j = 0; j < productCount; ++j) {
                if (products[j].product_id == pid) {
                    cout << "- " << products[j].product_name << endl;
                }
            }
        }
    }
}

int main() {
    createDummyData();  
    queryProductsForUser("Linus");
    return 0;
}
