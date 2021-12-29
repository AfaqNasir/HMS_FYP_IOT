
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
double ATC,OTC,ATF,OTF;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)

void init_display(){
  Wire.setClock(400000);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
  display.display();
  display.clearDisplay();                                   //Clear the display
  display.setTextSize(2);                                   //Near it display the average BPM you can display the BPM if you want
  display.setTextColor(WHITE); 
  } 
void init_ir_sensor(){
  Wire.setClock(100000);
  mlx.begin();
}
void read_ir_sensor(){
  Wire.setClock(100000);  
  OTC = mlx.readObjectTempC();
  OTF = mlx.readObjectTempF();
  ATC = mlx.readAmbientTempC();
  ATF = mlx.readAmbientTempF();
  } 
void show_result(){
  Wire.setClock(400000);
  display.clearDisplay();         //Clear the display
  display.setTextSize(1);         
  display.setTextColor(WHITE); 
  display.setCursor(35,5);                
  display.println("Body Temp:");      
  display.setTextSize(2);  
  display.setCursor(20,23);    
  display.print(OTC);
  display.print((char)247);
  display.println("C");
   if (OTC > 37.8){
    display.setTextSize(1);  
    display.setCursor(35,45);                
    display.println("Fever!");    
    }
  if (OTC < 20.1){
    display.setTextSize(1);  
    display.setCursor(20,45);                
    display.println("Low Temprature!");    
    }
   if (OTC < 37.8 & OTC > 20.1){
    display.setTextSize(1);  
    display.setCursor(35,45);                
    display.println("Normal!");    
    }
  display.display();
  } 

void setup(){
  init_display();
  init_ir_sensor();
  }
 
void loop(){
  read_ir_sensor();
  show_result();
  delay(1000);
}
