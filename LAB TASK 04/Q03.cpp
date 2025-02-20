#include <iostream>
using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string pNum, string pDesc, int qty, double price) {
        partNumber = pNum;
        partDescription = pDesc;
        quantity = (qty > 0) ? qty : 0;
        pricePerItem = (price > 0) ? price : 0.0;
    }

    double getInvoiceAmount() {
        return quantity * pricePerItem;
    }
};

int main() {
    Invoice item("123", "ABCD", 5, 10.5);
    cout << "Invoice Amount: $" << item.getInvoiceAmount() << endl;
    return 0;
}
