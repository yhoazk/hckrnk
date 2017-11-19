# ASYMMETRISCHE SCHLÜSSELTAUSCH-ALGORITHMEN

Ziel der Aufgabe ist es ein Schlüsselaustausch-Algorithmus nach Diffie und Hellman zu implementieren. Dafür haben wir einen Server aufgesetzt, der nach folgenden Regeln arbeitet: Der Client verbindet sich mit dem Server 35.157.103.77 per TCP auf den Port 8080. Der Server sendet in ASCII kodiert das Modul p und den Generator g, welche als Basis für die Berechnung dient. Diese werden durch einen line feed ('\n', 0x0A) getrennt. Anschließend wird auf dem Server ein geheimer Schlüssel a generiert und der öffentliche Schlüssel A mittels diskreter Exponentiation berechnet. A = g ^ a mod p. Dieser Wert wird anschließend auch versendet. Der Client muss nun auch einen geheimen Schlüssel b generieren. Es ist darauf zu achten, dass dieser ausreichend hohe Qualität hat. Daraufhin sendet der Client den berechneten öffentlichen Schlüssel B = g ^ b mod p an den Server. Beide sind nun in der Lage den geteilten Schlüssel k zu berechnen: k = B ^ a mod p = A ^ b mod p. Der Schlüssel k wird nun als 16 Byte großer Key für die RC4 Stromchiffre verwendet. Dabei wird der errechnete geteilte Schlüssel nach dem Little Endian Prinzip verwendet.

![](./Little-Endian.svg)


Der Server verschickt die verschlüsselte Botschaft und die Aufgabe ist beendet.
