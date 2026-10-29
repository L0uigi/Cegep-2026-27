package projetgym;

public class Abonnement {
    private double prix;
    private int duree;
    private String nomMembre;

    private static int nbAbonnements = 0;

    public Abonnement(String nomMembre){
        this.prix = 41.25;
        this.duree = 30;
        this.nomMembre = nomMembre;
        nbAbonnements++;
    }
    public Abonnement(int duree,String nomMembre){
        this.prix = (duree * 8.25);
        this.duree = duree;
        this.nomMembre = nomMembre;
        nbAbonnements++;
    }

    public Abonnement(double prix, int duree ,String nomMembre){
        this.prix = prix;
        this.duree = duree;
        this.nomMembre = nomMembre;
        nbAbonnements++;
    }
    public static int getNbAbonnements(){
        return nbAbonnements;
    }
    public double getPrix() {
        return prix;
    }

    public void setPrix(double prix) {
        this.prix = prix;
    }

    public int getDuree() {
        return duree;
    }

    public void setDuree(int duree) {
        this.duree = duree;
    }

    public String getNomMembre() {
        return nomMembre;
    }

    public void setNomMembre(String nomMembre) {
        this.nomMembre = nomMembre;
    }


}
