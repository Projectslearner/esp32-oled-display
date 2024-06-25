/*
    Project name: ESP32 OLED Display
    Modified Date: 24-06-2024
    Code by: Projectslearner
    Website: https://projectslearner.com/learn/esp32-oled-display
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define the dimensions of the OLED display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Define the I2C address of the OLED display (usually 0x3C or 0x3D)
#define OLED_ADDRESS 0x3C

// Create an OLED display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600); // Initialize serial communication

  // Initialize the OLED display
  if (!display.begin(SSD1306_I2C_ADDRESS, OLED_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  // Clear the buffer
  display.clearDisplay();

  // Set the text size and color
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Display initial message
  display.setCursor(0, 0);
  display.println(F("ESP32 OLED Display"));
  display.display();
  delay(2000);
}

void loop() {
  // Clear the display
  display.clearDisplay();

  // Display dynamic content
  display.setCursor(0, 0);
  display.println(F("Hello, world!"));
  display.setCursor(0, 10);
  display.println(F("ESP32 & OLED"));

  // Display a counter
  static int counter = 0;
  display.setCursor(0, 20);
  display.print(F("Counter: "));
  display.print(counter);
  counter++;

  // Update the display with new content
  display.display();

  // Print the same information to the Serial Monitor
  Serial.print("Hello, world! ");
  Serial.println("ESP32 & OLED");
  Serial.print("Counter: ");
  Serial.println(counter - 1);

  delay(1000); // Add a delay before updating the display
}
