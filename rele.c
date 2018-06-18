int ledGreen = 13;  
int abreCircuito = 10;  
int ledRed = 12;
int cont = 1;
float current = 0;     
  
void setup() {  
    Serial.begin(9600);  
    pinMode(abreCircuito, INPUT);
    pinMode(ledGreen, OUTPUT); 
    pinMode(ledRed, OUTPUT);
}  
  
  
void loop() {  
   
   Serial.println("Start:");   
   Serial.println("Fase 1, Enter with a current:");  
   digitalWrite(ledGreen, HIGH); // sets the LED to the button's value
   
  while (Serial.available()==0){                                     
    //Wait for user input  
  }  
  current = Serial.parseFloat();
  Serial.print("Corrent actual:");
  Serial.println(current);

   if(current > 5){
     Serial.println("Fase 2. Current above 5 A: ");
     Serial.println("Enter a new current: "); 
     delay(200);
     
     while (Serial.available()==0)  {                                       
       //Wait for user input  
     }
     current = Serial.parseFloat();
     Serial.print("Corrent actual:");
     Serial.println(current);
     
     if(current > 5){
      
       Serial.println("Fase 3. Current above 5A for the second time: ");
       Serial.println("Enter a new current: "); 
       
       
       while (Serial.available()==0)  {                                       
         //Wait for user input  
       }
       current = Serial.parseFloat();
       Serial.print("Corrent actual:");
       Serial.println(current);
       
       digitalWrite(ledGreen, LOW); // sets the LED to the button's value
       digitalWrite(ledRed, HIGH); // Abre o circuito
       delay(1000);

       //while(cont == 1){
       
         if(current > 5){

           Serial.println("Fase 4. Current above 5A for the third time, manual reclosing required. ");
           Serial.println("Push the button: "); 
          
           while(digitalRead(abreCircuito) == LOW) { }

           if(digitalRead(abreCircuito) == HIGH){
             Serial.println("Reopened circuit: ");
             Serial.println("Program closed: ");

             digitalWrite(ledGreen, HIGH); // sets the LED to the button's value
             digitalWrite(ledRed, LOW); // Abre o circuito
           }
           
           delay(1000); 
           cont = 1;
           
           // ativar botão - colocar um botão para religar

         }else{
           cont = 0;
           Serial.println("menor que 5"); 
           delay(500);
         }
       //}

     }else{
       Serial.println("menor que 5"); 
       delay(500);
     }  

   }else{
     Serial.println("menor que 5"); 
     delay(500);
   }
  delay(200);
   
}  