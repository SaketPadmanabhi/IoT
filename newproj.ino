int const trigPin = 12;
int const echoPin = 10;
int const buzzPin = 9;
void setup()
{
pinMode(trigPin, OUTPUT); // trig pin will have pulses output
pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
}
void loop()
{
// Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
int duration, distance;
// Output pulse with 1ms width on trigPin
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
// Measure the pulse input in echo pin
duration = pulseIn(echoPin, HIGH);
// Distance is half the duration devided by 29.1 (from datasheet)
distance = (duration/2) / 29.1;
// if distance less than 0.5 meter and more than 0 (0 or less means over range)
if (distance <= 30 && distance >= 0)
{
// Buzz
digitalWrite(buzzPin, LOW);
int d= map(distance, 1, 100, 20, 2000);   
digitalWrite(buzzPin, HIGH);   
delay(10);   
digitalWrite(buzzPin, LOW);   
delay(d);  
} 
else {
// Don't buzz
digitalWrite(buzzPin, HIGH);
}
// Waiting 60 ms won't hurt any 
delay(60);
}
