package packagetp1;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class EmployeTest {

    private Employe emp;
    @org.junit.jupiter.api.BeforeEach
    void setUp() {
        emp = new Employe("Labonté", "3444", 23, 34, 3);

    @Test
    public void testSalaireBrut(){
        assertEquals(emp.salaireBrut(), emp.getNbreHeuresSemaine() * emp.getSalaireHoraire(), 0);
    }
    @Test
            public void testJoursVacances(){
        assertEquals(emp.joursVacances(), 18);
        }

        @Test
        public void testHeuresSup(){

        emp.heuresSup(10);
            assertEquals(emp.getNbreHeuresSemaine(), 44);
        }

        @Test
        public void testHeuresSup(){

            emp.heuresSup(10);
            assertEquals(emp.getNbreHeuresSemaine(), 44);
        }

}