//definition des pin
const byte led = 11;
const byte button = 2;
const byte light_res = A0;
const byte led2 = 10;


// pour ameliorer : 2 choses : button debouncing + button interrupt

//=======================================================//
//==================== FONCTIONS ========================//
//=======================================================//
//         fonction qui lit l'etat du bouton             //
//      et qui l'assigne a la variable button state      //
//=======================================================//
bool use_button() 
{
  return digitalRead(button);
}

//=======================================================//
//==================== FONCTIONS ========================//
//=======================================================//
//         fonction qui lit la valeur de la resistance   //
//=======================================================//
int use_light_res() 
{
  return analogRead(light_res);
}

//=======================================================//
//==================== FONCTIONS ========================//
//=======================================================//
//         fonction qui allume ou eteint la led          //
//      en fonction de la valeur de button_state(param)  //
//=======================================================//
void on_off(bool button_state, int light_res_value) 
{                                  
  switch(button_state) 
  { 
    case true:                                     // si button_state = 1                   
      Serial.print(button_state);                  // on affiche button_state
      Serial.print("||");
      Serial.println(light_res_value);

      digitalWrite(led, HIGH);                    // on allume la led
      
      if (light_res_value <= 100)                 // si la valeur de la resistance est inferieur a 100
      {
        digitalWrite(led2, HIGH);                 // on allume la led2
      }
      else if (light_res_value >= 100)            // si la valeur de la resistance est superieur a 100
      {
        digitalWrite(led2, LOW);                  // on eteint la led2
      }

    case fale:                                    // si button_state = 0
      Serial.println(button_state);               // on affiche button_state
      digitalWrite(led, LOW);                     // on eteint la led
      digitalWrite(led2, LOW);                    // on eteint la led2        

    default:                                      // si button_state != 0 ou 1
      digitalWrite(led, LOW);                     // on eteint la led
      digitalWrite(led2, LOW);                    // on eteint la led2
  }
}
void setup() 
{
  // definition des pin
  Serial.begin(9600);
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(light_res,INPUT);
}

void loop() 
{


  //utilisation des fonctions
  on_off(use_button(), use_light_res());
}
