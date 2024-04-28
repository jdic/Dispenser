#include <Ultrasonic.h>
#include <Arduino.h>

#define TPIN 18
#define EPIN 19
#define IN 21

const int DISPENSE_TIME = 25;
const int DISPENSE_DELAY = 1000;
const int DISTANCE_THRESHOLD[2] = { 3, 10 };
long distance = 0;

bool isDispensing = false;
unsigned long startTime = 0;
bool isReady = true;

Ultrasonic ultrasonic(TPIN, EPIN);

void blink(int speed)
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(speed);
  digitalWrite(LED_BUILTIN, LOW);
  delay(speed);
}

void awake()
{
  Serial.begin(115200);

  Serial.println("──────▄▀▄─────▄▀▄");
  Serial.println("─────▄█░░▀▀▀▀▀░░█▄");
  Serial.println("─▄▄──█░░░░░░░░░░░█──▄▄");
  Serial.println("█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█");

  pinMode(IN, OUTPUT);
  digitalWrite(IN, HIGH);
}

void setup()
{
  awake();
}

void loop()
{
  distance = ultrasonic.Ranging(CM);

  if (!isDispensing && isReady)
  {
    if (distance >= DISTANCE_THRESHOLD[0] && distance <= DISTANCE_THRESHOLD[1])
    {
      isDispensing = true;
      digitalWrite(IN, LOW);
      startTime = millis();
      isReady = false;
    }
  }

  else
  {
    unsigned long currentTime = millis();

    if (currentTime - startTime >= DISPENSE_TIME)
    {
      digitalWrite(IN, HIGH);
      isDispensing = false;
      delay(DISPENSE_DELAY);

      if (distance > DISTANCE_THRESHOLD[1])
      {
        isReady = true;
        Serial.println("Ready to dispense");
      }

      else
      {
        blink(100);
      }
    }

    else
    {
      blink(300);
    }
  }
}