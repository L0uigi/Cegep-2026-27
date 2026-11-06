package bison;

import org.junit.jupiter.api.Test;

import java.time.YearMonth;

import static org.junit.Assert.*;
import static org.junit.jupiter.api.Assertions.*;

class BisonTest {

    private Bison b;

    @org.junit.jupiter.api.BeforeEach
    void setUp() {
        b = new Bison("Bill le beau bison", 700, YearMonth.of(2026, 1));

    }

    @org.junit.jupiter.api.Test
    void pesee() {
        b.pesee(725, YearMonth.of(2026, 11));
        assertEquals("2026-11 : 725.0 kg", b.getHistoriquePoids());
        assertEquals(725, b.getPoidsKg());
    }

    @org.junit.jupiter.api.Test
    void ageEnMois() {
    }

    @org.junit.jupiter.api.Test
    void estUnBebe() {
        assertTrue(b.estUnBebe());
    }

    @org.junit.jupiter.api.Test
    void testEstUnBebe() {
        assertFalse(b.estUnBebe(YearMonth.of(2028,11)));
    }

    @Test
    void poidsNonValide(){
        assertThrows(IllegalArgumentException.class, () -> b.pesee(-2, YearMonth.of(2027, 12)));
    }


}