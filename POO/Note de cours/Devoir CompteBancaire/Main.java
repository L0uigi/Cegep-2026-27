import comptebancaire.CompteBancaire;

public class Main {
    static void main(String[] args) {
        CompteBancaire b = new CompteBancaire("Perlipinpin", 200, "lol");
        System.out.println(b.getIdentifiant());
        System.out.println(b.getCompteur());
        // méthodes ajouter/retirer solde.
        //méthode modifier libelle après création.
    }
}
