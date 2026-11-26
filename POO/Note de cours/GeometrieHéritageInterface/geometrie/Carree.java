package geometrie;

/*Carree hérite de Dessinable à cause de Rectangle*/
public class Carree extends Rectangle{

    public Carree(String couleur, double cote){
        super(couleur, cote, cote);
    }

    @Override
    public void setHauteur(double hauteur){
        super.setHauteur(hauteur);
        super.setLargeur(hauteur);
    }

    @Override
    public void setLargeur(double largeur){
        super.setLargeur(largeur);
        super.setHauteur(largeur);
    }
}
