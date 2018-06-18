int ledGreen = 13;  
int abreCircuito = 10;  
int ledRed = 12;
int cont = 1;
int cont2 = 1;
float current = 0;     
  
void setup() {  
    Serial.begin(9600);  
    pinMode(abreCircuito, INPUT); // Seta para o butao ser ser uma entrada(referencia arduino)
    pinMode(ledGreen, OUTPUT); // Seta para o led verde receber saida(referencia arduino) de sinal
    pinMode(ledRed, OUTPUT); // Seta para o led vermelho receber saida(referencia arduino) de sinal
}  
  
  
void loop() {  
   
   Serial.println("Start:");   
   Serial.println("Fase 1, Enter with a current:");  
   digitalWrite(ledRed, HIGH); // Acende o led verde
   
  while (Serial.available()==0){                                     
    //Wait for user input  
  }  
  current = Serial.parseFloat(); // recebe o valor digitado e tenta converter para numero com virgula
  Serial.print("Corrent actual:"); // escreve texto
  Serial.println(current); // escreve o valor convertido para numero com virgula

   if(current > 5){ // verifica se e maior que 5 
     Serial.println("Fase 2. Current above 5 A: ");
     Serial.println("Enter a new current: "); 
     delay(200); // espera 200 ms 
     
     while (Serial.available()==0)  {                                       
       //Wait for user input  
     }
     current = Serial.parseFloat();// recebe o valor digitado e tenta converter para numero com virgula
     Serial.print("Corrent actual:");// escreve texto
     Serial.println(current);// escreve o valor convertido para numero com virgula
     
     if(current > 5){ // verifica se e maior que 5 

      digitalWrite(ledRed, LOW); // seta o led verde desligado
      digitalWrite(ledGreen, HIGH); // seta o led vermelho ligado
      delay(300); // espera 1000 ms , 1s

      digitalWrite(ledRed, HIGH); // seta o led verde desligado
      digitalWrite(ledGreen, LOW); // seta o led vermelho ligado
      delay(300); // espera 1000 ms , 1s
      
       Serial.println("Fase 3. Current above 5A for the second time: ");
       Serial.println("Enter a new current: "); 
       
       
       while (Serial.available()==0)  {                                       
         //Wait for user input  
       }
       current = Serial.parseFloat();
       Serial.print("Corrent actual:");
       Serial.println(current);
       
       
       delay(1000); // espera 1000 ms , 1s

       //while(cont == 1){
       
         if(current > 5){

           digitalWrite(ledRed, LOW); // seta o led verde desligado
           digitalWrite(ledGreen, HIGH); // seta o led vermelho ligado

           Serial.println("Fase 4. Current above 5A for the third time, manual reclosing required. ");
           Serial.println("Push the button: "); 
          
           while(digitalRead(abreCircuito) == LOW) { // enquanto o botao n emitir sinal fica em um ciclo
           }

           if(digitalRead(abreCircuito) == HIGH){ // caso o botao emita sinal entra nessa condicao
             Serial.println("Reopened circuit: "); // escreve testo
             //Serial.println("Program closed: "); // escreve testo

             digitalWrite(ledRed, HIGH); // sets o led verde ligado
             digitalWrite(ledGreen, LOW); // sets o led vermelho desligado
           }

           while(cont2 == 1){

             Serial.println("Enter a new current: "); 
             while (Serial.available()==0)  {                                       
               //Wait for user input  
             }
             
             current = Serial.parseFloat();// recebe o valor digitado e tenta converter para numero com virgula
             Serial.print("Corrent actual:");// escreve texto
             Serial.println(current);// escreve o valor convertido para numero com virgula
             if (current > 5) {
              Serial.println("Fase 4 plus. Current above 5A. ");
             }else{
              cont2 = 0;
             }

           }
           

           
           delay(300);  // espera 1s
           cont = 1; // seta variavel cont igual a 1
           
           // ativar botão - colocar um botão para religar

         }else{
           cont = 0; // seta variavel cont igual a 0
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