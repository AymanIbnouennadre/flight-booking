#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include<map>
#include<set>
using namespace std;

// Structure pour stocker une date
struct Date {
    int jour;
    int mois;
    int annee;
};
class Passager;
class Vol;
//class reservation
class Reservation {
private:
    int idReservation;
    Date dateReservation;
    Passager* passager;
    Vol* vol;
    double totalAPayer;

public:
   // Dans la classe Reservation, ajoutez une surcharge de constructeur qui accepte un Vol* plutôt qu'une référence à Vol
Reservation(int id, Date date, Vol* vol, double Montanttotal)
    : idReservation(id), dateReservation(date), vol(vol), totalAPayer(Montanttotal) {}

    // Méthodes getter et setter pour idReservation
    int getIdReservation() const { return idReservation; }
    void setIdReservation(int id) { idReservation = id; }

    // Méthodes getter et setter pour dateReservation
    const Date& getDateReservation() const { return dateReservation; }
    void setDateReservation(const Date& date) { dateReservation = date; }

    // Méthodes getter et setter pour passager
    Passager* getPassager() const { return passager; }
    void setPassager(Passager* p) { passager = p; }

    // Méthodes getter et setter pour vol
    Vol* getVol() const { return vol; }
    void setVol(Vol* v) { vol = v; }

    // Méthodes getter et setter pour totalAPayer
    double getTotalAPayer() const { return totalAPayer; }
    void setTotalAPayer(double total) { totalAPayer = total; }

void afficher()  {
        cout << "ID Réservation: " << idReservation
                  << ", Date: " << dateReservation.jour << "/"
                  << dateReservation.mois << "/" << dateReservation.annee


                  << ", Total à Payer: " << totalAPayer << " dh"
                  << endl;
    }

};
// Classe Passager
class Passager {
private:
    int idPassager;
    string nom;
    string telephone;
    string numeroPasseport;
    vector<int> reservations; // Stocke les identifiants des réservations

public:
    // Constructeur
    Passager(int id, const string& nom, const string& tel, const string& passeport)
        : idPassager(id), nom(nom), telephone(tel), numeroPasseport(passeport) {}

    // Méthodes getter et setter pour idPassager
    int getIdPassager() const { return idPassager; }
    void setIdPassager(int id) { idPassager = id; }

    // Méthodes getter et setter pour nom
    const string& getNom() const { return nom; }
    void setNom(const string& n) { nom = n; }

    // Méthodes getter et setter pour telephone
    const string& getTelephone() const { return telephone; }
    void setTelephone(const string& tel) { telephone = tel; }

    // Méthodes getter et setter pour numeroPasseport
    const string& getNumeroPasseport() const { return numeroPasseport; }
    void setNumeroPasseport(const string& num) { numeroPasseport = num; }
    // Méthode pour afficher les détails du passager
void afficherDetails()  {
    cout << "Identifiant passager: " << idPassager << endl;
    cout << "Nom passager: " << nom << endl;
    cout << "Téléphone: " << telephone << endl;
    cout << "Numéro de passeport: " << numeroPasseport << endl;
    cout << "Reservations:" << endl;
    for (auto id : reservations) {
        cout << "  " << id << endl;
    }
}

    // Méthode pour ajouter une réservation
    void ajouterReservation(int idReservation) {
        reservations.push_back(idReservation);
    }

    // Méthode pour afficher la facture de paiement
    void afficherFacture()  {
        // Afficher les informations du passager
        cout << "Identifiant passager: " << idPassager << endl;
        cout << "Nom passager: " << nom << endl;
        // Afficher les réservations
        cout << "Reservations:" << endl;
        for (int id : reservations) {
            cout << "  " << id << endl;
        }
    }

};

// Classe Vol
class Vol {
protected:
    int numeroVol;
    string aeroportDepart;
    string aeroportArrivee;
    Date dateDepart;
    Date dateArrivee;
    int placesDisponibles;
    double prix;
    vector<Reservation*> reservationsvol; // Relation 1 à *
public:
    // Constructeur
    Vol(const int& numVol, const string& depart, const string& arrivee,
        const Date& dateDep, const Date& dateArr, int places, double prix)
        : numeroVol(numVol), aeroportDepart(depart), aeroportArrivee(arrivee),
          dateDepart(dateDep), dateArrivee(dateArr), placesDisponibles(places), prix(prix) {}

