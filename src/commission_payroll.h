#ifndef COMMISSION_PAYROLL_H
#define COMMISSION_PAYROLL_H
#include "payroll_data.h"


class CommissionPayroll: public PayrollData{
private:
    int how_many;
    double base_pay;

public:
    CommissionPayroll();
    CommissionPayroll(double pay_rate, int how_many, double base_pay, std::string name);
    virtual~CommissionPayroll(){};

    int get_how_many() const;
    double get_base_pay() const;
    void set_how_many(int how_many);
    void set_base_pay(double base_pay);
    double ComputeCommission() const;
    double ComputeGross() const;
    void WriteData(std::ostream &out) const;
    void WriteReport(std::ostream &out) const;

};

#endif