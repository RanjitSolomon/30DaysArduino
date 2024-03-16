
#include <U8glib.h>

//U8GLIB_SH1106_128X64 My_u8g_Panel(U8G_I2C_OPT_NONE); // I2C /TWI
U8GLIB_SSD1306_128X64 My_u8g_Panel(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

void draw(void){
  // graphic commands to redraw the complete screen should be placed here
  My_u8g_Panel.setFont(u8g_font_unifont);
  My_u8g_Panel.drawStr(10,25, "Hello World!");
  //My_u8g_Panel.drawStr(0, 30, "Build");
  //My_u8g_Panel.drawStr(0, 50, "Everything");
}

void setup() {
  // flip screen, if required
  // My_u8g_Panel.setRot180();

  // assign default color value
  My_u8g_Panel.setColorIndex(1); // pixel on

  // pinMode(8, OUTPUT);

}

void loop() {
  // picture loop
  My_u8g_Panel.firstPage();
  do {
    draw();
  } while (My_u8g_Panel.nextPage());

}


// OLED
// u8glib library
// I2C communication Protocol
// data send usig a single wire (CLK wire pulse / Data wire pulse)
// GND, VCC, SCL(Serial Clock), SDA(Serial Data)
// Arduino pins A4 and A5 should be used for components requiring I2C