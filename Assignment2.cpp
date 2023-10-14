// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "List.h"
#include "VisaApplication.h"

using namespace std;

void discard_line(ifstream& in);
void print(ofstream& out, VisaApplication& visaApp);
void print_success_list(List& myList);
void print_failure_list(List& myList);


int main()
{
    List myList;

    ifstream in;
    ofstream out;
    in.open("applications.txt", ios::in);
    out.open("applications_outcome.txt", ios::out);

    if (!in.is_open()) {
        cerr << "Unable to open the input file. " << endl;
    }

    string visaType;
    int invoiceNo;
    string surname;
    string firstName;
    string contact;
    string status;
    string result;

    discard_line(in);

    while (in >> visaType >> invoiceNo >> surname >> firstName >> contact >> status >> result) {
        VisaApplication* visaApp = new VisaApplication(visaType, invoiceNo, surname, firstName, contact, status, result);
        myList.appendNode(visaApp);

        print(out, *visaApp);
    }

    in.close();
    out.close();

    myList.printList();
    print_success_list(myList);
    print_failure_list(myList);

    system("pause");
    return 0;
}

void discard_line(ifstream& in)
{
    char c;

    do
        in.get(c);
    while (c != '\n');
}

void print(ofstream& out, VisaApplication& visaApp) {
    out << visaApp.getVisaType() << " ";
    out << visaApp.getInvoiceNo() << " ";
    out << visaApp.getSurname() << " ";
    out << visaApp.getFirstName() << " ";
    out << visaApp.getContact() << " ";
    out << visaApp.getStatus() << " ";
    out << visaApp.getResult() << endl;
}

void print_success_list(List& myList) {
    Node* pNode = myList.getpHead();

    cout << "--------------------------------" << endl;
    cout << "Successful Visa Applications:" << endl;
    cout << "--------------------------------" << endl;

    while (pNode != nullptr) {

        // Cast Data to VisaApplication
        VisaApplication* visaApp = (VisaApplication*)(pNode->getData());

        if (visaApp != nullptr) {
            if (visaApp->getResult() == "success") {
                // Print successful application details
                cout << visaApp->getVisaType() << " ";
                cout << visaApp->getInvoiceNo() << " ";
                cout << visaApp->getSurname() << " ";
                cout << visaApp->getFirstName() << " ";
                cout << visaApp->getContact() << " ";
                cout << visaApp->getStatus() << " ";
                cout << visaApp->getResult() << endl;
            }
        }
        pNode = myList.nextNode(pNode);
    }
}

void print_failure_list(List& myList) {
    Node* pNode = myList.getpHead();

    cout << "--------------------------------" << endl;
    cout << "Failed Visa Applications:" << endl;
    cout << "--------------------------------" << endl;

    while (pNode != nullptr) {

        // Cast Data to VisaApplication
        VisaApplication* visaApp = (VisaApplication*)(pNode->getData());

        if (visaApp != nullptr) {
            if (visaApp->getResult() == "failure") {
                // Print successful application details
                cout << visaApp->getVisaType() << " ";
                cout << visaApp->getInvoiceNo() << " ";
                cout << visaApp->getSurname() << " ";
                cout << visaApp->getFirstName() << " ";
                cout << visaApp->getContact() << " ";
                cout << visaApp->getStatus() << " ";
                cout << visaApp->getResult() << endl;
            }
        }
        pNode = myList.nextNode(pNode);
    }
}




