package projetgym;

public class TestConstructeur {
    static void main(String[] args) {
        Abonnement a1 = new Abonnement(40,30, "Gauvreau");
        Abonnement a2 = new Abonnement(50,30, "Lol");
        System.out.println(Abonnement.getNbAbonnements());
        System.out.println(a2.getPrix());
    }
}
