#pragma once
#include "Data.h"
#include <string>

class VisaApplication : public Data {
private:
    string visaType;
    int invoiceNo;
    string surname;
    string firstName;
    string contact;
    string status;
    string result;

public:
    VisaApplication(string vType, int invoice, string sName, string fName, string con, string stat, string res) :
        visaType(vType), invoiceNo(invoice), surname(sName), firstName(fName), contact(con), status(stat), result(res) {}

    void print() override {
        cout << visaType << " ";
        cout << invoiceNo << " ";
        cout << surname << " ";
        cout << firstName << " ";
        cout << contact << " ";
        cout << status << " ";
        cout << result << " ";
        cout << endl;
    }

    string getVisaType() { return visaType; }
    int getInvoiceNo() { return invoiceNo; }
    string getSurname() { return surname; }
    string getFirstName() { return firstName; }
    string getContact() { return contact; }
    string getStatus() { return status; }
    string getResult() { return result; }
};
