#include "../../externals/catch2/catch.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include "process_payroll.h"

TEST_CASE(
    "ProcessPayroll reads the data from the ../../tests/test_in.txt file and "
    "writes payroll reports to ../../tests/test_out.txt. ",
    "[process_payroll]") {
  ProcessPayroll("../../tests/test_in.txt", "../../tests/test_out.txt");

  std::ifstream in("../../tests/test_out.txt");
  if (in.fail()) {
    REQUIRE("File Opened" == "Unable to open file");
  }
  std::string line;

  getline(in, line);
  REQUIRE(line == "Jean Will James");
  getline(in, line);
  REQUIRE(line == "   Pay Rate: $120.00");
  getline(in, line);
  REQUIRE(line == "   How Many: 16");
  getline(in, line);
  REQUIRE(line == "   Commission: $1920.00");
  getline(in, line);
  REQUIRE(line == "   Base Pay: $900.00");
  getline(in, line);
  REQUIRE(line == "   Gross Pay: $2820.00");
  getline(in, line);
  REQUIRE(line == "Renee C. Javens");
  getline(in, line);
  REQUIRE(line == "   Hours Worked: 49.80");
  getline(in, line);
  REQUIRE(line == "   Pay Rate: $28.40");
  getline(in, line);
  REQUIRE(line == "   Gross Pay: $1553.48");
  getline(in, line);
  REQUIRE(line == "Rose Harrison");
  getline(in, line);
  REQUIRE(line == "   Pay Rate: $1895.00");
  getline(in, line);
  REQUIRE(line == "   Gross Pay: $1895.00");
  getline(in, line);
  REQUIRE(line == "Cathy Setzer");
  getline(in, line);
  REQUIRE(line == "   Hours Worked: 12.75");
  getline(in, line);
  REQUIRE(line == "   Pay Rate: $12.60");
  getline(in, line);
  REQUIRE(line == "   Gross Pay: $160.65");
  getline(in, line);
  REQUIRE(line == "Gordon J. Pike");
  getline(in, line);
  REQUIRE(line == "   Pay Rate: $1920.00");
  getline(in, line);
  REQUIRE(line == "   Gross Pay: $1920.00");
  getline(in, line);
  REQUIRE(line == "Beth R. Holland");
  getline(in, line);
  REQUIRE(line == "   Pay Rate: $18.20");
  getline(in, line);
  REQUIRE(line == "   How Many: 96");
  getline(in, line);
  REQUIRE(line == "   Commission: $1747.20");
  getline(in, line);
  REQUIRE(line == "   Base Pay: $312.00");
  getline(in, line);
  REQUIRE(line == "   Gross Pay: $2059.20");
  getline(in, line);
  REQUIRE(line == "");
  in.close();
}

//TEST_CASE(
//    "ProcessPayroll function throws out of range exception when there is an "
//    "invalid payroll type",
//    "[start]") {
//  REQUIRE_THROWS_AS(
//      ProcessPayroll("../../payroll_error1.txt", "../../tests/test_out.txt"),
//      std::out_of_range);
//}
//
//TEST_CASE(
//    "ProcessPayroll function throws out of range exception when a new "
//    "HourlyPayroll object is created with a pay rate below minimum wage.",
//    "[start]") {
//  REQUIRE_THROWS_AS(
//      ProcessPayroll("../../payroll_error2.txt", "../../tests/test_out.txt"),
//      std::out_of_range);
//}
//
//TEST_CASE(
//    "ProcessPayroll function throws out of range exception when a new "
//    "SalaryPayroll object is created with a negative pay rate.",
//    "[start]") {
//  REQUIRE_THROWS_AS(
//      ProcessPayroll("../../payroll_error2.txt", "../../tests/test_out.txt"),
//      std::out_of_range);
//}
