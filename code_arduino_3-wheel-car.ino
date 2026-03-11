#include <IRremote.h>

#define IR_PIN 8   // chân OUT của mắt thu IR

int in1 = 3;
int in2 = 5;
int in3 = 6;
int in4 = 9;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {

    uint32_t code = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(code, HEX);

    if (code == 0xE718FF00) {        // lên
      toi();
    }
    else if (code == 0xAD52FF00) {   // xuống
      lui();
    }
    else if (code == 0xF708FF00) {   // trái
      trai();
    }
    else if (code == 0xA55AFF00) {   // phải
      phai();
    }
    else if (code == 0xE31CFF00) {   // dừng
      dung();
    }

    IrReceiver.resume();
  }
}

// ======= HÀM ĐIỀU KHIỂN XE =======

void toi() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void lui() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void dung() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void trai() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void phai() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}