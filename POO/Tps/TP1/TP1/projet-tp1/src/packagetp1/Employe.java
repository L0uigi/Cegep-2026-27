package packagetp1;

public class Employe {
    // données
    private String nom;
    private final String numero;
    private double salaireHoraire;
    private double nbreHeuresSemaine;
    private int anciennete;

    // Constante(s) ici

    // Méthode constructeur à coder
    public Employe(String nom, String numero, double salaireHoraire, double nbreHeuresSemaine, int anciennete){
        if (nom == null || nom.isBlank()){
            throw new IllegalArgumentException("Nom invalide");
        }

        if (numero == null || numero.isBlank() || !((numero.charAt(0) < '5' && numero.charAt(0) > 0))){
            throw new IllegalArgumentException("Numero invalide");
        }

        if (salaireHoraire < 0){
            throw new IllegalArgumentException("Salaire Horaire invalide");
        }

        if (nbreHeuresSemaine < 0){
            throw new IllegalArgumentException("Nombre heures semaine invalide");
        }

        if (anciennete < 0){
            throw new IllegalArgumentException("Ancienneté invalide");
        }
        this.nom = nom;
        this.numero = numero;
        this.salaireHoraire = salaireHoraire;
        this.nbreHeuresSemaine = nbreHeuresSemaine;
        this.anciennete = anciennete;
    }
    // Accesseurs et mutateurs (getters, setters)

    public String getNumero() {
        return numero;
    }

    public String getNom() {
        return nom;
    }

    public double getSalaireHoraire() {
        return salaireHoraire;
    }

    public double getNbreHeuresSemaine() {
        return nbreHeuresSemaine;
    }

    public int getAnciennete() {
        return anciennete;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public void setSalaireHoraire(double salaireHoraire) {
        this.salaireHoraire = salaireHoraire;
    }

    public void setNbreHeuresSemaine(double nbreHeuresSemaine) {
        this.nbreHeuresSemaine = nbreHeuresSemaine;
    }

    public void setAnciennete(int anciennete) {
        this.anciennete = anciennete;
    }

    // Autres méthodes à coder
            // faire évoluer ancienneté++

    public double salaireBrut(){
        return nbreHeuresSemaine * salaireHoraire;
    }

    public double salaireNetAvantImpot(){
        double salaireB = salaireBrut();
        salaireB -= 0.111 * salaireBrut();
        salaireB -= 20;
        salaireB -= 0.0136 * salaireBrut();

        if (salaireB <= 0){
            return 0.00;
        }
        return salaireB;
    }

    public double impotFederal(){
        return salaireNetAvantImpot() * 0.19;
    }

    public double impotProvincial(){
        return salaireNetAvantImpot() * 0.20;
    }

    public double salaireNetApresImpot(){
        return salaireNetAvantImpot() - impotFederal() - impotProvincial();
    }

    public int joursVacances(){
        if (numero.charAt(0) == '1'){
            return 5 + anciennete;
        }
        else if (numero.charAt(0) == '2'){
            return 10 + anciennete;
        }
        else if (numero.charAt(0) == '3'){
            return 15 + anciennete;
        }
        else if (numero.charAt(0) == '4'){
            return 20 + anciennete;
        }
        return 0;
    }

    public void heuresSup(int heuresSuppl)
    {
        nbreHeuresSemaine += heuresSuppl;
    }



    // Vous devez obligatoirement respecter le nommage imposé.
    // Ces méthodes sont appelés dans le GUI et un changement
    // de nom fera que l'appel sera rejeté

}