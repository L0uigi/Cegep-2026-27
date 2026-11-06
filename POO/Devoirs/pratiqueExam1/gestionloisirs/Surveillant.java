package gestionloisirs;

public class Surveillant {
    private String matricule;
    private final String nom;
    private final String prenom;
    private  int anciennete;
    private Quart quart;
    public Surveillant(String matricule, String nom, String prenom, int anciennete, Quart quart){
        if (nom.isBlank()){
            throw new IllegalArgumentException("Nom invalide");
        }
        if (prenom.isBlank()){
            throw new IllegalArgumentException("Prenom invalide");
        }
        if (anciennete < 0){
            this.anciennete = anciennete;
        }
        if (matricule.charAt(0) !='S' || matricule.charAt(1) == 'V'){
            throw new IllegalArgumentException("Matricule Invalide");
        }
        this.matricule = matricule;
        this.nom = nom.trim();
        this.prenom = prenom.trim();
        this.anciennete = anciennete;
        this.quart = quart;
    }
    public Surveillant(String matrcilue, String nom , String prenom, int anciennete){
        this.matricule = matricule;
        this.nom = nom;
        this.prenom = prenom;
        this.anciennete = anciennete;
        this.quart = Quart.JOUR;

        // matricule doit respecter SV-0000
    }

    public String getMatricule() {
        return matricule;
    }

    public String getNom() {
        return nom;
    }

    public String getPrenom() {
        return prenom;
    }

    public int getAnciennete() {
        return anciennete;
    }

    public Quart getQuart() {
        return quart;
    }

    public void ajoutService(){
        ++anciennete;
    }

    public double calculerTaux(){
        double tauxHoraire = 17.00f;
        if (anciennete <= 12){
            tauxHoraire += (1.25f * anciennete) + (quart.getTaux());
        }
        else{
            tauxHoraire += (quart.getTaux());
        }
        return tauxHoraire;
    }
}