    // Méthodes getter et setter pour numeroVol
    const int& getNumeroVol() const { return numeroVol; }
    void setNumeroVol(const int& num) { numeroVol = num; }

    // Méthodes getter et setter pour aeroportDepart
    const string& getAeroportDepart() const { return aeroportDepart; }
    void setAeroportDepart(const string& aeroport) { aeroportDepart = aeroport; }

    // Méthodes getter et setter pour aeroportArrivee
    const string& getAeroportArrivee() const { return aeroportArrivee; }
    void setAeroportArrivee(const string& aeroport) { aeroportArrivee = aeroport; }

    // Méthodes getter et setter pour dateDepart
    const Date& getDateDepart() const { return dateDepart; }
    void setDateDepart(const Date& date) { dateDepart = date; }

    // Méthodes getter et setter pour dateArrivee
    const Date& getDateArrivee() const { return dateArrivee; }
    void setDateArrivee(const Date& date) { dateArrivee = date; }

    // Méthodes getter et setter pour placesDisponibles
    int getPlacesDisponibles() const { return placesDisponibles; }
    void setPlacesDisponibles(int places) { placesDisponibles = places; }

    // Méthodes getter et setter pour prix
    double getPrix() const { return prix; }
    void setPrix(double prix) { prix = prix; }
     // Méthode pour ajouter une réservation
    void ajouterReservation(Reservation* reservation) {
        reservationsvol.push_back(reservation);
    }
    // Méthode pour afficher les réservations
void afficherReservations()  {
    cout << "Réservations pour le vol " << numeroVol << ":" << endl;
     for (auto it = reservationsvol.begin(); it != reservationsvol.end(); ++it) {
        cout << "ID Réservation: " << (*it)->getIdReservation() << endl;
        cout << "Date Réservation: " << (*it)->getDateReservation().jour << "/" << (*it)->getDateReservation().mois << "/" << (*it)->getDateReservation().annee << endl;

    }
    }


void affichage()  {
        cout << "Numéro de vol : " << numeroVol << endl;
        cout << "Aéroport de départ : " << aeroportDepart << endl;
        cout << "Aéroport d'arrivée : " << aeroportArrivee << endl;
        cout << "Date de départ : " << dateDepart.jour << "/" << dateDepart.mois << "/" << dateDepart.annee << endl;
        cout << "Date d'arrivée : " << dateArrivee.jour << "/" << dateArrivee.mois << "/" << dateArrivee.annee << endl;
        cout << "Places disponibles : " << placesDisponibles << endl;
        cout << "Prix : " << prix << endl;
    }
    // Méthode pour réserver un vol
    virtual bool reserver() {
        if (placesDisponibles > 0) {
            placesDisponibles--;
            cout<< "reservation effectuée";
            return true;
        } else {
            cout << "Plus de places disponibles sur ce vol." << endl;
            return false;
        }
    }

    // Méthode pour augmenter le prix du vol de 20% si la date de départ est dans un mois
// et le nombre de places restantes est inférieur à 10
void augmenterPrix() {
    // Obtenir la date actuelle
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int moisActuel = now->tm_mon + 1; // tm_mon commence à 0
    int anneeActuelle = now->tm_year + 1900; // tm_year est le nombre d'années depuis 1900

    // Vérifier si la date de départ est dans un mois et le nombre de places est inférieur à 10
    if (dateDepart.annee == anneeActuelle && dateDepart.mois == moisActuel + 1 && placesDisponibles < 10) {
        // Augmenter le prix de 20%
        this->prix = prix + (prix*0.2);
        cout << "Le prix du vol " << numeroVol << " a été augmenté de 20%." << endl;
    } else {
        // Condition not true , donc l'augmentation de prix n'est pas effectuée
        cout << "Le prix du vol " << numeroVol << " n'a pas été augmenté." << endl;
    }
}
};

