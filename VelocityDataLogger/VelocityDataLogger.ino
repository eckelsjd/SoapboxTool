#include <avr/interrupt.h>
#include <SPI.h>
#include <SD.h>

#define COUNT_BLIPS 24
#define EPSILON 0.0001 // floating point tolerance

volatile float REV = 0;
volatile bool isCounting = true;
volatile bool readyToCount = false; // controlled by main loop only, not interrupts
volatile float start_time = 0;
volatile float end_time = 0;
float pi = 3.1415926535897932384626433832795;

String DATAFILE;
int pinIRinterrupt = 1;

void INTERRUPT()
{
    if (readyToCount) { // main loop will tell interrupt when its ready to start counting
        start_time = millis();
        isCounting = true;
        readyToCount = false;
    }
    
    if (isCounting) {
        REV = REV + 1; // Sets to record an interrupt every time the IR Sensor records a blip
    }

    if (abs(REV - COUNT_BLIPS) < EPSILON) {
        end_time = millis(); // stop time immediately at COUNT_BLIPS
        isCounting = false;
        readyToCount = false;
        REV = 0;
    }
}

//void printDirectory(File dir, int numTabs) {
//    while(true) {
//        File entry = dir.openNextFile();
//
//        if (! entry) {
//            break; // no more files
//        }
//
//        for (uint8_t i = 0; i < numTabs; i++) {
//            Serial.print('\t');
//        }
//
//        Serial.print(entry.name());
//
//        if (entry.isDirectory()) {
//            Serial.println("/");
//            printDirectory(entry,numTabs + 1);
//        } else {
//            // print file size
//            Serial.print("\t\t");
//            Serial.println(entry.size(),DEC);
//        }
//
//        entry.close();
//    }
//}

int getNextDatalogNumber() {

    int highestFileNum = 0;
    int currFileNum = 0;
    File root = SD.open("/");
    while(true) {
        File entry = root.openNextFile();
        if (! entry) {
            break; // no more files
        }
        String filename = String(entry.name());

        // filename format: "DATALOG4"
        if (filename.startsWith("DATALOG")) {
            String fileno = String(filename.charAt(7));
            currFileNum = fileno.toInt();

            if (currFileNum > highestFileNum) {
                highestFileNum = currFileNum;
            }
        }
        entry.close();
    }

    return highestFileNum + 1;
}

void setup()
{
  Serial.begin(9600);
  attachInterrupt(pinIRinterrupt, INTERRUPT, RISING); // A blip is recorded when the sensor reads positive, as opposed to negative, and recorded to interrupt 1 pin (D3)

  // SD Card Initialization
  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }

  DATAFILE = String("DATALOG") + String(getNextDatalogNumber()) + String(".txt");
}

void loop()
{

    // isCounting is a gate for the main loop
    if (!isCounting) { 
        float sec = (end_time - start_time)/1000; // time for exactly one revolution (8 blips)

        File dataFile = SD.open(DATAFILE, FILE_WRITE);
        if(dataFile) {
            float rev_s = 3/sec;
            dataFile.println(start_time + String(" ")+ rev_s);
//            Serial.println(start_time + String(" ") + rev_s);
            dataFile.close();
        }

        // Start counting blips
        readyToCount = true;
        isCounting = true;
    }
  
//  Serial.println(REC_TIME + String(" ")+ RAD_S); // Prints value for time in milliseconds and value for radians per second at that time
  
}
