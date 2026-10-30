package comptebancaire;

public class CompteBancaire{
    private final String proprietaire;
    private double solde;
    private final String identifiant;
    private String libelle;

    private static int compteur = 0;

    public CompteBancaire(String proprietaire, double solde,String libelle) {
        this.proprietaire = proprietaire;
        if (solde > 0) {
            this.solde = solde;
        }
        else {
            this.solde = 0;
        }
        this.identifiant = proprietaire.charAt(0) + "-" + ++compteur;
        this.libelle = libelle;
    }

    public CompteBancaire(String proprietaire,String libelle) {
        this.proprietaire = proprietaire;
        this.identifiant = proprietaire.charAt(0) + "-" + ++compteur;
        this.libelle = libelle;
        this.solde = 0;
    }
    public String getProprietaire() {
        return proprietaire;
    }

    public double getSolde() {
        return solde;
    }

    public String getLibelle() {
        return libelle;
    }

    public String getIdentifiant(){
        return identifiant;
    }
    public void setLibelle(String libelle) {
        this.libelle = libelle;
    }
    public int getCompteur(){
        return compteur;
    }


}
