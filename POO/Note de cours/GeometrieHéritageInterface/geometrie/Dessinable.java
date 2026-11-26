package geometrie;

public interface Dessinable {

    char SYMBOLE = '*';

    void dessiner();

    default void dessinerAvecTitre() {
        System.out.println(this);
        dessiner();
        System.out.println(); // saut de ligne
    }
}
