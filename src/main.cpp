#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <SD.h>

#define ONE_WIRE_BUS 2 // DS18B20 data pin
#define BUTTON1_PIN 3
#define BUTTON2_PIN 4
#define LED_BLUE_PIN 5
#define LED_RED_PIN 6
#define LED_GREEN_PIN 7
#define BUZZER_PIN 8
#define LDR_PIN A1
#define SD_CS_PIN 10 // SD card chip select pin

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

unsigned long previousMillis = 0;
const long interval = 1000; // Interval between different tones
int buzzerState = LOW;
bool muteBuzzer = false;

void setup() {
  Serial.begin(9600);
  
  // Initialize DS18B20 sensor
  sensors.begin();
  
  // Initialize pins
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(LED_BLUE_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  
  // Initialize SD card
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card initialization failed!");
    return;
  }
  Serial.println("SD card initialized.");

  // Create a test file
  File testFile = SD.open("test.txt", FILE_WRITE);
  if (testFile) {
    testFile.println("SD card is working!");
    testFile.close();
    Serial.println("Test file created.");
  } else {
    Serial.println("Error creating test file.");
  }
}

void loop() {
  // Test DS18B20
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  
  // Test buttons
  int button1State = digitalRead(BUTTON1_PIN);
  int button2State = digitalRead(BUTTON2_PIN);
  Serial.print("Button 1: ");
  Serial.println(button1State == LOW ? "Pressed" : "Not pressed");
  Serial.print("Button 2: ");
  Serial.println(button2State == LOW ? "Pressed" : "Not pressed");
  
  // Test LEDs
  digitalWrite(LED_BLUE_PIN, HIGH);
  
  // Test LDR
  float voltage = analogRead(LDR_PIN) * (3.3 / 1023.0);
  int ldrValue = map(voltage * 1023.0 / 3.3, 0, 1023, 300, 1023);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);
  
  // Log data to SD card
  File logFile = SD.open("log.txt", FILE_WRITE);
  if (logFile) {
    logFile.print("Temperature: ");
    logFile.print(temperature);
    logFile.print(" C, LDR Value: ");
    logFile.println(ldrValue);
    logFile.close();
    Serial.println("Data logged to SD card.");
  } else {
    Serial.println("Error opening log file.");
  }



  // Read data from SD card if button 2 is pressed
  if (button2State == LOW) {
    File logFile = SD.open("log.txt");
    if (logFile) {
      Serial.println("Reading log file:");
      while (logFile.available()) {
        Serial.write(logFile.read());
      }
      logFile.close();
    } else {
      Serial.println("Error opening log file.");
    }
    delay(1000); // Prevent multiple reads in quick succession
  }
  
  delay(2000); // Wait for 2 seconds before repeating the loop
}
