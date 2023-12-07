import file.sutc.Commun.ExcelManipulation;
import org.junit.jupiter.api.Test;

import static file.sutc.A0_Sheet.A0_ExcelSheet.getSDDD_Version;
import static org.junit.jupiter.api.Assertions.*;

public class MyStringUtilsTest {

    @Test
    public void testDeleteExtraReturnLine() {
        // Test case 1: Leading and trailing newlines should be removed
        String input1 = "\n\nHello, World!\n\n";
        String expected1 = "Hello, World!";
        String result1 = ExcelManipulation.deleteExtraReturnLine(input1);
        assertEquals(expected1, result1);

        // Test case 2: No newlines should be removed as they are within the string
        String input2 = "Hello\nWorld!";
        String expected2 = "Hello\nWorld!";
        String result2 = ExcelManipulation.deleteExtraReturnLine(input2);
        assertEquals(expected2, result2);

        // Test case 3: Only leading newlines should be removed
        String input3 = "\n\nJava is fun!";
        String expected3 = "Java is fun!";
        String result3 = ExcelManipulation.deleteExtraReturnLine(input3);
        assertEquals(expected3, result3);

        // Test case 4: Only trailing newlines should be removed
        String input4 = "Cats are cute!\n\n";
        String expected4 = "Cats are cute!";
        String result4 = ExcelManipulation.deleteExtraReturnLine(input4);
        assertEquals(expected4, result4);
    }
    @Test
    public void testSearch() {
        // Test case 1: Word is found in the array (case-insensitive)
        String[] array1 = {"apple", "Banana", "cherry"};
        String word1 = "BaNaNa";
        assertTrue(ExcelManipulation.Search(array1, word1));

        // Test case 2: Word is not found in the array (case-insensitive)
        String[] array2 = {"dog", "cat", "fish"};
        String word2 = "Bird";
        assertFalse(ExcelManipulation.Search(array2, word2));

        // Test case 3: Word is found in the array with leading/trailing spaces (case-insensitive)
        String[] array3 = {"  Java  ", "  Python  ", "  C++  "};
        String word3 = "  python  ";
        assertTrue(ExcelManipulation.Search(array3, word3));

        // Test case 4: Word is not found in an empty array
        String[] emptyArray = {};
        String word4 = "Hello";
        assertFalse(ExcelManipulation.Search(emptyArray, word4));


    }


    @Test
    public void testStubCallRequirementsModifier() {
        // Test case 1: Basic string replacements
        String input1 = "This is  a   test.\n\n\nAnother test.";
        String expected1 = "This is a test.\nAnother test.";
        String result1 = ExcelManipulation.stubCallRequirementsModifier(input1);
        assertEquals(expected1, result1);

        // Test case 2: Replacing phrases with " by calling "
        String input2 = "Function] corresponds to the following call:";
        String expected2 = "Function by calling :";
        String result2 = ExcelManipulation.stubCallRequirementsModifier(input2);
        assertEquals(expected2, result2);

        // Test case 3: Removing "]:"
        String input3 = "[read data on LPSPI] corresponds to the following call:\n" +
                "•\tDrvLPSPI_Read:\n" +
                "OUT: the address of {the read value}\n" +
                "OUT: the address of {status}\n";

        String expected3 = "read data on LPSPI by calling\n" +
                "•\tDrvLPSPI_Read:\n" +
                "OUT: the address of {the read value}\n" +
                "OUT: the address of {status}\n";
        String result3 = ExcelManipulation.stubCallRequirementsModifier(input3);
        assertEquals(expected3, result3);

        // Test case 4: Removing "[ ... ]" when conditions are met
        String input4 = "This is [a test].";
        String expected4 = "This is a test.";
        String result4 = ExcelManipulation.stubCallRequirementsModifier(input4);
        assertEquals(expected4, result4);
    }


    @Test
    public void testGetSDDD_Version() {
        // Arrange
        String input = "FADEX-OSS_PU_SDDD-A429.docm~1E:word_doc:fadex#1  Page 16/27\n" +
                " (\n" +
                "ATTENTION\n" +
                "Cette page est un dos de couverture.\n" +
                "Ne pas supprimer\n" +
                ")\n" +
                "FADEX SDDD\n" +
                "\n" +
                "FADEX-OSS_PU_SDDD-A429.docm~1E:word_doc:fadex#1  Page 27/27\n" +
                "FADEX SDDD\n" +
                "\n" +
                " Titre Long25 Titre Long25 Titre Long25 Rf Titre Long25 Titre Long25 Titre Long25 Titre Long25 Titre Long25 Titre Long25 Titre Long25 Titre Long25 Titre Long25 Titre Long25 Titre Long25 Titre Long25    Titre Long25 Titre Long25      Titre Long25 Titre Long25      Titre Long25 Titre Long25      Titre Long25 Titre Long25      Titre Long25 Titre Long25       Titre Long25 Titre Long25      Titre Long25 Titre Long25      Titre Long25 Titre Long25      Titre Long25 Titre Long25      Titre Long25 Titre Long25      Titre Long25 Titre Long25      Titre Long25 Titre Long25   Titre Long25 Titre Long25 Titre Long25 \n" +
                " Titre Long25 Titre Long25 Titre Long25 Titre Long25  Titre Long25  Titre Long25 Titre Long25  Titre Long25  Titre Long25  Titre Long25  Titre Long25           Erreur! Signet non dfini.  \n" +
                "FADEX SDDD  OSS_PU - A429  Software Detailed Design Description         FADEX-OSS_PU_SDDD-A429.docm~1E:word_doc:fadex#1     \n" +
                "       \n" +
                "\n" +
                "   \n" +
                "\n" +
                "       \n" +
                "\n" +
                "   \n" +
                "\n" +
                "FADEX-OSS_PU_SDDD-A429.docm~1E:word_doc:fadex#1  Page 12/27\n" +
                "FADEX SDDD";
        String expectedOutput = "1E";

        // Act
        String result = getSDDD_Version(input);

        // Assert
        assertEquals(expectedOutput, result);
    }

}
