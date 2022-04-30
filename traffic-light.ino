const int LED_R  = D2;
const int LED_Y  = D4;
const int LED_G  = D6;
void setup() {
    pinMode(LED_R,OUTPUT);
    pinMode(LED_Y,OUTPUT);
    pinMode(LED_G,OUTPUT);
    Particle.function("traffic_light_control",control_light);

}
int LED(String &color){
    if (color.equals("red")) return LED_R;
    if (color.equals("yellow")) return LED_Y;
    if (color.equals("green")) return LED_G;
    return -1;
}
void loop() {

}

int control_light(String color){
    
    // turn off all led
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_Y,LOW);
    digitalWrite(LED_G,LOW);

    int led = LED(color);
    Particle.publish("Light changed",color);
    if (led != -1)
    { 
        digitalWrite(led,HIGH);
        return 1;
    }
    else if (color.equals("off"))
    {
        digitalWrite(LED_R,LOW);
        digitalWrite(LED_Y,LOW);
        digitalWrite(LED_G,LOW);
        return 1;
    }
    return -1;
}