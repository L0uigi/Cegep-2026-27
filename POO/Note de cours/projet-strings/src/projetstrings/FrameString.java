package projetstrings;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class FrameString {
    private JPanel monPanel;
    private JTextArea champString;
    private JButton boutonResultats;
    private JTextField champMot;
    private JPanel panelOccurences;
    private JLabel reponse1;
    private JLabel reponse3;
    private JLabel reponse2;
    private JLabel reponse4;
    private JLabel reponse5;
    private JLabel reponse6;

    public static void main(String[] args) {
        JFrame frame = new JFrame("FrameString");
        frame.setContentPane(new FrameString().monPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1100, 600);
        frame.setVisible(true);
        frame.setLocationRelativeTo(null);
    }
	
    public FrameString()
    {
        Ecouteur ec = new Ecouteur ();
        boutonResultats.addActionListener(ec);
    }

    private class Ecouteur implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent e) {
            //contenu du champ texte
            String texte;
            texte = champString.getText();

            // codez ici question 1 ( caractère à l'indice 8 )
            reponse1.setText(String.valueOf(texte.charAt(8)));

            // codez ici qu8estion 2 ( indice du premier e )
             reponse2.setText(String.valueOf(texte.indexOf("e")));
            // codez ici question 3 ( indice du dernier e )
			
            // codez ici question 4 ( nombre de caractères de la phrase )

            // codez ici question 5 ( commence par une majuscule ) ( chercher dans classe Character )

            // codez ici question 6 ( nombre d'occurences d'un mot )
            String mot;
            mot = champMot.getText();
        }
	}
}

