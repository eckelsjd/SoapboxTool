# SoapboxTool
Soap box derby pre-race optimization software tool

## About
This is the online repository created to host the SoapboxTool numerical application as part of the Rose-Hulman senior design project for Joshua Eckels, Pascal Liberge, Shane Saylor, and Charles Earle. The tool was created to generate optimized pre-race tunings for a soapbox derby car based solely on a set of known or measurable racing conditions. See the full [documentation](doc/Soapbox-Handoff-Report.pdf).

## Installation
The SoapboxTool software application relies on the MATLAB runtime environment. This installation procedure was tested and ran on a Windows 10 machine.
1. Download a .ZIP file of this repository by clicking the green "Code" button above and clicking "Download .ZIP".
2. Extract the contents of the .ZIP to a desired folder on your computer.
3. Install the MATLAB R2020a (v. 9.8) [runtime environment](https://www.mathworks.com/products/compiler/matlab-runtime.html). Download the 64-bit Windows package for R2020a (9.8).
4. Unzip the runtime file by right-clicking and selecting "Extract All".
5. Once the extract process is complete, double click on the "setup.exe" application file in the extracted folder to run the software installer. Follow the on-screen installer instructions and accept all of the default options. MATLAB by default will install all of its files to "C:\Program Files\MATLAB\MATLAB Runtime". 
6. The install procedure can also be found [here](https://mathworks.com/help/compiler/install-the-matlab-runtime.html).
7. Click "Finish". 
8. Navigate back to the repository download folder from step 2. 
9. Navigate into the "SoapboxTool App" subfolder and run the "SoapboxTool.exe" application. 
10. That's it!

## Files
1. The images folder contains all photos used in the software application.
2. The SoapboxTool App folder contains the "SoapboxTool.exe" application file. Double click on this file to run the software application.
3. The data folder contains 2 files. The "wilburShaw.xlsx" file contains the measured hill slope profile of the Wilbur Shaw derby hill in Indianapolis, IN. The "DATALOG-test.txt" file contains properly formatted velocity test data for use in road load calculations.
4. The "SoapboxTool.mlapp" contains the MATLAB app designer code used during the development of this software application. This file is included for bookkeeping only. A full MATLAB installation and license is needed to open and edit this file to make changes directly to the application. This would be used for the purpose of app development and bug fixing.
5. The parts folder contains Solidworks and .stl files used to create the custom housing for the velocity data logger. The .stl files can be used with most 3D printers to reprint the parts.
6. The "VelocityDataLogger" folder contains the Arduino file that can be uploaded to the Arduino Nano over a Serial (USB) connection. This code collects and stores velocity time data onto a microSD card.
7. The doc folder contains the full handoff report and documentation for this project. See the appendices in this report for references and specification sheets.

## Author
Joshua Eckels (eckelsjd@rose-hulman.edu)


