package geometrie;

public class Triangle extends Forme{

    private double base;
    private double hauteur;

    public Triangle(String couleur, double base, double hauteur){
        super(couleur);
        this.base = base;
        this.hauteur = hauteur;
    }

    @Override
    public double aire(){
        return base * hauteur / 2;
    }

    @Override
    public double perimetre(){
        double hypothenuse = Math.sqrt(base * base + hauteur * hauteur);
        return base + hauteur + hypothenuse;
    }

}
