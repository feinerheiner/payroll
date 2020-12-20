#ifndef SALARY_PAYROLL_H
#define SALARY_PAYROLL_H
#include "payroll_data.h"


class SalaryPayroll: public PayrollData{


public:
    SalaryPayroll();
    SalaryPayroll(double pay_rate, std::string name);
    virtual ~SalaryPayroll(){};

    double ComputeGross() const;
    void WriteData(std::ostream &out) const;
    void WriteReport(std::ostream &out) const;

};

#endif