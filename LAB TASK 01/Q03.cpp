#include<iostream>
using namespace std;

int main(){
    int customerid,units;
    string customername;
    float charge;
    float totalamount,surcharge = 0,netamount;
   

    cout << "Enter Customer ID: ";
    cin >> customerid;
    cout << "Enter Customer Name: ";
    cin >> customername;
    cout << "Enter Units Consumed: ";
    cin >> units;

    if (units > 0 && units <= 199){
        charge = 16.20;
    }
    if (units >= 200 && units < 300){
        charge = 20.10;
    }
    if (units >= 300 && units < 500){
        charge = 27.10;
    }
   else{
        charge = 35.9;
    }
    totalamount = charge * units;

    if (totalamount > 18000)
    {
        surcharge = totalamount * 0.15;
       
    }
    netamount = totalamount + surcharge;

    cout << "Customer ID: " << customerid << endl;
    cout << "Customer Name: " << customername << endl;
    cout << "Units Consumed: " << units << endl;
    cout << "Amount Charges @Rs. " << charge << " per unit: " << totalamount << endl;
    cout << "Surcharge Amount: " << surcharge << endl;
    cout << "Net Amount Paid by the Customer: " << netamount << endl;
    return 0;
}