package geometrie;

public class Texte implements Dessinable{

    private String mot;

    public Texte(String mot){
        this.mot = mot;
    }

    @Override
    public void dessiner(){
        String bordure = "";
        for (int i = 0; i < mot.length() + 4; ++i){
            bordure += SYMBOLE;
        }
        System.out.println(bordure);
        System.out.println(SYMBOLE + " " + mot + " " + SYMBOLE);
        System.out.println(bordure);
    }

    @Override
    public String toString(){
        return "Texte : " + mot;
    }
}
