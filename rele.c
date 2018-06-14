int ledGreen = 13;  
int abre = 12; 
int fecha = 11;   
int ledRed = 10;
int cont = 1;
int val = 0;
int incomingByte = 0;
float corrent = 0;

void setup() {
  	pinMode(ledGreen, OUTPUT);
    pinMode(abre, OUTPUT);
    pinMode(fecha, OUTPUT);
    pinMode(ledRed, OUTPUT);
    Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {

// send data only when you receive data:
	if (Serial.available() > 0) {
			
		Serial.println("Digite uma corrent: ");
	    corrent = Serial.parseFloat();


	    Serial.print("Corrent atual: ");
	    Serial.println(corrent);

		if(corrent > 5){

			Serial.println("Corrente acima de 5: ");
			Serial.println("Digite uma nova corrent: ");

			delay(200);
			corrent = Serial.parseFloat();
			if(corrent > 5){
				
			  	Serial.println("Corrente acima de 5 pela segunda vez: ");
				Serial.println("Digite uma nova corrent: ");
			  
				digitalWrite(ledGreen, HIGH); // sets the LED to the button's value
				digitalWrite(abre, HIGH); // Abre o circuito
				delay(300);
				
				digitalWrite(ledRed, HIGH); // sets the LED to the button's value
				digitalWrite(fecha, HIGH); // Fecha o circuito
				delay(200);

				while(cont == 1){

					corrent = Serial.parseFloat();
					if(corrent > 5){
						digitalWrite(ledGreen, HIGH); // sets the LED to the button's value
						digitalWrite(abre, HIGH); // Abre o circuito

						//wait();

						// Religamento Manual - mostrar no Visor
						// ativar botão - colocar um botão para religar

						delay(200);

					}else{
						cont = 0;
					}

				}

			}	

		}  

	}
}