#include<Keypad.h>   
#include<LiquidCrystal.h>

int a=0, b=0, c=0, d=0,e=0, f=0, g=0, h=0;//acumuladores de datos enteros para la contrseña.
int var=0; //incremento apara el switch.

int C1='a', C2='d', C3='1', C4='0',C5='2', C6='3', C7='4', C8='4'; //CLAVE1
int D1='d', D2='c', D3='7', D4='7',D5='4', D6='2', D7='3', D8='5'; //CLAVE2
int G1='c', G2='a', G3='5', G4='4',G5='3', G6='1', G7='8', G8='7'; //CLAVE3


char y='*';  //caracter para cubrir la contraseña.
int veces=0,incorrecto=0; //seguridad de solo 3 intentos para ingresar la contraseña correcta.
int aviso=3; //aviso para mostrar los intentos como seguridad para el usuario.

const byte filas = 4; //cuatro  filas.
const byte columnas = 4; //cuatro columnas.

String dato;
char tecla[filas][columnas] = {
  {'7','8','9','a'},
  {'4','5','6','c'},
  {'1','2','3','d'},
  {'*','0','#','E'}
};
byte pinFilas[filas] = {7, 6, 5, 4}; //conectarse a las patillas de salida de fila del teclado.
byte pinColumnas[columnas] = {3, 2, A4, A5}; //conectarse a las patillas de las columnas del teclado.

Keypad keypad = Keypad( makeKeymap(tecla), pinFilas, pinColumnas, filas, columnas );

LiquidCrystal lcd(13,12,11,10,9,8); //RS,E,D4,D5,D6,D7

//----------------------------------
int Li          = 16;
int Lii         = 0; 
int Ri          = -1;
int Rii         = -1;
//----------------------------------

