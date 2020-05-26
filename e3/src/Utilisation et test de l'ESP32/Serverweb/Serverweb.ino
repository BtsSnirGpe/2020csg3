#include <WiFi.h>

// Remplacez par vos informations d'identification réseau
const char * ssid = "ESP32";
const char * password = "SAPESP32";

// Définir le numéro de port du serveur Web sur 80
Serveur WiFiServer (80);

// Variable pour stocker la requête HTTP
En-tête de chaîne;

// Variables auxiliaires pour stocker l'état de sortie actuel
String output26State = "off";
String output27State = "off";

// Attribuer des variables de sortie aux broches GPIO
const int output26 = 26;
const int output27 = 27;

// Heure actuelle
unsigned long currentTime = millis ();
// Heure précédente
unsigned long previousTime = 0; 
// Définissez le délai d'expiration en millisecondes (exemple: 2000 ms = 2 s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin (115200);
  // Initialise les variables de sortie comme sorties
  pinMode (sortie26, SORTIE);
  pinMode (sortie27, SORTIE);
  // Définir les sorties sur LOW
  digitalWrite (output26, LOW);
  digitalWrite (output27, LOW);

  // Connectez-vous au réseau Wi-Fi avec SSID et mot de passe
  Serial.print ("Connexion à");
  Serial.println (ssid);
  WiFi.begin (ssid, mot de passe);
  while (WiFi.status ()! = WL_CONNECTED) {
    retard (500);
    Serial.print (".");
  }
  // Imprimer l'adresse IP locale et démarrer le serveur Web
  Serial.println ("");
  Serial.println ("WiFi connecté.");
  Serial.println ("adresse IP:");
  Serial.println (WiFi.localIP ());
  server.begin ();
}

boucle vide () {
  Client WiFiClient = server.available (); // Écoutez les clients entrants

  if (client) {// Si un nouveau client se connecte,
    currentTime = millis ();
    previousTime = currentTime;
    Serial.println ("Nouveau client."); // imprime un message sur le port série
    String currentLine = ""; // crée une chaîne pour contenir les données entrantes du client
    while (client.connected () && currentTime - previousTime <= timeoutTime) {// boucle pendant que le client est connecté
      currentTime = millis ();
      if (client.available ()) {// s'il y a des octets à lire depuis le client,
        char c = client.read (); // lit un octet, puis
        Serial.write (c); // imprime le moniteur série
        en-tête + = c;
        if (c == '\ n') {// si l'octet est un caractère de nouvelle ligne
          // si la ligne actuelle est vide, vous obtenez deux caractères de nouvelle ligne d'affilée.
          // c'est la fin de la requête HTTP du client, alors envoyez une réponse:
          if (currentLine.length () == 0) {
            // Les en-têtes HTTP commencent toujours par un code de réponse (par exemple HTTP / 1.1 200 OK)
            // et un type de contenu pour que le client sache ce qui s'en vient, puis une ligne vierge:
            client.println ("HTTP / 1.1 200 OK");
            client.println ("Type de contenu: texte / html");
            client.println ("Connexion: fermer");
            client.println ();
            
            // active et désactive les GPIO
            if (header.indexOf ("GET / 26 / on")> = 0) {
              Serial.println ("GPIO 26 activé");
              output26State = "on";
              digitalWrite (output26, HIGH);
            } else if (header.indexOf ("GET / 26 / off")> = 0) {
              Serial.println ("GPIO 26 désactivé");
              output26State = "off";
              digitalWrite (output26, LOW);
            } else if (header.indexOf ("GET / 27 / on")> = 0) {
              Serial.println ("GPIO 27 activé");
              output27State = "on";
              digitalWrite (output27, HIGH);
            } else if (header.indexOf ("GET / 27 / off")> = 0) {
              Serial.println ("GPIO 27 désactivé");
              output27State = "off";
              digitalWrite (output27, LOW);
            }
            
            // Afficher la page Web HTML
            client.println ("<! DOCTYPE html> <html>");
            client.println ("<head> <meta name = \" viewport \ "content = \" width = device-width, initial-scale = 1 \ ">");
            client.println ("<link rel = \" icon \ "href = \" data:, \ ">");
            // CSS pour styliser les boutons on / off 
            // N'hésitez pas à modifier les attributs de couleur d'arrière-plan et de taille de police selon vos préférences
            client.println ("<style> html {font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println (". button {background-color: # 4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println ("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println (". button2 {background-color: # 555555;} </style> </head>");
            
            // En-tête de page Web
            client.println ("<body> <h1> Serveur Web ESP32 </h1>");
            
            // Affiche l'état actuel et les boutons ON / OFF pour GPIO 26  
            client.println ("<p> GPIO 26 - State" + output26State + "</p>");
            // Si le output26State est désactivé, il affiche le bouton ON       
            if (output26State == "off") {
              client.println ("<p> <a href=\"/26/on\"> <button class = \" button \ "> ON </button> </a> </p>");
            } autre {
              client.println ("<p> <a href=\"/26/off\"> <button class = \" button button2 \ "> OFF </button> </a> </p>");
            } 
               
            // Affiche l'état actuel et les boutons ON / OFF pour GPIO 27  
            client.println ("<p> GPIO 27 - State" + output27State + "</p>");
            // Si le output27State est désactivé, il affiche le bouton ON       
            if (output27State == "off") {
              client.println ("<p> <a href=\"/27/on\"> <button class = \" button \ "> ON </button> </a> </p>");
            } autre {
              client.println ("<p> <a href=\"/27/off\"> <button class = \" button button2 \ "> OFF </button> </a> </p>");
            }
            client.println ("</body> </html>");
            
            // La réponse HTTP se termine par une autre ligne vierge
            client.println ();
            // Sortir de la boucle while
            Pause;
          } else {// si vous avez une nouvelle ligne, effacez currentLine
            currentLine = "";
          }
        } else if (c! = '\ r') {// si vous avez autre chose qu'un caractère retour chariot,
          currentLine + = c; // l'ajouter à la fin de la ligne courante
        }
      }
    }
    // Efface la variable d'en-tête
    header = "";
    // Fermer la connexion
    client.stop ();
    Serial.println ("Client déconnecté.");
    Serial.println ("");
  }
}
