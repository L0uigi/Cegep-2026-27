import bison.Bison;
import java.time.YearMonth;

public class Main{
    public static void main(String[] args) {
        Bison b;
        b = new Bison( "Bill l beau bison", 700, YearMonth.of(2023,1));
        b.pesee(725, YearMonth.now());
        System.out.println(b.getHistoriquePoids());
    }

}