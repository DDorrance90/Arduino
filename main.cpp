const int MOTOR_PIN = 10;
const int PROX_SENSOR_PIN = 12;



void setup() {
    Serial.begin(9600);
    pinMode(MOTOR_PIN, OUTPUT);
    pinMode(PROX_SENSOR_PIN, INPUT); 
}

bool notEmpty () {  // return true or false based on proximity sensor input value. 
    if(analogRead(PROX_SENSOR_PIN)) > 0) {  //Not sure what this value will be
        return true;
    } 
    return false; 
    
   
}

void HandleEvent (String Message) {
    String response = "";
    
    if(Message == "CMD:Feed") {
        
        if(notEmpty()) {
            // Turn the motor for one feeding. 
            response = "INFO:Running";  
        } else {
            response = "INFO:Empty"; 
        }
        Serial.Write(response); 
    }
}

void loop() {
    char curChar; 
    String Message = ""; 
    while(Serial.available() > 0) {
       curChar = Serial.Read(); 
       Message.concat(curChar); 
    }  
    if(Message != "") {
        HandleEvent(Message); 
    }
}