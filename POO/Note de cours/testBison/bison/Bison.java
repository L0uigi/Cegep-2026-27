package bison;

import java.time.YearMonth;

public class Bison {
    private final String tag;
    private double poidsKg;
    private YearMonth anniversaire;
    private String historiquePoids;

    private static final double LIVRES_PAR_KG = 2.20462;

    public Bison(String tag, int poidsKg, YearMonth anniversaire) {
        if (tag == null || tag.isBlank()) {
            throw new IllegalArgumentException("Tag Invalide");
        }

        if (poidsKg < 0) {
            throw new IllegalArgumentException("Poids Invalide");
        }

        if (anniversaire == null) {
            throw new IllegalArgumentException("Date invalide");
        }

        this.tag = tag;
        this.poidsKg = poidsKg;
        this.anniversaire = anniversaire;
        this.historiquePoids = "";
    }

    public double getPoidsKg() {
        return poidsKg;
    }

    public double getPoidsLivres() {
        return poidsKg * LIVRES_PAR_KG;
    }

    public YearMonth getAnniversaire() {
        return anniversaire;
    }

    public String getTag() {
        return tag;
    }

    public String getHistoriquePoids() {
        return historiquePoids;
    }

    private void setPoidsKg(double poidsKg){
        if (poidsKg < 0){
            throw new IllegalArgumentException("Poids invalide");
        }
        this.poidsKg = poidsKg;
    }
    public void pesee(double nouveauPoids, YearMonth date){
        if (date == null || date.isBefore(anniversaire)){
            throw new IllegalArgumentException("Date de pesée invalide");
        }

        setPoidsKg(nouveauPoids);

        if (!historiquePoids.isEmpty()){
            historiquePoids += '\n';
        }



        historiquePoids += date.toString() + " : "
                + nouveauPoids + " kg";
    }

    public int ageEnMois(YearMonth reference){
        if (reference == null || reference.isBefore(anniversaire)){
            throw new IllegalArgumentException("Date de référence invalide");
        }

        int annees = reference.getYear() - anniversaire.getYear();
        int mois = reference.getMonthValue() - anniversaire.getMonthValue();

        return annees * 12 + mois;
    }

    public boolean estUnBebe(YearMonth reference){
        return ageEnMois(reference) < 12;
    }

    public boolean estUnBebe(){
        return estUnBebe(YearMonth.now());
    }

    @Override
    public String toString(){
        return "Bison : tag[" + tag + "] poidsKg[" + poidsKg + "]";
    }
}
