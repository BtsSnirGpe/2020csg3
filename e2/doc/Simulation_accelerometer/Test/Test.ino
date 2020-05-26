//---- pour écriture dans fichier texte
fwrite output = null; // initialise un objet PrintWriter pour stocker le flux de donnée à écrire dans le fichier

String cheminAbsoluFichier="C:\Users\Msad\Desktop\Projet 2020\2020csg3\e2\src\Simulation_accelerometer\test.txt";
// le fichier doit exister - chemin entier obligatoire

// déclaration variables globales
int second0=second();
// XXXXXXXXXXXXXXXXXXXXXX  Fonction SETUP XXXXXXXXXXXXXXXXXXXXXX

void setup(){ // fonction d'initialisation exécutée 1 fois au démarrage

// --- initialisation des objets et fonctionnalités utilisées ---

       //----- ouvre le fichier de datalogging texte ---
       output=ouvreFichier(cheminAbsoluFichier);   // ouvre le fichier existant dans un PrintWriter
        //le fichier doit exister - chemin entier obligatoire

       output.println("------------ Debut Nouvel enregistrement -------------"); // Ajoute la ligne au fichier
       output.print(day()+"/"+month()+"/"+year()+";"); //Ecrit la date dans le fichier suivi ;
       output.println(hour()+":"+minute()+":"+second()+";"); // Ecrit l'heure dans le fichier
       output.println("------------ Format CSV  -------------"); // Ajoute la ligne au fichier
       output.println("Jour/mois/annee; heure:minutes:secondes; valeur;"); // Ajoute la ligne au fichier


} // fin fonction Setup

// XXXXXXXXXXXXXXXXXXXXXX Fonction Draw XXXXXXXXXXXXXXXXXXXX

void  draw() { // fonction exécutée en boucle


       if (second()>second0) { //si une seconde de passée

       second0=second(); //réinitialise second0

       //----- Code type pour datalogging dans fichier texte ---

       //Ecriture d'une ligne dans le fichier au format "Jour/mois/annee; heure:minutes:secondes; valeur;"
       output.print(day()+"/"+month()+"/"+year()+";"); //Ecrit la date dans le fichier suivi ;
       output.print(hour()+":"+minute()+":"+second()+";"); // Ecrit l'heure dans le fichier
       output.print(000); // Ecrit la valeur dans le fichier
       output.println(); // Ajoute saut de ligne

       output.flush(); // Ecrit les données du PrintWriter dans le fichier

       } // fin if second()> second0

        // while(true); // stoppe boucle draw

} // fin de la fonction draw()

// XXXXXXXXXXXXXXXXXXXXXX Autres Fonctions XXXXXXXXXXXXXXXXXXXXXX




//----- Fonction ouvre Fichier---
fwrite ouvreFichier( String cheminAbsoluFichier) {

// ouvre le fichier existant dans un PrintWriter- le fichier doit exister - chemin entier obligatoire

       PrintWriter pw=null;

       try //obligé ici...
       {
       // ouvre le fichier existant - le fichier doit exister - chemin entier obligatoire
       pw = new PrintWriter(new BufferedWriter(new FileWriter(cheminAbsoluFichier, true))); // true means: "append"
       }

       catch (IOException e)
       {
       // Report problem or handle it
       }

       return (pw); // renvoie l'objet pw

} // fin de ouvreFichier

//XXXXXXXXXXXXXXXXXX Fin du programme XXXXXXXXXXXXXXXXX
 
