package feu;

public enum Feu {
VERT(30, "Passez"),
JAUNE(4, "Ralentissez"),
ROUGE(25, "Arrêtez");

    private final int sec;
    private final String message;

    Feu(int sec, String message){
        this.sec = sec;
        this.message = message;
    }

    public int getSec(){
        return sec;
    }

    public String getMessage(){
        return message;
    }

    public Feu suivant(){
        switch(this){  // this = feu
            case VERT: return JAUNE;
            case JAUNE: return ROUGE;
            default : return VERT;      //default obligatoire
        }
    }
}

