#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
constexpr int COLS = 5;

int y[COLS];
int elts[COLS];
int speeds[COLS];

void setup() {
  // put your setup code here, to run once:
  tft.init();
  tft.setRotation(1);  // landscape

  for (int i = 0; i < COLS; i++) {
    y[i] = 0;
    elts[i] = random(3);
    speeds[i] = random(5, 15);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < COLS; i++) {
    if (y[i] > tft.height()) { 
      y[i] = 0; // reset element fall from the top
      elts[i] = random(3); // randomize element at the top
      speeds[i] = random(5, 10); // randomize element fall speed
    }

    y[i] += speeds[i]; // fall
  }

  draw(); // draw three elements
}

void draw() {
  // clear elements
  tft.fillScreen(TFT_DARKCYAN);

  // 3 elements: each randomize color
  // decrement y (falling down), randomize x + rotation (wind)
  // draw leaf in each column
  for (int i = 0; i < COLS; i++) {
    // randomize x within column (wind!)
    int x = random(tft.width() * i / COLS, tft.width() * (i + 1) / COLS);

    drawElement(elts[i], x, y[i]);
  }

  delay(1000);
}

void drawElement(int elt, int centerX, int centerY) {
  if (elt == 0) { // leaf
    drawLeaf(centerX, centerY, 2);
  } else if (elt == 1) { // rain
    drawRain(centerX, centerY, 5);
  } else { // snow
    drawSnow(centerX, centerY, 5);
  }
}

void drawSnow(int centerX, int centerY, int scale) {
  int rainColor = TFT_WHITE;
  int rad = 18 / scale;
  tft.drawCircle(centerX, centerY, rad, rainColor);
  tft.fillCircle(centerX, centerY, rad, rainColor);
}

void drawRain(int centerX, int centerY, int scale) {
  int rainColor = TFT_CYAN;
  int rad = 20 / scale;
  tft.drawCircle(centerX, centerY, rad, rainColor);
  tft.fillCircle(centerX, centerY, rad, rainColor);

  int base = 36 / scale;
  int lowerHeight = 20 / scale;
  int upperHeight = 15 / scale;
  tft.drawTriangle(centerX, centerY - rad - upperHeight,
                    centerX + base / 2, centerY - rad + lowerHeight, 
                    centerX - base / 2, centerY - rad + lowerHeight, 
                    rainColor);
  tft.fillTriangle(centerX, centerY - rad - upperHeight,
                    centerX + base / 2, centerY - rad + lowerHeight, 
                    centerX - base / 2, centerY - rad + lowerHeight, 
                    rainColor);
}

void drawLeaf(int centerX, int centerY, int scale) {
  // randomize leaf color
  uint16_t leafColors[3] = {TFT_MAROON, TFT_ORANGE, TFT_YELLOW};
  uint16_t leafColor = leafColors[random(3)];
  
  // x, y (center), radius x, radius y for elliptical leaf body
  // int centerX = 120;
  // int centerY = 80;
  int radX = 50 / scale;
  int radY = 20 / scale;
  tft.drawEllipse(centerX, centerY, 
                  radX, radY, 
                  leafColor);
  tft.fillEllipse(centerX, centerY, 
                  radX, radY, 
                  leafColor);

  // x1, y1, x2, y2, x3, y3 (vertices) for triangular leaf tip
  int base = 33 / scale;
  int lowerHeight = 20 / scale;
  int upperHeight = 15 / scale;
  tft.drawTriangle(centerX - radX - upperHeight, centerY, 
                    centerX - radX + lowerHeight, centerY + base / 2, 
                    centerX - radX + lowerHeight, centerY - base / 2, 
                    leafColor);
  tft.fillTriangle(centerX - radX - upperHeight, centerY, 
                    centerX - radX + lowerHeight, centerY + base / 2, 
                    centerX - radX + lowerHeight, centerY - base / 2, 
                    leafColor);

  // x, y (top left), width, height, color
  int height = 5 / scale;
  int width = 28 / scale;
  tft.drawRect(centerX + radX, centerY - height / 2, 
                width, height, 
                leafColor);
  tft.fillRect(centerX + radX, centerY - height / 2, 
                width, height, 
                leafColor);
}