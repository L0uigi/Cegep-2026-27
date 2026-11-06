import feu.Feu;

import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        for (Feu poteau : Feu.values()) {
            System.out.println(poteau.ordinal());
            System.out.println(poteau.getSec());
            System.out.println(poteau.getMessage());
        }

        Feu nouvPoteau = Feu.VERT;
        System.out.println(nouvPoteau);
        nouvPoteau = nouvPoteau.suivant();
        System.out.println(nouvPoteau);
        nouvPoteau = nouvPoteau.suivant();
        System.out.println(nouvPoteau);

        Scanner sc = new Scanner((System.in));

        System.out.println("Entrez une couleur pour votre feu");
        String saisie = sc.nextLine().trim().toUpperCase();
        System.out.println(saisie);

        Feu nouveauFeu = Feu.valueOf(saisie);
        System.out.println(nouveauFeu);


        try{
            Feu nouveauFeu2 = Feu.valueOf(saisie);

            System.out.println(nouveauFeu2.getMessage());
        }
        catch (Exception e){
            System.out.println("Couleur non valide : " + saisie);
            System.out.println(e);
        }
    }
    }