
#include "process_payroll.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "commission_payroll.h"
#include "hourly_payroll.h"
#include "payroll_data.h"
#include "salary_payroll.h"

using namespace std;

void ProcessPayroll(std::string inputFile, std::string outputFile){
    ifstream in(inputFile);
    if(in.fail()){
        cout << "unable to open file shutting down....\n";
        return;
    }
    vector<PayrollData*> list;
    char type;
    double pay_rate;
    double hours;
    int how_many;
    double base_pay;
    string name;

    while(in >> type){
        switch (type) {
            case 'S':
                in >> pay_rate;
                in.ignore();
                getline(in, name);
                list.push_back(new SalaryPayroll(pay_rate,name));
                break;

            case 'C':
                in >> pay_rate;
                in >> how_many;
                in >> base_pay;
                in.ignore();
                getline(in, name);
                list.push_back(new CommissionPayroll(pay_rate, how_many, base_pay, name));
                break;

            case 'H':
                in >> pay_rate;
                in >> pay_rate;
                in.ignore();
                getline(in, name);
                list.push_back(new HourlyPayroll(hours, pay_rate, name));
                break;
        }
    }
    in.close();
    ofstream out(outputFile);
    

}