// Classe VolEconomique (dérivée de la classe Vol)
class VolEconomique : public Vol {
public:
    // Constructeur
    VolEconomique(const int& numVol, const string& depart, const string& arrivee,
                  const Date& dateDep, const Date& dateArr, int places, double prix)
        : Vol(numVol, depart, arrivee, dateDep, dateArr, places, prix) {}
};

// Classe VolBusiness (dérivée de la classe Vol)
class VolBusiness : public Vol {
private:
    string confort;

public:
    // Constructeur
    VolBusiness(const int& numVol, const string& depart, const string& arrivee,
                const Date& dateDep, const Date& dateArr, int places, double prix, const string& conf)
        : Vol(numVol, depart, arrivee, dateDep, dateArr, places, prix), confort(conf) {}
};

// Classe Reservation


// Classe Paiement
class Paiement {
private:
    int idPaiement;
    double montant;
    Date datePaiement;
    string methodePaiement;
    Reservation& reservation;

public:
    // Constructeur
    Paiement(int id, double mnt,  Date& date,  string& method,  Reservation& res)
        : idPaiement(id), montant(mnt), datePaiement(date), methodePaiement(method), reservation(res) {}

    // Méthodes getter et setter pour idPaiement
    int getIdPaiement() const { return idPaiement; }
    void setIdPaiement(int id) { idPaiement = id; }

    // Méthodes getter et setter pour montant
    double getMontant() const { return montant; }
    void setMontant(double montant) { montant = montant; }

    // Méthodes getter et setter pour datePaiement
    const Date& getDatePaiement() const { return datePaiement; }
    void setDatePaiement(const Date& date) { datePaiement = date; }

    // Méthodes getter et setter pour methodePaiement
    const string& getMethodePaiement() const { return methodePaiement; }
    void setMethodePaiement(const string& methode) { methodePaiement = methode; }

    // Méthodes getter et setter pour reservation
    Reservation& getReservation() const { return reservation; }
    void setReservation(Reservation& res) { reservation = res; }


};


