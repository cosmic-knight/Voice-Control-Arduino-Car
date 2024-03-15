String readvoice;
int k=0;
void setup() {
    Serial.begin(9600);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
}
 
void loop() {
    while (Serial.available())
    {
        delay(3);
        char c = Serial.read();
        readvoice += c;
    }
    
    if(readvoice.length() > 0)
    {
        Serial.println(readvoice);
        int adder=0;
        if ((String)(readvoice[readvoice.length()-1])>=(String)"0"){
            char unit=(readvoice[readvoice.length()-1]);
            adder=adder+(unit-48);
            if ((String)(readvoice[readvoice.length()-2])>(String)"0"){
            char unit=(readvoice[readvoice.length()-2]);
            adder=adder+((unit-48)*10);
            }
        }
        int number=(adder)*1000;
        if((String)readvoice[0] == (String)"f")
        {
            digitalWrite(2, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            k=1;
            delay(number);
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
        }
        
        if((String)readvoice[0] == (String)"b")
        {
            digitalWrite(2, LOW);
            digitalWrite(3, HIGH);
            digitalWrite(4, LOW);
            digitalWrite(5, HIGH);
            k=2;
            delay(number);
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
        }
        
        if((String)readvoice[0] == (String)"l")
        {
            if (k==2)
            {
                digitalWrite(2, HIGH);
                digitalWrite(3, LOW);
                digitalWrite(4, LOW);
                digitalWrite(5, LOW);
                delay(1000);
                digitalWrite(2, LOW);
                digitalWrite(3, HIGH);
                digitalWrite(4, LOW);
                digitalWrite(5, HIGH);
                delay(number);
                digitalWrite(2, LOW);
                digitalWrite(3, LOW);
                digitalWrite(4, LOW);
                digitalWrite(5, LOW);
            }
            else
            {
                digitalWrite(2, HIGH);
                digitalWrite(3, LOW);
                digitalWrite(4, LOW);
                digitalWrite(5, LOW);
                delay(1000);
                digitalWrite(2, HIGH);
                digitalWrite(3, LOW);
                digitalWrite(4, HIGH);
                digitalWrite(5, LOW);
                delay(number);
                digitalWrite(2, LOW);
                digitalWrite(3, LOW);
                digitalWrite(4, LOW);
                digitalWrite(5, LOW);
            }
        }
        
        if((String)readvoice[0] == (String)"r")
        {
            if (k==2)
            {
                digitalWrite(2, LOW);
                digitalWrite(3, LOW);
                digitalWrite(4, HIGH);
                digitalWrite(5, LOW);
                delay(1000);
                digitalWrite(2, LOW);
                digitalWrite(3, HIGH);
                digitalWrite(4, LOW);
                digitalWrite(5, HIGH);
                delay(number);
                digitalWrite(2, LOW);
                digitalWrite(3, LOW);
                digitalWrite(4, LOW);
                digitalWrite(5, LOW);
            }
            else
            {
                digitalWrite(2, LOW);
                digitalWrite(3, LOW);
                digitalWrite(4, HIGH);
                digitalWrite(5, LOW);
                delay(1000);
                digitalWrite(2, HIGH);
                digitalWrite(3, LOW);
                digitalWrite(4, HIGH);
                digitalWrite(5, LOW);
                delay(number);
                digitalWrite(2, LOW);
                digitalWrite(3, LOW);
                digitalWrite(4, LOW);
                digitalWrite(5, LOW);
            }
        }
        
        if(readvoice == "stop")
        {
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
        }
    }
    readvoice="";
}