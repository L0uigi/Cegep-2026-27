package restaurant;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Placier extends JFrame{
    private JPanel panel;
    private JSpinner nbConvives;
    private JCheckBox ouiCheckBox;
    private JButton valider;
    private JLabel labelNumTable;
    private JLabel labelNbTablesOccupees;
    private JSpinner numTableLiberer;
    private JButton liberer;
    private Restaurant restaurant;

    public Placier(Restaurant restaurant){
        super("TableMatch");

        this.restaurant = restaurant;

        nbConvives.setModel(new SpinnerNumberModel(2,2,4,1));
        numTableLiberer.setModel(new SpinnerNumberModel(1, 1, restaurant.getTables().length, 1));

        Listener listener = new Listener();
        valider.addActionListener(listener);
        liberer.addActionListener(listener);

//        Ces instructions qui placent les components dans
//        notre JPanel sont déjà effectuées par Swing UI Designer
//        Nous n'avons pas à les mettre pour cette raison

//        panel.add(spinner);
//        panel.add(ouiCheckBox);
//        panel.add(bouton);
//        panel.add(labelNumTable);
//        panel.add(labelNbTablesOccupees);
//        panel.add(numTableLiberer);
//        panel.add(liberer);

        setContentPane(panel);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(700,500);
        setLocationRelativeTo(null);
    }

    private class Listener implements ActionListener {

        public void actionPerformed ( ActionEvent event) {

            if(event.getSource() == valider){
               traiterValidation();
            }
            else if(event.getSource() == liberer){
                traiterLiberation();
            }
        }
    }

    private void traiterValidation() {
        // Récupérer les informations de l'interface
        // Appeler restaurant.assignerTableDispo(...)
        // Actualiser l'affichage


    }

    private void traiterLiberation() {
        // Récupérer le numéro de table
        // Appeler restaurant.libererTable(...)
    }
}
