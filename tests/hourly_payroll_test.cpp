// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <iostream>
#include "hourly_payroll.h"

using namespace std;

//***************************kRegularHours*************************
TEST_CASE("Consant kRegularHours is defined and set to 40", "[start]") {
  REQUIRE(HourlyPayroll::kRegularHours == 40);
}

//***************************kOvertimeRate*************************
TEST_CASE("Consant kOvertimeRate is defined and set to 1.5", "[start]") {
  REQUIRE(HourlyPayroll::kOvertimeRate == 1.5);
}

//***************************kRegularHours*************************
TEST_CASE("Consant kMinHours is defined and set to 0", "[start]") {
  REQUIRE(HourlyPayroll::kMinHours == 0);
}

//***************************kOvertimeRate*************************
TEST_CASE("Consant kMaxHours is defined and set to 168", "[start]") {
  REQUIRE(HourlyPayroll::kMaxHours == 168);
}

//***************************kOvertimeRate*************************
TEST_CASE("Consant kMinWage is defined and set to 7.25", "[start]") {
  REQUIRE(HourlyPayroll::kMinWage == 7.25);
}

//***************************Default Constructor*************************
TEST_CASE(
    "Default constructor sets pay rate to kMinWage, first name to "
    "'it is', last name to 'unknown', and hours worked to 0",
    "[start]") {
  HourlyPayroll hourly;
  REQUIRE(fabs(hourly.get_hours() - 0) < .0001);
  REQUIRE(fabs(hourly.get_pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.get_first_name() == "it is");
  REQUIRE(hourly.get_last_name() == "unknown");
}

//***************************Other constructor*************************
TEST_CASE(
    "Other constructor sets values as expected when called with "
    "'12.54, 34, 'Peters, Walter' ",
    "[start]") {
  HourlyPayroll hourly(34, 12.54, "Peters, Walter");
  REQUIRE(fabs(hourly.get_hours() - 34) < .0001);
  REQUIRE(fabs(hourly.get_pay_rate() - 12.54) < .0001);
  REQUIRE(hourly.get_first_name() == "Walter");
  REQUIRE(hourly.get_last_name() == "Peters");
}

TEST_CASE(
    "Other constructor throws out of range exception when called with negative "
    "hours",
    "[start]") {
  HourlyPayroll hourly = HourlyPayroll(-34, 12.54, "Peters, Walter");
  REQUIRE(fabs(hourly.get_pay_rate() - 12.54) < .0001);
  REQUIRE(hourly.get_first_name() == "Walter");
  REQUIRE(hourly.get_last_name() == "Peters");
}

TEST_CASE(
    "Other constructor throws out of range exception when called with hours "
    "greater than 168",
    "[start]") {
  HourlyPayroll hourly = HourlyPayroll(169, 12.54, "Peters, Walter");
  REQUIRE(fabs(hourly.get_hours() - HourlyPayroll::kMaxHours) < .0001);
  REQUIRE(fabs(hourly.get_pay_rate() - 12.54) < .0001);
  REQUIRE(hourly.get_first_name() == "Walter");
  REQUIRE(hourly.get_last_name() == "Peters");
}

TEST_CASE(
    "Other constructor throws out of range exception when called with pay rate "
    "less than 7.25",
    "[start]") {
  double low_wage = HourlyPayroll::kMinWage - .02;
  HourlyPayroll hourly = HourlyPayroll(34, low_wage, "Peters, Walter");
  REQUIRE(fabs(hourly.get_hours() - 34) < .0001);
  REQUIRE(fabs(hourly.get_pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.get_first_name() == "Walter");
  REQUIRE(hourly.get_last_name() == "Peters");
}

//***************************getters*************************
TEST_CASE("Getters return expected values", "[start]") {
  HourlyPayroll hourly(47, 25.71, "Johnson, Terry");
  REQUIRE(fabs(hourly.get_hours() - 47) < .0001);
  REQUIRE(fabs(hourly.get_pay_rate() - 25.71) < .0001);
  REQUIRE(hourly.get_first_name() == "Terry");
  REQUIRE(hourly.get_last_name() == "Johnson");
//  REQUIRE(hourly.get_name() == "Terry Johnson");
//  REQUIRE(hourly.get_name_last_first() == "Johnson, Terry");
}

//***************************set hours*************************
TEST_CASE("Hours setter sets hours to 0", "[start]") {
  HourlyPayroll hourly;
  hourly.set_hours(0);
  REQUIRE(fabs(hourly.get_hours() - 0) < .0001);
  REQUIRE(fabs(hourly.get_pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.get_first_name() == "it is");
  REQUIRE(hourly.get_last_name() == "unknown");
}

TEST_CASE("Hours setter sets hours to 168", "[start]") {
  HourlyPayroll hourly;
  hourly.set_hours(168);
  REQUIRE(fabs(hourly.get_hours() - 168) < .0001);
  REQUIRE(fabs(hourly.get_pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.get_first_name() == "it is");
  REQUIRE(hourly.get_last_name() == "unknown");
}

TEST_CASE("Hours setter sets hours to 54", "[start]") {
  HourlyPayroll hourly;
  hourly.set_hours(54);
  REQUIRE(fabs(hourly.get_hours() - 54) < .0001);
  REQUIRE(fabs(hourly.get_pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.get_first_name() == "it is");
  REQUIRE(hourly.get_last_name() == "unknown");
}

TEST_CASE("Hours setter sets hours to 22.3", "[start]") {
  HourlyPayroll hourly;
  hourly.set_hours(22.3);
  REQUIRE(fabs(hourly.get_hours() - 22.3) < .0001);
  REQUIRE(fabs(hourly.get_pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.get_first_name() == "it is");
  REQUIRE(hourly.get_last_name() == "unknown");
}

TEST_CASE(
    "Hours setter throws out of bounds exception when set to negative number",
    "[start]") {
  HourlyPayroll hourly;
  hourly.set_hours(-1);
  REQUIRE(fabs(hourly.get_hours() - HourlyPayroll::kMinHours) < .0001);
}

TEST_CASE(
    "Hours setter throws out of bounds exception when set to number greater "
    "than 168",
    "[start]") {
  HourlyPayroll hourly;
  hourly.set_hours(169);
  REQUIRE(fabs(hourly.get_hours() - HourlyPayroll::kMaxHours) < .0001);
}

TEST_CASE("Hours setter throws out of bounds exception when set to 168.1",
          "[start]") {
  HourlyPayroll hourly;
  hourly.set_hours(168.1);
  REQUIRE(fabs(hourly.get_hours() - HourlyPayroll::kMaxHours) < .0001);
}

//***************************set pay rate*************************

TEST_CASE("Pay rate setter sets pay rate to 8.12", "[start]") {
  HourlyPayroll hourly(18, 14.50, "Walters, Kerry");
  hourly.set_pay_rate(8.12);
  REQUIRE(fabs(hourly.get_hours() - 18) < .0001);
  REQUIRE(fabs(hourly.get_pay_rate() - 8.12) < .0001);
  REQUIRE(hourly.get_first_name() == "Kerry");
  REQUIRE(hourly.get_last_name() == "Walters");
}

TEST_CASE("Pay rate setter throws out of bounds exception when set to 7.01",
          "[start]") {
  HourlyPayroll hourly;
  hourly.set_pay_rate(7.01);
  REQUIRE(fabs(hourly.get_pay_rate() - HourlyPayroll::kMinWage) < .0001);
}

TEST_CASE("Pay rate setter throws out of bounds exception when set to -7.01",
          "[start]") {
  HourlyPayroll hourly;
  hourly.set_pay_rate(-7.01);
  REQUIRE(fabs(hourly.get_pay_rate() - HourlyPayroll::kMinWage) < .0001);
}

//***************************set name*************************

TEST_CASE("Name setter sets name to Kelly Walters when sent Kelly Walters",
          "[start]") {
  HourlyPayroll hourly;
  hourly.set_name("Kelly Walters");
  REQUIRE(fabs(hourly.get_hours() - 0) < .0001);
  REQUIRE(fabs(hourly.get_pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.get_first_name() == "Kelly");
  REQUIRE(hourly.get_last_name() == "Walters");
}

TEST_CASE("Name setter sets name to Kelly Walters when sent Walters, Kelly ",
          "[start]") {
  HourlyPayroll hourly;
  hourly.set_name("Walters, Kelly");
  REQUIRE(fabs(hourly.get_hours() - 0) < .0001);
  REQUIRE(fabs(hourly.get_pay_rate() - HourlyPayroll::kMinWage) < .0001);
  REQUIRE(hourly.get_first_name() == "Kelly");
  REQUIRE(hourly.get_last_name() == "Walters");
}

//***************************ComputeGross*************************

TEST_CASE(
    "ComputeGross returns 752 when hours is 32 and pay is "
    "23.5",
    "[gross]") {
  HourlyPayroll hourly(32, 23.5, "Kim Johnson");

  REQUIRE(fabs(hourly.ComputeGross() - 752) < .0001);
}

TEST_CASE(
    "ComputeGross returns 1010.5 when hours is 42 and pay is "
    "23.5",
    "[gross]") {
  HourlyPayroll hourly(42,23.5, "Kim Johnson");

  REQUIRE(fabs(hourly.ComputeGross() - 1010.5) < .0001);
}

TEST_CASE(
    "ComputeGross returns 0 when hours is 0 and pay is "
    "23.5",
    "[gross]") {
  HourlyPayroll hourly(0, 23.5, "Kim Johnson");

  REQUIRE(fabs(hourly.ComputeGross() - 0) < .0001);
}

TEST_CASE(
    "ComputeGross returns 2324.4 when hours is 63 and pay is "
    "31.2",
    "[gross]") {
  HourlyPayroll hourly(63, 31.2, "Kim Johnson");

  REQUIRE(fabs(hourly.ComputeGross() - 2324.4) < .0001);
}

//***************************WriteData*************************

TEST_CASE(
    "WriteData writes data as expected when hours is 43 and "
    "pay is 14.92",
    "[write_data]") {
  HourlyPayroll hourly(43, 14.92, "Kim Johnson");
  ofstream out("test.out");
  hourly.WriteData(out);
  out.close();
  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;
  getline(in, line);
  REQUIRE(line == "H 43.00 14.92 663.94");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "WriteData writes data as expected when multiple HourlyPayroll is written",
    "[write_data]") {
  HourlyPayroll hourly1(22, 12.79, "Johnson, Kim");
  HourlyPayroll hourly2(43, 14.92, "Kim Johnson");
  ofstream out("test.out");
  hourly1.WriteData(out);
  hourly2.WriteData(out);
  out.close();

  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;
  getline(in, line);
  REQUIRE(line == "H 22.00 12.79 281.38");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "H 43.00 14.92 663.94");
  getline(in, line);
  REQUIRE(line == "Johnson, Kim");
  getline(in, line);
  REQUIRE(line == "");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

//***************************PayrollReport*************************

TEST_CASE(
    "WriteReport prints expected report when hours are 35 and "
    "pay is 17.5",
    "[write_data]") {
  ofstream out("test.out");

  HourlyPayroll payroll_data(35, 17.5, "John Jones");
  payroll_data.WriteReport(out);
  out.close();

  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;

  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "   Hours Worked: 35.00");
  getline(in, line);
  REQUIRE(line == "   Pay Rate: $17.50");
  getline(in, line);
  REQUIRE(line == "   Gross Pay: $612.50");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "WriteReport prints expected report when hours is 72.3"
    " and pay is 1722.6",
    "[write_data]") {
  ofstream out("test.out");

  HourlyPayroll payroll_data(72.3, 22.6, "Jones, John");
  payroll_data.WriteReport(out);
  out.close();

  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;

  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "   Hours Worked: 72.30");
  getline(in, line);
  REQUIRE(line == "   Pay Rate: $22.60");
  getline(in, line);
  REQUIRE(line == "   Gross Pay: $1998.97");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

TEST_CASE(
    "WriteReport prints expected report when multiple reports are written",
    "[write_data]") {
  ofstream out("test.out");

  HourlyPayroll payroll_data(72.3, 22.6, "Jones, John");
  HourlyPayroll payroll_data2(35, 17.5, "John Jones");
  payroll_data.WriteReport(out);
  payroll_data2.WriteReport(out);
  out.close();

  ifstream in("test.out");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  string line;

  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "   Hours Worked: 72.30");
  getline(in, line);
  REQUIRE(line == "   Pay Rate: $22.60");
  getline(in, line);
  REQUIRE(line == "   Gross Pay: $1998.97");
  getline(in, line);
  REQUIRE(line == "John Jones");
  getline(in, line);
  REQUIRE(line == "   Hours Worked: 35.00");
  getline(in, line);
  REQUIRE(line == "   Pay Rate: $17.50");
  getline(in, line);
  REQUIRE(line == "   Gross Pay: $612.50");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}
