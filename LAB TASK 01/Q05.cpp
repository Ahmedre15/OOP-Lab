#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    string movieName;
    double adultTicketPrice, childTicketPrice;
    int adultTicketsSold, childTicketsSold;
    double donationPercentage;

    cout << "Enter movie name: ";
    getline(cin, movieName);
    cout << "Enter adult ticket price: ";
    cin >> adultTicketPrice;
    cout << "Enter child ticket price: ";
    cin >> childTicketPrice;
    cout << "Enter number of adult tickets sold: ";
    cin >> adultTicketsSold;
    cout << "Enter number of child tickets sold: ";
    cin >> childTicketsSold;
    cout << "Enter percentage of gross amount to be donated: ";
    cin >> donationPercentage;
    
    double grossAmount = (adultTicketPrice * adultTicketsSold) + (childTicketPrice * childTicketsSold);
    double amountDonated = (donationPercentage / 100) * grossAmount;
    double netSale = grossAmount - amountDonated;
    printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("Movie Name: .................................... %s\n", movieName.c_str());
    printf("Number of Tickets Sold: .......................... %d\n", adultTicketsSold + childTicketsSold);
    printf("Gross Amount: ......................................... $ %.2f\n", grossAmount);
    printf("Percentage of Gross Amount Donated: %.2f%%\n", donationPercentage);
    printf("Amount Donated: ................................... $ %.2f\n", amountDonated);
    printf("Net Sale: ................................................... $ %.2f\n", netSale);
    
    return 0;
}
