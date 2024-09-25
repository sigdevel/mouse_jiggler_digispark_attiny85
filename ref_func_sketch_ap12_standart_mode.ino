#include "DigiMouse.h"

void moveMouse(int dx, int dy, int delayTime) {
  digitalWrite(1, HIGH); // Включить светодиод
  DigiMouse.move(dx, dy, 0);
  DigiMouse.delay(random(delayTime - 30, delayTime + 30));
  digitalWrite(1, LOW); // Выключить светодиод
}

void setup() {
  pinMode(1, OUTPUT); // Установить пин 1 как выход
  DigiMouse.begin();
}

void loop() {
  // Базовые перемещения
  int randomRight = random(1, 6);
  int randomDown = random(1, 6);
  int randomUp = random(1, 6);

  // Двигаться вправо и вниз
  moveMouse(randomRight, 0, 75);
  moveMouse(0, randomDown, 64);

  // Возврат в начальное положение
  moveMouse(-randomRight * 2, -randomDown, 64);

  // Двигаться вправо и вверх
  moveMouse(randomRight, 0, 90);
  moveMouse(0, -randomUp, 55);

  // Возврат в начальное положение
  moveMouse(-randomRight, randomUp, 55);

  // Пауза перед перемещением
  DigiMouse.delay(random(2000, 12000));

  // Переместить курсор в случайное место на экране
  moveMouse(random(0, 1920), random(0, 1080), 3000);
}
