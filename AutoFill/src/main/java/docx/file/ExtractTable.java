package docx.file;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;

import org.apache.poi.xwpf.usermodel.XWPFDocument;
import org.apache.poi.xwpf.usermodel.XWPFTable;
import org.apache.poi.xwpf.usermodel.XWPFTableCell;
import org.apache.poi.xwpf.usermodel.XWPFTableRow;
import static docx.file.ExtractText.removeInvisibleChars;
import static excel.file.Services.ExcelFinal.number_of_causes;
import static excel.file.Services.ExcelFinal.switchArray;

public class ExtractTable {

    public static final String WHITE_COLOR_HEXA="FFFFFF";
    private static int rowNumber=-1;

    public static boolean IsRequirement(String requirement) {
        String[] notReq={"DO NOTHING","EFFECTS","ALL OTHER CASES","ALL OTHER CASE","CAUSES","NO EFFECT","ALWAYS","NO EFFECTS","ALL THE OTHER CASES","NO DATA TO READ"};
        requirement=requirement.replaceAll("[^a-zA-Z]", " ");
        requirement=requirement.trim();
        if( Objects.equals(requirement, ""))
        {
            return false;
        }
        for (String req:notReq)
        {
            if (requirement.equalsIgnoreCase(req)) {
                return false;
            }
        }
        return true;
    }

    public static void AddCause(String cell,ArrayList<String> cause) {

            String causes = cell.trim();

            if ((!(causes.startsWith("["))) && (!(causes.endsWith("]")))) {
                if ((causes.toUpperCase().contains("OR"))||(causes.toUpperCase().contains("AND"))) {

                    String[] cause_table = causes.split("\\s+(?i)(or|and)\\s+");
                    cause.addAll(Arrays.asList(cause_table));
                }else
                    cause.add(causes);
            }
            else {
                causes = causes.replaceAll("\\(", "");
                causes = causes.replaceAll("\\)", "");

                while (!Objects.equals(causes.trim(), "")) {
                    String c = causes.substring(causes.indexOf("["), causes.indexOf("]") + 1);
                    c = c.replaceAll("[^\\w\\[\\]]", " ").trim();
                    cause.add(c);
                    causes = causes.trim().substring(causes.indexOf("]") + 1);

                    if (!causes.trim().equals("")) {
                        causes = causes.trim().substring(causes.indexOf("[") - 1);
                    }
                }
            }
        }

    public static void ExtractCausesEffects(XWPFTableRow row,ArrayList<String> cause, ArrayList<String> effect) {

        XWPFTableCell cell;
        int number_Of_Cause=0;

        for (int i = 0; i < row.getTableCells().size(); i++) {
            cell = row.getCell(i);
            if (((Objects.equals(cell.getColor(), WHITE_COLOR_HEXA)) || Objects.equals(cell.getColor(), "auto") || Objects.equals(cell.getColor(), null)) && (IsRequirement(cell.getText())))
                effect.add(removeInvisibleChars(cell.getText().trim()));

            else
            {
                if(IsRequirement(cell.getText()))
                    number_Of_Cause++;
                if(number_Of_Cause==1)
                    rowNumber++; // stored the row
            }
        }


        if(number_Of_Cause>=3) { // if the line in cause/effect table is >3

            if (!switchArray[rowNumber]) { // if 'if'
                for (int i = 1; i <= number_Of_Cause; i +=2) {
                    cell = row.getCell(i);
                    if (IsRequirement(cell.getText()))
                        AddCause(cell.getText(), cause);
                }
            } else {

                for (int i = 1; i < number_Of_Cause; i++) { // if 'switch'

                    cell = row.getCell(i);
                    if (IsRequirement(cell.getText()))
                        AddCause(cell.getText(), cause);
                }
            }
        }else {
            for (int i = 1; i <= number_Of_Cause; i +=2) {
                cell = row.getCell(i);
                if (IsRequirement(cell.getText()))
                    AddCause(cell.getText(), cause);
            }
        }
    }

    public static void Extract_Table(String path, ArrayList<String> cause, ArrayList<String> effect) throws IOException {

            rowNumber=-1;
            // Open the docx file
            File file = new File(path);
            FileInputStream fis = new FileInputStream(file);
            XWPFDocument document = new XWPFDocument(fis);

            // Get the first table in the document
            XWPFTable table = document.getTables().get(0);
            // Loop through each row of the table
             for (int i = 0; i < table.getRows().size(); i++) {

                  ExtractCausesEffects( table.getRow(i),cause,effect);

            // Loop through each cell of the row
           /*     for (int j = 0; j < row.getTableCells().size(); j++) {
                    XWPFTableCell cell = row.getCell(j);
                // Print the index of the current row and cell
                    System.out.println("Row " + i + ", Cell " + j+" = "+cell.getText());

                    if((Objects.equals(cell.getColor(), WHITE_COLOR_HEXA))||Objects.equals(cell.getColor(), "auto")||Objects.equals(cell.getColor(), null)){
                        if (IsRequirement(cell.getText()))
                        {
                            effect.add(removeInvisibleChars(cell.getText().trim()));
                        }
                    }
                    else
                    {

                        }
                    }
                }*/
            }
            // Close the document
        document.close();
        }

}