int main() {
    system("COLOR 5f");
	cout<<"\n\t\t\t\t AYMAN IBNOUENNADRE AND YASSINE KHABICH PRESENTE : \n \t\t\t\t\t GESTION RESERVATION DE VOL "<<endl;
    vector<Vol*> vols; // Vecteur pour stocker les vols
    deque<Passager> passagers; // deque pour stocker les passagers
    set<Paiement*> paiements;
     int nombrepassagers,numvol,idpass,choix=0,choix1=0,choix2=0,choix3=0,nombreDeVols, nombreReservations;
     multimap<int, Reservation> reservationMap;
    int fonctionnalite=0;
    do {
    cout<<" *****MENU***** "<<endl;
    cout<<" Saisir tout d'abord un vol , passager , reservation puis paiement pour utiliser tous les fonctions "<<endl;
    cout<<"1.GESTION DES VOLS"<<endl;
    cout<<"2.GESTION DES PASSAGERS"<<endl;
    cout<<"3.GESTION DES RESERVATIONS"<<endl;
    cout<<"4.GESTION& DES PAIEMENTS"<<endl;
    cout<<"5.QUITTER"<<endl;
    cout<<"Choisir la fonctionnalite : ";
    cin>>fonctionnalite;
switch(fonctionnalite) {
case 1 : {
    do {
    cout<< "*****Gestion des vols***** " <<endl;
    cout<< "0. saisir des vols "<<endl;
    cout<< "1. afficher la liste des vols "<<endl;
    cout<< "2. modifier un vol "<<endl;
    cout<< "3. supprimer un vol "<<endl;
    cout<<"4. afficher  les nombres de places des vols dont la date de depart dans 12 mois "<<endl;
    cout<<"5. activer l'augementation de prix de vol de 20% si date de depart dans un mois et le nombre de place < 10"<<endl;
    cout<<"6. quitter"<<endl;
    cout<< "entrer votre choix : ";
    cin >>choix;

switch (choix) {
case 0 : {
    cout << "Combien de vols souhaitez-vous ajouter ? ";
    cin >> nombreDeVols;
    for (int i = 0; i < nombreDeVols; i++) {
        // Demander les détails du vol à l'utilisateur
        string aeroportDepart, aeroportArrivee;
        Date dateDepart, dateArrivee;
        int placesDisponibles,numeroVol;
        double prix;

        cout << "Vol " << i+1 << ":" << endl;
        cout << "Numéro de vol : ";
        cin >> numeroVol;
        cout << "Aéroport de départ : ";
        cin >> aeroportDepart;
        cout << "Aéroport d'arrivée : ";
        cin >> aeroportArrivee;
        cout << "Date de départ (jour mois année) : ";
        cin >> dateDepart.jour >> dateDepart.mois >> dateDepart.annee;
        cout << "Date d'arrivée (jour mois année) : ";
        cin >> dateArrivee.jour >> dateArrivee.mois >> dateArrivee.annee;
        cout << "Nombre de places disponibles : ";
        cin >> placesDisponibles;
        cout << "Prix : ";
        cin >> prix;

        // Créer un nouvel objet Vol avec les détails fournis
        Vol* nouveauVol = new Vol(numeroVol, aeroportDepart, aeroportArrivee,
                              dateDepart, dateArrivee, placesDisponibles, prix);
        // Ajouter le vol au vecteur
        vols.push_back(nouveauVol);
    }
     break;
}
case 1: {
for (auto it = vols.begin(); it != vols.end(); it++) {
    (*it)->affichage();
}
break;
}
case 2: {
    int numvol = 0;
    cout << "Saisir le numéro du vol que vous voulez modifier : ";
    cin >> numvol;
     for (auto it = vols.begin(); it != vols.end(); it++) {
        if ((*it)->getNumeroVol() == numvol) {
                cout<<"vol trouvé "<<endl;
            int attribut;
            do {
                cout << "**** Menu Modification **** : " << endl;
                cout << "1. Numéro de vol" << endl;
                cout << "2. Aéroport de départ" << endl;
                cout << "3. Aéroport d'arrivée" << endl;
                cout << "4. Date de départ" << endl;
                cout << "5. Date d'arrivée" << endl;
                cout << "6. Places disponibles" << endl;
                cout << "7. Prix" << endl;
                cout << "8. Pour finir la modification" << endl;
                cout << "Choisir l'attribut que vous voulez modifier selon son numéro : ";
                cin >> attribut;

                switch (attribut) {
                    // Cas de modification du numéro de vol
                    case 1: {
                        int nouveau_numerodevol;
                        cout << "Saisir le nouveau numéro de vol : ";
                        cin >> nouveau_numerodevol;
                        (*it)->setNumeroVol(nouveau_numerodevol);
                        cout << "Modification effectuée" << endl;
                        break;
                    }
                    // Cas de modification de l'aéroport de départ
                    case 2: {
                        string nouveau_aeoroport_depart;
                        cout << "Saisir le nouveau aéroport de départ : ";
                        cin >> nouveau_aeoroport_depart;
                        (*it)->setAeroportDepart(nouveau_aeoroport_depart);
                        cout << "Modification effectuée" << endl;
                        break;
                    }
                    case 3 : {
                    string nouveau_aeoroport_darrive;
                   cout<<"saisir le nouveau aeoroport d'arrive : ";
                   cin>>nouveau_aeoroport_darrive;
                   (*it)->setAeroportArrivee(nouveau_aeoroport_darrive) ;
                    cout<<"done"<<endl;
                   break;
                   }
        case 4 : {
        Date nouveau_datedepart;
        cout<<"saisir la nouvelle date de depart : ";
        cout<<"jour : ";
        cin>>nouveau_datedepart.jour;
        cout<<"mois : ";
        cin>>nouveau_datedepart.mois;
        cout<<"annee : ";
        cin>>nouveau_datedepart.annee;
        (*it)->setDateDepart(nouveau_datedepart) ;
        cout<<"done"<<endl;
        break;
        }
          case 5 : {
        Date nouveau_datedarrive;
        cout<<"saisir la nouvelle date d'arrive : ";
        cout<<"jour : ";
        cin>>nouveau_datedarrive.jour;
        cout<<"mois : ";
        cin>>nouveau_datedarrive.mois;
        cout<<"annee : ";
        cin>>nouveau_datedarrive.annee;
        (*it)->setDateDepart(nouveau_datedarrive) ;
        cout<<"done"<<endl;
        break;
        }
        case 6 : {
        int nouveau_nbrdeplace;
        cout<<"saisir le nouveau nombre de place disponible: ";
        cin>>nouveau_nbrdeplace;
        (*it)->setPlacesDisponibles(nouveau_nbrdeplace);
        cout<<"done"<<endl;
        break;
        }
         case 7 : {
        double nouveau_prix;
        cout<<"saisir le nouveau prix ";
        cin>>nouveau_prix;
        (*it)->setPrix(nouveau_prix);
        cout<<"done"<<endl;
        break;
        }
                    case 8:
                        cout << "Modification terminée" << endl;
                        break;

                    // Cas par défaut en cas de choix invalide
                    default:
                        cout << "Choix invalide" << endl;
                        break;
                }
            } while (attribut != 8);

        }


    if ((*it)->getNumeroVol() != numvol) {
        cout << "Vol non trouvé" << endl;
    }
}
break;
}

case 3 : {
    int num_vol;
    cout<<"saisir numero de vol que tu veux supprimé : ";
    cin>>num_vol;
for (auto it = vols.begin(); it != vols.end(); /* Pas d'incrémentation ici */) {
    if ((*it)->getNumeroVol() == num_vol) {
        it = vols.erase(it); // Supprimer l'élément et obtenir un nouvel itérateur valide
        cout << "Vol supprimé avec succès." << endl;
    } else {
        ++it; // Avancez seulement si vous ne supprimez pas cet élément
    }
}
break;
}
case 4 : {
 // Obtenez la date actuelle
    time_t now = time(nullptr);
    tm* current = localtime(&now);
    int currentYear = current->tm_year + 1900;
    int currentMonth = current->tm_mon + 1;

    // Calculez la date dans 12 mois
    int futureYear = currentYear + 1;
    int futureMonth = currentMonth;

    if (futureMonth > 12) {
        futureMonth -= 12;
        futureYear++;
    }

    bool found = false; // Variable pour suivre si un vol a été trouvé ou non

    // Parcourez chaque vol dans le vecteur et affichez uniquement ceux dont la date de départ est dans les 12 prochains mois
    for (auto it = vols.begin(); it != vols.end(); ++it) {
        if (((*it)->getDateDepart().annee == futureYear && (*it)->getDateDepart().mois >= currentMonth) ||
            ((*it)->getDateDepart().annee == futureYear + 1 && (*it)->getDateDepart().mois <= futureMonth)) {
            cout << "Vol " << (*it)->getNumeroVol() << ": Places disponibles = " << (*it)->getPlacesDisponibles() << endl;
            found = true;
        }
    }

    // Si aucun vol n'a été trouvé, afficher un message
    if (found==false) {
        cout << "Aucun vol trouvé dont la date de départ est dans les 12 prochains mois." << endl;
    }
    break;
}



case 5 : {
// Boucle pour parcourir tous les vols et augmenter le prix si nécessaire
for (auto it = vols.begin(); it != vols.end(); it++) {
    (*it)->augmenterPrix();
}
break;
}
case 6 : {
    cout<<"****by****"<<endl;
    break;
}
 default:
        cout << "Choix invalide" << endl;
        break;


}
}while(choix!=6);
break;
}

case 2 :
    {
     do {
    cout<< "*****Gestion des Passagers***** " <<endl;
    cout<< "1. saisir des Passager "<<endl;
    cout<< "3. trier la liste des vols par nom passager "<<endl;
    cout<<"4. effectuer une reduction 20% si le nombre de passage > 5 "<<endl;
    cout<<"5. afficher pour chaque passager la facture de paiement"<<endl;
    cout<<"6. quitter"<<endl;
    cout<< "entrer votre choix : ";
    cin >>choix1;
switch(choix1) {
    case 1 : {
     cout<<"Combien de passager souhaitez-vous ajouter ?  ";
     cin>>nombrepassagers;
     for(int i=0 ;i < nombrepassagers ; i++)
     {
         int idPassager;
        string nom, telephone, numeroPasseport;

        cout << "Passager " << (i + 1) << " :" << endl;
        cout << "ID du passager: ";
        cin >> idPassager;
        cout << "Nom: ";
        cin >> nom;
        cout << "Téléphone: ";
        cin >> telephone;
        cout << "Numéro de passeport: ";
        cin >> numeroPasseport;
         // Affichage des coordonnées saisies
        cout << "Coordonnées saisies pour le passager " << (i + 1) << " :" << endl;
        cout << "ID du passager: " << idPassager << endl;
        cout << "Nom: " << nom << endl;
        cout << "Téléphone: " << telephone << endl;
        cout << "Numéro de passeport: " << numeroPasseport << endl;
        }
        break;
    }
    case 3 :
        {
            sort(vols.begin(), vols.end(), [](const Vol* a, const Vol* b) {
        return a->getNumeroVol() < b->getNumeroVol();});

         break;

        }


case 4 : {
    double montant;
    auto range = reservationMap.equal_range(1);
    int nombreReservations = distance(range.first, range.second);
    if (nombreReservations > 5) {
        cout << "Passager 1 a plus de 5 réservations. Réduction de 20 % appliquée." << endl;
        for (auto it = range.first; it != range.second; it++) {
            double reduction = montant * 0.2;  // 20 % de réduction
            double rmontant=(montant - reduction);  // Appliquer la réduction
        }
    }
    break;
}
case 5:
{
    int idPassager;
    cout << "Saisir l'ID du passager pour afficher sa facture: ";
    cin >> idPassager;

    auto range = reservationMap.equal_range(idPassager);  // Obtenir toutes les réservations associées à cet ID
    if (range.first == range.second) {  // Si la plage est vide
        cout << "Aucune réservation trouvée pour le passager avec ID " << idPassager << endl;
    } else {
        double totalPayer = 0;  // Total à payer pour ce passager
        cout << "Facture pour le passager avec ID " << idPassager << ":" << endl;
        for (auto it = range.first; it != range.second; ++it) {  // Parcourir les réservations associées
            it->second.afficher();  // Afficher les détails de chaque réservation
            totalPayer += it->second.getTotalAPayer();  // Ajouter le montant au total
        }
        cout << "Total à payer: " << totalPayer << " dh" << endl;
    }
    break;
}


    case 6 :
        cout<< "*** By ***"<<endl;
        break;
    default :
        cout<<" choix invalide "<<endl;
        break;
}
}while(choix1!=6);
break;
    }
case 3 : {
 do {
    cout<< "*****Gestion des Reservation ***** " <<endl;
    cout<< "1. saisir une reservation "<<endl;
    cout<< "2. afficher la liste des Reservation "<<endl;
    cout<< "3. Modifier une Reservation "<<endl;
    cout<<"4. Supprimer une reservation "<<endl;
    cout<<"5. activer la reduction du 15% au montant global si le paiement est par espece"<<endl;
    cout<<"6. quitter"<<endl;
    cout<< "entrer votre choix : ";
    cin >>choix2;
switch(choix2) {
    case 1 : {
     // Demander à l'utilisateur de remplir le map
 cout << "Donner le numéro de vol que vous souhaitez réserver : ";
    cin >> numvol;
    for ( auto ir=vols.begin();ir!=vols.end();ir++)  {
      if ((*ir)->getNumeroVol() == numvol && (*ir)->getPlacesDisponibles() > 0) {
            cout << "Vol trouvé et les places sont disponibles" << endl;

        // Demander l'ID du passager
        cout << "Saisir l'ID du passager : ( un vrai id d'un vrai passager déja saisi ) ";
        cin >> idpass;

        cout << " vous pouvez réserver votre vol maintenant" << endl;
        cout << "Combien de réservations au total souhaitez-vous faire pour ce vol ? ";
        cin >> nombreReservations;

        // Saisir les détails de chaque réservation
        for (int i = 0; i < nombreReservations; ++i) {
            // Demander les détails de la réservation
            int idres;
            Date datereser;

            // Demander l'identifiant de la réservation
            cout << "Entrez l'identifiant de la réservation : ";
            cin >> idres;
            cout << "Saisir la date (jour mois année) : ";
            cin >> datereser.jour >> datereser.mois >> datereser.annee;

            // Créer une nouvelle réservation
            Reservation nouvelleReservation(idres, datereser, *ir, (*ir)->getPrix());
            // Insérer la nouvelle réservation dans la map
            reservationMap.insert({idpass, nouvelleReservation}); // Utilisez getIdPassager() directement via *ip

            // Mettre à jour le nombre de places disponibles dans le vol
            (*ir)->setPlacesDisponibles(((*ir)->getPlacesDisponibles() - 1));
        }




      }

     else {
        cout << "Désolé, vol non trouvé ou places épuisées" << endl;

    }
    }


 break;
}


    case 2 :
        {
            // Parcourir la map reservationMap pour afficher les détails de chaque réservation
cout << "Liste des réservations : " << endl;
for (const auto& pair : reservationMap) {
    cout << "ID Passager associé : " << pair.first << endl; // ID du passager associé
    Reservation reservation = pair.second;
    cout << "  ID Réservation : " << reservation.getIdReservation() << endl; // ID de la réservation
    cout << "  Date de réservation : " << reservation.getDateReservation().jour << "/" << reservation.getDateReservation().mois << "/" << reservation.getDateReservation().annee << endl; // Date de réservation
    cout << "  ID Vol associé : " << reservation.getVol()->getNumeroVol() << endl; // ID du vol associé
    cout<<" le Montant Total a paye est : "<<reservation.getTotalAPayer()<<" MAD "<<endl;
}
         break;

        }
        case 3 : {
        // Demander l'ID de la réservation à modifier
int idReservation;
cout << "Entrez l'ID de la réservation à modifier : ";
cin >> idReservation;

// Recherche de la réservation dans la map
auto reservationIt = reservationMap.find(idReservation);
if (reservationIt != reservationMap.end()) {
    // Réservation trouvée
    Reservation& reservation = reservationIt->second;

    // Demander le nouvel ID du passager
    int nouvelIdPassager;
    cout << "Entrez le nouvel ID du passager : ";
    cin >> nouvelIdPassager;

    // Recherche du nouveau passager dans le deque des passagers
    auto passagerIt = find_if(passagers.begin(), passagers.end(), [nouvelIdPassager](const Passager& passager) {
        return passager.getIdPassager() == nouvelIdPassager;
    });

    if (passagerIt != passagers.end()) {
        // Nouveau passager trouvé
        Passager& nouveauPassager = *passagerIt;

        // Mettre à jour le passager associé à la réservation
        reservation.setPassager(&nouveauPassager);

        cout << "Passager associé à la réservation mis à jour avec succès !" << endl;
    } else {
        // Nouveau passager non trouvé
        cout << "Erreur : Passager avec l'ID " << nouvelIdPassager << " non trouvé." << endl;
    }
} else {
    // Réservation non trouvée
    cout << "Erreur : Réservation avec l'ID " << idReservation << " non trouvée." << endl;
}
break;
        }
        case 4 : {
         // Demander l'ID de la réservation à supprimer
int idReservation;
cout << "Entrez l'ID de la réservation à supprimer : ";
cin >> idReservation;

// Recherche de la réservation dans la map
auto reservationIt = reservationMap.find(idReservation);
if (reservationIt != reservationMap.end()) {
    // Réservation trouvée
    Reservation& reservation = reservationIt->second;

    // Récupérer le vol associé à la réservation
    Vol* volAssocie = reservation.getVol();

    // Mettre à jour le nombre de places disponibles dans le vol
    volAssocie->setPlacesDisponibles(volAssocie->getPlacesDisponibles() + 1);

    // Supprimer la réservation de la map
    reservationMap.erase(reservationIt);

    cout << "Réservation avec l'ID " << idReservation << " supprimée avec succès." << endl;
} else {
    // Réservation non trouvée
    cout << "Erreur : Réservation avec l'ID " << idReservation << " non trouvée." << endl;
}
       break;
        }

    case 6 :
        cout<< "*** By ***"<<endl;
        break;
    default :
        cout<<" choix invalide "<<endl;
        break;
}
}while(choix2!=6);
break;
}
case 4 :{
          do {
        cout << "***** Menu des Paiements *****"<<endl;
        cout << "1. Ajouter un paiement"<<endl;
        cout << "2. Supprimer un paiement"<<endl;
        cout << "3. Afficher les paiements avec un montant supérieur à 3000 dh"<<endl;
        cout << "4. Quitter"<<endl;
        cout << "Entrez votre choix: ";
        cin>>choix3;
          switch(choix3)
{
    case 1 :{
                // Demander l'ID de la réservation pour effectuer le paiement
                 int idReservation,idPaiement;
                double montant;
                Date datePaiement;
                string methode;
                 cout << "Entrez l'ID de la réservation pour effectuer le paiement : ";
                 cin >> idReservation;
                 // Vérifier si l'ID de réservation existe dans la map
auto reservationIt = reservationMap.find(idReservation);
if (reservationIt != reservationMap.end()) {
    cout << "Réservation trouvée !" << endl;
    cout << "Saisir l'ID du paiement: ";
                cin >> idPaiement;
                cout << "Saisir le montant: ";
                cin >> montant;
                cout << "Saisir la méthode de paiement: ";
                cin >> methode;
                // Vérifier si la méthode de paiement est "cash"
if (methode == "cash") {
    // Appliquer la réduction de 15%
    montant *= 0.85; // Soustraire 15%
}
                cout << "Saisir la date du paiement (jour mois année) : ";
cin >> datePaiement.jour >> datePaiement.mois >> datePaiement.annee;
Reservation& reservation = reservationIt->second;
                // Créer un nouvel objet Paiement avec les valeurs saisies
                 Paiement* nouveauPaiement = new Paiement(idPaiement,montant,datePaiement,methode,reservation);
                paiements.insert(nouveauPaiement);
break;
}
else
    cout << "Réservation non trouvée." << endl;

break;
    }
case 2 :{
          int id_paiement;
                cout << "Saisir l'ID du paiement à supprimer: ";
                cin >> id_paiement;
                 auto it = find_if(paiements.begin(), paiements.end(),
                    [id_paiement](Paiement* paiement) { return paiement->getIdPaiement() == id_paiement; });

                if (it != paiements.end()) {
                    delete *it;  // Supprime le paiement alloué dynamiquement
                    paiements.erase(it);  // Retire le pointeur du set
                    cout << "Paiement supprimé avec succès." << endl;
                } else {
                    cout << "Aucun paiement trouvé avec cet ID." << endl;
                }

break;
    }
case 3:
{
    for (const auto& pair : reservationMap) {
        const Reservation& reservation = pair.second;
        if (reservation.getTotalAPayer() > 3000) {  // Condition pour vérifier le montant
           cout << "Liste des réservations : " << endl;
    cout << "ID Passager associé : " << pair.first << endl; // ID du passager associé
    Reservation reservation = pair.second;
    cout << "  ID Réservation : " << reservation.getIdReservation() << endl; // ID de la réservation
    cout << "  Date de réservation : " << reservation.getDateReservation().jour << "/" << reservation.getDateReservation().mois << "/" << reservation.getDateReservation().annee << endl; // Date de réservation
    cout << "  ID Vol associé : " << reservation.getVol()->getNumeroVol() << endl; // ID du vol associé
    cout<<" le Montant Total a paye est : "<<reservation.getTotalAPayer()<<" MAD "<<endl;
}
            }


    break;
}

    case 4:{
        cout << "****by****" << endl;
                break;

    }
}

          }while (choix!=4);
          break;
          }

          case 5 :
            cout<<"****BY****";
            break;



    default:
                        cout << "Choix invalide" << endl;
                        break;
    }
}while(fonctionnalite!=5);

 return 0;
    }
