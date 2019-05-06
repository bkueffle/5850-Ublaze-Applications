A Study on Soft Core Processor Configurations for Embedded Applications

Git : https://github.com/bkueffle/5850-Ublaze-Applications

Documentation and presentations

doc
  |
  --> paper.pdf
  --> poster.ppt
  --> presentation.ppt

Vivado Project & Block Diagram

src
  |
  --> uBlaze_Applications

Software Source Code & Linker Script

src
  |
  --> uBlaze_Applications
    |
    --> uBlaze_Applications.sdk
      |
      --> uBlaze_application
        |
        --> src
          |
          --> ublaze_app_functions.c
          --> ublaze_app_functions.h
          --> ublaze_app.c
	  --> platform.c
          --> platform.h
          --> ublaze_application.ld

Constraints (Digilent Xilinx AT-50 development board)

src
  |
  --> constraints
    |
    --> fpga.xdc


Tests - Vivado reports

test
  |
  --> impl1
  --> impl2
  --> impl3
  --> impl4
  --> impl5
  --> impl6

Test Scripts

test
  |
  --> Latin_32kB_Script.txt
  --> Numbers_32kB_Script.txt
  --> verify_algorithm_test.txt

Data Recording

test
  |
  --> Results.xlsx



