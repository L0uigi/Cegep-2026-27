package packagetp1;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;

public class EmployeGUI {

    private JPanel panel1;
    private JTextField champNom;
    private JTextField champNumero;
    private JTextField champSalaireHoraire;
    private JTextField champNbHeures;
    private JTextField champAnciennete;
    private JSpinner spinnerHeuresSup;
    private JPanel panelHaut;
    private JPanel panelBas;
    private JButton bouton;
    private JTextField champSalaireApresImpot;
    private JTextField champJoursVacances;


    public static void main(String[] args) {
        JFrame frame = new JFrame("Salaire d'un employé");
        frame.setContentPane(new EmployeGUI().panel1);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setSize(520, 500);  // taille de la fenêtre
        frame.setLocationRelativeTo(null);  // la fenêtre est centrée par rapport à l'écran
        frame.setVisible(true);
    }

    public EmployeGUI() {
        SpinnerNumberModel snm = new SpinnerNumberModel(0,0,10,1);
        spinnerHeuresSup.setModel(snm);
        BoutonListener bl = new BoutonListener();
        bouton.addActionListener(bl);
    }

    private class BoutonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            DecimalFormat df = new DecimalFormat ( "0.00");

            // Vous aurez une erreur ici tant que votre classe Employe ne contiendra pas la méthode
            // permettant de construire une instance de la classe Employe ainsi qu'une définition des
            // méthodes heuresSup, salaireNetApresImpot et joursVacances.


//            Employe unEmploye = new Employe ( champNom.getText(),
//                                            champNumero.getText(),
//                                            Double.parseDouble(champSalaireHoraire.getText()),
//                                            Double.parseDouble(champNbHeures.getText()),
//                                            Integer.parseInt(champAnciennete.getText()));
//            unEmploye.heuresSup((int)spinnerHeuresSup.getValue());
//            champSalaireApresImpot.setText(df.format(unEmploye.salaireNetApresImpot()) + "$");
//            champJoursVacances.setText(unEmploye.joursVacances() + " jours");

        }
    }
}
