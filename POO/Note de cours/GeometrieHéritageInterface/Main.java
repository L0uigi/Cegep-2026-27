import geometrie.Carree;
import geometrie.Rectangle;
import geometrie.Texte;
import geometrie.Triangle;
import org.w3c.dom.css.Rect;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in
public class Main{

    static void main(String[] args) {

        Triangle t = new Triangle("Rouge", 4, 3);
        System.out.println(t.description());

        Rectangle r = new Rectangle("Brun", 6, 3);
        r.dessinerAvecTitre();


        Carree c = new Carree("Bleu", 5);
        c.dessinerAvecTitre();
        c.setHauteur(2);
        c.dessinerAvecTitre();


        Texte tx = new Texte("Totototototo");
        tx.dessinerAvecTitre();
    }
}