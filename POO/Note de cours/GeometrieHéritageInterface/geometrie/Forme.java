package geometrie;

public abstract class Forme {
    private final String couleur;

    public Forme (String couleur){
        this.couleur = couleur;
    }

    public String getCouleur() {
        return couleur;
    }

    public abstract double aire();

    public abstract double perimetre();

    public String description(){
        return toString() + " : "
                + "Périmètre : " + perimetre()
                + " Aire : " + aire();
    }

    @Override
    public String toString(){
        return getClass().getSimpleName() + " " + couleur;
    }
}
