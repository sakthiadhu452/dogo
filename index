const express = require('express');
const bodyParser = require('body-parser');
const mongoose = require('mongoose');

const app = express();
const port = 3000;

// Connect to MongoDB
mongoose.connect('mongodb+srv://sakthiadhavank21eie:7399sakthi@cluster0.4ohedjk.mongodb.net/dogo-v', { useNewUrlParser: true, useUnifiedTopology: true });

// Define a MongoDB schema
const personSchema = new mongoose.Schema({
  person: Boolean,
  // other fields if needed
});

const Person = mongoose.model('Person', personSchema);

app.use(bodyParser.json());

// API endpoint for searching and finding a person with "person" field set to true
app.get('/find-person', async (req, res) => {
  try {
    const foundPerson = await Person.findOne({ person: true });

    if (foundPerson) {
      res.json({ message: 'found' });
    } else {
      res.json({ message: 'not found' });
    }
  } catch (error) {
    res.status(500).json({ error: 'Internal server error' });
  }
});

// API endpoint for inserting a new person
app.post('/insert-person', async (req, res) => {
  try {
    const newPerson = new Person({ person: true });
    await newPerson.save();
    
    res.json({ message: 'Person inserted successfully' });
  } catch (error) {
    res.status(500).json({ error: 'Internal server error' });
  }
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});





// #include <ESP8266WiFi.h>
// #include <ESP8266HTTPClient.h>

// const char* ssid = "your-ssid";
// const char* password = "your-password";

// const char* server = "your-server-ip"; // or domain name
// const int serverPort = 3000;

// const int ledPin = D1;

// void setup() {
//   Serial.begin(115200);
//   pinMode(ledPin, OUTPUT);

//   // Connect to Wi-Fi
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to WiFi...");
//   }
//   Serial.println("Connected to WiFi");
// }

// void loop() {
//   // Make an HTTP GET request to the /find-person endpoint
//   HTTPClient http;
//   String url = "http://" + String(server) + ":" + String(serverPort) + "/find-person";

//   Serial.print("Sending GET request to: ");
//   Serial.println(url);

//   http.begin(url);

//   int httpResponseCode = http.GET();

//   if (httpResponseCode == 200) {
//     String response = http.getString();
//     Serial.print("Response from server: ");
//     Serial.println(response);

//     // Check if the response indicates a person was found
//     if (response == "found") {
//       digitalWrite(ledPin, HIGH); // Enable D1 pin (you may need to adjust the pin number)
//     } else {
//       digitalWrite(ledPin, LOW);  // Disable D1 pin
//     }
//   } else {
//     Serial.print("Error during GET request. HTTP response code: ");
//     Serial.println(httpResponseCode);
//   }

//   http.end();

//   delay(5000); // Wait for 5 seconds before making the next request
// }
