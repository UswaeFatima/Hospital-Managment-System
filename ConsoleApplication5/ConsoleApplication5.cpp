//Project of Hospital Management System
//Header files here
#include<iostream>
#include<fstream>
#include<conio.h>

using namespace std;
int main()
{
    char filename[20];
    //Print welcome note
    cout << "HOSPITAL MANAGEMENT SYSTEM" << endl;
    system("pause");
    system("cls");
    int i;
    int login();
    login();
    //Giving options to users
b:
    cout << "HOSPITAL MANAGEMENT SYSTEM" << endl;
    cout << "1 Add New Patient Record" << endl;
    cout << "2 Add Diagnosis Information" << endl;
    cout << "3 Full History of the Patient" << endl;
    cout << "4 Exit the Program" << endl << endl;
a:cout << "Enter your choice: ";
    cin >> i;
    if (i > 5 || i < 1)
    {
        cout << "Invalid Choice" << endl;
        cout << "Try again..........." << endl; goto a;
    }
    //if inputed choice is other than given choice
    system("cls");
    //Adding the record of the new patient..................option 1
    if (i == 1)
    {
        ofstream pat_file;
        char fname[20];
        cout << "Enter the patient's file name : " << endl;
        cin.ignore();
        gets(fname);
        pat_file.open(fname);
        if (!fname)
        {
            cout << "Error while opening the file" << endl; goto b;
        }
        else
        {
            struct patient_info
            {
                char name[20];
                char address[100];
                char contact[10];
                char age[5];
                char gender[8];
                char blood_gp[5];
                char disease_past[50];
                char id[15];
            };
            patient_info ak;
            cout << pat_file;
            cout << "Name : "; pat_file << "Name : "; gets(ak.name); pat_file << ak.name << endl;
            cout << "Address : "; pat_file << "Address : "; gets(ak.address); pat_file << ak.address << endl;
            cout << "Contact Number : "; pat_file << "Contact Number : "; gets(ak.contact); pat_file << ak.contact << endl;
            cout << "Age : "; pat_file << "Age : "; gets(ak.age); pat_file << ak.age << endl;
            cout << "Gender : "; pat_file << "Gender : "; gets(ak.gender); pat_file << ak.gender << endl;
            cout << "Blood Group : "; pat_file << "Blood Group : "; gets(ak.blood_gp); pat_file << ak.blood_gp << endl;
            cout << "Any Major disease suffered earlier : "; pat_file << "Any Major disease suffered earlier : "; gets(ak.disease_past); pat_file << ak.disease_past << endl;
            cout << "Patient ID : "; pat_file << "Patient ID : "; gets(ak.id); pat_file << ak.id << endl;
            cout << pat_file << endl;
            cout << "Information Saved Successfully" << endl;
        }
        system("pause");
        system("cls");
        goto b;
    }
    //Adding diagnosis information of patient.........option 2
    if (i == 2)
    {
        fstream pat_file;
        cout << "Enter the patient's file name to be opened : " << endl;
        cin.ignore();
        gets(filename);
        system("cls");
        pat_file.open(filename, ios::in);
        if (!pat_file)
        {
            cout << "Error while opening the file" << endl;
            goto b;
        }
        else
        {
            cout << "Information about " << filename << endl;
            string info;
            while (pat_file.good())
            {
                getline(pat_file, info);
                cout << info << endl;
            }
            pat_file.close();
            pat_file.open(filename, ios::out | ios::app);
            cout << "Adding more information in patient's file................on : " << pat_file << "Description of " << endl;
            struct app
            {
                char symptom[500];
                char diagnosis[500];
                char medicine[500];
                char addmission[30];
                char ward[15];
            };
            app add;
            cout << "Symptoms : "; pat_file << "Symptoms : "; gets(add.symptom); pat_file << add.symptom << endl;
            cout << "Diagnosis : "; pat_file << "Diagnosis : "; gets(add.diagnosis); pat_file << add.diagnosis << endl;
            cout << "Medicines : "; pat_file << "Medicines : "; gets(add.medicine); pat_file << add.medicine << endl;
            cout << "Addmission Required? : "; pat_file << "Addmission Required? : "; gets(add.addmission); pat_file << add.addmission << endl;
            cout << "Type of ward : "; pat_file << "Type of ward : "; gets(add.ward); pat_file << add.ward << endl; pat_file << endl;
            cout << add.ward << " ward is alloted Successfully" << endl;
            pat_file.close();
            system("pause");
            system("cls");
            goto b;
        }
    }
    // full medical history of patient in that hospital............option 3
    if (i == 3)
    {
        fstream pat_file;
        cout << "Enter the patient's file name to be opened : " << endl;
        cin.ignore();
        gets(filename);
        system("cls");
        pat_file.open(filename, ios::in);
        if (!pat_file)
        {
            cout << "Error while opening the file" << endl; goto b;
        }
        else
        {
            cout << "Full Medical History of " << endl;
            string info;
            while (pat_file.good())
            {
                getline(pat_file, info);
                cout << info << endl;
            }
        }
        system("pause");
        system("cls");
        goto b;
    }
    //Exiting Through the system with a Thank You note........................option 4
    if (i == 4)
    {
        system("cls");
        cout << "THANK YOU FOR USING" << endl;
        cout << "HOSPITAL MANAGEMENT SYSTEM" << endl;
    }
}
int login() {
    string pass = "";
    char ch;
    cout << "HOSPITAL MANAGEMENT SYSTEM" << endl;
    cout << "LOGIN" << endl;

    cout << "Enter Password: " << endl;
    ch = _getch();
    while (ch != 13)
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (pass == "pass") {
        cout << "Access Granted! " << endl;
        system("PAUSE");
        system("CLS");
    }
    else {
        cout << "Access Aborted...Please Try Again" << endl;
        system("PAUSE");
        system("CLS");
        login();
    }
}