package gestionloisirs;

public enum Quart {
    JOUR(7, 15, 0.00),
    SOIR(15, 23, 1.00),
    NUIT(23, 7, 2.50);

    private final int debut;
    private final int fin;
    private final double taux;

    Quart(int debut, int fin, double taux){
        this.debut = debut;
        this.taux = taux;
        this.fin = fin;
    }

    public int getDebut() {
        return debut;
    }

    public int getFin() {
        return fin;
    }

    public double getTaux() {
        return taux;
    }

    public boolean couvre(int heure){
        if (heure < 0){
            throw new IllegalArgumentException("heure donnée Invalide");
        }
        if (this == JOUR && heure >= debut && heure < fin){
            return true;
        }
        else if (this == SOIR && heure >= debut && heure < fin){
            return true;
        }
        else if(this == NUIT && ( (heure >= 23 && heure <=24) || (heure >= 0 && heure < 7) ) ){
            return true;
        }
        else{
            return false;
        }
    }
}

