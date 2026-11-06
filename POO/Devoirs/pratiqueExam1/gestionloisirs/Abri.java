package gestionloisirs;

public class Abri {
    private final String identifiant;
    private int ouverture;
    private int fermeture;
    private final int nbreToilettes;

    public static int compteur;

    public Abri(String identifiant, int ouverture, int fermeture, int nbreToilettes){
        if (nbreToilettes < 0){
            throw new IllegalArgumentException("Nombre de toilette Invalide");
        }
        if (ouverture < 0 || ouverture > 24)
        {
            throw new IllegalArgumentException("Heure d'ouverture indisponible");
        }
        if (fermeture < 0 || fermeture > 24)
        {
            throw new IllegalArgumentException("Heure de fermeture indisponible");
        }
        if (identifiant.charAt(0) != 'A' || identifiant.charAt(1) != 'B' ||
        identifiant.charAt(2) != 'R' || identifiant.charAt(3) != 'I'){
            throw new IllegalArgumentException("Identifiant invalide");
        }
        this.ouverture = ouverture;
        this.fermeture = fermeture;
        this.nbreToilettes = nbreToilettes;
        this.identifiant = identifiant;
        ++compteur;
    }
    //ouverture et fermeture 0 à 23h. il ferme toujours après son ouverture.
    // ouverture et fermeture changent en même temps et doivent être cohérents

}
