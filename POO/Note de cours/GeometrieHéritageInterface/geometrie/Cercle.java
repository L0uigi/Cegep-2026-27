package geometrie;

public class Cercle extends Forme {

    private double rayon;

    public Cercle(String couleur, double rayon) {
        super(couleur);
        this.rayon = rayon;
    }

    public double getRayon() {
        return rayon;
    }

    public void setRayon(double rayon) {
        this.rayon = rayon;
    }


    @Override
    public double aire(){
        return Math.PI * rayon * rayon;
    }

    @Override
    public double perimetre(){
        return 2 * Math.PI * rayon;
    }
}
