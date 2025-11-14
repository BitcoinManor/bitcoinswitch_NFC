#ifdef NFC
#include <Wire.h>
#include <Adafruit_PN532.h>

// Define PN532 connections for I2C
#define PN532_IRQ   (2)
#define PN532_RESET (3)  

Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

// NFC configuration
bool nfcEnabled = false;
String lastCardId = "";
unsigned long lastCardTime = 0;
const unsigned long CARD_DEBOUNCE_TIME = 2000; // 2 seconds debounce

void setupNFC() {
    Serial.println("Initializing NFC...");
    
    #ifdef TFT
    printTFT("Initializing NFC...", 21, 115);
    #endif
    
    nfc.begin();
    
    // Check if PN532 is connected
    uint32_t versiondata = nfc.getFirmwareVersion();
    if (!versiondata) {
        Serial.println("Didn't find PN532 board");
        #ifdef TFT
        printTFT("PN532 not found!", 21, 135);
        #endif
        nfcEnabled = false;
        return;
    }
    
    // Got valid data, print it out
    Serial.print("Found chip PN5"); Serial.println((versiondata>>24) & 0xFF, HEX);
    Serial.print("Firmware ver. "); Serial.print((versiondata>>16) & 0xFF, DEC);
    Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
    
    // Configure board to read RFID tags
    nfc.SAMConfig();
    
    nfcEnabled = true;
    Serial.println("NFC initialized successfully!");
    
    #ifdef TFT
    printTFT("NFC Ready!", 21, 135);
    #endif
}

void loopNFC() {
    if (!nfcEnabled) return;
    
    uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
    uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
    
    // Check for NFC card
    if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength)) {
        // Build card ID string
        String cardId = "";
        for (uint8_t i = 0; i < uidLength; i++) {
            if (cardId.length() > 0) cardId += ":";
            if (uid[i] < 0x10) cardId += "0";
            cardId += String(uid[i], HEX);
        }
        cardId.toUpperCase();
        
        // Debounce same card
        unsigned long currentTime = millis();
        if (cardId == lastCardId && (currentTime - lastCardTime) < CARD_DEBOUNCE_TIME) {
            return;
        }
        
        lastCardId = cardId;
        lastCardTime = currentTime;
        
        Serial.println("NFC Card detected!");
        Serial.println("Card ID: " + cardId);
        
        #ifdef TFT
        clearTFT();
        printTFT("NFC Card Found!", 21, 21);
        printTFT("ID: " + cardId, 21, 45);
        #endif
        
        // Process the NFC card
        processNFCCard(cardId, uid, uidLength);
        
        delay(100); // Small delay to prevent rapid reads
    }
}

void processNFCCard(String cardId, uint8_t* uid, uint8_t uidLength) {
    Serial.println("Processing card: " + cardId);
    
    // Try to read NDEF data
    uint8_t data[32];
    uint8_t dataLength = 32;
    
    // For now, just use the card ID for payment
    // In future versions, you could implement NDEF reading here
    executeDefaultNFCAction(cardId);
}

void executeNFCPayment(String paymentData) {
    Serial.println("Executing NFC payment: " + paymentData);
    
    #ifdef TFT
    printTFT("Processing payment...", 21, 85);
    #endif
    
    // Send payment data via WebSocket
    if (webSocket.available()) {
        webSocket.send("NFC_PAYMENT:" + paymentData);
        Serial.println("Sent NFC payment via WebSocket: " + paymentData);
        
        #ifdef TFT
        printTFT("Payment sent!", 21, 105);
        #endif
    } else {
        Serial.println("WebSocket not connected, cannot send payment");
        
        #ifdef TFT
        printTFT("No connection!", 21, 105);
        #endif
        
        // Try to execute payment locally if it's in the correct format (pin-time-comment)
        String parts[3];
        int numParts = splitString(paymentData, '-', parts, 3);
        if (numParts >= 2) {
            executeLocalNFCPayment(paymentData);
        }
    }
}

void executeLocalNFCPayment(String paymentData) {
    Serial.println("Executing local NFC payment: " + paymentData);
    
    String parts[3]; // pin, time, comment
    int numParts = splitString(paymentData, '-', parts, 3);
    
    if (numParts < 2) {
        Serial.println("Invalid payment data format");
        return;
    }
    
    int pin = parts[0].toInt();
    int time = parts[1].toInt();
    String comment = (numParts == 3) ? parts[2] : "";
    
    #ifdef TFT
    clearTFT();
    printTFT("NFC Payment!", 21, 21);
    printTFT("Pin: " + String(pin), 21, 45);
    printTFT("Time: " + String(time), 21, 65);
    if (comment != "") {
        printTFT("Comment: " + comment, 21, 85);
    }
    #endif
    
    Serial.println("NFC Payment - Pin: " + String(pin) + ", Duration: " + String(time));
    if (comment != "") {
        Serial.println("Comment: " + comment);
    }
    
    // Execute the payment
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    delay(time);
    digitalWrite(pin, LOW);
    
    #ifdef TFT
    delay(2000); // Show payment info for 2 seconds
    printHome(true, webSocket.available(), false);
    #endif
}

void executeDefaultNFCAction(String cardId) {
    Serial.println("Executing default NFC action for card: " + cardId);
    
    // Default action: trigger GPIO pin 2 for 1 second
    String defaultPayment = "2-1000-NFC_Card_" + cardId;
    
    #ifdef TFT
    printTFT("Default action", 21, 85);
    #endif
    
    if (webSocket.available()) {
        webSocket.send("NFC_DEFAULT:" + defaultPayment);
        Serial.println("Sent default NFC action via WebSocket");
    } else {
        executeLocalNFCPayment(defaultPayment);
    }
}

String getNFCStatus() {
    if (!nfcEnabled) return "NFC: Disabled";
    return "NFC: Ready";
}

#else
// NFC disabled - empty functions
void setupNFC() {
    Serial.println("NFC support not compiled");
}

void loopNFC() {
    // Do nothing when NFC is disabled
}

String getNFCStatus() {
    return "NFC: Not compiled";
}
#endif