void setup(){
  Serial.begin(9600);
  Serial.println("INGRESO DE PERSONA:");
  lcd.begin(16,2); //LCD (16 COLUMNAS Y 2 FILAS)
  pinMode(A0,OUTPUT); //clave correcta LED verde.
  pinMode(A1,OUTPUT); //clave incorrecta LED Rojo.
}
void loop(){
   //recibir mensajes
  if(Serial.available()>0){ //revisa si existen datos en el puerto cx serial
    dato=Serial.readString();
    Serial.println(dato);// si los tienes, almacena el dato en variable
  }
  char key = keypad.getKey();
  if (key){
   lcd.setCursor(4+var,1);
   
   lcd.print(key),lcd.setCursor(4+var,1),lcd.print(y); //imprimir en el lcd
   var++; //var se incrementa los case 
   switch(var){
    case 1:
    a=key; //almacenamos para la contraseña 1
    break;
    case 2:
    b=key; //almacenamos dígito para la contraseña 2
    break;
    case 3:
    c=key; //almacenamos dígito para la contraseña 3
    break;
    case 4:
    d=key; //almacenamos dígito para la contraseña 4
    break;
    case 5:
    e=key; //almacenamos dígito para la contraseña 5
    break;
    case 6:
    f=key; //almacenamos dígito para la contraseña  6
    break;
    case 7:
    g=key; //almacenamos dígito para la contraseña  7
    break;
    case 8:
    h=key;  //almacenamos dígito para la contraseña  8
    
   delay(100);
  if(a==C1 && b==C2 && c==C3 && d==C4 && e==C5 && f==C6 && g==C7 && h==C8){
    digitalWrite(A0,HIGH);
    delay(1000);
    lcd.clear();
    digitalWrite(A0,LOW);
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("BIENVENIDO");
    Clear_Scroll_LCD_Left();
      for (int i = 0; i <= 28; i++) {  
        lcd.setCursor(0, 1);
        lcd.print(Scroll_LCD_Right("Ariel Davalos"));
        delay(200);
        }
     Serial.println(String("Ariel Davalos")); 
      delay(200);
    } 
    else if(a==D1 && b==D2 && c==D3 && d==D4 && e==D5 && f==D6 && g==D7 && h==D8){
    digitalWrite(A0,HIGH);
    delay(1000);
    lcd.clear();
    digitalWrite(A0,LOW);
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("BIENVENIDO");
    Clear_Scroll_LCD_Left();
      for (int i = 0; i <= 28; i++) {  
        lcd.setCursor(0, 1);
        lcd.print(Scroll_LCD_Right("Damian Cervantes"));
        delay(200);
        }
     Serial.println(String("Damian Cervantes")); 
      delay(200);  
    }
     else if(a==G1 && b==G2 && c==G3 && d==G4 && e==G5 && f==G6 && g==G7 && h==G8){
    digitalWrite(A0,HIGH);
    delay(1000);
    lcd.clear();
    digitalWrite(A0,LOW);
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("BIENVENIDO");
    Clear_Scroll_LCD_Left();
      for (int i = 0; i <= 28; i++) {  
        lcd.setCursor(0, 1);
        lcd.print(Scroll_LCD_Right("Carlos Benavides"));
        delay(200);
        }
     Serial.println(String("Carlos Benavides")); 
      delay(200);  
    }
  else{
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("CLAVE");
    lcd.setCursor(2,1);
    lcd.print("INCORRECTA");
    digitalWrite(A1,HIGH);
    delay(1000);
    lcd.clear();
    digitalWrite(A1,LOW);
    }

    
//------Seguridad para la contraseña y sus restricciones-------------------//

  if(a==C1 && b==C2 && c==C3 && d==C4 && e==C5 && f==C6 && g==C7 && h==C8
  ||a==D1 && b==D2 && c==D3 && d==D4 && e==D5 && f==D6 && g==D7 && h==D8
  ||a==G1 && b==G2 && c==G3 && d==G4 && e==G5 && f==G6 && g==G7 && h==G8){
      veces=0;//si es correcto la clave ,variable veces no se incremeta.
      aviso=3;//variable aviso se mantiene en 3
    }
  else{
      veces ++; //incrementamos los intentos incorrectos de clave para el bloqueo.
      aviso --; //decremento de variable aviso ,de 3 hasta 0 según las veces de fallas al ingresar el clave.
      lcd.setCursor(2,0);
      lcd.print("LE QUEDAN: ");
      lcd.setCursor(13,0);
      lcd.print(aviso);
      lcd.setCursor(2,1);
      lcd.print("INTENTOS");
       if(aviso==0){
          lcd.clear();
          lcd.setCursor(5,0);
          lcd.print("ACCESO");
          lcd.setCursor(4,1);
          lcd.print("DENEGADO");
        }
      delay(1000);lcd.clear();
      }

  while(veces>=3){
      lcd.setCursor(1,0),lcd.print("BLOQUEO DE");
      lcd.setCursor(4,1),lcd.print("INGRESO");
      digitalWrite(A1,HIGH);
      delay(1000);
      lcd.clear();
      digitalWrite(A1,LOW);delay(1000);
  }//while es Bucle infinito de seguridad para bloquear los re intentos del clave

   var=0;
   lcd.clear();
  break;//se  termina el
  }

 }
 
 if(!key){lcd.setCursor(0,0),lcd.print("DIGITE CLAVE");//portada de inicio en el LCD
 delay(2);
 }
 
 if(key=='E'){
   lcd.clear();
  lcd.setCursor(0,0),lcd.print("PERSONAS");
  delay(700);
    if(dato=="PASS"){
     Serial.println();
     Serial.println(String("NO INGRESADAS:"));
     Serial.println(String("Damian Cervantes"));
     Serial.println(String("Carlos Benavides"));
      delay(200); 
    }
    if(dato=="PASS "){
     Serial.println(String("NO INGRESADAS:"));
     Serial.println(String("Ariel Davalos"));
      delay(200); 
    }
    if(dato=="PASS  "){
     Serial.println(String("NO INGRESADAS:"));
     Serial.println(String("Ariel Davalos"));
     Serial.println(String("Damian Cervantes"));
      delay(200); 
    
    }

    if(dato=="PASS   "){
     Serial.println(String("NO INGRESADAS:"));
     Serial.println(String("Carlos Benavides"));
      delay(200); 
    }
    if(dato=="PASS    "){
     Serial.println(String("NO INGRESADAS:"));
     Serial.println(String("Ariel Davalos"));
     Serial.println(String("Carlos Benavides"));
      delay(200); 
    }
    if(dato=="PASS     "){
     Serial.println(String("NO INGRESADAS:"));
     Serial.println(String("Damian Cervantes"));
      delay(200); 
    }
     if(dato=="PASS      "){
     Serial.println(String("NO INGRESADAS:"));
     Serial.println(String("Ariel Davalos"));
     Serial.println(String("Damian Cervantes"));
     Serial.println(String("Carlos Benavides"));
      delay(200); 
    }

    if(dato=="PASS       "){
     Serial.println(String("NO INGRESADAS:"));
     Serial.println(String("TODOS INGRESARON"));
      delay(200); 
     }
    else{
      Serial.println(String(""));
    }
 }
  
}
//----------------------------------
String Scroll_LCD_Left(String StrDisplay){
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  result = StrProcess.substring(Li,Lii);
  Li++;
  Lii++;
  if (Li>StrProcess.length()){
    Li=16;
    Lii=0;
  }
  return result;
}

void Clear_Scroll_LCD_Left(){
  Li=16;
  Lii=0;
}
//----------------------------------
String Scroll_LCD_Right(String StrDisplay){
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  if (Rii<1){
    Ri  = StrProcess.length();
    Rii = Ri-16;
  }
  result = StrProcess.substring(Rii,Ri);
  Ri--;
  Rii--;
  return result;
}

void Clear_Scroll_LCD_Right(){
  Ri=-1;
  Rii=-1;
}
