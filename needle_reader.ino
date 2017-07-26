#define NEEDLE_IN A0
#define WHITE_NEEDLE_OUT 9

int needleSetting = 0;
long upTime;

void setup() {
  Serial.begin(9600);
  upTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(voltToDial(analogRead(NEEDLE_IN)));
  setWhiteNeedle(needleSetting);

  if (millis() - upTime >= 1000) {
    needleSetting = random(0, 30);
    upTime = millis();
  }
}

float voltToDial(int volt) {
  volt = constrain(volt, 25, 700);

  // return (volt - minimum value) * (maximum value / range)
  return (volt - 25) * (31 / 630.0);
}

float setWhiteNeedle(float dialSetting) {
  // Map: 0 - 30 dial setting == 0 - 155 output
  
  analogWrite(WHITE_NEEDLE_OUT, dialSetting * (155 / 30.0));
}

