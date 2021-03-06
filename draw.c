#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int a = y1 - y0;
  int b = -(x1 - x0);
  int d;
  float m = a * 1.0 / -b;
  if (b > 0) {
    draw_line(x1, y1, x0, y0, s, c);
  }
  //horizontal
  if (a == 0) {
    while(x0 <= x1) {
      plot(s, c, x0, y0);
      x0++;
    }
  }
  //vertical
  if (b == 0) {
    while(y0 <= y1) {
      plot(s, c, x0, y0);
      y0++;
    }
  }
  //1,5
  if(0 <= m && m <= 1) {
    d = 2 * a + b;
    while(x0 <= x1) {
      plot(s, c, x0, y0);
      if (d > 0) {
        y0++;
        d += 2 * b;
      }
      x0++;
      d += 2 * a;
    }
  }
  if (m > 1) {
    d = a + 2 * b;
    while (y0 <= y1) {
      plot(s, c, x0, y0);
      if (d < 0) {
        x0++;
        d += 2 * a;
      }
      y0++;
      d += 2 * b;
    }
  }
  if (m < -1) {
    d = a - 2 * b;
    while (y0 >= y1) {
      plot(s, c, x0, y0);
      if (d < 0) {
        x0++;
        d -= 2 * a;
      }
      y0--;
      d += 2 * b;
    }
  }
  if (m >= -1 && m < 0) {
    d = 2 * a - b;
     while (x0 <= x1) {
       plot(s, c, x0, y0);
       if (d > 0) {
         y0--;
         d += 2 * b;
       }
       x0++;
       d -= 2 * a;
     }
  }
}
