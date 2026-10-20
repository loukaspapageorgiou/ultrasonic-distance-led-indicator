// Ορισμός των Pins
const int trigPin = 9;
const int echoPin = 10;
const int ledGreen = 2;
const int ledYellow = 3;
const int ledRed = 4;

// Μεταβλητές για τον υπολογισμό της απόστασης
long duration;
int distance;

void setup() {
  // Ρύθμιση των Pins ως εισόδους ή εξόδους
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  
  // Εκκίνηση της σειριακής επικοινωνίας (για να βλέπουμε την απόσταση στην οθόνη)
  Serial.begin(9600); 
}

void loop() {
  // Καθαρισμός του trigPin (το κλείνουμε για 2 μικροδευτερόλεπτα)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Στέλνουμε έναν ήχο (παλμό) για 10 μικροδευτερόλεπτα
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Διαβάζουμε πόσος χρόνος πέρασε μέχρι να επιστρέψει ο ήχος
  duration = pulseIn(echoPin, HIGH);
  
  // Υπολογισμός της απόστασης σε εκατοστά (Ταχύτητα ήχου = 343m/s)
  distance = duration * 0.034 / 2;

  // Εκτύπωση της απόστασης στην οθόνη του υπολογιστή
  Serial.print("Απόσταση: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Λογική του Αισθητήρα Παρκαρίσματος
  if (distance > 20) {
    // Πάνω από 20cm: Ανάβει μόνο το Πράσινο
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
  }
  else if (distance <= 20 && distance > 10) {
    // Ανάμεσα σε 10cm και 20cm: Ανάβει μόνο το Κίτρινο
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledRed, LOW);
  }
  else if (distance <= 10 && distance > 0) {
    // Κάτω από 10cm (κίνδυνος!): Ανάβει μόνο το Κόκκινο
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, HIGH);
  }

  // Μικρή καθυστέρηση πριν την επόμενη μέτρηση
  delay(100);
}