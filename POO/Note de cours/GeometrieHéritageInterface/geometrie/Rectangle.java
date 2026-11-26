package geometrie;

public class Rectangle extends Forme implements Dessinable{
    private double largeur;
    private double hauteur;


    public Rectangle(String couleur, double largeur, double hauteur){
//        super("brun")
        super(couleur);
        this.largeur = largeur;
        this.hauteur = hauteur;
    }

    public double getLargeur() {
        return largeur;
    }

    public void setLargeur(double largeur) {
        this.largeur = largeur;
    }

    public double getHauteur() {
        return hauteur;
    }

    public void setHauteur(double hauteur) {
        this.hauteur = hauteur;
    }

    @Override
    public double aire(){
        return hauteur * largeur;
    }

    @Override
    public double perimetre(){
        return 2 * (hauteur * largeur);
    }

    @Override
    public void dessiner(){
        for(int ligne = 0; ligne < (int)hauteur; ++ligne ){
            for(int col = 0; col < (int)largeur; ++col){
                System.out.print(SYMBOLE + " ");
            }
            System.out.println();
        }
    }
}
