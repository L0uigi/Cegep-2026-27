package restaurant;

public class Restaurant {
    // peut mettre tables en final constante et on pourrait modifier ses elements À L'INTÉRIEUR DU TABLEAU.
    private Table[] tables = new Table[75];

    public Restaurant(){

        int i = 0;
        while (i < 30){
            tables[i] = new Table(2, i + 1, true);
            ++i;
        }
        while (i < 35){
            tables[i] = new Table(2, i + 1, false);
            ++i;
        }
        while (i < 65){
            tables[i] = new Table(4, i + 1, true);
            ++i;
        }
        while (i < 75){
            tables[i] = new Table(4, i + 1, false);
            ++i;
        }
    }


    public Table[] getTables() {
        return tables;
    }

    public void setTables(Table[] tables) {
        this.tables = tables;
    }

    public int nbTablesOccupees(){
        int somme = 0;
        for (int i = 0; i < tables.length; ++i) {
            if (tables[i].isOccupe()){
                somme++;
            }
        }
        return somme;
    }

    public Table assignerTableDispo(int nombreClient, boolean veutBanquette){
        Table tableAssignee = null;
        if (nombreClient <= 0 || nombreClient > 4)
            throw new IllegalArgumentException("Nombre de Client non disponible");
        else if (nombreClient <= 2 && veutBanquette == true){
            for (int i = 0; i < tables.length; ++i){
                if (!tables[i].isOccupe() && tables[i].isBanquette()){
                    tableAssignee = tables[i];
                }
                if (tableAssignee == null){

                }
            }
        }
    }

    public boolean verifierSiTableOccupe(int numeroTable){

    }

    public void libererTable(){

    }

}
/* Pour Checkbox    cb.isSelected();

   Pour Spinner     (Integer)s.getValue()`;
 */