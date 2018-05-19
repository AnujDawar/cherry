#include <HEADERLOL.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(resetPin, INPUT);
  //digitalWrite(resetPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

Screen2:

  //digitalWrite(resetPin, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    CIVIL");
  lcd.setCursor(0, 1);
  lcd.print("  CALCULATOR");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A:Circle");
  lcd.setCursor(9, 0);
  lcd.print("B:Dome");
  lcd.setCursor(0, 1);
  lcd.print("C:Irregular");
  lcd.setCursor(12, 1);
  lcd.print("-> ");
  lcd.setCursor(15, 1);

  customKey = customKeypad.waitForKey();

  if (customKey)
  {
    checkReset();
    lcd.print(customKey);
  }

  delay(500);

  lcd.clear();
  lcd.setCursor(0, 0);

  switch (customKey)
  {
    case 'A':

      lcd.print("Circle Selected");
      delay(1000);

      inputDiameter();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Diameter : ");
      lcd.setCursor(0, 1);
      lcd.print(finalDia, 2);
      lcd.print(" Meters");
      delay(1000);

      inputS1();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("S1 : ");
      lcd.setCursor(0, 1);
      lcd.print(finalS1, 2);
      lcd.print(" Meters");
      delay(1000);

      inputS2();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("S2 : ");
      lcd.setCursor(0, 1);
      lcd.print(finalS2, 2);
      lcd.print(" Meters");
      delay(1000);

      Length = calculateCircle(finalDia, finalS1, finalS2);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Length Required : ");
      lcd.setCursor(0, 1);
      lcd.print(Length, 2);
      lcd.print(" Meters");
      customKeypad.waitForKey();

      break;

    case 'B':

      lcd.print("Dome Selected");
      delay(1000);

      inputRadius();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Radius : ");
      lcd.setCursor(0, 1);
      lcd.print(finalRadius, 2);
      lcd.print(" Meters");
      delay(1000);

      inputS1();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("S1 : ");
      lcd.setCursor(0, 1);
      lcd.print(finalS1, 2);
      lcd.print(" Meters");
      delay(1000);

      inputS2();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("S2 : ");
      lcd.setCursor(0, 1);
      lcd.print(finalS2, 2);
      lcd.print(" Meters");
      delay(1000);

      inputHeight();

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Height : ");
      lcd.setCursor(0, 1);
      lcd.print(finalHeight, 2);
      lcd.print(" Meters");
      delay(1000);


      Length = calculateDome(finalRadius, finalS1, finalS2, finalHeight);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Length Required : ");
      lcd.setCursor(0, 1);
      lcd.print(Length, 2);
      lcd.print(" Meters");

      customKeypad.waitForKey();

      break;

    case 'C':

      lcd.print("Irregular");
      lcd.setCursor(0, 1);
      lcd.print(" Selected");
      delay(1000);

      inputArea();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Area : ");
      lcd.setCursor(0, 1);
      lcd.print(finalArea, 2);
      lcd.print(" Meters");
      delay(1000);

      inputS1();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("S1 : ");
      lcd.setCursor(0, 1);
      lcd.print(finalS1, 2);
      lcd.print(" Meters");
      delay(1000);

      inputS2();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("S2 : ");
      lcd.setCursor(0, 1);
      lcd.print(finalS2, 2);
      lcd.print(" Meters");
      delay(1000);

      Length = calculateIrregular(finalArea, finalS1, finalS2);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Length Required : ");
      lcd.setCursor(0, 1);
      lcd.print(Length, 2);
      lcd.print(" Meters");

      customKey = customKeypad.waitForKey();
      break;

    default:

      invalidCode();
      goto Screen2;

  }  //  switch

}  //  loop

