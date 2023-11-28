//definition des pin
const byte led = 11;
const byte button = 2;



//=======================================================//
//==================== FONCTIONS ========================//
//=======================================================//
//         fonction qui lit l'etat du bouton             //
//      et qui l'assigne a la variable button state      //
//=======================================================//
byte use_button() 
{
  return digitalRead(button);
}

//=======================================================//
//==================== FONCTIONS ========================//
//=======================================================//
//         fonction qui allume ou eteint la led          //
//      en fonction de la valeur de button_state(param)  //
//=======================================================//
void on_off(byte button_state) 
{                                  
  switch(button_state) 
  { 
    case 1:                                        // si button_state = 1                   
      Serial.println(button_state);                // on affiche button_state
      digitalWrite(led, HIGH);                     // on allume la led

    case 0:                                       // si button_state = 0
      Serial.println(button_state);               // on affiche button_state
      digitalWrite(led, LOW);                     // on eteint la led        

    default:                                      // si button_state != 0 ou 1
      digitalWrite(led, LOW);                     // on eteint la led
  }
}
void setup() 
{
  // definition des pin
  Serial.begin(9600);
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
}

void loop() 
{
  //definition des variables
  byte button_state = use_button();
  
  //utilisation des fonctions
  on_off(button_state);
}
